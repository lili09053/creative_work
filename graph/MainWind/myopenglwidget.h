#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QOpenGLWidget>

class MyOpenGLWidget : public QOpenGLWidget
{
public:
    MyOpenGLWidget(QWidget *parent);
    void set_matrix(QVector<QVector<int>> mtrx);

public slots:
    void redraw();

protected:
    void paintEvent(QPaintEvent *event) override;
    void draw(QPainter* painter, QPaintEvent *event);

    QVector<QVector<int>> matrix = QVector<QVector<int>>();
};

#endif // MYOPENGLWIDGET_H
