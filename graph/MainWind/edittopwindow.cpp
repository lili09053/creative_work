#include "edittopwindow.h"
#include "ui_edittopwindow.h"

EditTopWindow::EditTopWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditTopWindow)
{
    ui->setupUi(this);
}

EditTopWindow::~EditTopWindow()
{
    delete ui;
}
