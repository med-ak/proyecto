#ifndef APP_H
#define APP_H

#include "doctest.h"
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include "../WebSocket_Mohammed/cliente.h"

class Db
{
    QSqlDatabase m_db;

public:
    QSqlDatabase getDatabase();
    Db();
    ~Db();
    bool init();
    void close();
    QSqlError lastError();
    bool insert();
};

class App : public QObject
{
    Q_OBJECT

    doctest::Context m_context;

public:
    App(QObject *parent = nullptr);

public slots:

    void run();
};

#endif // APP_H
