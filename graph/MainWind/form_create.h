#ifndef FORM_CREATE_H
#define FORM_CREATE_H

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
class Form_create;
}

class Form_create : public QWidget
{
    Q_OBJECT

public:
    explicit Form_create(QWidget *parent = nullptr);
    ~Form_create();

private slots:
    void on_pB_ok_clicked();
    void on_pB_create_gr_clicked();

private:
    Ui::Form_create *ui;
    int nV = 0;                 //количество вершин
    QVector<QVector<QString>> matrix_adj = QVector<QVector<QString>>(nV);
    void record_to_file(const QVector<QVector<QString>> &mtr);

};

#endif // FORM_CREATE_H
