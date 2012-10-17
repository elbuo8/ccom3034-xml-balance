// File: main.cpp
// The client to test the XMLFile class.

#include "xmlfile.h"

int main(){
    XMLFile X("/tmp/test.dat");
    qDebug() << "The list of tags: " << X.toTagList();
    return 0;
}
