#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qstandarditemmodel.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
   void loadData();

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QList<QStandardItem *> list_items;
};
#endif // MAINWINDOW_H
