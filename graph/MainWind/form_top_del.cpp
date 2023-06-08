#include "form_top_del.h"
#include "ui_form_top_del.h"
#include<iostream>

Form_top_del::Form_top_del(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_top_del)
{
    ui->setupUi(this);
}

Form_top_del::~Form_top_del()
{
    delete ui;
}

const QString Form_top_del::allFileToString(QFile &aFile)
{
    QTextStream in(&aFile);
    return in.readAll();
}

void Form_top_del::setDataToVector(const QStringList &aStringList)
{
    nV = aStringList.size() - 1; // Count of line
    matrix_adj_str.clear();
    for (int i = 0; i < nV; ++i) {
        QVector<QString> temp_vector;
        for (int j = 0; j < nV; ++j) {
            temp_vector.push_back(aStringList.at(i).split(" ").at(j));
        }
        matrix_adj_str.push_back(temp_vector);
    }
}

void Form_top_del::record_to_vector()
{
    QFile file("D:/IT/LabWorks/graph/MainWind/matrix.txt");

    if(!file.open(QIODevice::ReadOnly))
       QMessageBox::warning(this, "Error", "File open error!");

    setDataToVector(allFileToString(file).split("\n"));
    file.close();
}

void Form_top_del::record_to_file(const QVector<QVector<QString>> & mtr)
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

void Form_top_del::on_pB_del_top_clicked()
{
    record_to_vector();
    delV = (ui->lineEdit_del_top->text()).toInt();

    if(delV < 1 || delV > nV)
    {
        QMessageBox::warning(this, "Error", "Vertex isn't in the graph!");

    }
    else
    {
        delV -= 1; // т.к вершина - номер, работаем с индексами
        nV -=1;    //т.к удаляем вершину

        QVector< QVector<QString>> tmp1;
        for(int i = 0; i < matrix_adj_str.size(); i++)
        {
            if(i != delV)
            {
                QVector<QString> tmp2;
                for(int j = 0; j <matrix_adj_str[i].size(); j++)
                    if(j != delV )
                    {
                        tmp2.push_back(matrix_adj_str[i][j]);
                    }
                tmp1.push_back(tmp2);
            }

        }
        matrix_adj_str.clear();
        matrix_adj_str = tmp1;
        record_to_file(matrix_adj_str);
    }
    this->close();
}

