/********************************************************************************
** Form generated from reading UI file 'deleteerrordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEERRORDIALOG_H
#define UI_DELETEERRORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DeleteErrorDialog
{
public:
    QLabel *label;

    void setupUi(QDialog *DeleteErrorDialog)
    {
        if (DeleteErrorDialog->objectName().isEmpty())
            DeleteErrorDialog->setObjectName(QString::fromUtf8("DeleteErrorDialog"));
        DeleteErrorDialog->resize(400, 170);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DeleteErrorDialog->sizePolicy().hasHeightForWidth());
        DeleteErrorDialog->setSizePolicy(sizePolicy);
        DeleteErrorDialog->setMinimumSize(QSize(400, 170));
        DeleteErrorDialog->setMaximumSize(QSize(400, 170));
        label = new QLabel(DeleteErrorDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 381, 151));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        retranslateUi(DeleteErrorDialog);

        QMetaObject::connectSlotsByName(DeleteErrorDialog);
    } // setupUi

    void retranslateUi(QDialog *DeleteErrorDialog)
    {
        DeleteErrorDialog->setWindowTitle(QApplication::translate("DeleteErrorDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("DeleteErrorDialog", "\320\243\320\267\320\265\320\273 \321\201\320\276 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265\320\274 _ \320\275\320\265 \320\275\320\260\320\271\320\264\320\265\320\275!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteErrorDialog: public Ui_DeleteErrorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEERRORDIALOG_H
