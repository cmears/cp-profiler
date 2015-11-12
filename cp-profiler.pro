#-------------------------------------------------
#
# Project created by QtCreator 2014-03-28T15:13:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport


TARGET = cp-profiler


TEMPLATE = app

CONFIG += c++11
#CONFIG += static
#CONFIG += -std=c++0x

SOURCES += main.cpp\
        gistmainwindow.cpp \
        globalhelper.cpp \
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
    solver_tree_dialog.cpp \
    cmp_tree_dialog.cpp \
    receiverthread.cpp \
    treebuilder.cpp \
    readingQueue.cpp \
    treecomparison.cpp \
    pixelview.cpp \
    nogood_dialog.cpp \
    node_info_dialog.cpp \
    depth_analysis.cpp \
    message.pb.cpp \


HEADERS  += gistmainwindow.h \
    globalhelper.hh \
    qtgist.hh \
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
    solver_tree_dialog.hh \
    cmp_tree_dialog.hh \
    receiverthread.hh \
    treebuilder.hh \
    readingQueue.hh \
    treecomparison.hh \
    pixelview.hh \
    nogood_dialog.hh \
    node_info_dialog.hh \
    depth_analysis.hh \
    message.pb.hh

FORMS    +=

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../usr/local/lib/release/ -lzmq
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../usr/local/lib/debug/ -lzmq
else:unix: LIBS += -L$$PWD/../../../../../../usr/local/lib/ -lzmq -ldl

LIBS += `pkg-config --cflags --libs protobuf` -lprotobuf

INCLUDEPATH += $$PWD/../../../../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../../../../usr/local/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../../usr/local/lib/release/libzmq.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../../usr/local/lib/debug/libzmq.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../../usr/local/lib/release/zmq.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../../usr/local/lib/debug/zmq.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../../../usr/local/lib/libzmq.a