#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>
#include <QFile>
#include <QTextStream>

#include "adderrordialog.h"
#include "searchtree.h"

namespace Ui {
class AddWindow;
}

class AddWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddWindow(QWidget *parent = nullptr);
    ~AddWindow();

private slots:
    // Реализация кнопок

    void AddNode();

private:
    Ui::AddWindow *ui;
};

#endif // ADDWINDOW_H
