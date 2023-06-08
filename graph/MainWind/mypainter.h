#ifndef MYPAINTER_H
#define MYPAINTER_H

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>
#include <QtWidgets>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>

class MyPainter
{
public:
    MyPainter();

public:
    void draw(QPainter *painter, QPaintEvent *event);
    void make_matrix();
    void add_node();
    void delete_node();
    int nV = 0;
    QVector<QVector<int>> matrix_adj = QVector<QVector<int>>(nV);
    QBrush front;

private:
    QBrush back;
    QFont glFont;
    QPen textPen;
    const QString allFileToString(QFile &aFile);
    void setDataToVector(const QStringList &aStringList);
    void record_to_vector();
};

#endif // MYPAINTER_H
