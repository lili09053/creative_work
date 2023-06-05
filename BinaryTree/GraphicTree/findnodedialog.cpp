#include "findnodedialog.h"
#include "ui_findnodedialog.h"

FindNodeDialog::FindNodeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindNodeDialog)
{
    ui->setupUi(this);

    QFile finded_error_file("D:/IT/LabWorks/BinaryTree/GraphicTree/finded.txt"); // Для вставки своего пути навестись на нужный файл слева от кода (папка 'Другие файлы')
    QTextStream finded_error_stream(&finded_error_file);

    finded_error_file.open(QFile::ReadOnly | QFile::Text);
    QString key = finded_error_stream.readLine(),
            finded = finded_error_stream.readLine(),
            row;

    row += "Узел со значением " + key + " ";
    if (finded != "0")
    {
        row += "найден!";
    }
    else
    {
        row += "не найден!";
    }
    finded_error_file.flush();
    finded_error_file.close();

    ui->label->setText(row);
}

FindNodeDialog::~FindNodeDialog()
{
    delete ui;
}
