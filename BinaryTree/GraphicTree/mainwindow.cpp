#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QGridLayout>
#include <QPushButton>
#include <QProcess>
#include <QFile>
#include <QTextStream>

QFile tree_global_file("D:/IT/LabWorks/BinaryTree/GraphicTree/tree.txt"), // Для вставки своего пути навестись на нужный файл слева от кода
      size_global_file("D:/IT/LabWorks/BinaryTree/GraphicTree/size.txt"); // Для вставки своего пути навестись на нужный файл слева от кода
QTextStream tree_global_stream(&tree_global_file),
            size_global_stream(&size_global_file);

QGraphicsScene *scene;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ClearFiles();

    tree = new SearchTree();

    visual_mode = 0;

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 2000, 2000);
    ui->canvas->setScene(scene); // Отображение сцены с элементами
    scene->clear();

    connect(ui->addNodeBtn, &QPushButton::clicked, this, &MainWindow::ButtonAdd);
    connect(ui->deleteNodeBtn, &QPushButton::clicked, this, &MainWindow::ButtonDelete);
    connect(ui->findNodeBtn, &QPushButton::clicked, this, &MainWindow::ButtonFind);
    connect(ui->deleteTreeBtn, &QPushButton::clicked, this, &MainWindow::ButtonClear);
    connect(ui->balanceTreeBtn, &QPushButton::clicked, this, &MainWindow::ButtonBalance);
    connect(ui->switchModeBtn, &QPushButton::clicked, this, &MainWindow::ButtonPrintMode);
}

void MainWindow::EditTree()
{
    delete tree;
    tree = new SearchTree();

    size_global_file.open(QFile::ReadOnly | QFile::Text);
    int size = size_global_stream.readLine().toInt();
    size_global_file.flush();
    size_global_file.close();

    tree_global_file.open(QFile::ReadOnly | QFile::Text);

    for (int i = 0; i < size; i++)
    {
        int val = tree_global_stream.readLine().toInt();
        tree->insert(val);
    }
    tree_global_file.flush();
    tree_global_file.close();

    EditText();
}

void MainWindow::ClearFiles()
{
    tree_global_file.open(QFile::WriteOnly | QFile::Truncate);
    tree_global_file.flush();
    tree_global_file.close();


    size_global_file.open(QFile::WriteOnly | QFile::Truncate);
    size_global_stream << QString::number(0);
    size_global_file.flush();
    size_global_file.close();
}

void MainWindow::ClearText()
{
    ui->forwardText->clear();
    ui->symmetricText->clear();
    ui->reverseText->clear();
}

void MainWindow::SetText()
{
    ui->forwardText->setText(tree->print(1));
    ui->symmetricText->setText(tree->print(2));
    ui->reverseText->setText(tree->print(3));
}

void MainWindow::EditText()
{
    ClearText();
    SetText();
}

void MainWindow::UpdateScene()
{
    scene->clear();
    tree->visualise(scene, visual_mode);
}

void MainWindow::ButtonAdd()
{
    AddWindow window;
    window.setModal(true);
    window.exec();

    EditTree();
    UpdateScene();
}

void MainWindow::ButtonDelete()
{
    DeleteWindow window;
    window.setModal(true);
    window.exec();

    EditTree();
    UpdateScene();
}

void MainWindow::ButtonFind()
{
    FindWindow window;
    window.setModal(true);
    window.exec();

    EditText();
}

void MainWindow::ButtonClear()
{
    ClearFiles();
    delete tree;
    tree = new SearchTree();

    EditText();
    UpdateScene();
}

void MainWindow::ButtonBalance()
{
    BinaryTree* temp = tree;
    tree = new SearchTree(*temp->balance());
    delete temp;

    tree_global_file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    QStringList vals = tree->print(1).split(' '); // Метод возвращает последовательность с доп пробелом в конце
    vals.removeLast();  // Поэтому последний элемент удаляется
    for (int i = 0; i < vals.size(); i++)
    {
        tree_global_stream << vals[i] << "\n";
    }
    tree_global_file.flush();
    tree_global_file.close();

    EditTree();
    UpdateScene();
}

void MainWindow::ButtonPrintMode()
{
    if (ui->switchModeBtn->text() == "Вертикальная печать")
    {
        visual_mode = 1;
        ui->switchModeBtn->setText("Горизонтальная печать");
    }
    else
    {
        visual_mode = 0;
        ui->switchModeBtn->setText("Вертикальная печать");
    }
    UpdateScene();
}

MainWindow::~MainWindow()
{
    ClearFiles();

    delete tree;
    delete ui;
}

