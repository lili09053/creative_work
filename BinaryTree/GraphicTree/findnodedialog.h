#ifndef FINDNODEDIALOG_H
#define FINDNODEDIALOG_H

#include <QDialog>
#include <QFile>
#include <QTextStream>

namespace Ui {
class FindNodeDialog;
}

class FindNodeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindNodeDialog(QWidget *parent = nullptr);
    ~FindNodeDialog();

private:
    Ui::FindNodeDialog *ui;
};

#endif // FINDNODEDIALOG_H
