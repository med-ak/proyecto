#include "app.h"
#include <QCoreApplication>
#include <QTimer>
#include <QDebug>
#include <QSqlQuery>

App::App(QObject *parent) : QObject(parent)
{
    QTimer::singleShot(0, this, SLOT(run()));
}


void App::run()
{
    qDebug() << "running...";

    m_context.run(); // run
    if (m_context.shouldExit())
    {
        QCoreApplication::quit();
    } // end if

}

Db::~Db()
{
    if (m_db.isOpen())
    {
        m_db.close();
    } // end if
}

bool Db::insert()
{
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO tabla (nombre_tabla) VALUES (:nombre_tabla)");
    query.bindValue(":nombre_tabla", "prueba");
    bool result = query.exec();
qDebug() << query.lastError().text();
    return result;
}

Db::Db()
{
    if (!QSqlDatabase::contains( "MyDb"))
    {
        m_db = QSqlDatabase::addDatabase("QPSQL", "MyDb");
    }
    else
    {
        m_db = QSqlDatabase::database("MyDb");
    } // end if
    m_db.setHostName("localhost");
    m_db.setPort(5432);
    m_db.setUserName("postgres");
    m_db.setPassword("");

}
QSqlDatabase Db::getDatabase(){
    return m_db;
}

void Db::close()
{
    m_db.close();
}

bool Db::init()
{
    bool result = 0;

    m_db.close();
    m_db.setDatabaseName("template1");

    bool ok = m_db.open();

    if (ok)
    {

        qDebug() << "Borrando...";

        QSqlQuery q0("DROP DATABASE IF EXISTS prueba_doctest", m_db);
        if (q0.lastError().type() == QSqlError::NoError)
        {
            qDebug() << "Creando...";
            QSqlQuery q1("CREATE DATABASE prueba_doctest", m_db);
            if (q1.lastError().type() == QSqlError::NoError)
            {
                m_db.close();
                m_db.setDatabaseName("prueba_doctest");
                m_db.open();

                /// Crea estructura en la base de datos
                QString sql {"CREATE TABLE cliente ( \
                    id_cliente     SERIAL, \
                    nombre    varchar(100), \
                    apellidos varchar(100), \
                    dni       varchar(40), \
                    telefono  varchar(40), \
                    email     varchar(40), \
                    PRIMARY KEY(id_tabla) \
                )"};

                qDebug() << "Iniciando...";
                QSqlQuery q2(sql, m_db);

                if (q2.lastError().type() == QSqlError::NoError)
                {
                    result = true;
                } // end if
            }
            else
            {
                qDebug() << "BB:" << m_db.lastError().text();
            } // end if

        }
        else
        {
            qDebug() << "AA:" << m_db.lastError().text();
        } // end if

    } // end if


    return result;
}

QSqlError Db::lastError()
{
    return m_db.lastError();
}

TEST_CASE("base datos #0")
{
    Db db;
    int ok = db.init();

    if (ok)
    {
        qDebug() << "DB UP AND RUNNING";

        SUBCASE("Insertar #0")
        {
            CHECK( db.insert() == true );
        }

        SUBCASE("Insertar #0")
        {
            CHECK( db.insert() == true );
        }
    }
    else
    {
        qDebug() << db.lastError().text();

    } // end if

}
TEST_CASE("anyadir_cliente #0")
{
    Db db;
    Cliente cliente;
    JSON datosCliente;
    datosCliente["nombre"] = "Moha";
    datosCliente["apellidos"] = "Aknioui";
    datosCliente["dni"] = "45555555c";
    datosCliente["telefono"] = "6666666";
    datosCliente["email"] = "Moha@gmail.com";
    int ok = db.init();

    if (ok)
    {
        cliente.anyadir_cliente(db.getDatabase(),datosCliente);
        cliente.load(db.getDatabase(),2);


    }
    else
    {
        qDebug() << db.lastError().text();

    } // end if

}


