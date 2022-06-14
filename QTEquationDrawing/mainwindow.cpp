#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    graphSetting();
    graphplota();
    //graphplotb();
    ZoomInorOut();
}
MainWindow::~MainWindow()
{
    delete ui;
}



//----------Plot Setting----------
void MainWindow::ZoomInorOut(){
    ui->customplot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->customplot->rescaleAxes(true);
}

void MainWindow::graphSetting(){
    ui->customplot->addGraph();
    ui->customplot->xAxis->setLabel("X");
    ui->customplot->yAxis->setLabel("Y");
    ui->customplot->legend->setVisible(true);
    // set axes ranges, so we see all data:
}
//----------     End    ----------






//----------GraphPlotting----------
void MainWindow::graphplota(){
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->customplot->graph(0)->setData(x, y);
    ui->customplot->replot();
}

void MainWindow::graphplotb(){
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 5; // x goes from -1 to 1
      y[i] = x[i]+2; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->customplot->graph(1)->setPen(QPen(Qt::red));
    ui->customplot->replot();
}
//----------     End    ----------



//----------DeleteButton----------
void MainWindow::on_pushButton_2_clicked()
{
    ui->customplot->clearGraphs();
}
//----------     End    ----------
//----------CreateButton----------
void MainWindow::on_pushButton_clicked()
{



    ui->lineEdit->clear();
}
//----------     End    ----------
//----------Press  Enter----------
void MainWindow::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}
//----------     End    ----------
