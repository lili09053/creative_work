#include "myopenglwidget.h"

#include <QPainter>
#include <QPaintEvent>
#include <QPainter>
#include <QWidget>
#include <QtCore/qmath.h>

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent)
    :QOpenGLWidget(parent)
{

}

void MyOpenGLWidget::redraw()
{
    this->update();
}

void MyOpenGLWidget::set_matrix(QVector<QVector<int>> mtrx)
{
    matrix = mtrx;
}

void MyOpenGLWidget::draw(QPainter* painter, QPaintEvent *event)
{
    int len = matrix.size();                        // Кол-во узлов в графе
    int R = 120;                                    // Радиус графа
    int r = 40;                                     // Радиус узла
    double pi = 3.1415;
    int HeightText = 30;                            // Высота текста
    int xa = 400;                                   // Отступ от вертикали
    int ya = 200;                                   // Отступ от горизонтали
    double angle = pi / 12;                          // Угол раствора стрелки
    int ls = 15;                                    // Длина кончика стрелки
    int disp = 20;                                  // Разброс подписей ребер

    QBrush front, back;
    QFont glFont;
    QPen textPen;

    front = QBrush(QColor(255, 255, 255));
    back = QBrush(QColor(247,240,247));
    textPen = QPen(QColor(33, 33, 33));
    glFont.setPixelSize(HeightText);

    painter->fillRect(event->rect(), back);
    painter->setBrush(front);
    painter->setPen(textPen);
    painter->setFont(glFont);
    textPen.setWidth(4);

    for (int i = 0; i < len; i++)
    {
        double a = pi * 3 / 2 + pi * 2 / len * i;   // Угол в полярных координатах (узел)

        int xc = cos(a) * R + xa;                   // Декартовы координата узла
        int yc = sin(a) * R + ya;

        int c1 = xc - 20;                           // Координаты текста
        int c2 = yc - HeightText / 2;
        int c3 = 40;
        int c4 = HeightText;

        QString text; text.setNum(i + 1);

        painter->drawEllipse(QRectF(xc - r, yc - r, 2 * r, 2 * r));
        painter->drawText(QRect(c1, c2, c3, c4), Qt::AlignCenter, text);

        for (int k = 0 ; k < len; k++)
        {
            if (matrix[i][k] != 0)
            {
                // Отрисовка линии

                double a2 = pi * 3 / 2 + pi * 2 / len * k;

                double xc2 = cos(a2) * R + xa;
                double yc2 = sin(a2) * R + ya;

                double l = sqrt((xc2 - xc) * (xc2 - xc) + (yc2 - yc) * (yc2 - yc));

                int xl1 = (xc2-xc) / l * r + xc;
                int yl1 = (yc2-yc) / l * r + yc;

                int xl2 = xc2 - (xc2-xc)/l * r;
                int yl2 = yc2 - (yc2 - yc) / l * r;

                painter->drawLine(xl1, yl1 , xl2 , yl2);

                // Рисование стрелки

                double b;

                if (xc2 == xl2 && yl2 < yc2)
                    b = pi * 3 / 2;
                else
                    if (yc2 == yl2 && xl2 < xc2)
                        b = pi;
                else
                    if (xc2 == xl2 && yl2 > yc2)
                        b = pi / 2;
                else
                    if (yc2 == yl2 && xl2 > xc2)
                        b = 0;
                else
                    if (xl2 > xc2 && yl2 < yc2)
                        b = atan((yc2 - yl2) / (xc2 - xl2)) + pi * 2;
                else
                    if (xl2 < xc2 && yl2 < yc2)
                        b = atan((yc2 - yl2) / (xc2 - xl2)) + pi;
                else
                    if (xl2 < xc2 && yl2 > yc2)
                        b = atan((yc2 - yl2) / (xc2 - xl2)) + pi;
                else
                    if (xl2 > xc2 && yl2 > yc2)
                        b = atan((yc2 - yl2) / (xc2 - xl2));

                int xs1 = cos(b + angle) * ls + xl2;
                int ys1 = sin(b + angle) * ls + yl2;

                int xs2 = cos(b - angle) * ls + xl2;
                int ys2 = sin(b - angle) * ls + yl2;

                painter->drawLine(xl2, yl2, xs1, ys1);
                painter->drawLine(xl2, yl2, xs2, ys2);

                // Отрисовка текста

                c1 = (xl2 + xl1) / 2 - 20;  // - 20 + qrand() % disp - disp / 2
                c2 = (yl2 + yl1) / 2 - 5;  // - HeightText / 2 + qrand() % disp - disp / 2
                c3 = 40;
                c4 = HeightText;

                if (matrix[k][i] != 0)
                {
                    if (k >= i)
                    {
                        text = QString::number(matrix[i][k]) + "     " + QString::number(matrix[k][i]);
                    }
                    else
                    {
                        text = "";
                    }
                }
                else
                {
                    text.setNum(matrix[i][k]);
                }
                painter->drawText(QRect(c1, c2, c3, c4), Qt::AlignCenter, text);
            }
        }
    }
}

void MyOpenGLWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    draw(&painter, event);
    painter.end();
}
