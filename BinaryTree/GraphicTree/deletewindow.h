#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H

#include <QDialog>
#include <QFile>
#include <QTextStream>

#include "deleteerrordialog.h"
#include "searchtree.h"

namespace Ui {
class DeleteWindow;
}

class DeleteWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteWindow(QWidget *parent = nullptr);
    ~DeleteWindow();

private slots:
    // Реализация кнопок

    void DeleteNode();

private:
    Ui::DeleteWindow *ui;
};

#endif // DELETEWINDOW_H
