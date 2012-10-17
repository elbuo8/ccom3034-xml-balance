// File: xmlfile.h
// A class to represent an XMLFile and perform several
// usefull functions.

#ifndef XMLFILE_H
#define XMLFILE_H

#include <QtDebug>
#include <QRegExp>
#include <QFile>
#include <vector>
#include <QStringList>
#include <iostream>

using namespace std;

class XMLFile: public QFile {

public:
    XMLFile(const QString st) : QFile(st) {}

    // Reads the file and returns a list of all the tags used
    QStringList toTagList();

};

// Service function that takes a string adds
// the tags in that string to the passed list
void trim(QString str,QStringList  &L);

#endif // XMLFILE_H
