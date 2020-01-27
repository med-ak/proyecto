#include "mainwindow.h"


#include <QApplication>
#include "iniciar.h"
#include "ui_iniciar.h"


#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w;
    Iniciar w;
    w.show();
    return a.exec();
}



