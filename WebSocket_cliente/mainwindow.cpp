#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include "json.hpp"
#include <QString>
#include <QMap>
#include <QMessageBox>

/*!\file*/

using JSON = nlohmann::json;

bool exists(const JSON& json, const std::string& key)
{
  return json.find(key) !=json.end();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer::singleShot(0, this, SLOT(startWSClient()));
    m_webSocket = std::make_shared<ix::WebSocket>();

    ui->ButtonProveedores->setEnabled(false);
    ui->ButtonProductos->setEnabled(false);
    ui->ButtonUsuarios->setEnabled(false);
    ui->ButtonFacturas->setEnabled(false);
    ui->ButtonPedidos->setEnabled(false);
}

MainWindow::~MainWindow()
{
    m_webSocket->stop();
    delete ui;
}

/**
 *  inicio del WS Cliente
 */
void MainWindow::startWSClient()
{
    //m_webSocket->setUrl(std::string("wss://localhost:9990"));
     m_webSocket->setUrl(std::string("ws://localhost:9990"));
    ix::SocketTLSOptions tlsOptions;
    tlsOptions.tls =true;
    tlsOptions.certFile = "NONE";
    tlsOptions.keyFile = "NONE";
    tlsOptions.caFile ="/home/moha/Escritorio/WebSocket_Mohammed/cert/myCA.pem";

    if(tlsOptions.isValid())
    {
       std::cerr <<"SSL valid"<< std::endl;
    }
   // m_webSocket->setTLSOptions(tlsOptions);


    m_webSocket->setOnMessageCallback([this](const ix::WebSocketMessagePtr& msg)
     {

        if (msg->type == ix::WebSocketMessageType::Open)
        {
            std::cout << "conexion con el Servidor" << std::endl;

        }
        else if (msg->type == ix::WebSocketMessageType::Close)
        {
            std::cout << "Bye bye connection" << std::endl;
        }
         if (msg->type == ix::WebSocketMessageType::Message)
         {
             //  std::cout << msg->str << std::endl;

             if (!msg->binary)
             {
                 /// Text format
            // std::cout << "Received message: " << msg->str << std::endl;
             }

            JSON receivedObject = JSON::parse(msg->str, nullptr,false);
             if(receivedObject.is_discarded())
             {
               std::cout << receivedObject.is_discarded() << std::endl;
             }
             else
             {

                 if (exists(receivedObject,"type"))
                 {
                    Cliente cliente;
                    cliente.setMainWindow(this);
                    std::string action =receivedObject["type"];

                        if (action == "BuscarCliente")
                        {
                          JSON respuesta = receivedObject["BuscarCliente"];

                             int idWsCliente = receivedObject["idWsCliente"];
                             int idcliente = respuesta["id"];

                             qDebug()<< "----idWSCliente_recibido";
                             qDebug()<<idcliente;
                             qDebug()<<"-------------------------";

                             auto element {m_actions.find(idWsCliente)};

                                 if (element != m_actions.end())
                                    {
                                        std::cout << "Executing action id: " << idWsCliente << std::endl;
                                        cliente.VerRespuesta(respuesta);
                                        m_actions.erase(element);
                                        std::cout << "Num actions: " << m_actions.size() << std::endl;
                                    }
                                else
                                    {
                                        std::cout << "Action not found" << std::endl;
                                    } // end if

                        }
                        if (action == "ClienteCreado")
                        {
                          JSON respuesta = receivedObject["ClienteCreado"];
                          cliente.VerRespuesta(respuesta);
                        }
                        if (action == "ClienteBorrado")
                        {
                          JSON respuesta = receivedObject["ClienteBorrado"];
                          cliente.respuestaBorrarCliente(respuesta);
                        }

                        if (action == "ClienteModificado")
                        {
                          JSON respuesta = receivedObject["ClienteModificado"];

                          cliente.VerRespuesta(respuesta);


                        }
                 }

                else
                {
                   // std::cout << " No hay mensaje " << std::endl;
                }//fin if*/
             }//fin if
         } //fin if
     }
     );


     m_webSocket->connect(100);
     m_webSocket->send("funciona!");
     m_webSocket->start();
}

void MainWindow::on_ButtonCliente_clicked()
{
    clienteview = new ClienteView (this);
    clienteview->setMainWindow(this);
    clienteview->setWebSocket(m_webSocket);
    clienteview->show();
    this->window();




}


ClienteView* MainWindow::clienteView()
{
    return clienteview;
}
