#include "adderrordialog.h"
#include "ui_adderrordialog.h"

AddErrorDialog::AddErrorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddErrorDialog)
{
    ui->setupUi(this);

    QFile added_error_file("D:/IT/LabWorks/BinaryTree/GraphicTree/added.txt"); // Для вставки своего пути навестись на нужный файл слева от кода (папка 'Другие файлы')
    QTextStream added_error_stream(&added_error_file);

    added_error_file.open(QFile::ReadOnly | QFile::Text);
    QString row = "Узел со значением " + added_error_stream.readLine() + " уже существует!";
    added_error_file.flush();
    added_error_file.close();

    ui->label->setText(row);
}

AddErrorDialog::~AddErrorDialog()
{
    delete ui;
}
