#ifndef EDITTOPWINDOW_H
#define EDITTOPWINDOW_H

#include <QMainWindow>

namespace Ui {
class EditTopWindow;
}

class EditTopWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditTopWindow(QWidget *parent = nullptr);
    ~EditTopWindow();

private:
    Ui::EditTopWindow *ui;
};

#endif // EDITTOPWINDOW_H
