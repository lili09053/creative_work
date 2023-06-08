#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    f_cr = new Form_create;
    f_edit_matrix = new Form_mtx_adj;
    f_delete_vertex = new Form_top_del;
    f_add_vertex = new Form_top_add;
    f_add_edge = new Form_edge_add;
    f_del_edge = new Form_edge_del;
    f_edit_edge = new Form_edge_edit;
    f_out_res = new output_dij;
    connect(ui->pB_createGraph, SIGNAL(clicked()),f_cr, SLOT(show())); // вызов окна создания графа по нажатию
    ui->rB_width->setChecked(true);

    // Кастомный виджет для отрисовки

    openGLW = new MyOpenGLWidget(this);
    ui->grid->addWidget(openGLW, 0, 0);
    connect(ui->pB_drawGraph, &QPushButton::clicked, openGLW, &MyOpenGLWidget::redraw);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pB_start_v_ok_clicked()
{
     num_start_vert = (ui->lineEdit_startVert->text()).toInt() - 1;  //стартовая вершина для обхода
}

const QString MainWindow::allFileToString(QFile &aFile)
{
    QTextStream in(&aFile);
    return in.readAll();
}

void MainWindow::setDataToVector(const QStringList &aStringList)
{
    nV = aStringList.size() - 1; // Count of line
    matrix_adj.clear();
    for (int i = 0; i < nV; ++i) {
        QVector<int> temp_vector;
        for (int j = 0; j < nV; ++j) {
            temp_vector.push_back(aStringList.at(i).split(" ").at(j).toInt());
        }
        matrix_adj.push_back(temp_vector);
    }
}

void MainWindow::record_to_vector()
{
    QFile file("D:/graph/MainWind/matrix.txt");
    if(!file.open(QIODevice::ReadOnly))
       QMessageBox::warning(this, "Error", "File open error!");

    setDataToVector(allFileToString(file).split("\n"));

    // печать вектора для проверки
    for (int i = 0; i < matrix_adj.size(); ++i) {
        for (int j = 0; j < matrix_adj[i].size(); ++j) {
            std::cout << matrix_adj[i][j] << " ";
        }
        std::cout << std::endl;}
    file.close();
}

void MainWindow::matrix_weight_to_unweight()
{
    matrix_adj_0_1.clear();
    for (int i = 0; i < nV; ++i)
    {
        QVector<int> tmp;
        for (int j = 0; j < nV; ++j) {
            if (matrix_adj[i][j] == 0)
                tmp.push_back(0);
            else
                tmp.push_back(1);
        }
    matrix_adj_0_1.push_back(tmp);
    }
}

void MainWindow::BFS()
{
    // соответствующий невзвешенный граф
    ui->txtBr_route->clear();
    matrix_weight_to_unweight();
    QVector<bool> visited (nV, false);
    QQueue<int> q;

    for (int i=0; i<nV; i++)
        q.enqueue(0);

    int count=0;
    int head = 0;
    q[count++]= num_start_vert;
    visited[num_start_vert]=true;
    while (head < count)
    {
        num_start_vert=q[head++];
        if (head == count && head != 1)
            route += QString::number(num_start_vert + 1);
        else
            route += QString::number(num_start_vert + 1) + " -> ";

        for (int i=0;  i< nV; i++)
        {
            if ((matrix_adj_0_1[num_start_vert][i] > 0) && !visited[i])
            {
                q[count++]=i;
                visited[i]=true;
            }
        }

    }
     ui->txtBr_route->append(route);
     route = "";

}



void MainWindow::Dij()
{
    bool visited[nV];
    int distances[nV];
    int minimalWeight, minimalIndex;

    for (int i = 0; i < nV; ++i)
    {
        visited[i] = false;
        distances[i] = INT_MAX;
    }

    distances[num_start_vert] = 0;

    do
    {
        minimalIndex = INT_MAX;
        minimalWeight = INT_MAX;

        for (int i = 0; i < nV; ++i)
        {
            if (!visited[i] && distances[i] < minimalWeight)
            {
                minimalIndex = i;
                minimalWeight = distances[i];
            }
        }

        if (minimalIndex != INT_MAX)
        {
            for (int i = 0; i < nV; ++i)
            {
                if (matrix_adj[minimalIndex][i])
                {
                    int temp = minimalWeight + matrix_adj[minimalIndex][i];

                    if (temp < distances[i])
                        distances[i] = temp;
                }
            }

            visited[minimalIndex] = true;
        }
    }
    while (minimalIndex < INT_MAX);

    QFile file("D:/graph/MainWind/dij.txt"); // "D:/IT/LabWorks/graph/MainWind/matrix.txt"

    if(!file.open(QIODevice::WriteOnly))
       QMessageBox::warning(this, "Error", "File open error!");


    QTextStream out(&file);

    for (int i = 0; i < nV; ++i)
    {
        if (distances[i] != INT_MAX)
        {
            out << "Weight: " << num_start_vert + 1 << " -> " <<  QString::number(i + 1) << " = "  << QString::number(distances[i])  << "\t\t";
            int end = i;
            unsigned weight = distances[end];
            QString way = QString::number(end + 1) + " >- ";

            while (end != num_start_vert)
            {
                for (int j = 0; j < nV; ++j)
                {
                    if (matrix_adj[j][end])
                    {
                        int temp = weight - matrix_adj[j][end];

                        if (temp == distances[j])
                        {
                            end = j;
                            weight = temp;
                            way += QString::number(j + 1) + " >- ";
                        }
                    }
                }
            }

            out << "Route: ";
            for (int j = way.length() - (nV-1); j >= 0; --j)
                out << way[j];

            out << "\n";


        }
        else
            out << "Weight: " << QString::number(num_start_vert + 1) << " - " << QString::number(i + 1) << " = " << "route unavailable" << "\n";
    }
     file.close();
     f_out_res -> show();
}

void MainWindow::DFS(int st)
{
    vis[st]=true;
    route += QString::number(num_start_vert + 1) + " -> ";
    std::cout <<num_start_vert + 1 << " -> ";
    for ( int i : matrix_adj_0_1[st])
    {
        if (!vis[i])
            DFS(i);
    }
}



void MainWindow::on_pB_lenRoute_clicked()
{
    record_to_vector();         // перенос матрицы смежности из файла в вектор
    if (num_start_vert + 1 > nV)
         QMessageBox::warning(this, "Error", "Vertex doesn't exist!");

    if(ui->rB_width->isChecked())
    {
        //длина пути в отдельный лейбл!!!
        // вызов алгоритма в ширину
        BFS();
        std::cout << "W" << std::endl;
        return;
    }
    else
    {
        if(ui->rB_depth->isChecked())
        {
            // вызов алгоритма в глубину
            ui->txtBr_route->clear();
            matrix_weight_to_unweight();
            for(int i = 0; i < nV; i++)
                vis.push_back(false);
            DFS(num_start_vert);
            ui->txtBr_route->append(route);
            route = "";
            std::cout << "D" << std::endl;
            return;
        }
        else
        {
            if(ui->rB_Dijkstra->isChecked())
            {
                // вызов алгоритма Дейкстры
                Dij();
                std::cout << "Dj" << std::endl;
                return;
            }
        }
    }

}

void MainWindow::on_matrix_adj_menu_triggered(){f_edit_matrix->show();}

void MainWindow::on_top_del_triggered(){f_delete_vertex->show();}

void MainWindow::on_top_add_triggered() {f_add_vertex->show();}

void MainWindow::on_edge_add_triggered() {f_add_edge->show();}

void MainWindow::on_edge_del_triggered() {f_del_edge->show();}

void MainWindow::on_edge_edit_triggered() {f_edit_edge->show();}


void MainWindow::on_pB_drawGraph_clicked()
{
    record_to_vector();
    openGLW->set_matrix(matrix_adj);
}

