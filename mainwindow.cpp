#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"cdbedesclist.h"
#include<QFile>
#include<QTextStream>
#include<QDebug>
#include<qstandarditemmodel.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadData();
}

void MainWindow::loadData()
{



    model->clear();
    model->setHorizontalHeaderItem(0, new QStandardItem("Nr"));
    model->setHorizontalHeaderItem(1, new QStandardItem("TabNr"));
    model->setHorizontalHeaderItem(2, new QStandardItem("szDBName"));
    model->setHorizontalHeaderItem(3, new QStandardItem("DBType"));

    ui->tableView->setModel(model);
   /* CDbedescList obj;
    obj.SetDbdescList();

    QList<QStandardItem *> list_items;
    for (int i=0;i<obj.SetDbdescList().size();i++){

        for (int j=0;j<obj.SetDbdescList()[i].size();j++){
         list_items.append(new QStandardItem(obj.SetDbdescList()[i][0]));
         list_items.append(new QStandardItem(obj.SetDbdescList()[i][1]));
         list_items.append(new QStandardItem(obj.SetDbdescList()[i][2]));
         list_items.append(new QStandardItem(obj.SetDbdescList()[i][3]));
         model->appendRow(list_items);
         list_items.clear();
     }
    }*/
}
MainWindow::~MainWindow()
{
    delete ui;
}

