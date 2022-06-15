/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCustomPlot *customplot;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QFrame *line;
    QListWidget *listWidget;
    QLabel *error_label;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *label_2;
    QLineEdit *variableName;
    QLabel *label_3;
    QLineEdit *variableValue;
    QPushButton *addButton;
    QLineEdit *existingVariableName;
    QLabel *label_4;
    QPushButton *VisableButton;
    QPushButton *clearExistingVariableButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        customplot = new QCustomPlot(centralwidget);
        customplot->setObjectName(QString::fromUtf8("customplot"));
        customplot->setGeometry(QRect(10, 10, 550, 550));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(860, 170, 120, 21));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setAutoFillBackground(true);
        pushButton->setStyleSheet(QString::fromUtf8(""));
        pushButton->setFlat(false);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(645, 450, 121, 51));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(665, 20, 306, 25));
        lineEdit->setClearButtonEnabled(true);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(585, 20, 71, 20));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(585, 150, 391, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(580, 220, 401, 215));
        error_label = new QLabel(centralwidget);
        error_label->setObjectName(QString::fromUtf8("error_label"));
        error_label->setGeometry(QRect(580, 510, 391, 41));
        error_label->setContextMenuPolicy(Qt::DefaultContextMenu);
        error_label->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));
        error_label->setAlignment(Qt::AlignCenter);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(585, 50, 391, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(585, 195, 391, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(580, 75, 121, 20));
        variableName = new QLineEdit(centralwidget);
        variableName->setObjectName(QString::fromUtf8("variableName"));
        variableName->setGeometry(QRect(700, 75, 71, 25));
        variableName->setClearButtonEnabled(true);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(785, 75, 111, 20));
        variableValue = new QLineEdit(centralwidget);
        variableValue->setObjectName(QString::fromUtf8("variableValue"));
        variableValue->setGeometry(QRect(900, 75, 71, 25));
        variableValue->setClearButtonEnabled(true);
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(585, 170, 120, 21));
        addButton->setCursor(QCursor(Qt::PointingHandCursor));
        addButton->setAutoFillBackground(true);
        addButton->setStyleSheet(QString::fromUtf8(""));
        addButton->setFlat(false);
        existingVariableName = new QLineEdit(centralwidget);
        existingVariableName->setObjectName(QString::fromUtf8("existingVariableName"));
        existingVariableName->setGeometry(QRect(705, 120, 266, 25));
        existingVariableName->setContextMenuPolicy(Qt::DefaultContextMenu);
        existingVariableName->setAutoFillBackground(false);
        existingVariableName->setStyleSheet(QString::fromUtf8("Background-color:rgb(230, 230, 230)"));
        existingVariableName->setReadOnly(true);
        existingVariableName->setClearButtonEnabled(false);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(580, 120, 131, 20));
        VisableButton = new QPushButton(centralwidget);
        VisableButton->setObjectName(QString::fromUtf8("VisableButton"));
        VisableButton->setGeometry(QRect(790, 450, 120, 51));
        VisableButton->setCursor(QCursor(Qt::PointingHandCursor));
        VisableButton->setAutoFillBackground(true);
        VisableButton->setStyleSheet(QString::fromUtf8(""));
        VisableButton->setFlat(false);
        clearExistingVariableButton = new QPushButton(centralwidget);
        clearExistingVariableButton->setObjectName(QString::fromUtf8("clearExistingVariableButton"));
        clearExistingVariableButton->setGeometry(QRect(720, 170, 120, 21));
        clearExistingVariableButton->setCursor(QCursor(Qt::PointingHandCursor));
        clearExistingVariableButton->setAutoFillBackground(true);
        clearExistingVariableButton->setStyleSheet(QString::fromUtf8(""));
        clearExistingVariableButton->setFlat(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        pushButton->setDefault(false);
        addButton->setDefault(false);
        VisableButton->setDefault(false);
        clearExistingVariableButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Create", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "delete", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Function :", nullptr));
        error_label->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Variable names :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Variable value :", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add Variables", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Existing variable:", nullptr));
        VisableButton->setText(QCoreApplication::translate("MainWindow", "Switch Visable", nullptr));
        clearExistingVariableButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
