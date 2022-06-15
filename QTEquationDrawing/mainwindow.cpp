#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    colorSetting();
    graphSetting();
    //graphplota();
    //graphplotb();
    ZoomInorOut();
    listwidgetSetting();
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
    //ui->customplot->legend->setVisible(true);
    // set axes ranges, so we see all data:
}
//----------     End    ----------
//----------ListWidget Setting----------
void MainWindow::listwidgetSetting(){
    ui->listWidget->setViewMode(QListView::ListMode);
    ui->listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
}
//-------------     End    -------------
//----------Color Setting----------
void MainWindow::colorSetting(){
    colors << QColor(220, 20, 60)<< QColor(170, 255, 1)<<QColor(0, 255, 255) <<  QColor(255, 127, 1)<<QColor(255, 255, 1) << QColor(0, 206, 209)
           << QColor(153, 130, 204)<< QColor(255, 192, 203)<< QColor(255, 222, 173)<< QColor(205,133,63);
}
//----------     End     ----------











//----------GraphPlotting----------
void MainWindow::graphplota(){
    // generate some data:
    ui->customplot->addGraph();
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->customplot->graph(graphcnt)->setData(x, y);
    ui->customplot->graph(graphcnt)->setPen(QPen(colors[graphcnt%10]));
    ui->customplot->replot();
    ui->customplot->rescaleAxes(true);
}

void MainWindow::graphplotb(){
    // generate some data:
    ui->customplot->addGraph();
    QVector<double> x(2001), y(2001); // initialize with entries 0..100
    for (int i=0; i<2001; ++i)
    {
      x[i] = i/100.0 - 10; // x goes from -1 to 1
      y[i] = x[i]+graphcnt; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->customplot->graph(graphcnt)->setData(x, y);
    ui->customplot->graph(graphcnt)->setPen(QPen(colors[graphcnt%10]));
    ui->customplot->replot();
    ui->customplot->rescaleAxes(true);
}
//----------     End    ----------



//----------DeleteButton----------
void MainWindow::on_pushButton_2_clicked()
{
    //ui->customplot->clearGraphs();
    QListWidgetItem *line= ui->listWidget->currentItem();
    if(line){
        QString linestr = line->text();
        QString graphstr = "";
        int i = 0;
        while(1){
            if(linestr[i]=='.') break;
            else graphstr=graphstr+linestr[i];
            i++;
        }
        int graphnum = graphstr.toInt();
        ui->customplot->graph(graphnum)->data().data()->clear();
        delete ui->listWidget->currentItem();
        ui->customplot->replot();
    }
}
//----------     End    ----------
//----------CreateButton----------
void MainWindow::on_pushButton_clicked()
{

    //if(checkVaild(ui->lineEdit->text())==1)
    if(ui->listWidget->count()<10){
        graphcnt++;
        QListWidgetItem *ritem = new QListWidgetItem;
        ritem->setText(QString::number(graphcnt) + ".  " +ui->lineEdit->text());

        ritem->setBackgroundColor(colors[graphcnt%10]);


        ui->error_label->setText(QString(/*text*/ ));
        ui->listWidget->addItem(ritem);



        graphplotb();

        ui->lineEdit->clear();
    }
    else{
        ui->error_label->setText(QString("Over 10 functions"));
    }


}
//----------     End    ----------
//----------Press  Enter----------
void MainWindow::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}
//----------     End    ----------
