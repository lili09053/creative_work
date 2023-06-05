/********************************************************************************
** Form generated from reading UI file 'findwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDWINDOW_H
#define UI_FINDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FindWindow
{
public:
    QLabel *heading;
    QLabel *key;
    QPushButton *findBtn;
    QLineEdit *findText;

    void setupUi(QDialog *FindWindow)
    {
        if (FindWindow->objectName().isEmpty())
            FindWindow->setObjectName(QString::fromUtf8("FindWindow"));
        FindWindow->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FindWindow->sizePolicy().hasHeightForWidth());
        FindWindow->setSizePolicy(sizePolicy);
        FindWindow->setMinimumSize(QSize(400, 300));
        FindWindow->setMaximumSize(QSize(400, 300));
        FindWindow->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	border: 5px solid rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	font: 16pt;\n"
"}\n"
"\n"
"QLineEdit::focus\n"
"{\n"
"	border: 5px solid rgb(0, 170, 255);\n"
"	border-radius: 10px\n"
"}"));
        heading = new QLabel(FindWindow);
        heading->setObjectName(QString::fromUtf8("heading"));
        heading->setGeometry(QRect(10, 10, 381, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Reference Sans Serif"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        heading->setFont(font);
        heading->setAlignment(Qt::AlignCenter);
        key = new QLabel(FindWindow);
        key->setObjectName(QString::fromUtf8("key"));
        key->setGeometry(QRect(10, 110, 191, 61));
        key->setFont(font);
        key->setAlignment(Qt::AlignCenter);
        findBtn = new QPushButton(FindWindow);
        findBtn->setObjectName(QString::fromUtf8("findBtn"));
        findBtn->setGeometry(QRect(30, 200, 341, 81));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        findBtn->setFont(font1);
        findBtn->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: rgb(0, 85, 255);\n"
"	background-color: rgb(255, 170, 0);\n"
"	border: 4px solid black;\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	color: rgb(30, 115, 255);\n"
"	background-color: rgb(255, 200, 30);\n"
"	border: 3px solid black;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	color: rgb(0, 55, 225);\n"
"	background-color: rgb(225, 140, 0);\n"
"	border: 5px solid black;\n"
"}"));
        findText = new QLineEdit(FindWindow);
        findText->setObjectName(QString::fromUtf8("findText"));
        findText->setGeometry(QRect(210, 110, 171, 51));

        retranslateUi(FindWindow);

        QMetaObject::connectSlotsByName(FindWindow);
    } // setupUi

    void retranslateUi(QDialog *FindWindow)
    {
        FindWindow->setWindowTitle(QApplication::translate("FindWindow", "Find node", nullptr));
        heading->setText(QApplication::translate("FindWindow", "\320\237\320\276\320\270\321\201\320\272 \321\203\320\267\320\273\320\260", nullptr));
        key->setText(QApplication::translate("FindWindow", "\320\232\320\273\321\216\321\207", nullptr));
        findBtn->setText(QApplication::translate("FindWindow", "\320\235\320\260\320\271\321\202\320\270 \321\203\320\267\320\265\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindWindow: public Ui_FindWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDWINDOW_H
