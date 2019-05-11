#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtSerialPort>
#include <QString>

QSerialPort * serialPort;
int count = 0;
int times = 0;
QString t;
QString u;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize serial port
    serialPort = new QSerialPort(this);

    serialPort->setPortName("/dev/ttyUSB0");
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);

    serialPort->open(QIODevice::ReadWrite);

    connect(serialPort, SIGNAL(readyRead()),this,SLOT(serialport_read()));

    // Initialize graph
    ui->plotTemp->addGraph();
    ui->plotTemp->graph(0)->setPen(QPen(Qt::red));
    ui->plotHumid->addGraph();
    ui->plotHumid->graph(0)->setPen(QPen(Qt::blue));
}

MainWindow::~MainWindow()
{
    delete ui;
    serialPort->close();
}

void MainWindow::addPointTemp(double x, double y)
{
    qv_x.append(x);
    qv_y.append(y);
}

void MainWindow::plotTemp()
{
    ui->plotTemp->graph(0)->setData(qv_x,qv_y);
    ui->plotTemp->graph(0)->rescaleAxes();
    ui->plotTemp->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->plotTemp->replot();
    ui->plotTemp->update();
}

void MainWindow::addPointHumid(double x, double y)
{
    hv_x.append(x);
    hv_y.append(y);
}

void MainWindow::plotHumid()
{
    ui->plotHumid->graph(0)->setData(hv_x,hv_y);
    ui->plotHumid->graph(0)->rescaleAxes();
    ui->plotHumid->replot();
    ui->plotHumid->update();
}

void MainWindow::serialport_read()
{
    QString a = serialPort->readAll();

    count = count%4;
    switch (count) {
    case 0:
        t.append(a);
        break;
    case 1:
        t.append(a);
        ui->progressBar_2->setValue(t.toInt());
        addPointTemp(double(times), t.toDouble());
        plotTemp();
        t.clear();
        break;
    case 2:
        u.append(a);
        break;
    case 3:
        u.append(a);
        ui->progressBar->setValue(u.toInt());
        addPointHumid(double(times), u.toDouble());
        plotHumid();
        u.clear();
        times++;
        break;
    default:
        break;
    }
    count++;
}
