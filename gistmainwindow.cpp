/*  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject to
 *  the following conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 *  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 *  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include "gistmainwindow.h"
#include "preferences.hh"
#include "nodewidget.hh"

#include <cmath>
#include <fstream>

AboutGist::AboutGist(QWidget* parent) : QDialog(parent) {

  setMinimumSize(300, 240);
  setMaximumSize(300, 240);
  QVBoxLayout* layout = new QVBoxLayout();
  QLabel* aboutLabel =
    new QLabel(tr("<h2>Gist</h2>"
                   "<p><b>The Gecode Interactive Search Tool</b</p> "
                  "<p>You can find more information about Gecode and Gist "
                  "at</p>"
                  "<p><a href='http://www.gecode.org'>www.gecode.org</a>"
                  "</p"));
  aboutLabel->setOpenExternalLinks(true);
  aboutLabel->setWordWrap(true);
  aboutLabel->setAlignment(Qt::AlignCenter);
  layout->addWidget(aboutLabel);
  setLayout(layout);
  setWindowTitle(tr("About Gist"));
  setAttribute(Qt::WA_QuitOnClose, false);
  setAttribute(Qt::WA_DeleteOnClose, false);
}



GistMainWindow::GistMainWindow(Execution* execution, QWidget* parent) : QMainWindow(parent), aboutGist(this) {
    c = new Gist(execution, this);
  setCentralWidget(c);
  setWindowTitle(tr("CP-Profiler"));

  

//  Logos logos;
//  QPixmap myPic;
//  myPic.loadFromData(logos.gistLogo, logos.gistLogoSize);
//  setWindowIcon(myPic);

  resize(500,500);
  setMinimumSize(400, 200);

  menuBar = new QMenuBar(0);

  QMenu* fileMenu = menuBar->addMenu(tr("&File"));
  fileMenu->addAction(c->print);
  fileMenu->addAction(c->printSearchLog);
#if QT_VERSION >= 0x040400
  fileMenu->addAction(c->exportWholeTreePDF);
#endif

  prefAction = fileMenu->addAction(tr("Preferences"));
  connect(prefAction, SIGNAL(triggered()), this, SLOT(preferences()));

  QAction* quitAction = fileMenu->addAction(tr("Quit"));
  quitAction->setShortcut(QKeySequence("Ctrl+Q"));
  connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

  QMenu* nodeMenu = menuBar->addMenu(tr("&Node"));
  nodeMenu->addAction(c->showNodeStats);

  bookmarksMenu = new QMenu("Bookmarks", this);
  bookmarksMenu->addAction(c->bookmarkNode);
  connect(bookmarksMenu, SIGNAL(aboutToShow()),
          this, SLOT(populateBookmarks()));
  nodeMenu->addMenu(bookmarksMenu);
  nodeMenu->addSeparator();
  nodeMenu->addAction(c->navUp);
  nodeMenu->addAction(c->navDown);
  nodeMenu->addAction(c->navLeft);
  nodeMenu->addAction(c->navRight);
  nodeMenu->addAction(c->navRoot);
  nodeMenu->addAction(c->navNextSol);
  nodeMenu->addAction(c->navPrevSol);
  nodeMenu->addSeparator();
  nodeMenu->addAction(c->toggleHidden);
  nodeMenu->addAction(c->hideFailed);
  nodeMenu->addAction(c->unhideAll);
  nodeMenu->addAction(c->labelBranches);
  nodeMenu->addAction(c->labelPath);
  nodeMenu->addAction(c->analyzeSimilarSubtrees);
  nodeMenu->addAction(c->showNogoods);
  nodeMenu->addAction(c->showNodeInfo);
  // nodeMenu->addAction(c->toggleStop);
  // nodeMenu->addAction(c->unstopAll);
  nodeMenu->addSeparator();
  nodeMenu->addAction(c->zoomToFit);
  nodeMenu->addAction(c->center);
#if QT_VERSION >= 0x040400
  nodeMenu->addAction(c->exportPDF);
#endif

  /// ***** Tree Visualisaitons *****

  QMenu* treeVisMenu = menuBar->addMenu(tr("Tree"));

  treeVisMenu->addAction(c->showPixelTree);
  treeVisMenu->addAction(c->showIcicleTree);
  treeVisMenu->addAction(c->hideSize);
  treeVisMenu->addAction(c->followPath);

  /// *******************************

  QMenu* searchMenu = menuBar->addMenu(tr("&Search"));
  // searchMenu->addAction(c->searchNext);
  // searchMenu->addAction(c->searchAll);
  // searchMenu->addSeparator();
  // searchMenu->addAction(c->stop);
  searchMenu->addSeparator();
  searchMenu->addAction(c->reset);
  searchMenu->addAction(c->sndCanvas);
  searchMenu->addAction(c->initComparison);

  QMenu* helpMenu = menuBar->addMenu(tr("&Help"));
  QAction* aboutAction = helpMenu->addAction(tr("About"));
  connect(aboutAction, SIGNAL(triggered()),
          this, SLOT(about()));

  // Don't add the menu bar on Mac OS X
#ifndef Q_WS_MAC
  setMenuBar(menuBar);
#endif

  // Set up status bar
  QWidget* stw = new QWidget();
  QHBoxLayout* hbl = new QHBoxLayout();
  hbl->setContentsMargins(0,0,0,0);
  hbl->addWidget(new QLabel("Depth:"));
  depthLabel = new QLabel("0");
  hbl->addWidget(depthLabel);
  hbl->addWidget(new NodeWidget(SOLVED));
  solvedLabel = new QLabel("0");
  hbl->addWidget(solvedLabel);
  hbl->addWidget(new NodeWidget(FAILED));
  failedLabel = new QLabel("0");
  hbl->addWidget(failedLabel);
  hbl->addWidget(new NodeWidget(BRANCH));
  choicesLabel = new QLabel("0");
  hbl->addWidget(choicesLabel);
  hbl->addWidget(new NodeWidget(UNDETERMINED));
  openLabel = new QLabel("     0");
  hbl->addWidget(openLabel);
  stw->setLayout(hbl);
  statusBar()->addPermanentWidget(stw);

  isSearching = false;
  statusBar()->showMessage("Ready");

  connect(c,SIGNAL(statusChanged(const Statistics&,bool)),
          this,SLOT(statusChanged(const Statistics&,bool)));

  connect(c, SIGNAL(changeMainTitle(QString)),
          this, SLOT(changeTitle(QString)));

  connect(c, SIGNAL(buildingFinished(void)),
          this, SIGNAL(buildingFinished(void)));

  // connect(this, SIGNAL(stopReceiver()), c->getReceiver(), SLOT(stopThread()));

  preferences(true);
  show();
  c->reset->trigger();
}

// void
// GistMainWindow::closeEvent(QCloseEvent* event) {

//   emit stopReceiver();
//   // c->getReceiver()->wait();

//   if (c->finish())
//     event->accept();
//   else 
//     event->ignore();
// }

void
GistMainWindow::statusChanged(const Statistics& stats, bool finished) {
  if (stats.maxDepth==0) {
    isSearching = false;
    statusBar()->showMessage("Ready");
    prefAction->setEnabled(true);
  } else if (isSearching && finished) {
    isSearching = false;

    /// add total time to 'Done' label
    QString t;
    unsigned long long totalTime = c->getExecution()->getData()->getTotalTime();
    float seconds = totalTime / 1000000.0;
    t.setNum(seconds);
    statusBar()->showMessage("Done in " + t + "s");

    /// no need to change Status Bar anymore
    disconnect(c,SIGNAL(statusChanged(const Statistics&,bool)),
            this,SLOT(statusChanged(const Statistics&,bool)));


    prefAction->setEnabled(true);
  } else if (!isSearching && !finished) {
    prefAction->setEnabled(false); /// TODO: leave active all the time instead?
    statusBar()->showMessage("Searching");
    isSearching = true;
  }
  depthLabel->setNum(stats.maxDepth);
  solvedLabel->setNum(stats.solutions);
  failedLabel->setNum(stats.failures);
  choicesLabel->setNum(stats.choices);
  openLabel->setNum(stats.undetermined);
}

void
GistMainWindow::about(void) {
  aboutGist.show();
}

void
GistMainWindow::preferences(bool setup) {
  PreferencesDialog pd(this);
  if (setup) {
    c->setAutoZoom(pd.zoom);
  }
  if (setup || pd.exec() == QDialog::Accepted) {
    c->setAutoHideFailed(pd.hideFailed);
    c->setRefresh(pd.refresh);
    c->setRefreshPause(pd.refreshPause);
    c->setSmoothScrollAndZoom(pd.smoothScrollAndZoom);
    c->setMoveDuringSearch(pd.moveDuringSearch);
  }
}

void
GistMainWindow::populateBookmarks(void) {
  bookmarksMenu->clear();
  bookmarksMenu->addAction(c->bookmarkNode);
  bookmarksMenu->addSeparator();
  bookmarksMenu->addActions(c->bookmarksGroup->actions());
}

void
GistMainWindow::changeTitle(QString file_name) {
  qDebug() << "changing title to: " << file_name;
  this->setWindowTitle(file_name);
}

void
GistMainWindow::gatherStatistics(void) {
  std::cerr << "GistMainWindow::gatherStatistics\n";
  std::ofstream out;
  out.open(statsFilename.toStdString(), std::ofstream::out);
  c->getCanvas()->collectMLStatsRoot(out);
  out.close();
}
