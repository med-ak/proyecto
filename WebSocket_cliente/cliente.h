#ifndef CLIENTE_H
#define CLIENTE_H

#include <memory>
#include "ixwebsocket/IXWebSocket.h"
#include "ixwebsocket/IXSocketOpenSSL.h"
#include "json.hpp"
#include <map>
#include <functional>
#include <QString>


class MainWindow;

using JSON = nlohmann::json;

struct DatosCliente
{
    int c_idCliente;
    QString c_nombre;
    QString c_apellidos;
    QString c_dni;
    QString c_telefono;
    QString c_email;
};


class Cliente
{
public:

    std::shared_ptr<ix::WebSocket> m_webSocket;
    void setWebSocket(std::shared_ptr<ix::WebSocket> webSocket);

    MainWindow *m_mainWindow {nullptr};
    void setMainWindow(MainWindow *mainWindow);


    Cliente();

    
    int m_sendMessageCounter {0};
    int newMessageId();


    void VerRespuesta(JSON respuesta);
    void RespuestaBorrarCliente(JSON respuesta);

    void respuestaLista(DatosCliente);

};

#endif // CLIENTE_H
