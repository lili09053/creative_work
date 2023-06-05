/********************************************************************************
** Form generated from reading UI file 'addwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWINDOW_H
#define UI_ADDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddWindow
{
public:
    QLabel *heading;
    QPushButton *addBtn;
    QLabel *data;
    QLineEdit *addText;

    void setupUi(QDialog *AddWindow)
    {
        if (AddWindow->objectName().isEmpty())
            AddWindow->setObjectName(QString::fromUtf8("AddWindow"));
        AddWindow->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddWindow->sizePolicy().hasHeightForWidth());
        AddWindow->setSizePolicy(sizePolicy);
        AddWindow->setMinimumSize(QSize(400, 300));
        AddWindow->setMaximumSize(QSize(400, 300));
        AddWindow->setStyleSheet(QString::fromUtf8("QLineEdit\n"
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
        heading = new QLabel(AddWindow);
        heading->setObjectName(QString::fromUtf8("heading"));
        heading->setGeometry(QRect(10, 10, 381, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Reference Sans Serif"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        heading->setFont(font);
        heading->setAlignment(Qt::AlignCenter);
        addBtn = new QPushButton(AddWindow);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        addBtn->setGeometry(QRect(30, 210, 341, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        addBtn->setFont(font1);
        addBtn->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(0, 170, 127);\n"
"	border: 4px solid black;\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(30, 200, 157);\n"
"	border: 3px solid black;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	color: rgb(225, 225, 225);\n"
"	background-color: rgb(0, 140, 97);\n"
"	border: 5px solid black;\n"
"}"));
        data = new QLabel(AddWindow);
        data->setObjectName(QString::fromUtf8("data"));
        data->setGeometry(QRect(10, 110, 191, 61));
        data->setFont(font);
        data->setAlignment(Qt::AlignCenter);
        addText = new QLineEdit(AddWindow);
        addText->setObjectName(QString::fromUtf8("addText"));
        addText->setGeometry(QRect(210, 120, 171, 51));

        retranslateUi(AddWindow);

        QMetaObject::connectSlotsByName(AddWindow);
    } // setupUi

    void retranslateUi(QDialog *AddWindow)
    {
        AddWindow->setWindowTitle(QApplication::translate("AddWindow", "Add node", nullptr));
        heading->setText(QApplication::translate("AddWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\203\320\267\320\273\320\260", nullptr));
        addBtn->setText(QApplication::translate("AddWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\203\320\267\320\265\320\273", nullptr));
        data->setText(QApplication::translate("AddWindow", "\320\224\320\260\320\275\320\275\321\213\320\265", nullptr));
        addText->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddWindow: public Ui_AddWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWINDOW_H
