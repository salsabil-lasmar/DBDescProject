#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>


#include "cdbedesclist.h"
#include<qstandarditemmodel.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QStandardItemModel(this); // you didn't initialize model, this caused the crash of the App.
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

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


    CDbedescList obj;

    QList<QList<QString>> m_dbList;
    obj.SetDbdescList(m_dbList);

    qDebug()<<m_dbList.size();


    QList<QStandardItem *> list_items;
    for (int i=0;i<m_dbList.size();i++){

        list_items.append(new QStandardItem(m_dbList[i][0]));
        list_items.append(new QStandardItem(m_dbList[i][1]));
        list_items.append(new QStandardItem(m_dbList[i][2]));
        list_items.append(new QStandardItem(m_dbList[i][3]));
        model->appendRow(list_items);
        list_items.clear();

    }
}
MainWindow::~MainWindow()
{
    delete ui;
}

