#include <iostream>
#include "ixwebsocket/IXWebSocketServer.h"
#include "ixwebsocket/IXWebSocket.h"
#include "ixwebsocket/IXConnectionState.h"
#include "json.hpp"
#include <QSqlError>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include "cliente.h"

using JSON = nlohmann::json;
/*static int g_idMensaje =0;

int dameIdMensaje(){

    g_idMensaje++;
    return g_idMensaje;
}*/

bool exists(const JSON& json, const std::string& key){
    return json.find(key) !=json.end();
}


JSON Buscar_cliente(JSON receivedObject){

    JSON respuesta;
    int Loadid=receivedObject["id"];

    qDebug() << "ID: " << Loadid;
    Cliente c;
    c.load(Loadid);

    JSON datos;

    datos["id"] = c.m_idCliente;
    datos["nombre"] = c.m_nombre.toStdString();
    datos["apellidos"] = c.m_apellidos.toStdString();
    datos["dni"] = c.m_dni.toStdString();
    datos["telefono"] = c.m_telefono.toStdString();
    datos["email"] = c.m_email.toStdString();

    respuesta["responder"] = datos;
    return  respuesta;
}


int main(int argc, char *argv[])
{
    ///conexion con la base de datos
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("venta");
    db.setPort(5432);
    db.setUserName("postgres");
    db.setPassword("");
    bool ok = db.open();
    qDebug()<< ok;
    qDebug()<< db.lastError().text();

    /*if (ok)
    {
       Cliente c;
       c.load(4);
       c.setCliente("moha","aknioui","yyyyy","55555","dddd");
       c.save();
    } // end if*/

    /// Servidor WebSocket
  ix::WebSocketServer server(9990, "0.0.0.0");

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
                            /// Text format
                            std::cout << "Received message: " << msg->str << std::endl;
                        }
                            // webSocket->send(msg->str, msg->binary);
                        JSON receivedObject = JSON::parse(msg->str, nullptr,false);
                        if(receivedObject.is_discarded())
                         {
                            std::cout << "error" << std::endl;
                         }
                         else
                         {
                             if (exists(receivedObject,"action"))
                             {
                                    std::string action =receivedObject["action"];
                                    if (action == "BuscarCliente")
                                    {
                                      JSON respuesta= Buscar_cliente(receivedObject);
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
        // Error handling
        return 1;
    }
    server.start();
    server.wait();
    server.stop();

}
