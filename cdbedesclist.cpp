#include "cdbedesclist.h"
#include <QTextStream>
#include<QFile>
CDbedescList::CDbedescList()
{

}
QList<QList<QString>> CDbedescList::SetDbdescList(){

   QList<QString> list;
   QList<QList<QString>> list1;
   QString path ="C:\\Users\\salsabil.lasmar\\Desktop\\exemple.cpp";//"C:\\Projekte\\windekis_src\\GIT\\windekis\\Genix\\ApWare32\\WinDekis\\Source\\DbDescCommon.cpp";
   QFile file(path);
   if (file.open(QIODevice::ReadOnly | QIODevice::Text) ) {
         QTextStream flux(&file);
         while (!flux.atEnd()) {
             QString line = flux.readLine();
             if(line.contains("{")){
                 list =line.split(',').replaceInStrings(" ","");
                 list.replaceInStrings("{","");
                 list.replaceInStrings("}","");
                 list1.append(list);

             }

           }


   }
return list1;


}
