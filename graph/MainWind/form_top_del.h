#ifndef FORM_TOP_DEL_H
#define FORM_TOP_DEL_H

#include <QWidget>
#include <QtWidgets>
#include <QTableWidget>
#include <QVector>
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QTextStream>

namespace Ui {
class Form_top_del;
}

class Form_top_del : public QWidget
{
    Q_OBJECT

public:
    explicit Form_top_del(QWidget *parent = nullptr);
    ~Form_top_del();

private slots:
    void on_pB_del_top_clicked();

private:
    Ui::Form_top_del *ui;
    int nV = 0;
    int delV = 0;
    QVector<QVector<QString>> matrix_adj_str = QVector<QVector<QString>>(nV);
    void record_to_vector();    //запись из файла в вектор
    void record_to_file(const QVector<QVector<QString>> & mtr);
    const QString allFileToString(QFile &aFile); // функция для записи матрицы в вектор
    void setDataToVector(const QStringList &aStringList);       // функция для записи матрицы в вектор
};

#endif // FORM_TOP_DEL_H
