#include "addwindow.h"
#include "ui_addwindow.h"

QFile added_file("D:/IT/LabWorks/BinaryTree/GraphicTree/added.txt"), // Для вставки своего пути навестись на нужный файл слева от кода (папка 'Другие файлы')
        tree_add_file("D:/IT/LabWorks/BinaryTree/GraphicTree/tree.txt"), // Для вставки своего пути навестись на нужный файл слева от кода (папка 'Другие файлы')
        size_add_file("D:/IT/LabWorks/BinaryTree/GraphicTree/size.txt"); // Для вставки своего пути навестись на нужный файл слева от кода (папка 'Другие файлы')
QTextStream added_stream(&added_file),
        tree_add_stream(&tree_add_file),
        size_add_stream(&size_add_file);

AddWindow::AddWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWindow)
{
    ui->setupUi(this);

    connect(ui->addBtn, &QPushButton::clicked, this, &AddWindow::AddNode);
}

void AddWindow::AddNode()
{
    bool success;
    int key = ui->addText->text().toInt(&success);
    if (ui->addText->text() != "" || success)
    {
        // Создаём бинарное дерево tree на основе файла tree.txt

        size_add_file.open(QFile::ReadOnly | QFile::Text);
        int size = size_add_stream.readLine().toInt();
        size_add_file.flush();
        size_add_file.close();

        tree_add_file.open(QFile::ReadOnly | QFile::Text);
        BinaryTree* temp = new SearchTree();
        for (int i = 0; i < size; i++)
        {
            int val = tree_add_stream.readLine().toInt();
            temp->insert(val);
        }
        tree_add_file.flush();
        tree_add_file.close();

        // Выполняем нужное нам действие + Обработка исключительной ситуации с помощью диалогового окна

        added_file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
        added_stream << QString::number(key) << "\n";
        if (!temp->insert(key))
        {
            added_file.flush();
            added_file.close();
            AddErrorDialog dialog;
            dialog.setModal(true);
            dialog.exec();
        }
        else
        {
            // Перезаполнение файла tree.txt новыми данными дерева (tree->print(1))

            size++;
            size_add_file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
            size_add_stream << QString::number(size);
            size_add_file.flush();
            size_add_file.close();

            tree_add_file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
            QStringList vals = temp->print(1).split(' '); // Метод возвращает последовательность с доп пробелом в конце
            vals.removeLast(); // Поэтому последний элемент удаяется
            for (int i = 0; i < vals.size(); i++)
            {
                tree_add_stream << vals[i] << "\n";
            }
            tree_add_file.flush();
            tree_add_file.close();
        }
        added_file.flush();
        added_file.close();

        // Удаление бинарного дерева tree

        delete temp;

        close();
    }
    ui->addText->clear();
}

AddWindow::~AddWindow()
{
    delete ui;
}
