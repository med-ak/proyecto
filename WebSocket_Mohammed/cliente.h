#include <QSqlDatabase>
#include <QString>
#include "json.hpp"
#ifndef CLIENTE_H
#define CLIENTE_H

using JSON = nlohmann::json;


class Cliente
{

public:

    static void getDatabase();
    int m_idCliente {0};
    QString m_nombre {""};
    QString m_apellidos {""};
    QString m_dni {""};
    QString m_telefono{""};
    QString m_email {""};

public:

    Cliente();
    void load(QSqlDatabase db ,int id);
    void loadMaxId();
    void loadAll();
    bool save();
    bool remove();
    bool validarID(int id_Cliente);

    void setCliente(QString Nombre,QString Apellidos,QString DNI,QString Telefono,QString Email);
    void updateCliente(int id,QString Nombre,QString Apellidos,QString DNI,QString Telefono,QString Email);
    JSON Buscar_cliente(QSqlDatabase db ,JSON receivedObject);
    JSON anyadir_cliente(QSqlDatabase db ,JSON receivedObject);
    JSON Borrar_cliente(QSqlDatabase db ,JSON receivedObject);
    JSON Modificar_cliente(QSqlDatabase db ,JSON receivedObject);

};

#endif
