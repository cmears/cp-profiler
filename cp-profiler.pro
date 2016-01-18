#-------------------------------------------------
#
# Project created by QtCreator 2014-03-28T15:13:15
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport


TARGET = cp-profiler


TEMPLATE = app

CONFIG += c++11
#CONFIG += static
#CONFIG += -std=c++0x

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
    base_tree_dialog.cpp \
    cmp_tree_dialog.cpp \
    receiverthread.cpp \
    treebuilder.cpp \
    readingQueue.cpp \
    pixelview.cpp \
    treecomparison.cpp \
    nogood_dialog.cpp \
    node_info_dialog.cpp \
    depth_analysis.cpp \
    pixelImage.cpp \
    maybeCaller.cpp \
    message.pb.cpp \
    profiler-conductor.cpp \
    profiler-tcp-server.cpp \
    ml-stats.cpp

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
    nodecursor.hh \
    nodecursor.hpp \
    layoutcursor.hh \
    layoutcursor.hpp \
    nodevisitor.hh \
    nodevisitor.hpp \
    zoomToFitIcon.hpp \
    data.hh \
    base_tree_dialog.hh \
    cmp_tree_dialog.hh \
    receiverthread.hh \
    treebuilder.hh \
    readingQueue.hh \
    pixelview.hh \
    treecomparison.hh \
    nogood_dialog.hh \
    node_info_dialog.hh \
    depth_analysis.hh \
    message.pb.hh \
    profiler-conductor.hh \
    profiler-tcp-server.hh \
    execution.hh \
    pixelImage.hh \
    maybeCaller.hh \
    ml-stats.hh

FORMS    +=

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../usr/local/lib/release/
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../usr/local/lib/debug/
else:unix: LIBS += -L$$PWD/../../../../../../usr/local/lib/ -ldl

# LIBS += `pkg-config --cflags --libs protobuf` -lprotobuf

CONFIG += link_pkgconfig
PKGCONFIG += protobuf

