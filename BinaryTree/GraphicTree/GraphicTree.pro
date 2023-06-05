QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adderrordialog.cpp \
    addwindow.cpp \
    binarytree.cpp \
    deleteerrordialog.cpp \
    deletewindow.cpp \
    findnodedialog.cpp \
    findwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    nodeshape.cpp \
    searchtree.cpp

HEADERS += \
    adderrordialog.h \
    addwindow.h \
    binarytree.h \
    deleteerrordialog.h \
    deletewindow.h \
    findnodedialog.h \
    findwindow.h \
    mainwindow.h \
    nodeshape.h \
    searchtree.h

FORMS += \
    adderrordialog.ui \
    addwindow.ui \
    deleteerrordialog.ui \
    deletewindow.ui \
    findnodedialog.ui \
    findwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    added.txt \
    deleted.txt \
    finded.txt \
    size.txt \
    tree.txt
