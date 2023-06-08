#include "output_dij.h"
#include "ui_output_dij.h"

output_dij::output_dij(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::output_dij)
{
    ui->setupUi(this);

    QFile file("D:/graph/MainWind/dij.txt");

    if(!file.open(QIODevice::ReadOnly))
       QMessageBox::warning(this, "Error", "File open error!");


    QTextStream out(&file);

    while(!out.atEnd())
    {
         QString line = out.readLine();
         ui->tB_out->append(line);
    }
}

output_dij::~output_dij()
{
    delete ui;
}
