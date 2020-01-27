#include <QSqlDatabase>
#include <QString>
#ifndef CLIENTE_H
#define CLIENTE_H


class Cliente
{

public:
    int m_idCliente {0};
    QString m_nombre {""};
    QString m_apellidos {""};
    QString m_dni {""};
    QString m_telefono{""};
    QString m_email {""};

public:
    Cliente();
    void load(int id);
    bool save();
    bool remove();
    void setCliente(QString Nombre,QString Apellidos,QString DNI,QString Telefono,QString Email);
};

#endif
