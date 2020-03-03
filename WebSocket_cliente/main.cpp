#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QTranslator>


using namespace std;
/*!\file*/

/////////////////////////////////////////////////
/// ... main ...
/////////////////////////////////////////////////

/**
 * funcion principal del programa
 */
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    ///cargar el archivo archivo de traduccion

    QTranslator myappTranslator;
    myappTranslator.load("myapp_en_US.ts");
    a.installTranslator(&myappTranslator);




    MainWindow w;
    w.show();

    return a.exec();
}
