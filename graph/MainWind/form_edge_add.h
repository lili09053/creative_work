#ifndef FORM_EDGE_ADD_H
#define FORM_EDGE_ADD_H

#include <QWidget>
#include <QtWidgets>
#include <QTableWidget>
#include <QVector>
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QTextStream>


namespace Ui {
class Form_edge_add;
}

class Form_edge_add : public QWidget
{
    Q_OBJECT

public:
    explicit Form_edge_add(QWidget *parent = nullptr);
    ~Form_edge_add();

private slots:
    void on_pB_add_edge_clicked();

private:
    Ui::Form_edge_add *ui;
    int nV = 0;
    int startV = 0;   // стартовая вершина
    int finishV = 0;    // конечная вершина
    int len_startV_to_finishV = 0;
    int len_finishV_to_startV = 0;
    QVector<QVector<QString>> matrix_adj_str = QVector<QVector<QString>>(nV);
    void record_to_vector();    //запись из файла в вектор
    void record_to_file(const QVector<QVector<QString>> & mtr);
    const QString allFileToString(QFile &aFile); // функция для записи матрицы в вектор
    void setDataToVector(const QStringList &aStringList);       // функция для записи матрицы в вектор
};

#endif // FORM_EDGE_ADD_H
