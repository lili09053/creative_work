#include "form_top_add.h"
#include "ui_form_top_add.h"
#include <iostream>

Form_top_add::Form_top_add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_top_add)
{
    ui->setupUi(this);
}

Form_top_add::~Form_top_add()
{
    delete ui;
}

const QString Form_top_add::allFileToString(QFile &aFile)
{
    QTextStream in(&aFile);
    return in.readAll();
}

void Form_top_add::setDataToVector(const QStringList &aStringList)
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

void Form_top_add::record_to_vector()
{
    QFile file("D:/IT/LabWorks/graph/MainWind/matrix.txt");

    if(!file.open(QIODevice::ReadOnly))
       QMessageBox::warning(this, "Error", "File open error!");

    setDataToVector(allFileToString(file).split("\n"));
    file.close();
}

void Form_top_add::record_to_file(const QVector<QVector<QString>> & mtr)
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


void Form_top_add::on_pB_add_top_clicked()
{
    record_to_vector();
    addV = (ui->lineEdit_a->text()).toInt();
    toV = (ui->lineEdit_b->text()).toInt();
    len_addV_toV = (ui->lineEdit_ab->text()).toInt();
    len_toV_addV = (ui->lineEdit_ba->text()).toInt();

    if (len_addV_toV < 0 || len_toV_addV < 0)
        QMessageBox::warning(this, "Error", "Path length must be non-negative!");
    else
    {
        addV -= 1; // т.к вершина - номер, работаем с индексами
        toV -= 1;
        nV +=1;    //т.к добавляем вершину

        QVector< QVector<QString>> tmp1;

        for(int i = 0; i <= matrix_adj_str.size(); i++)
        {
            if(i < matrix_adj_str.size())
            {
                QVector<QString> tmp2;
                for(int j = 0; j <= matrix_adj_str[i].size(); j++)
                    if(j < matrix_adj_str[i].size() )
                    {
                        tmp2.push_back(matrix_adj_str[i][j]);
                    }
                    else
                    {
                        tmp2.push_back("0");
                    }
                tmp1.push_back(tmp2);
            }
            else
            {
                QVector<QString> tmp3 (nV, "0");
                tmp1.push_back(tmp3);
            }

        }
        matrix_adj_str.clear();
        matrix_adj_str = tmp1;

        for (int i = 0; i < tmp1.size(); i++)
        {
            for (int j = 0; j < tmp1[i].size(); j++)
            {
                if (i == addV && j == toV)
                    tmp1[i][j] = QString::number(len_addV_toV);

                if (i == toV && j == addV)
                     tmp1[i][j] = QString::number(len_toV_addV);
            }
        }
       record_to_file(tmp1);
    }
    this->close();
}






