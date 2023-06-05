#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "addwindow.h"
#include "deletewindow.h"
#include "findwindow.h"
#include "searchtree.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void ButtonAdd();
    void ButtonDelete();
    void ButtonFind();
    void ButtonClear();
    void ButtonBalance();
    void ButtonPrintMode();

private:
    void EditTree();
    void ClearFiles();
    void ClearText();
    void SetText();
    void EditText();
    void UpdateScene();

    Ui::MainWindow *ui;
    BinaryTree* tree;
    int visual_mode;
};
#endif // MAINWINDOW_H
