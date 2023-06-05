#ifndef DELETEERRORDIALOG_H
#define DELETEERRORDIALOG_H

#include <QDialog>
#include <QFile>
#include <QTextStream>

namespace Ui {
class DeleteErrorDialog;
}

class DeleteErrorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteErrorDialog(QWidget *parent = nullptr);
    ~DeleteErrorDialog();

private:
    Ui::DeleteErrorDialog *ui;
};

#endif // DELETEERRORDIALOG_H
