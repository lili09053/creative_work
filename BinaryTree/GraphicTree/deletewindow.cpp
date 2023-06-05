#include "deletewindow.h"
#include "ui_deletewindow.h"

QFile deleted_file("D:/IT/LabWorks/BinaryTree/GraphicTree/deleted.txt"), // Для вставки своего пути навестись на нужный файл слева от кода (папка 'Другие файлы')
        tree_delete_file("D:/IT/LabWorks/BinaryTree/GraphicTree/tree.txt"), // Для вставки своего пути навестись на нужный файл слева от кода (папка 'Другие файлы')
        size_delete_file("D:/IT/LabWorks/BinaryTree/GraphicTree/size.txt"); // Для вставки своего пути навестись на нужный файл слева от кода (папка 'Другие файлы')
QTextStream deleted_stream(&deleted_file),
        tree_delete_stream(&tree_delete_file),
        size_delete_stream(&size_delete_file);

DeleteWindow::DeleteWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteWindow)
{
    ui->setupUi(this);

    connect(ui->deleteBtn, &QPushButton::clicked, this, &DeleteWindow::DeleteNode);
}

void DeleteWindow::DeleteNode()
{
    bool success;
    int key = ui->deleteText->text().toInt(&success);
    if (ui->deleteText->text() != "" || success)
    {
        // Создаём бинарное дерево tree на основе файла tree.txt

        size_delete_file.open(QFile::ReadOnly | QFile::Text);
        int size = size_delete_stream.readLine().toInt();
        size_delete_file.flush();
        size_delete_file.close();

        tree_delete_file.open(QFile::ReadOnly | QFile::Text);
        BinaryTree* temp = new SearchTree();
        for (int i = 0; i < size; i++)
        {
            int val = tree_delete_stream.readLine().toInt();
            temp->insert(val);
        }
        tree_delete_file.flush();
        tree_delete_file.close();

        // Выполняем нужное нам действие + Обработка исключительной ситуации с помощью диалогового окна

        deleted_file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
        deleted_stream << QString::number(key);
        if (temp->remove(key) == nullptr) //!temp->contains(key)
        {
            deleted_file.flush();
            deleted_file.close();
            DeleteErrorDialog dialog;
            dialog.setModal(true);
            dialog.exec();
        }
        else
        {
            // Перезаполнение файла tree.txt новыми данными дерева (tree->print(1))

            size--;
            size_delete_file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
            size_delete_stream << QString::number(size);
            size_delete_file.flush();
            size_delete_file.close();

            tree_delete_file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
            QStringList vals = temp->print(1).split(' '); // Метод возвращает последовательность с доп пробелом в конце
            vals.removeLast(); // Поэтому последний элемент удаляется
            for (int i = 0; i < vals.size(); i++)
            {
                tree_delete_stream << vals[i] << "\n";
            }
            tree_delete_file.flush();
            tree_delete_file.close();
        }
        deleted_file.flush();
        deleted_file.close();

        // Удаление бинарного дерева tree

        delete temp;

        close();
    }
    ui->deleteText->clear();
}

DeleteWindow::~DeleteWindow()
{
    delete ui;
}
