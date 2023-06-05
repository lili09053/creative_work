#include "deleteerrordialog.h"
#include "ui_deleteerrordialog.h"

DeleteErrorDialog::DeleteErrorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteErrorDialog)
{
    ui->setupUi(this);

    QFile deleted_error_file("D:/IT/LabWorks/BinaryTree/GraphicTree/deleted.txt"); // Для вставки своего пути навестись на нужный файл слева от кода (папка 'Другие файлы')
    QTextStream deleted_error_stream(&deleted_error_file);

    deleted_error_file.open(QFile::ReadOnly | QFile::Text);
    QString row = "Узел со значением " + deleted_error_stream.readLine() + " не существует!";
    deleted_error_file.flush();
    deleted_error_file.close();

    ui->label->setText(row);
}

DeleteErrorDialog::~DeleteErrorDialog()
{
    delete ui;
}
