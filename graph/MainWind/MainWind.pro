QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    form_create.cpp \
    form_edge_add.cpp \
    form_edge_del.cpp \
    form_edge_edit.cpp \
    form_mtx_adj.cpp \
    form_top_add.cpp \
    form_top_del.cpp \
    main.cpp \
    mainwindow.cpp \
    myopenglwidget.cpp \
    output_dij.cpp

HEADERS += \
    form_create.h \
    form_edge_add.h \
    form_edge_del.h \
    form_edge_edit.h \
    form_mtx_adj.h \
    form_top_add.h \
    form_top_del.h \
    mainwindow.h \
    myopenglwidget.h \
    output_dij.h

FORMS += \
    form_create.ui \
    form_edge_add.ui \
    form_edge_del.ui \
    form_edge_edit.ui \
    form_mtx_adj.ui \
    form_top_add.ui \
    form_top_del.ui \
    mainwindow.ui \
    output_dij.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    dij.txt \
    matrix.txt
