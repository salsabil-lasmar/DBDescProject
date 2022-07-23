#include <QTextStream>
#include <QFile>
#include <QCoreApplication>
#include <QDebug>
#include <QDir>



#include "cdbedesclist.h"
CDbedescList::CDbedescList()
{

}

void CDbedescList::SetDbdescList(QList<QList<QString> > &m_dbList)
{
    QList<QString> list;

    QString path = QDir::currentPath()+"/input/exemple.cpp";
    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text) ) {
        QTextStream flux(&file);
        while (!flux.atEnd()) {
            QString line = flux.readLine();

            if(line.contains("{")){
                list =line.split(',').replaceInStrings(" ","");
                list.replaceInStrings("{","");
                list.replaceInStrings("}","");
                m_dbList.append(list);
            }
        }
    }

    file.close();
}


