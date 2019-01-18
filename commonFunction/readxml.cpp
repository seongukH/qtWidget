#include "readxml.h"

ReadXML::ReadXML()
{

}

void ReadXML::ReadSystemXML()
{
    QDomDocument document;

    QFile file("C:/zzz/system.xml");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() <<"Failed to open window file. and open linux file";
       QFile file("/sw/adapt/system.xml");

        //return -1;
    }//if file open
    else{
        if(!document.setContent(&file)){
            qDebug()<<"failed to load document";
         //   return -1;
        }//if document
        file.close();
    }//else


    QDomElement root = document.firstChildElement(); //get elemet staart

    //ListElements(root, "System", "ip_addr");
      //  ListElements(root, "System", "Name");

    g_data->infoSystem.name = getElements(root, "System", "name");
    g_data->infoSystem.ip_addr = getElements(root, "System", "ip_addr");
    g_data->infoSystem.listenPort = getElements(root, "System", "port").toInt();

    qDebug()<<"  name : "<< g_data->infoSystem.name
           <<"  ip_addr : "<<g_data->infoSystem.ip_addr
          <<"  listenPort : "<<g_data->infoSystem.listenPort;



     getElements(root, "System", "port");



}

void ReadXML::ListElements(QDomElement root, QString tagname, QString attribute)
{
    QDomNodeList items = root.elementsByTagName(tagname);

   // qDebug()<<"Total items = "<<items.count();

    for(int i = 0; i<items.count(); i++){
        QDomNode itemnode = items.at(i);

        if(itemnode.isElement()){
            QDomElement itemele = itemnode.toElement();
            qDebug()<<itemele.attribute(attribute);
        }
    }
}

QString ReadXML::getElements(QDomElement root, QString tagname, QString attribute)
{
    QDomNodeList items = root.elementsByTagName(tagname);

   // qDebug()<<"Total items = "<<items.count();

    for(int i = 0; i<items.count(); i++){
        QDomNode itemnode = items.at(i);

        if(itemnode.isElement()){
            QDomElement itemele = itemnode.toElement();
           // qDebug()<<itemele.attribute(attribute);

            return itemele.attribute(attribute);
        }
    }

    return "";
}


/*
g_data->testData.insert(1, "bob");
g_data->testData.insert(2, "chad");
g_data->testData.insert(3, "mary");

QList<QString> list;
 list << "one" << "two" << "three";

g_data->xmlBookData.insert("first", list);
g_data->xmlBookData.insert("second", list);


foreach(int i, g_data->testData.keys()){
    qDebug()<<g_data->testData[i];
}

qDebug()<<g_data->xmlBookData["first"][1];


*/


