#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addPointTemp(double x, double y);
    void plotTemp();

    void addPointHumid(double x, double y);
    void plotHumid();

private slots:
    void serialport_read();

private:
    Ui::MainWindow *ui;

    QVector<double> qv_x, qv_y;
    QVector<double> hv_x, hv_y;
};

#endif // MAINWINDOW_H
