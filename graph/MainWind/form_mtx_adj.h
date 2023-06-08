#ifndef FORM_MTX_ADJ_H
#define FORM_MTX_ADJ_H

#include <QWidget>
#include <QtWidgets>
#include <QTableWidget>
#include <QVector>
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <QPushButton>

namespace Ui {
class Form_mtx_adj;
}

class Form_mtx_adj : public QWidget
{
    Q_OBJECT

public:
    explicit Form_mtx_adj(QWidget *parent = nullptr);
    ~Form_mtx_adj();

private slots:
    void on_pB_edit_mtr_clicked();
    void on_pB_open_tab_clicked();

private:
    Ui::Form_mtx_adj *ui;
    int nV = 0;
    QVector<QVector<int>> matrix_adj = QVector<QVector<int>>(nV);
    QVector<QVector<QString>> matrix_adj_2 = QVector<QVector<QString>>(nV);
    void record_to_file(const QVector<QVector<QString>> &mtr);
    void record_to_vector();    //запись из файла в вектор
    const QString allFileToString(QFile &aFile); // функция для записи матрицы в вектор
    void setDataToVector(const QStringList &aStringList);       // функция для записи матрицы в вектор
    void record_to_table();
    void vector_for_table();
};

#endif // FORM_MTX_ADJ_H
