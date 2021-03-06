#-------------------------------------------------
#
# Project created by QtCreator 2014-03-28T15:13:15
#
#-------------------------------------------------

# Turn this on for "development mode" (see e.g. webscript.hh)
DEFINES += CP_PROFILER_DEVELOPMENT


QT       += core gui network

QT += webkitwidgets
# QT += webenginewidgets webchannel

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

QMAKE_CXXFLAGS += -g

macx: {
  QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.7
  LIBS += -lc++
  QMAKE_CXXFLAGS += -stdlib=libc++
}

TARGET = cp-profiler

TEMPLATE = app

RESOURCES = cp-profiler.qrc

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
    globalhelper.cpp \
    gistmainwindow.cpp \
    heap.cpp \
    nodewidget.cpp \
    drawingcursor.cpp \
    treecanvas.cpp \
    visualnode.cpp \
    nodestats.cpp \
    preferences.cpp \
    qtgist.cpp \
    spacenode.cpp \
    node.cpp \
    data.cpp \
    cmp_tree_dialog.cpp \
    receiverthread.cpp \
    treebuilder.cpp \
    readingQueue.cpp \
    treecomparison.cpp \
    nogood_dialog.cpp \
    node_info_dialog.cpp \
    cpprofiler\pixeltree\pixelImage.cpp \
    maybeCaller.cpp \
    message.pb.cpp \
    profiler-conductor.cpp \
    profiler-tcp-server.cpp \
    ml-stats.cpp \
    execution.cpp \
    cpprofiler\analysis\backjumps.cpp \
    cpprofiler\pixeltree\pixel_tree_dialog.cpp \
    cpprofiler\pixeltree\icicle_tree_dialog.cpp \
    cpprofiler\pixeltree\pixel_tree_canvas.cpp \
    cpprofiler\analysis\depth_analysis.cpp \
    cpprofiler\analysis\similar_shapes.cpp \

HEADERS  += globalhelper.hh \
    qtgist.hh \
    gistmainwindow.h \
    treecanvas.hh \
    visualnode.hh \
    spacenode.hh \
    node.hh \
    node.hpp \
    spacenode.hpp \
    visualnode.hpp \
    heap.hpp \
    nodestats.hh \
    preferences.hh \
    nodewidget.hh \
    drawingcursor.hh \
    drawingcursor.hpp \
    nodecursor_base.hh \
    nodecursor.hh \
    nodecursor.hpp \
    layoutcursor.hh \
    layoutcursor.hpp \
    nodevisitor.hh \
    nodevisitor.hpp \
    zoomToFitIcon.hpp \
    data.hh \
    highlight_nodes_dialog.hpp \
    cmp_tree_dialog.hh \
    receiverthread.hh \
    treebuilder.hh \
    readingQueue.hh \
    treecomparison.hh \
    nogood_dialog.hh \
    node_info_dialog.hh \
    message.pb.hh \
    profiler-conductor.hh \
    profiler-tcp-server.hh \
    execution.hh \
    cpprofiler\pixeltree\pixelImage.hh \
    maybeCaller.hh \
    ml-stats.hh \
    third-party\json.hpp \
    cpprofiler/analysis/backjumps.hh \
    cpprofiler/pixeltree/pixel_data.hh \
    cpprofiler/pixeltree/pixel_tree_dialog.hh \
    cpprofiler/pixeltree/icicle_tree_dialog.hh \
    cpprofiler/pixeltree/pixel_tree_canvas.hh \
    cpprofiler/pixeltree/pixel_item.hh \
    cpprofiler/analysis/depth_analysis.hh \
    cpprofiler/analysis/similar_shapes.hh \
    webscript.hh \
    

FORMS    +=

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../usr/local/lib/release/
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../usr/local/lib/debug/
else:unix: LIBS += -L$$PWD/../../../../../../usr/local/lib/ -ldl

INCLUDEPATH += /usr/local/include

LIBS += `pkg-config --cflags --libs protobuf` -lprotobuf

#CONFIG += link_pkgconfig
#PKGCONFIG += protobuf
