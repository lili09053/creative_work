#include "findwindow.h"
#include "ui_findwindow.h"

QFile finded_file("D:/IT/LabWorks/BinaryTree/GraphicTree/finded.txt"), // Для вставки своего пути навестись на нужный файл слева от кода (папка 'Другие файлы')
        tree_find_file("D:/IT/LabWorks/BinaryTree/GraphicTree/tree.txt"), // Для вставки своего пути навестись на нужный файл слева от кода (папка 'Другие файлы')
        size_find_file("D:/IT/LabWorks/BinaryTree/GraphicTree/size.txt"); // Для вставки своего пути навестись на нужный файл слева от кода (папка 'Другие файлы')
QTextStream finded_stream(&finded_file),
        tree_find_stream(&tree_find_file),
        size_find_stream(&size_find_file);

FindWindow::FindWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindWindow)
{
    ui->setupUi(this);

    connect(ui->findBtn, &QPushButton::clicked, this, &FindWindow::FindNode);
}

void FindWindow::FindNode()
{
    bool success;
    int key = ui->findText->text().toInt(&success);
    if (ui->findText->text() != "" || success)
    {
        // Создаём бинарное дерево tree на основе файла tree.txt

        tree_find_file.open(QFile::ReadOnly | QFile::Text);
        BinaryTree* temp = new SearchTree();
        while (!tree_find_file.atEnd())
        {
            int val = tree_find_stream.readLine().toInt();
            temp->insert(val);
        }

        tree_find_file.flush();
        tree_find_file.close();

        // Выполняем нужное нам действие + Обработка исключительной ситуации с помощью диалогового окна

        finded_file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
        finded_stream << QString::number(key) << "\n";
        finded_stream << QString::number(temp->contains(key));
        finded_file.flush();
        finded_file.close();
        FindNodeDialog dialog;
        dialog.setModal(true);
        dialog.exec();
        finded_file.open(QFile::WriteOnly | QFile::Text);
        finded_file.flush();
        finded_file.close();

        // Удаление бинарного дерева tree

        delete temp;

        close();
    }
    ui->findText->clear();
}

FindWindow::~FindWindow()
{
    delete ui;
}
