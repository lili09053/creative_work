/********************************************************************************
** Form generated from reading UI file 'deletewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEWINDOW_H
#define UI_DELETEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DeleteWindow
{
public:
    QLabel *heading;
    QLabel *key;
    QPushButton *deleteBtn;
    QLineEdit *deleteText;

    void setupUi(QDialog *DeleteWindow)
    {
        if (DeleteWindow->objectName().isEmpty())
            DeleteWindow->setObjectName(QString::fromUtf8("DeleteWindow"));
        DeleteWindow->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DeleteWindow->sizePolicy().hasHeightForWidth());
        DeleteWindow->setSizePolicy(sizePolicy);
        DeleteWindow->setMinimumSize(QSize(400, 300));
        DeleteWindow->setMaximumSize(QSize(4000, 300));
        DeleteWindow->setStyleSheet(QString::fromUtf8("QLineEdit\n"
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
        heading = new QLabel(DeleteWindow);
        heading->setObjectName(QString::fromUtf8("heading"));
        heading->setGeometry(QRect(10, 10, 381, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Reference Sans Serif"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        heading->setFont(font);
        heading->setAlignment(Qt::AlignCenter);
        key = new QLabel(DeleteWindow);
        key->setObjectName(QString::fromUtf8("key"));
        key->setGeometry(QRect(10, 110, 191, 61));
        key->setFont(font);
        key->setAlignment(Qt::AlignCenter);
        deleteBtn = new QPushButton(DeleteWindow);
        deleteBtn->setObjectName(QString::fromUtf8("deleteBtn"));
        deleteBtn->setGeometry(QRect(30, 210, 341, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        deleteBtn->setFont(font1);
        deleteBtn->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(170, 0, 0);\n"
"	border: 4px solid black;\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(200, 30, 30);\n"
"	border: 3px solid black;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	color: rgb(225, 225, 225);\n"
"	background-color: rgb(140, 0, 0);\n"
"	border: 5px solid black;\n"
"}"));
        deleteText = new QLineEdit(DeleteWindow);
        deleteText->setObjectName(QString::fromUtf8("deleteText"));
        deleteText->setGeometry(QRect(210, 110, 171, 61));

        retranslateUi(DeleteWindow);

        QMetaObject::connectSlotsByName(DeleteWindow);
    } // setupUi

    void retranslateUi(QDialog *DeleteWindow)
    {
        DeleteWindow->setWindowTitle(QApplication::translate("DeleteWindow", "Dialog", nullptr));
        heading->setText(QApplication::translate("DeleteWindow", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \321\203\320\267\320\273\320\260", nullptr));
        key->setText(QApplication::translate("DeleteWindow", "\320\232\320\273\321\216\321\207", nullptr));
        deleteBtn->setText(QApplication::translate("DeleteWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\203\320\267\320\265\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteWindow: public Ui_DeleteWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEWINDOW_H
