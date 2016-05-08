#include "similar_shapes.hh"

#include <QLabel>
#include <QScrollBar>
#include <QPaintEvent>
#include "drawingcursor.hh"
#include "nodevisitor.hh"
#include "visualnode.hh"
#include <algorithm>
#include <chrono>
#include "globalhelper.hh"

namespace cpprofiler {
namespace analysis {

/// TODO(maxim): show all subtrees of a particular shape
/// TODO(maxim): find 'exact' subtrees

/// TODO(maxim): normalize only using currently shown shapes

ShapeProperty interpretShapeProperty(const QString& str) {
  if (str == "size") return ShapeProperty::SIZE;
  if (str == "count") return ShapeProperty::COUNT;
  if (str == "height") return ShapeProperty::HEIGHT;
  abort();
  return {};
}

SimilarShapesWindow::SimilarShapesWindow(TreeCanvas* tc)
    : QDialog(tc), m_tc(tc), shapeSet(CompareShapes{}), filters(*this) {
  addNodesToMap();

  scene.reset(new QGraphicsScene{});

  view = new QGraphicsView{this};
  view->setScene(scene.get());
  view->setAlignment(Qt::AlignLeft | Qt::AlignTop);

  auto m_scrollArea = new QAbstractScrollArea{this};

  auto splitter = new QSplitter{this};

  splitter->addWidget(view);
  splitter->addWidget(m_scrollArea);
  splitter->setSizes(QList<int>{1, 1});  // for splitter to be centered

  auto depthFilterSB = new QSpinBox{this};
  depthFilterSB->setMinimum(1);
  depthFilterSB->setValue(2);
  QObject::connect(depthFilterSB, SIGNAL(valueChanged(int)), this,
                   SLOT(depthFilterChanged(int)));

  auto countFilterSB = new QSpinBox{this};
  countFilterSB->setMinimum(1);
  countFilterSB->setValue(2);
  QObject::connect(countFilterSB, SIGNAL(valueChanged(int)), this,
                   SLOT(countFilterChanged(int)));

  auto histChoiceCB = new QComboBox();
  histChoiceCB->addItem("size");
  histChoiceCB->addItem("count");
  histChoiceCB->addItem("height");
  connect(histChoiceCB, &QComboBox::currentTextChanged,
          [this](const QString& str) {
            m_histType = interpretShapeProperty(str);
            drawHistogram();
          });

  auto sortChoiceCB = new QComboBox();
  sortChoiceCB->addItem("size");
  sortChoiceCB->addItem("count");
  sortChoiceCB->addItem("height");
  connect(sortChoiceCB, &QComboBox::currentTextChanged,
          [this](const QString& str) {
            m_sortType = interpretShapeProperty(str);
            drawHistogram();
          });

  auto depthFilterLayout = new QHBoxLayout{};
  depthFilterLayout->addWidget(new QLabel("min height"));
  depthFilterLayout->addWidget(depthFilterSB);

  auto countFilterLayout = new QHBoxLayout{};
  countFilterLayout->addWidget(new QLabel("min count"));
  countFilterLayout->addWidget(countFilterSB);

  auto filtersLayout = new QHBoxLayout{};
  filtersLayout->addLayout(depthFilterLayout);
  filtersLayout->addLayout(countFilterLayout);
  filtersLayout->addStretch();
  filtersLayout->addWidget(new QLabel{"sort by: "});
  filtersLayout->addWidget(sortChoiceCB);
  filtersLayout->addWidget(new QLabel{"histogram: "});
  filtersLayout->addWidget(histChoiceCB);

  auto globalLayout = new QVBoxLayout{this};
  globalLayout->addWidget(splitter);
  globalLayout->addLayout(filtersLayout);

  // m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
  // m_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
  m_scrollArea->setAutoFillBackground(true);

  shapeCanvas = new ShapeCanvas(m_scrollArea, tc, shapeSet);
  shapeCanvas->show();

  drawHistogram();
}

void SimilarShapesWindow::addNodesToMap() {
  auto na = m_tc->get_na();
  VisualNode* root = (*na)[0];

  root->unhideAll(*na);
  root->layout(*na);
  SimilarShapesCursor ac(root, *na, *this);
  PostorderNodeVisitor<SimilarShapesCursor>(ac).run();
}

int maxShapeValue(const std::vector<ShapeI>& shapes, ShapeProperty prop,
                  const std::multiset<ShapeI, CompareShapes>& set) {
  if (prop == ShapeProperty::SIZE) {
    const ShapeI& max_shape = *std::max_element(
        begin(shapes), end(shapes), [](const ShapeI& s1, const ShapeI& s2) {
          return s1.shape_size < s2.shape_size;
        });
    return max_shape.shape_size;
  } else if (prop == ShapeProperty::COUNT) {
    const ShapeI& max_shape = *std::max_element(
        begin(shapes), end(shapes), [&set](const ShapeI& s1, const ShapeI& s2) {
          return set.count(s1) < set.count(s2);
        });
    return set.count(max_shape);
  } else if (prop == ShapeProperty::HEIGHT) {
    const ShapeI& max_shape = *std::max_element(
        begin(shapes), end(shapes), [&set](const ShapeI& s1, const ShapeI& s2) {
          return s1.s->depth() < s2.s->depth();
        });
    return max_shape.s->depth();
  }

  return 1;
}

void sortShapes(std::vector<ShapeI>& shapes, ShapeProperty prop,
  const std::multiset<ShapeI, CompareShapes>& set) {
  if (prop == ShapeProperty::SIZE) {
    std::sort(begin(shapes), end(shapes),
              [](const ShapeI& s1, const ShapeI& s2) {
                return s1.shape_size > s2.shape_size;
              });
  } else if (prop == ShapeProperty::COUNT) {
    std::sort(begin(shapes), end(shapes),
              [&set](const ShapeI& s1, const ShapeI& s2) {
                return set.count(s1) > set.count(s2);
              });
  } else if (prop == ShapeProperty::HEIGHT) {
    std::sort(begin(shapes), end(shapes),
              [&set](const ShapeI& s1, const ShapeI& s2) {
                return s1.s->depth() > s2.s->depth();
              });
  }
}

namespace detail {

inline void addText(QGraphicsTextItem* text_item, int x, int y,
                    QGraphicsScene& scene) {
  // center the item vertically at y
  int text_y_offset = text_item->boundingRect().height() / 2;
  text_item->setPos(x, y - text_y_offset);
  scene.addItem(text_item);
}
};

inline void addText(const char* text, int x, int y, QGraphicsScene& scene) {
  /// will this memory be released?
  auto str_text_item = new QGraphicsTextItem{text};
  detail::addText(str_text_item, x, y, scene);
}

// constexpr int
constexpr int NUMBER_WIDTH = 50;
constexpr int COLUMN_WIDTH = NUMBER_WIDTH + 10;

inline void addText(int value, int x, int y, QGraphicsScene& scene) {
  auto int_text_item = new QGraphicsTextItem{QString::number(value)};
  // alignment to the right
  x += COLUMN_WIDTH - int_text_item->boundingRect().width();
  detail::addText(int_text_item, x, y, scene);
}

void SimilarShapesWindow::drawHistogram() {
  qDebug() << "draw histogram\n";

  scene.reset(new QGraphicsScene{});
  view->setScene(scene.get());

  int curr_y = 40;
  int rects_displayed = 0;

  auto rect_max_w = ShapeRect::SELECTION_WIDTH;

  addText("hight", 10, 10, *scene);
  addText("count", 10 + COLUMN_WIDTH, 10, *scene);
  addText("size", 10 + COLUMN_WIDTH * 2, 10, *scene);

  perfHelper.begin("applying a filter");

  shapesShown.clear();
  shapesShown.reserve(shapeSet.size());

  for (auto it = shapeSet.begin(), end = shapeSet.end(); it != end;
       it = shapeSet.upper_bound(*it)) {
    if (!filters.apply(*it)) {
      continue;
    }

    shapesShown.push_back(*it);
  }

  perfHelper.end();

  perfHelper.begin("finding max");
  int max_value = maxShapeValue(shapesShown, m_histType, shapeSet);
  qDebug() << "max_value: " << max_value;
  perfHelper.end();

  perfHelper.begin("sorting a histogram");

  sortShapes(shapesShown, m_sortType, shapeSet);

  perfHelper.end();

  perfHelper.begin("displaying a histogram");
  for (auto it = shapesShown.begin(), end = shapesShown.end(); it != end;
       ++it) {
    const int shape_count = shapeSet.count(*it);
    const int shape_size = it->shape_size;
    const int shape_height = (it->node)->getShape()->depth();

    int value;
    if (m_histType == ShapeProperty::SIZE) {
      value = shape_size;
    } else if (m_histType == ShapeProperty::COUNT) {
      value = shape_count;
    } else if (m_histType == ShapeProperty::HEIGHT) {
      value = shape_height;
    }

    const int rect_width = rect_max_w * value / max_value;
    auto rect = new ShapeRect(0, curr_y, rect_width, it->node, shapeCanvas);
    rect->draw(scene.get());

    /// NOTE(maxim): drawing text is really expensive
    /// TODO(maxim): only draw if visible

    // auto sb_value = view->verticalScrollBar()->value();

    addText(shape_height, 10 + COLUMN_WIDTH * 0, curr_y, *scene);
    addText(shape_count, 10 + COLUMN_WIDTH * 1, curr_y, *scene);
    addText(shape_size, 10 + COLUMN_WIDTH * 2, curr_y, *scene);

    rects_displayed++;
    curr_y += ShapeRect::HEIGHT + 1;
  }

  perfHelper.end();
}

void SimilarShapesWindow::depthFilterChanged(int val) {
  filters.setMinDepth(val);
  drawHistogram();
}

void SimilarShapesWindow::countFilterChanged(int val) {
  filters.setMinCount(val);
  drawHistogram();
}

// ---------------------------------------

Filters::Filters(const SimilarShapesWindow& ssw) : m_ssWindow(ssw) {}

bool Filters::apply(const ShapeI& si) {
  if (si.s->depth() < m_minDepth) return false;
  if ((int)m_ssWindow.shapeSet.count(si) < m_minCount) return false;
  return true;
}

void Filters::setMinDepth(int val) { m_minDepth = val; }

void Filters::setMinCount(int val) { m_minCount = val; }

static const QColor transparent_red{255, 0, 0, 50};

ShapeRect::ShapeRect(int x, int y, int width, VisualNode* node, ShapeCanvas* sc,
                     QGraphicsItem* parent)
    : QGraphicsRectItem(x, y - HALF_HEIGHT, SELECTION_WIDTH, HEIGHT, parent),
      visibleArea(x, y - HALF_HEIGHT + 1, width, HEIGHT - 2),
      m_node{node},
      m_canvas{sc} {
  setBrush(Qt::white);
  QPen whitepen(Qt::white);
  setPen(whitepen);
  setFlag(QGraphicsItem::ItemIsSelectable);
  visibleArea.setBrush(transparent_red);
  visibleArea.setPen(whitepen);
}

void ShapeRect::draw(QGraphicsScene* scene) {
  scene->addItem(this);
  scene->addItem(&visibleArea);
}

VisualNode* ShapeRect::getNode() { return m_node; }

void ShapeRect::mousePressEvent(QGraphicsSceneMouseEvent*) {
  m_canvas->highlightShape(m_node);
}

ShapeCanvas::ShapeCanvas(QAbstractScrollArea* sa, TreeCanvas* tc,
                         const std::multiset<ShapeI, CompareShapes>& set)
    : QWidget{sa}, m_sa{sa}, m_tc{tc}, m_shapesSet{set} {}

void ShapeCanvas::paintEvent(QPaintEvent* event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  auto it = m_shapesSet.begin();
  if (m_targetNode == nullptr) {
    m_targetNode = it->node;
  }

  int view_w = m_sa->viewport()->width();
  int view_h = m_sa->viewport()->height();

  int xoff = m_sa->horizontalScrollBar()->value();
  int yoff = m_sa->verticalScrollBar()->value();

  const BoundingBox bb = m_targetNode->getBoundingBox();

  int w = bb.right - bb.left + Layout::extent;
  int h =
      2 * Layout::extent + m_targetNode->getShape()->depth() * Layout::dist_y;

  // center the shape if small
  if (w < view_w) {
    xoff -= (view_w - w) / 2;
  }

  setFixedSize(view_w, view_h);

  xtrans = -bb.left + (Layout::extent / 2);

  m_sa->horizontalScrollBar()->setRange(0, w - view_w);
  m_sa->verticalScrollBar()->setRange(0, h - view_h);
  m_sa->horizontalScrollBar()->setPageStep(view_w);
  m_sa->verticalScrollBar()->setPageStep(view_h);

  QRect origClip = event->rect();
  painter.translate(0, 30);
  painter.translate(xtrans - xoff, -yoff);
  QRect clip{origClip.x() - xtrans + xoff, origClip.y() + yoff,
             origClip.width(), origClip.height()};

  DrawingCursor dc{m_targetNode, *m_tc->get_na(), painter, clip, false};
  PreorderNodeVisitor<DrawingCursor>(dc).run();
}

void ShapeCanvas::highlightShape(VisualNode* node) {
  m_targetNode = node;
  m_tc->highlightShape(node);
  QWidget::update();
}

void ShapeCanvas::scroll() { QWidget::update(); }

int shapeSize(const Shape& s) {
  int total_size = 0;

  int prev_l = 0;
  int prev_r = 0;

  for (int i = 0; i < s.depth(); ++i) {
    total_size += std::abs((s[i].r + prev_r) - (s[i].l + prev_l));
    prev_l = s[i].l;
    prev_r = s[i].r;
  }

  return total_size;
}

ShapeI::ShapeI(int sol0, VisualNode* node0)
    : sol(sol0), node(node0), s(Shape::copy(node->getShape())) {
  shape_size = shapeSize(*s);
}

ShapeI::~ShapeI() { Shape::deallocate(s); }

ShapeI::ShapeI(const ShapeI& sh)
    : sol(sh.sol),
      shape_size(sh.shape_size),
      node(sh.node),
      s(Shape::copy(sh.s)) {}

ShapeI& ShapeI::operator=(const ShapeI& sh) {
  if (this != &sh) {
    Shape::deallocate(s);
    s = Shape::copy(sh.s);
    sol = sh.sol;
    shape_size = sh.shape_size;
    node = sh.node;
  }
  return *this;
}

bool CompareShapes::operator()(const ShapeI& n1, const ShapeI& n2) const {
  if (n1.sol > n2.sol) return false;
  if (n1.sol < n2.sol) return true;

  const Shape& s1 = *n1.s;
  const Shape& s2 = *n2.s;

  if (s1.depth() < s2.depth()) return true;
  if (s1.depth() > s2.depth()) return false;

  for (int i = 0; i < s1.depth(); ++i) {
    if (s1[i].l < s2[i].l) return false;
    if (s1[i].l > s2[i].l) return true;
    if (s1[i].r < s2[i].r) return true;
    if (s1[i].r > s2[i].r) return false;
  }
  return false;
}
}
}