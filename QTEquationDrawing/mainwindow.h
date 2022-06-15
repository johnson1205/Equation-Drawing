#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int graphcnt = 0;
    QList<QColor> colors;

private slots:
    void ZoomInorOut();
    void graphSetting();
    void graphplota();
    void graphplotb();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_lineEdit_returnPressed();
    void listwidgetSetting();
    void colorSetting();
    void on_addButton_clicked();

    void on_VisableButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
