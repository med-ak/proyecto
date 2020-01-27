#include "iniciar.h"
#include "ui_iniciar.h"
#include"mainwindow.h"
#include "ixwebsocket/IXWebSocket.h"
#include <iostream>
#include <string>
using namespace std;

Iniciar::Iniciar(QWidget *parent) :

    QDialog(parent),
    ui(new Ui::Iniciar)
{
    ui->setupUi(this);

    ix::WebSocket webSocket;
    webSocket.setUrl(std::string("ws://127.0.0.1:9990/"));
    webSocket.setOnMessageCallback([](const ix::WebSocketMessagePtr& msg)
    {
        if(msg->type == ix::WebSocketMessageType::Message)
        {
            std::cout << msg->str << std::endl;

        }
    }

   );
    //webSocket.connect(100);
    webSocket.send("helloo");
   // webSocket.run();
}

Iniciar::~Iniciar()
{
    delete ui;


}



void Iniciar::on_pushButton_19_clicked()
{

}

void Iniciar::on_pushButton_20_clicked()
{
    close();
}
/*int Iniciar::web(){

 webSocket.connect(100);
 webSocket.send("helloo");
 webSocket.run();
 return  0;
}*/
