/********************************************************************************
** Form generated from reading UI file 'findnodedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDNODEDIALOG_H
#define UI_FINDNODEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_FindNodeDialog
{
public:
    QLabel *label;

    void setupUi(QDialog *FindNodeDialog)
    {
        if (FindNodeDialog->objectName().isEmpty())
            FindNodeDialog->setObjectName(QString::fromUtf8("FindNodeDialog"));
        FindNodeDialog->resize(400, 173);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FindNodeDialog->sizePolicy().hasHeightForWidth());
        FindNodeDialog->setSizePolicy(sizePolicy);
        FindNodeDialog->setMinimumSize(QSize(400, 173));
        FindNodeDialog->setMaximumSize(QSize(400, 173));
        label = new QLabel(FindNodeDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(14, 5, 371, 151));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        retranslateUi(FindNodeDialog);

        QMetaObject::connectSlotsByName(FindNodeDialog);
    } // setupUi

    void retranslateUi(QDialog *FindNodeDialog)
    {
        FindNodeDialog->setWindowTitle(QApplication::translate("FindNodeDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("FindNodeDialog", "\320\243\320\267\320\265\320\273 \321\201\320\276 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265\320\274 _ \320\275\320\260\320\271\320\264\320\265\320\275! / \320\275\320\265 \320\275\320\260\320\271\320\264\320\265\320\275!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindNodeDialog: public Ui_FindNodeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDNODEDIALOG_H
