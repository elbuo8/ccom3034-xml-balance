// File: xmlfile.cpp
// Implementation of the XMLFile funcions.

#include "xmlfile.h"


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

void trim(QString str,QStringList  &L) {
    QRegExp rxlen("(?:<)(/*[a-z|A-Z]+)(?:>)");
    int pos = 0;
    while ((pos = rxlen.indexIn(str, pos)) != -1) {
         L.push_back(rxlen.cap(1));
         pos += rxlen.matchedLength();
    }
}
