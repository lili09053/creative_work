#include "form_create.h"
#include "ui_form_create.h"

#include <iostream>
Form_create::Form_create(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_create)
{
    ui->setupUi(this);
    ui->tableWidget_aj_mtrx->horizontalHeader()->setVisible(false);
    ui->tableWidget_aj_mtrx->verticalHeader()->setVisible(false);
}

Form_create::~Form_create()
{
    delete ui;
}

void Form_create::on_pB_ok_clicked()
{
    nV = ui->spinBox_num_vert->value(); // извлечение количества вершин графа
    ui->tableWidget_aj_mtrx->setRowCount(nV);   // количество строк в таблице
    ui->tableWidget_aj_mtrx->setColumnCount(nV);    //количество столбцов в таблице

    for(int i = 0; i < ui->tableWidget_aj_mtrx->rowCount(); i++) // заполнение таблицы значениями по умолчанию
      {
         for(int j = 0; j < ui->tableWidget_aj_mtrx->columnCount(); j++)
           {
                   QTableWidgetItem *el = new QTableWidgetItem("0");
                   ui->tableWidget_aj_mtrx->setItem(i, j, el);
           }
      }

}


void Form_create::on_pB_create_gr_clicked()
{
   for(int i = 0; i < ui->tableWidget_aj_mtrx->rowCount(); i++) // при нажтии составлять двумерный массив из таблицы
     {
        QVector<QString> tmp;
        for(int j = 0; j < ui->tableWidget_aj_mtrx->columnCount(); j++)
          {
                  QTableWidgetItem *element = ui ->tableWidget_aj_mtrx->item(i, j);
                 // tmp.push_back((element->text()).toInt());
                  tmp.push_back(element->text());
          }
        matrix_adj.push_back(tmp);
     }
    this->close();
    record_to_file(matrix_adj);
}


void Form_create::record_to_file(const QVector<QVector<QString>> & mtr)
{
    QFile file("D:/graph/MainWind/matrix.txt");

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
