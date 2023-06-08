#ifndef OUTPUT_DIJ_H
#define OUTPUT_DIJ_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

namespace Ui {
class output_dij;
}

class output_dij : public QWidget
{
    Q_OBJECT

public:
    explicit output_dij(QWidget *parent = nullptr);
    ~output_dij();

private:
    Ui::output_dij *ui;
};

#endif // OUTPUT_DIJ_H
