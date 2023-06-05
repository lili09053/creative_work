#ifndef ADDERRORDIALOG_H
#define ADDERRORDIALOG_H

#include <QDialog>
#include <QFile>
#include <QTextStream>

namespace Ui {
class AddErrorDialog;
}

class AddErrorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddErrorDialog(QWidget *parent = nullptr);
    ~AddErrorDialog();

private:
    Ui::AddErrorDialog *ui;
};

#endif // ADDERRORDIALOG_H
