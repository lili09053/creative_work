#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQueue>
#include <QVector>
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <QStack>
#include "form_create.h"
#include "form_mtx_adj.h"
#include "form_top_del.h"
#include "form_top_add.h"
#include "form_edge_add.h"
#include "form_edge_del.h"
#include "form_edge_edit.h"
#include "output_dij.h"
#include "myopenglwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


struct Edge         // для обхода графа в ширину
{
  int begin;
  int end;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pB_start_v_ok_clicked();
    void on_pB_lenRoute_clicked();
    void on_matrix_adj_menu_triggered();
    void on_top_del_triggered();
    void on_top_add_triggered();
    void on_edge_add_triggered();
    void on_edge_del_triggered();
    void on_edge_edit_triggered();

    void on_pB_drawGraph_clicked();

private:

    MyOpenGLWidget* openGLW;

    Ui::MainWindow *ui;
    Form_create *f_cr;
    Form_mtx_adj *f_edit_matrix;
    Form_top_del * f_delete_vertex;
    Form_top_add * f_add_vertex;
    Form_edge_add * f_add_edge;
    Form_edge_del * f_del_edge;
    Form_edge_edit * f_edit_edge;
    output_dij * f_out_res;
    int num_start_vert;
    QString route = "";
    int nV = 0;
    QVector<QVector<int>> matrix_adj = QVector<QVector<int>>(nV);
    QVector<QVector<int>> matrix_adj_0_1 = QVector<QVector<int>>(nV);
    QVector<bool> vis;
    void record_to_vector();    //запись из файла в вектор
    const QString allFileToString(QFile &aFile); // функция для записи матрицы в вектор
    void setDataToVector(const QStringList &aStringList);       // функция для записи матрицы в вектор
    void matrix_weight_to_unweight(); // невзвешенный граф
    void BFS();
    void Dij();
    void DFS(int);
    void draw();
};
#endif // MAINWINDOW_H
