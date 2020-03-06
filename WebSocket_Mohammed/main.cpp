#include <iostream>
#include "ixwebsocket/IXWebSocketServer.h"
#include "ixwebsocket/IXWebSocket.h"
#include "ixwebsocket/IXConnectionState.h"
#include "ixwebsocket/IXSocketTLSOptions.h"
#include "ixwebsocket/IXSocketOpenSSL.h"
#include "json.hpp"
#include <QSqlError>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include "cliente.h"
#include "Conexion.h"

/*!\file*/

using JSON = nlohmann::json;

static QSqlDatabase db;
bool exists(const JSON& json, const std::string& key){
    return json.find(key) !=json.end();
}

/**
 * funcion principal del programa
 */

int main()
{

    ///conexion con la base de datos
    Conexion c;

   /* db = QSqlDatabase::addDatabase("QPSQL");

    db.setHostName("localhost");
    db.setDatabaseName("venta");
    db.setPort(5432);
    db.setUserName("postgres");
    db.setPassword("");*/
    bool ok = c.open();
    qDebug()<< ok;
   // qDebug()<< c.lastError().text();

   if (ok)
       {
            qDebug()<<" conexion con BBDD ";
        } else {
            qDebug()<<" ERROR en  conexion con BBDD : verifica el archivo bbdd.conf";
        }// fin_if

   /// Servidor WebSocket
    ix::WebSocketServer server(9990, "0.0.0.0");

   /// SSL
     ix::SocketTLSOptions tlsOptions;
   tlsOptions.tls =true;
    tlsOptions.certFile = "../WebSocket_Mohammed/cert/localhost.crt";
    tlsOptions.keyFile = "../WebSocket_Mohammed/cert/localhost.key";
    tlsOptions.caFile = "NONE";


  if(tlsOptions.isValid()){
  std::cerr <<"SSL valid"<< std::endl;
  }

  //server.setTLSOptions(tlsOptions);

  /**
   *  funcion lambda: enviar y recibir mensajes JSON
   */

    server.setOnConnectionCallback(
        [&server](std::shared_ptr<ix::WebSocket> webSocket,
                  std::shared_ptr<ix::ConnectionState> connectionState)
        {
            webSocket->setOnMessageCallback(
                [webSocket, connectionState, &server](const ix::WebSocketMessagePtr msg)
                {

                    if (msg->type == ix::WebSocketMessageType::Open)
                    {
                        std::cout << "conexion con el cliente" << std::endl;

                    }
                    else if (msg->type == ix::WebSocketMessageType::Close)
                    {
                        std::cout << "Bye bye connection" << std::endl;
                    }
                    else if (msg->type == ix::WebSocketMessageType::Message)
                    {
                        if (!msg->binary)
                        {

                            std::cout << "Received message: " << msg->str << std::endl;
                        }
                            // webSocket->send(msg->str, msg->binary);
                        JSON receivedObject = JSON::parse(msg->str, nullptr,false);

                        if(receivedObject.is_discarded())
                         {
                          //  std::cout << "error" << std::endl;
                         }
                         else
                         {
                             if (exists(receivedObject,"action"))
                             {
                                    Cliente cliente;
                                    std::string action =receivedObject["action"];
                                    if (action == "BuscarCliente")
                                    {

                                      JSON respuesta = cliente.Buscar_cliente(db , receivedObject);
                                      webSocket->send(respuesta.dump());

                                    }

                                    if (action == "AnyadirCliente")
                                    {

                                      JSON respuesta = cliente.anyadir_cliente(db , receivedObject);
                                      webSocket->send(respuesta.dump());

                                    }
                                    if (action == "BorrarCliente")
                                    {

                                      JSON respuesta = cliente.Borrar_cliente(db , receivedObject);
                                      webSocket->send(respuesta.dump());

                                    }
                                    if (action == "ModificarCliente")
                                    {

                                      JSON respuesta = cliente.Modificar_cliente(db , receivedObject);
                                      webSocket->send(respuesta.dump());

                                    }
                              }
                              else
                              {
                                    std::cout << " error no hay mensaje " << std::endl;
                              }//fin if
                        }//fin if
                    }
                }
            );
        }
    );



    auto res = server.listen();
    if (!res.first)
    {
        return 1;
    }
    server.start();
    server.wait();
    server.stop();
}
