#include "cliente.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include "json.hpp"
#include "ixwebsocket/IXWebSocketServer.h"
#include "ixwebsocket/IXWebSocket.h"
#include "ixwebsocket/IXConnectionState.h"

using JSON = nlohmann::json;

Cliente::Cliente()
{
}

void Cliente::load(int id)
{
    QSqlQuery q;
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

bool Cliente::save()
{
    QSqlQuery q;

    if (m_idCliente > 0)
    {
        qDebug() << "save update";
        /// UPDATE
        q.prepare("UPDATE venta.clientes SET nombre = :_nombre WHERE id_cliente = :idCliente");
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


