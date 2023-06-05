/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *addNodeBtn;
    QLabel *title;
    QLabel *forwardPassage;
    QPushButton *deleteNodeBtn;
    QPushButton *deleteTreeBtn;
    QPushButton *findNodeBtn;
    QPushButton *switchModeBtn;
    QTextEdit *forwardText;
    QLabel *symmetricPassage;
    QTextEdit *symmetricText;
    QTextEdit *reverseText;
    QLabel *reversePassage;
    QPushButton *balanceTreeBtn;
    QGraphicsView *canvas;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1463, 918);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1463, 918));
        MainWindow->setMaximumSize(QSize(1463, 918));
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow\n"
"{\n"
"	background-color: aliceblue;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"	color: brown;\n"
"	font: 15pt 'Consolas';\n"
"	background-color: aqua;\n"
"	border: 5px solid black;\n"
"	border-radius: 40px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	color: darkred;\n"
"	background-color: aquamarine;\n"
"	border: 3px solid black;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	color: firebrick;\n"
"	background-color: cornflowerblue;\n"
"	border: 7px solid black;\n"
"}\n"
"\n"
"QGraphicsView\n"
"{\n"
"	background-color: wheat;\n"
"}\n"
"\n"
"QTextEdit\n"
"{\n"
"	color: black;\n"
"	font: 20pt 'Consolas';\n"
"	border: 5px solid black;\n"
"	border-radius: 10px;\n"
"\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"	color: black;\n"
"	font: 20pt 'Monotype Corsiva';\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        addNodeBtn = new QPushButton(centralwidget);
        addNodeBtn->setObjectName(QString::fromUtf8("addNodeBtn"));
        addNodeBtn->setGeometry(QRect(1130, 110, 321, 91));
        title = new QLabel(centralwidget);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(1130, 10, 321, 91));
        title->setAlignment(Qt::AlignCenter);
        forwardPassage = new QLabel(centralwidget);
        forwardPassage->setObjectName(QString::fromUtf8("forwardPassage"));
        forwardPassage->setGeometry(QRect(10, 700, 471, 71));
        forwardPassage->setAlignment(Qt::AlignCenter);
        deleteNodeBtn = new QPushButton(centralwidget);
        deleteNodeBtn->setObjectName(QString::fromUtf8("deleteNodeBtn"));
        deleteNodeBtn->setGeometry(QRect(1130, 210, 321, 91));
        deleteTreeBtn = new QPushButton(centralwidget);
        deleteTreeBtn->setObjectName(QString::fromUtf8("deleteTreeBtn"));
        deleteTreeBtn->setGeometry(QRect(1130, 310, 321, 91));
        findNodeBtn = new QPushButton(centralwidget);
        findNodeBtn->setObjectName(QString::fromUtf8("findNodeBtn"));
        findNodeBtn->setGeometry(QRect(1130, 410, 321, 91));
        switchModeBtn = new QPushButton(centralwidget);
        switchModeBtn->setObjectName(QString::fromUtf8("switchModeBtn"));
        switchModeBtn->setGeometry(QRect(10, 610, 1441, 81));
        forwardText = new QTextEdit(centralwidget);
        forwardText->setObjectName(QString::fromUtf8("forwardText"));
        forwardText->setGeometry(QRect(10, 780, 471, 81));
        forwardText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        forwardText->setLineWrapMode(QTextEdit::NoWrap);
        symmetricPassage = new QLabel(centralwidget);
        symmetricPassage->setObjectName(QString::fromUtf8("symmetricPassage"));
        symmetricPassage->setGeometry(QRect(980, 700, 471, 71));
        symmetricPassage->setAlignment(Qt::AlignCenter);
        symmetricText = new QTextEdit(centralwidget);
        symmetricText->setObjectName(QString::fromUtf8("symmetricText"));
        symmetricText->setGeometry(QRect(490, 780, 481, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        symmetricText->setFont(font);
        symmetricText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        symmetricText->setLineWrapMode(QTextEdit::NoWrap);
        reverseText = new QTextEdit(centralwidget);
        reverseText->setObjectName(QString::fromUtf8("reverseText"));
        reverseText->setGeometry(QRect(980, 780, 471, 81));
        reverseText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        reverseText->setLineWrapMode(QTextEdit::NoWrap);
        reversePassage = new QLabel(centralwidget);
        reversePassage->setObjectName(QString::fromUtf8("reversePassage"));
        reversePassage->setGeometry(QRect(490, 700, 481, 71));
        reversePassage->setAlignment(Qt::AlignCenter);
        balanceTreeBtn = new QPushButton(centralwidget);
        balanceTreeBtn->setObjectName(QString::fromUtf8("balanceTreeBtn"));
        balanceTreeBtn->setGeometry(QRect(1130, 510, 321, 91));
        canvas = new QGraphicsView(centralwidget);
        canvas->setObjectName(QString::fromUtf8("canvas"));
        canvas->setGeometry(QRect(15, 10, 1111, 591));
        canvas->setSceneRect(QRectF(0, 0, 2000, 2000));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1463, 26));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Binary Search Tree", nullptr));
        addNodeBtn->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\203\320\267\320\265\320\273", nullptr));
        title->setText(QApplication::translate("MainWindow", "\320\221\320\270\320\275\320\260\321\200\320\275\320\276\320\265 \320\264\320\265\321\200\320\265\320\262\320\276 \320\277\320\276\320\270\321\201\320\272\320\260", nullptr));
        forwardPassage->setText(QApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\320\271 \320\276\320\261\321\205\320\276\320\264 \320\264\320\265\321\200\320\265\320\262\320\260", nullptr));
        deleteNodeBtn->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\203\320\267\320\265\320\273", nullptr));
        deleteTreeBtn->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\264\320\265\321\200\320\265\320\262\320\276", nullptr));
        findNodeBtn->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260", nullptr));
        switchModeBtn->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\320\260\321\217 \320\277\320\265\321\207\320\260\321\202\321\214", nullptr));
        symmetricPassage->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\321\202\320\275\321\213\320\271 \320\276\320\261\321\205\320\276\320\264 \320\264\320\265\321\200\320\265\320\262\320\260", nullptr));
        symmetricText->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Consolas'; font-size:20pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        reverseText->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Consolas'; font-size:20pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        reversePassage->setText(QApplication::translate("MainWindow", "\320\241\320\270\320\274\320\274\320\265\321\202\321\200\320\270\321\207\320\275\321\213\320\271 \320\276\320\261\321\205\320\276\320\264 \320\264\320\265\321\200\320\265\320\262\320\260", nullptr));
        balanceTreeBtn->setText(QApplication::translate("MainWindow", "\320\241\320\261\320\260\320\273\320\260\320\275\321\201\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\264\320\265\321\200\320\265\320\262\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
