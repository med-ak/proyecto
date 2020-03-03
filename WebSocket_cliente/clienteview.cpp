#include "clienteview.h"
#include "ui_clienteview.h"
#include <QDebug>
#include <QTimer>
#include <memory>
#include "mainwindow.h"
#include <QMessageBox>
#include <QMetaType>

/*!\file*/

/////////////////////////////////////////////////
/// ... Este Clase se encarga de interfaz, heredada de clase Cliente...
/////////////////////////////////////////////////

ClienteView::ClienteView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClienteView)
{
    ui->setupUi(this);

}

ClienteView::~ClienteView()
{
    delete ui;
}


void ClienteView::rellenarTabla(DatosCliente datosCliente)
{
    qRegisterMetaType<QVector<int>>();



    if(datosCliente.c_idCliente==0)
     {
        qDebug()<<"No existe ningún cliente con este ID.";
        /*QMessageBox msgBox;
        msgBox.setText("No existe ningún cliente con este ID.");
        msgBox.setMinimumWidth(500);
        msgBox.setMinimumHeight(200);
        msgBox.exec();*/

        ui->labelinfo->setText("No existe ningún cliente con este ID.");
     }
    if (datosCliente.c_idCliente > 0)
    {
           ui->tablaCliente->setColumnCount(6);
           ui->tablaCliente->setRowCount(0);
           QStringList l;
           l<<"ID"<<"Nombre"<<"Apellidos"<<"Dni"<<"Telefono"<<"Email";
           ui->tablaCliente->setHorizontalHeaderLabels(l);
           ui->tablaCliente->setColumnWidth(0,110);
           ui->tablaCliente->setColumnWidth(1,200);
           ui->tablaCliente->setColumnWidth(2,200);
           ui->tablaCliente->setColumnWidth(3,200);
           ui->tablaCliente->setColumnWidth(4,200);
           ui->tablaCliente->setColumnWidth(5,200);

        ui->tablaCliente->insertRow(ui->tablaCliente->rowCount());
        int fila = ui->tablaCliente->rowCount() -1;
        ui->tablaCliente->setItem(fila,0, new QTableWidgetItem (QString::number(datosCliente.c_idCliente)) );
        ui->tablaCliente->setItem(fila,1, new QTableWidgetItem (datosCliente.c_nombre) );
        ui->tablaCliente->setItem(fila,2, new QTableWidgetItem (datosCliente.c_apellidos) );
        ui->tablaCliente->setItem(fila,3, new QTableWidgetItem (datosCliente.c_dni) );
        ui->tablaCliente->setItem(fila,4, new QTableWidgetItem (datosCliente.c_email) );
        ui->tablaCliente->setItem(fila,5, new QTableWidgetItem (datosCliente.c_telefono));
    }
}


void ClienteView::on_ButtonBuscar_clicked()
{
    ui->labelinfo->setText("");
    ui->ButtonBuscar->setIcon(QIcon("buscar.png"));
     txtID = ui->txt_id->text().toInt();
    int messageId {newMessageId()};
    JSON jsonMessage = {
                        {"action","BuscarCliente"},
                        {"idWsCliente",messageId},
                        {"id",txtID}
                        };
    qDebug()<< "-----------------idWSCliente_Enviado";
    qDebug()<< messageId;
    qDebug()<< "------------------------------------";

        m_mainWindow->m_actions[messageId] = [this](JSON respuesta){
        VerRespuesta(respuesta);
        };
    std::string messageToSend = jsonMessage.dump();
    m_webSocket->send(messageToSend);
   clear();
}


void ClienteView::on_ButtonBorrar_clicked()
{
    txtID = ui->txt_id->text().toInt();
    qDebug()<< txtID;
    JSON jsonMessage = {
                        {"action","BorrarCliente"},
                        {"idWsCliente",newMessageId()},
                        {"id",txtID}
                       };

    std::string messageToSend = jsonMessage.dump();
    m_webSocket->send(messageToSend);
    clear();

}


void ClienteView::on_ButtonAnyadir_clicked()
{
    txtNombre = ui->txt_nombre->text().toStdString();
    txtApellidos = ui->txt_apellidos->text().toStdString();
    txtDni = ui->txt_dni->text().toStdString();
    txtTelefono = ui->txt_telefono->text().toStdString();
    txtEmail = ui->txt_email->text().toStdString();

    JSON jsonMessage = {
                        {"action","AnyadirCliente"},
                        {"idWsCliente",newMessageId()},
                        {"nombre",txtNombre},
                        {"apellidos",txtApellidos},
                        {"dni",txtDni},
                        {"telefono",txtTelefono},
                        {"email",txtEmail}
                        };

    std::string messageToSend = jsonMessage.dump();
    m_webSocket->send(messageToSend);
    clear();
}


void ClienteView::on_ButtonModificar_clicked()
{
    txtID = ui->txt_id->text().toInt();
    txtNombre = ui->txt_nombre->text().toStdString();
    txtApellidos = ui->txt_apellidos->text().toStdString();
    txtDni = ui->txt_dni->text().toStdString();
    txtTelefono = ui->txt_telefono->text().toStdString();
    txtEmail = ui->txt_email->text().toStdString();

    JSON jsonMessage = {
                        {"action","ModificarCliente"},
                        {"idWsCliente",newMessageId()},
                        {"idcliente",txtID},
                        {"nombre",txtNombre},
                        {"apellidos",txtApellidos},
                        {"dni",txtDni},
                        {"telefono",txtTelefono},
                        {"email",txtEmail}
                        };
    std::string messageToSend = jsonMessage.dump();
    m_webSocket->send(messageToSend);
    clear();
}

void ClienteView::clear()
{
    ui->txt_id->clear();
    ui->txt_nombre->clear();
    ui->txt_apellidos->clear();
    ui->txt_dni->clear();
    ui->txt_telefono->clear();
    ui->txt_email->clear();

}

