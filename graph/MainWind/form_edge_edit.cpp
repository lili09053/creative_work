#include "form_edge_edit.h"
#include "ui_form_edge_edit.h"

Form_edge_edit::Form_edge_edit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_edge_edit)
{
    ui->setupUi(this);
}

Form_edge_edit::~Form_edge_edit()
{
    delete ui;
}

const QString Form_edge_edit::allFileToString(QFile &aFile)
{
    QTextStream in(&aFile);
    return in.readAll();
}

void Form_edge_edit::setDataToVector(const QStringList &aStringList)
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

void Form_edge_edit::record_to_vector()
{
    QFile file("D:/IT/LabWorks/graph/MainWind/matrix.txt");

    if(!file.open(QIODevice::ReadOnly))
       QMessageBox::warning(this, "Error", "File open error!");

    setDataToVector(allFileToString(file).split("\n"));
    file.close();
}

void Form_edge_edit::record_to_file(const QVector<QVector<QString>> & mtr)
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


void Form_edge_edit::on_pB_edit_edge_clicked()
{
    record_to_vector();
    startV = (ui->lineEdit_a->text()).toInt();
    finishV = (ui->lineEdit_b->text()).toInt();
    len_startV_to_finishV = (ui->lineEdit_ab->text()).toInt();
    len_finishV_to_startV = (ui->lineEdit_ba->text()).toInt();

    if (len_startV_to_finishV < 0 || len_finishV_to_startV < 0)
        QMessageBox::warning(this, "Error", "Path length must be non-negative!");

    else
    {
        startV -= 1; // т.к вершина - номер, работаем с индексами
        finishV -= 1;

        for (int i = 0; i < matrix_adj_str.size(); i++)
        {
            for (int j = 0; j < matrix_adj_str[i].size(); j++)
            {
                if (i == startV && j == finishV)
                     matrix_adj_str[i][j] = QString::number( len_startV_to_finishV );
                if (i == finishV && j == startV)
                    matrix_adj_str[i][j] = QString::number(len_finishV_to_startV);
            }
        }

        record_to_file(matrix_adj_str);
    }
    this->close();
}

