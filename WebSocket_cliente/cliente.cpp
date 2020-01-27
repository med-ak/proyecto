#include "cliente.h"
#include "ui_cliente.h"
#include "json.hpp"
#include <QString>
#include <QDebug>
#include "mainwindow.h"

using JSON = nlohmann::json;

Cliente::Cliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cliente)
{
    ui->setupUi(this);
}

Cliente::~Cliente()
{
    delete ui;
}

void Cliente::setWebSocket(std::shared_ptr<ix::WebSocket> webSocket)
{
    m_webSocket = webSocket;
}

void Cliente::on_ButtonBuscar_clicked()
{
    txtID = ui->txt_id->text().toInt();
    qDebug()<< txtID;
    JSON jsonMessage = {{"action","BuscarCliente"},{"id",txtID}};
    std::string messageToSend = jsonMessage.dump();
    m_webSocket->send(messageToSend);

}
