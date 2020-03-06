#include <iostream>
#include "cliente.h"
#include "json.hpp"
#include <QString>
#include <QDebug>
#include "mainwindow.h"
#include <QTimer>
#include "clienteview.h"
#include <QMessageBox>

/*!\file*/
/////////////////////////////////////////////////
/// ... Este Clase se encarga de reciber los datos en JSON y enviarlos a la Tabla...
/////////////////////////////////////////////////

using JSON = nlohmann::json;
int Cliente::newMessageId()
{
    return ++m_sendMessageCounter;
}
void Cliente::VerRespuesta(JSON respuesta)
{
    DatosCliente datosCliente;

    datosCliente.c_idCliente = respuesta["id"];
    datosCliente.c_nombre = QString::fromStdString(respuesta["nombre"]);
    datosCliente.c_apellidos = QString::fromStdString(respuesta["apellidos"]);
    datosCliente.c_dni = QString::fromStdString(respuesta["dni"]);
    datosCliente.c_telefono = QString::fromStdString(respuesta["telefono"]);
    datosCliente.c_email = QString::fromStdString(respuesta["email"]);
    if(datosCliente.c_idCliente==0)
    {
     m_mainWindow->clienteView()->mensajeErrorSignal("Ya no existe este cliente.");
    }else
    {
     m_mainWindow->clienteView()->rellenarTabla(datosCliente);
    }

}


void Cliente::respuestaBorrarCliente(JSON respuesta)
{

    int  idCliente = respuesta["id"];

    if(idCliente > 0)
    {
     m_mainWindow->clienteView()->mensajeError("El cliente ha sido borrado correctamente.");
    }

}


/**
 * @brief Constructor Cliente
 */
Cliente::Cliente()
{

}

void Cliente::setWebSocket(std::shared_ptr<ix::WebSocket> webSocket)
{
    m_webSocket = webSocket;
}


void Cliente::setMainWindow(MainWindow *mainWindow)
{
    m_mainWindow = mainWindow;
}




