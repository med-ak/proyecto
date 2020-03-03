#include "cliente.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include "json.hpp"
#include "ixwebsocket/IXWebSocketServer.h"
#include "ixwebsocket/IXWebSocket.h"
#include "ixwebsocket/IXConnectionState.h"

using JSON = nlohmann::json;

/*!\file*/

static int g_idMensaje =0;
void Cliente::getDatabase(){


}

int dameIdMensaje(){
    /**
     * funcion que duelve el ID . para el Servidor
     */
    g_idMensaje++;
    return g_idMensaje;
}

/*!\file*/
JSON Cliente::Buscar_cliente(QSqlDatabase db , JSON receivedObject){
    /**
     * funcion que duelve los datos de cliente en formato JSON
     */
    JSON respuesta;
    int Loadid=receivedObject["id"];


    qDebug() << "ID: " << Loadid;
    Cliente c;
    c.load(db , Loadid);
    JSON datos;

       datos["id"] = c.m_idCliente;
       datos["nombre"] = c.m_nombre.toStdString();
       datos["apellidos"] = c.m_apellidos.toStdString();
       datos["dni"] = c.m_dni.toStdString();
       datos["telefono"] = c.m_telefono.toStdString();
       datos["email"] = c.m_email.toStdString();
       respuesta["idServidor"]= dameIdMensaje();
       respuesta["idWsCliente"]=receivedObject["idWsCliente"];
       respuesta["type"]= "BuscarCliente";
       respuesta["BuscarCliente"] = datos;


    return  respuesta;
}


/*!\file*/
JSON Cliente::anyadir_cliente(QSqlDatabase db, JSON receivedObject){
    /**
     * funcion para añadir el cliente y luego duelve sus datos en formato JSON
     */
    JSON respuesta;

    QString nombreRecibido=QString::fromStdString(receivedObject["nombre"]);
    QString apellidosRecibido=QString::fromStdString(receivedObject["apellidos"]);
    QString dniRecibido=QString::fromStdString(receivedObject["dni"]);
    QString telefonoRecibido=QString::fromStdString(receivedObject["telefono"]);
    QString emailRecibido=QString::fromStdString(receivedObject["email"]);

    Cliente c;
    c.setCliente(nombreRecibido,apellidosRecibido,dniRecibido,telefonoRecibido,emailRecibido);
    c.save();

    c.loadMaxId();
    JSON datos;

    datos["id"] = c.m_idCliente;
    datos["nombre"] = c.m_nombre.toStdString();
    datos["apellidos"] = c.m_apellidos.toStdString();
    datos["dni"] = c.m_dni.toStdString();
    datos["telefono"] = c.m_telefono.toStdString();
    datos["email"] = c.m_email.toStdString();
    respuesta["idServidor"]= dameIdMensaje();

    respuesta["idWsCliente"]=receivedObject["idWsCliente"];
    respuesta["type"]="ClienteCreado";
    respuesta["ClienteCreado"] = datos;
    return  respuesta;
}

JSON Cliente::Modificar_cliente(QSqlDatabase db,JSON receivedObject){
    /**
     * funcion para modificar los datos de cliente
     */

    JSON respuesta;
    int idClienteRecibido=receivedObject["id"];
    QString nombreRecibido=QString::fromStdString(receivedObject["nombre"]);
    QString apellidosRecibido=QString::fromStdString(receivedObject["apellidos"]);
    QString dniRecibido=QString::fromStdString(receivedObject["dni"]);
    QString telefonoRecibido=QString::fromStdString(receivedObject["telefono"]);
    QString emailRecibido=QString::fromStdString(receivedObject["email"]);


    Cliente c;
    c.updateCliente(idClienteRecibido,nombreRecibido,apellidosRecibido,dniRecibido,telefonoRecibido,emailRecibido);
    c.save();
    c.load(db ,idClienteRecibido);

    JSON datos;

    datos["id"] = c.m_idCliente;
    datos["nombre"] = c.m_nombre.toStdString();
    datos["apellidos"] = c.m_apellidos.toStdString();
    datos["dni"] = c.m_dni.toStdString();
    datos["telefono"] = c.m_telefono.toStdString();
    datos["email"] = c.m_email.toStdString();
    respuesta["idServidor"]= dameIdMensaje();
    respuesta["idWsCliente"]=receivedObject["idWsCliente"];
    respuesta["type"]="ClienteModificado";
    respuesta["ClienteModificado"] = datos;
    return  respuesta;
}

JSON Cliente::Borrar_cliente(QSqlDatabase db  , JSON receivedObject){
    /**
     * funcion para borrar el cliente
     */
    JSON respuesta;
    int Loadid=receivedObject["id"];
    qDebug() << "ID: " << Loadid;
    Cliente c;
    c.load(db , Loadid);
    c.remove();
    c.load(db , Loadid);
    JSON datos;

    datos["id"] = c.m_idCliente;
    respuesta["idServidor"]= dameIdMensaje();
    respuesta["idWsCliente"]=receivedObject["idWsCliente"];
    respuesta["type"]= "BorrarCliente";
    respuesta["BorrarCliente"] = datos;
    return  respuesta;
}

Cliente::Cliente()
{
}
/**
 * funcion para buscar el cliente (recibe el id y me devuelve datos de cliente) desde  bbdd
 */
void Cliente::load(QSqlDatabase db  , int id)
{
    QSqlQuery q(db);
    q.prepare("SELECT * FROM venta.clientes WHERE id_cliente = :idCliente LIMIT 1");
    q.bindValue(":idCliente", id);
    bool result {q.exec()};

    if (result)
    {
        q.next();
         m_idCliente = q.value("id_cliente").toInt();
         m_nombre = q.value("Nombre").toString();
         m_apellidos = q.value("Apellidos").toString();
         m_dni = q.value("dni").toString();
         m_telefono = q.value("Telefono").toString();
         m_email = q.value("Email").toString();

    } // end if
}
/**
 * funcion para buscar el cliente (me devuelve ultimo cliente que se ha insertado) desde bbdd
 */
void Cliente::loadMaxId()
{
    QSqlQuery q;
    q.prepare("SELECT * FROM venta.clientes ORDER BY id_cliente DESC LIMIT 1");
    bool result {q.exec()};

    if (result)
    {
        q.next();
         m_idCliente = q.value("id_cliente").toInt();
         m_nombre = q.value("Nombre").toString();
         m_apellidos = q.value("Apellidos").toString();
         m_dni = q.value("dni").toString();
         m_telefono = q.value("Telefono").toString();
         m_email = q.value("Email").toString();

    } // end if
}

/**
 * borrar cliente en bbdd
 */
bool Cliente::remove()
{
    QSqlQuery q;
    bool result {false};

    if (m_idCliente > 0)
    {
        q.prepare("DELETE FROM venta.clientes WHERE id_cliente = :idCliente");
        q.bindValue(":idCliente", m_idCliente);
        result = q.exec();
    } // end if
    qDebug() << "mensajeBorrarCliente" << result;
    return result;

}

void Cliente::setCliente(QString Nombre,QString Apellidos,QString DNI,QString Telefono,QString Email)
{
    m_nombre = Nombre;
    m_apellidos = Apellidos;
    m_dni = DNI;
    m_telefono = Telefono;
    m_email = Email;
}
void Cliente::updateCliente(int id_Cliente,QString Nombre,QString Apellidos,QString DNI,QString Telefono,QString Email)
{
    m_idCliente= id_Cliente;
    m_nombre = Nombre;
    m_apellidos = Apellidos;
    m_dni = DNI;
    m_telefono = Telefono;
    m_email = Email;
}

/**
 * funcion para insertar (en caso de que id_cliente=0) y modificar (en caso de que id_cliente>0) en  bbdd
 */
bool Cliente::save()
{
    QSqlQuery q;

    if (m_idCliente > 0)
    {
        qDebug() << "save update";
        /// UPDATE
        q.prepare("UPDATE venta.clientes SET nombre = :Nombre, apellidos = :Apellidos, dni = :DNI , telefono = :Telefono, email = :Email WHERE id_cliente = :idCliente");
        q.bindValue(":idCliente", m_idCliente);
        q.bindValue(":Nombre", m_nombre);
        q.bindValue(":Apellidos", m_apellidos);
        q.bindValue(":DNI", m_dni);
        q.bindValue(":Telefono", m_telefono);
        q.bindValue(":Email", m_email);
    }
    else
    {
        qDebug() << "save insert";
        /// INSERT
        q.prepare("INSERT INTO venta.clientes (nombre,apellidos,dni,telefono,email) VALUES (:Nombre,:Apellidos,:DNI,:Telefono,:Email)");
        q.bindValue(":Nombre", m_nombre);
        q.bindValue(":Apellidos", m_apellidos);
        q.bindValue(":DNI", m_dni);
        q.bindValue(":Telefono", m_telefono);
        q.bindValue(":Email", m_email);
    } // end if

    bool result {q.exec()};
    return result;
}



