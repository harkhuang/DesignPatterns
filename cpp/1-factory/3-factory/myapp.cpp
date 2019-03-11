#include <iostream>
#include "doc.h"
#include "app.h"

Doc *  myApp::createDoc()
{
    return  new mydoc();
};


Doc *  myApp1::createDoc()
{
    return  new mydoc1();
};