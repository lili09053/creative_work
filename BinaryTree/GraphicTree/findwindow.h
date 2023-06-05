#ifndef FINDWINDOW_H
#define FINDWINDOW_H

#include <QDialog>
#include <QFile>
#include <QTextStream>

#include "findnodedialog.h"
#include "searchtree.h"

namespace Ui {
class FindWindow;
}

class FindWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FindWindow(QWidget *parent = nullptr);
    ~FindWindow();

private slots:
    // Реализация кнопок

    void FindNode();

private:
    Ui::FindWindow *ui;
};

#endif // FINDWINDOW_H
