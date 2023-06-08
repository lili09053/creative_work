#include "form_mtx_adj.h"
#include "ui_form_mtx_adj.h"
#include <iostream>

Form_mtx_adj::Form_mtx_adj(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_mtx_adj)
{
    ui->setupUi(this);
    ui->tableWidget_aj_mtrx->horizontalHeader()->setVisible(false);
    ui->tableWidget_aj_mtrx->verticalHeader()->setVisible(false);
}

Form_mtx_adj::~Form_mtx_adj()
{
    delete ui;
}

const QString Form_mtx_adj::allFileToString(QFile &aFile)
{
    QTextStream in(&aFile);
    return in.readAll();
}

void Form_mtx_adj::setDataToVector(const QStringList &aStringList)
{
    nV = aStringList.size() - 1; // Count of line
    matrix_adj.clear();
    for (int i = 0; i < nV; ++i) {
        QVector<int> temp_vector;
        for (int j = 0; j < nV; ++j) {
            temp_vector.push_back(aStringList.at(i).split(" ").at(j).toInt());
        }
        matrix_adj.push_back(temp_vector);
    }
}

void Form_mtx_adj::record_to_vector()
{
    QFile file("D:/IT/LabWorks/graph/MainWind/matrix.txt");

    if(!file.open(QIODevice::ReadOnly))
       QMessageBox::warning(this, "Error", "File open error!");

    setDataToVector(allFileToString(file).split("\n"));

    // печать вектора для проверки
    for (int i = 0; i < matrix_adj.size(); ++i) {
        for (int j = 0; j < matrix_adj[i].size(); ++j) {
            std::cout << matrix_adj[i][j] << " ";
        }
        std::cout << std::endl;}
    file.close();
}

void Form_mtx_adj::record_to_table()
{
    ui->tableWidget_aj_mtrx->setRowCount(nV);   // количество строк в таблице
    ui->tableWidget_aj_mtrx->setColumnCount(nV);    //количество столбцов в таблице

    for(int i = 0; i < ui->tableWidget_aj_mtrx->rowCount(); i++) // заполнение таблицы значениями по умолчанию
      {
         for(int j = 0; j < ui->tableWidget_aj_mtrx->columnCount(); j++)
           {
                   QTableWidgetItem *el = new QTableWidgetItem(QString::number(matrix_adj[i][j]));
                   ui->tableWidget_aj_mtrx->setItem(i, j, el);
           }
      }
}

void Form_mtx_adj::vector_for_table()
{
   for(int i = 0; i < ui->tableWidget_aj_mtrx->rowCount(); i++) // при нажтии составлять двумерный массив из таблицы
     {
        QVector<QString> tmp;
        for(int j = 0; j < ui->tableWidget_aj_mtrx->columnCount(); j++)
          {
                  QTableWidgetItem *element = ui ->tableWidget_aj_mtrx->item(i, j);
                  tmp.push_back(element->text());
          }
        matrix_adj_2.push_back(tmp);
     }
    this->close();
    record_to_file(matrix_adj_2);
}


void Form_mtx_adj::record_to_file(const QVector<QVector<QString>> & mtr)
{
    QFile file("D:/IT/LabWorks/graph/MainWind/matrix.txt");

    if(!file.open(QIODevice::WriteOnly))
       QMessageBox::warning(this, "Error", "File open error!");

    QTextStream out(&file);
    for(int i = 0; i < mtr.size(); i++) // при нажтии составлять двумерный массив из таблицы
    {
        for(int j = 0; j < mtr[i].size(); j++)
        {
            out << mtr[i][j] << " ";
        }
        out << "\n";
    }
    file.close();
}

void Form_mtx_adj::on_pB_edit_mtr_clicked()
{
    matrix_adj.clear();
    matrix_adj_2.clear();
    vector_for_table();
    record_to_vector(); // перезапись вектора

}


void Form_mtx_adj::on_pB_open_tab_clicked()
{
    matrix_adj.clear();
    matrix_adj_2.clear();
    record_to_vector();
    record_to_table();
}

