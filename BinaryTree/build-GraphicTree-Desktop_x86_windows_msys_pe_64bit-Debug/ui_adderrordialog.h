/********************************************************************************
** Form generated from reading UI file 'adderrordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDERRORDIALOG_H
#define UI_ADDERRORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AddErrorDialog
{
public:
    QLabel *label;

    void setupUi(QDialog *AddErrorDialog)
    {
        if (AddErrorDialog->objectName().isEmpty())
            AddErrorDialog->setObjectName(QString::fromUtf8("AddErrorDialog"));
        AddErrorDialog->resize(400, 170);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddErrorDialog->sizePolicy().hasHeightForWidth());
        AddErrorDialog->setSizePolicy(sizePolicy);
        AddErrorDialog->setMinimumSize(QSize(400, 170));
        AddErrorDialog->setMaximumSize(QSize(400, 170));
        QFont font;
        font.setPointSize(14);
        AddErrorDialog->setFont(font);
        label = new QLabel(AddErrorDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(14, 15, 371, 141));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        retranslateUi(AddErrorDialog);

        QMetaObject::connectSlotsByName(AddErrorDialog);
    } // setupUi

    void retranslateUi(QDialog *AddErrorDialog)
    {
        AddErrorDialog->setWindowTitle(QApplication::translate("AddErrorDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("AddErrorDialog", "\320\243\320\267\320\265\320\273 \321\201\320\276 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265\320\274 _ \321\203\320\266\320\265 \321\201\321\203\321\211\320\265\321\201\321\202\320\262\321\203\320\265\321\202 \320\262 \320\264\320\265\321\200\320\265\320\262\320\265!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddErrorDialog: public Ui_AddErrorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDERRORDIALOG_H
