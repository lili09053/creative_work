#ifndef FORM_TOP_ADD_H
#define FORM_TOP_ADD_H

#include <QWidget>
#include <QtWidgets>
#include <QTableWidget>
#include <QVector>
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QTextStream>

namespace Ui {
class Form_top_add;
}

class Form_top_add : public QWidget
{
    Q_OBJECT

public:
    explicit Form_top_add(QWidget *parent = nullptr);
    ~Form_top_add();

private slots:
    void on_pB_add_top_clicked();

private:
    Ui::Form_top_add *ui;
    int nV = 0;
    int addV = 0;   // добавляемая вершина
    int toV = 0;    // [проложить ребро от добавленной вершины к] заданной
    int len_addV_toV = 0;
    int len_toV_addV = 0;
    QVector<QVector<QString>> matrix_adj_str = QVector<QVector<QString>>(nV);
    void record_to_vector();    //запись из файла в вектор
    void record_to_file(const QVector<QVector<QString>> & mtr);
    const QString allFileToString(QFile &aFile); // функция для записи матрицы в вектор
    void setDataToVector(const QStringList &aStringList);       // функция для записи матрицы в вектор
};

#endif // FORM_TOP_ADD_H
