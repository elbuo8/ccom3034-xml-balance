// File: xmlfile.cpp
// Implementation of the XMLFile funcions.

#include "xmlfile.h"
#include <QStack>


QStringList XMLFile::toTagList() {
    QFile file(this->fileName());
    QStringList L;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open file!";
        exit(1);
    }

    while(!file.atEnd())
        trim(file.readLine(), L);

    return L;
}

void trim(QString str, QStringList  &L) {
    QRegExp rxlen("(?:<)(/*[a-z|A-Z]+)(?:>)");
    int pos = 0;
    while ((pos = rxlen.indexIn(str, pos)) != -1) {
         L.push_back(rxlen.cap(1));
         pos += rxlen.matchedLength();
    }

}

bool XMLFile::isBalanced(QStringList xml) {
    QStack<QString> xmlContainer;
    xmlContainer.push(xml.at(0));
    for(int i = 1; i < xml.length(); i++) {
        if(xml.at(i).contains("/")) {
            if(xmlContainer.top() == xml.at(i).right(xml.at(i).length()-1))
                xmlContainer.pop();
        }
        else {
            xmlContainer.push(xml.at(i));
        }

    }
    return xmlContainer.isEmpty();
}
