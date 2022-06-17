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
    ui->customplot->xAxis->setRange(-10, 10);
    ui->customplot->yAxis->setRange(-10, 10);
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
    //exprtk setting
    exprtk::expression<double> expr;
    exprtk::parser<double> p;
    exprtk::symbol_table<double> symbol;
    p.compile(ui->lineEdit->text().toStdString(), expr);
    ui->customplot->addGraph();
    QVector<double> x(100001), y(100001); // initialize with entries 0..100
    int i = 0;
    x[i]=0;
    double tmpx = x[i];
    symbol.add_variable("x", tmpx);
    //

    //assign variables
    std::vector<std::string> variableStr;
    std::vector<double> variableValue;
    int index = 0;
    int state = 0;//0 is name, 1 is num
    std::string nametmp = "";
    std::string valuetmp = "";
    for(int i = 0; i < ui->existingVariableName->text().size(); i++){
        if(ui->existingVariableName->text()[i]==':'){
            state = 1;
            variableStr.push_back(nametmp);
            nametmp="";
        }
        else if(ui->existingVariableName->text()[i]==';'/*||i==ui->existingVariableName->text().size()-1*/){
            state = 0;
            variableValue.push_back(stod(valuetmp));
            valuetmp="";
            index++;
        }
        else{
            if(state==0){
                nametmp=nametmp+ui->existingVariableName->text().toStdString()[i];
            }
            else if(state==1){
                valuetmp=valuetmp+ui->existingVariableName->text().toStdString()[i];
            }
        }
    }
    for(int i = 0; i <index; i++){
        //ui->error_label->setText(ui->error_label->text()+QString::fromStdString(variableStr[i]));
        symbol.add_variable(variableStr[i], variableValue[i]);
    }
    //

    expr.register_symbol_table(symbol);
    p.compile(ui->lineEdit->text().toStdString(), expr);
    for (i=0; i<100001; ++i)
    {
        x[i] = i/50.0 - 1000; // x goes from -1 to 1
        tmpx=x[i];
        y[i] = expr.value(); // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->customplot->graph(graphcnt)->setData(x, y);
    ui->customplot->graph(graphcnt)->setPen(QPen(colors[graphcnt%10]));
    ui->customplot->replot();
   //ui->customplot->rescaleAxes(true);
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
        //ui->customplot->graph(graphnum)->setVisible(false);
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
        ritem->setText(QString::number(graphcnt) + ".  " +ui->lineEdit->text()+","+ui->existingVariableName->text());

        ritem->setBackgroundColor(colors[graphcnt%10]);


        ui->error_label->setText(QString(/*text*/ ));
        ui->listWidget->addItem(ritem);



        graphplotb();

        ui->lineEdit->clear();
        ui->variableName->clear();
        ui->variableValue->clear();
        ui->existingVariableName->clear();
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
//----------AddVariableButton----------
void MainWindow::on_addButton_clicked()
{
    if(ui->variableName->text().size()!=0&&ui->variableValue->text().size()!=0){
        ui->existingVariableName->setText(ui->existingVariableName->text()+ui->variableName->text()+":"+ui->variableValue->text());
        ui->existingVariableName->setText(ui->existingVariableName->text()+";");
        ui->variableName->clear();
        ui->variableValue->clear();
        ui->error_label->setText(QString(""));
    }
    else{
        if(ui->variableName->text().size()==0&&ui->variableValue->text().size()==0){
            ui->error_label->setText(QString("Please check \"Name\" and \"Value\" of variables"));
        }
        else if(ui->variableName->text().size()==0){
            ui->error_label->setText(QString("Please check \"Name\" of variables"));
        }
        else if(ui->variableValue->text().size()==0){
            ui->error_label->setText(QString("Please check \"Value\" of variables"));
        }
    }

}
//------------     End     ------------
//----------VisableButton----------
void MainWindow::on_VisableButton_clicked()
{
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
        if(ui->customplot->graph(graphnum)->visible()==1){
            ui->customplot->graph(graphnum)->setVisible(false);
            ui->customplot->replot();
        }
        else{
            ui->customplot->graph(graphnum)->setVisible(true);
            ui->customplot->replot();
        }
    }
}
//----------     End     ----------

void MainWindow::on_clearExistingVariableButton_clicked()
{
    ui->existingVariableName->clear();
}

