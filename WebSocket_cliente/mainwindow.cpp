#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include "json.hpp"
#include <QString>

using JSON = nlohmann::json;
/*static int g_idMensaje =0;

int dameIdMensaje(){

    g_idMensaje++;
    return g_idMensaje;
}*/
JSON VerRespuesta(JSON respuesta)
{
    ///extraer datos de la respuesta
   int idCliente = respuesta["id"];
   std::string nombre = respuesta["nombre"];
   std::string apellidos = respuesta["apellidos"];
   std::string dni = respuesta["dni"];
   std::string telefono = respuesta["telefono"];
   std::string email = respuesta["email"];


   std::cout << "id: " << idCliente << std::endl;
   std::cout << "nombre: " << nombre << std::endl;
   std::cout << "apellidos: " << apellidos << std::endl;
   std::cout << "dni: " << dni << std::endl;
   std::cout << "telefono: " << telefono << std::endl;
   std::cout << "email: " << email << std::endl;


}

bool exists(const JSON& json, const std::string& key)
{
    return json.find(key) !=json.end();
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer::singleShot(0, this, SLOT(startWSServer()));
    m_webSocket = std::make_shared<ix::WebSocket>();

}

MainWindow::~MainWindow()
{
    m_webSocket->stop();
    delete ui;

}


void MainWindow::startWSServer()
{

     m_webSocket->setUrl(std::string("ws://127.0.0.1:9990"));
     m_webSocket->setOnMessageCallback([](const ix::WebSocketMessagePtr& msg)
     {
         if (msg->type == ix::WebSocketMessageType::Message)
         {
           //  std::cout << msg->str << std::endl;

             if (!msg->binary)
             {
                 /// Text format
               std::cout << "Received message: " << msg->str << std::endl;
             }

             JSON receivedObject = JSON::parse(msg->str, nullptr,false);
             if(receivedObject.is_discarded())
             {
               std::cout << receivedObject.is_discarded() << std::endl;
             }
             else
             {
                if (exists(receivedObject,"responder"))
                {
                        JSON respuesta = receivedObject["responder"];
                        VerRespuesta(respuesta);

                 }//fin if
                else
                {
                    std::cout << " error no hay mensaje " << std::endl;
                }//fin if
             }//fin if
         } //fin if
     }
     );


     m_webSocket->connect(100);
     m_webSocket->send("funciona !!");
     m_webSocket->start();
}



void MainWindow::on_ButtonCliente_clicked()
{
    cliente = new Cliente (this);
    cliente->setWebSocket(m_webSocket);
    cliente->show();
}
