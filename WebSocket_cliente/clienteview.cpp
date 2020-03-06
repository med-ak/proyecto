#include "clienteview.h"
#include "ui_clienteview.h"
#include <QDebug>
#include <QTimer>
#include <memory>
#include "mainwindow.h"
#include <QMessageBox>
#include <QMetaType>
#include <QTableWidget>

/*!\file*/

/////////////////////////////////////////////////
/// ... Este Clase se encarga de la interfaz, heredada de clase Cliente...
/////////////////////////////////////////////////

ClienteView::ClienteView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClienteView)
{
    ui->setupUi(this);
    ui->ButtonBuscar->setEnabled(false);
    ui->ButtonBorrar->setEnabled(false);
    connect(ui->txt_id, SIGNAL(textChanged(const QString &)), this, SLOT(comprobarParaBuscarYmodificar(const QString &)));
    connect(this, SIGNAL(mensajeErrorS(QString)), this, SLOT(mensajeError(QString)));


}

ClienteView::~ClienteView()
{
    delete ui;
}
void ClienteView::comprobarParaBuscarYmodificar(const QString &text){

    if(text.isEmpty()){
      ui->ButtonBuscar->setEnabled(false);
       ui->ButtonBorrar->setEnabled(false);
      ui->ButtonAnyadir->setEnabled(true);
    }
    else
    {
    ui->ButtonBuscar->setEnabled(true);
    ui->ButtonBorrar->setEnabled(true);
    ui->ButtonAnyadir->setEnabled(false);
    }
}

void ClienteView::mensajeError(QString mensaje)
{
    QMessageBox msgBox;
    msgBox.setText(mensaje);
    msgBox.exec();
}


void ClienteView::mensajeErrorSignal(QString mensaje)
{
    emit mensajeErrorS(mensaje);
}


void ClienteView::rellenarTabla(DatosCliente datosCliente)
{

    qRegisterMetaType<QVector<int>>();
    qRegisterMetaType<Qt::Orientation>();


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

        ui->tablaCliente->setItem(0,0, new QTableWidgetItem (QString::number(datosCliente.c_idCliente)) );
        ui->tablaCliente->setItem(0,1, new QTableWidgetItem (datosCliente.c_nombre) );
        ui->tablaCliente->setItem(0,2, new QTableWidgetItem (datosCliente.c_apellidos) );
        ui->tablaCliente->setItem(0,3, new QTableWidgetItem (datosCliente.c_dni) );
        ui->tablaCliente->setItem(0,4, new QTableWidgetItem (datosCliente.c_email) );
        ui->tablaCliente->setItem(0,5, new QTableWidgetItem (datosCliente.c_telefono));

}


void ClienteView::on_ButtonBuscar_clicked()
{
    intID = ui->txt_id->text().toInt();
    if(intID > 0){
    int messageId {newMessageId()};
    JSON jsonMessage = {
                        {"action","BuscarCliente"},
                        {"idWsCliente",messageId},
                        {"id",intID}
                        };
    qDebug()<< "-----------------id";
    qDebug()<< intID;
    qDebug()<< "-------------------";

        m_mainWindow->m_actions[messageId] = [this](JSON respuesta){
        VerRespuesta(respuesta);
        };
    std::string messageToSend = jsonMessage.dump();
    m_webSocket->send(messageToSend);
    clear();
    }
}


void ClienteView::on_ButtonBorrar_clicked()
{
    intID = ui->txt_id->text().toInt();
    qDebug()<< intID;
    JSON jsonMessage = {
                        {"action","BorrarCliente"},
                        {"idWsCliente",newMessageId()},
                        {"idcliente",intID}
                       };

    std::string messageToSend = jsonMessage.dump();
    m_webSocket->send(messageToSend);
    clear();
    limpiarTabla();

}


void ClienteView::on_ButtonAnyadir_clicked()
{
    intID = ui->txt_id->text().toInt();
    txtNombre = ui->txt_nombre->text().toStdString();
    txtApellidos = ui->txt_apellidos->text().toStdString();
    txtDni = ui->txt_dni->text().toStdString();
    txtTelefono = ui->txt_telefono->text().toStdString();
    txtEmail = ui->txt_email->text().toStdString();

    if(intID==0 && txtNombre.size()>0 && txtApellidos.size()>0 && txtDni.size()>0 && txtTelefono.size()>0 && txtEmail.size()>0){

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
    }else
    {

         mensajeError("No se puede añadir el cliente: algun campo esta vacio ");

    }
}


void ClienteView::on_ButtonModificar_clicked()
{
    intID = ui->txt_id->text().toInt();
    txtNombre = ui->txt_nombre->text().toStdString();

    txtApellidos = ui->txt_apellidos->text().toStdString();
    txtDni = ui->txt_dni->text().toStdString();
    txtTelefono = ui->txt_telefono->text().toStdString();
    txtEmail = ui->txt_email->text().toStdString();


    if(intID>0 && txtNombre.size()>0 && txtApellidos.size()>0 && txtDni.size()>0 && txtTelefono.size()>0 && txtEmail.size()>0)
    {
    JSON jsonMessage = {
                        {"action","ModificarCliente"},
                        {"idWsCliente",newMessageId()},
                        {"idcliente",intID},
                        {"nombre",txtNombre},
                        {"apellidos",txtApellidos},
                        {"dni",txtDni},
                        {"telefono",txtTelefono},
                        {"email",txtEmail}
                        };
        std::string messageToSend = jsonMessage.dump();
        m_webSocket->send(messageToSend);
        clear();
     }else
     {
         mensajeError("No se puede modificar el cliente: algun campo esta vacio ");
     }
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

void ClienteView::on_tablaCliente_itemClicked(QTableWidgetItem *item)
{
    int f= item->row();
        QTableWidgetItem *idCliente = ui->tablaCliente->item(f,0);
        QTableWidgetItem *nombre = ui->tablaCliente->item(f,1);
        QTableWidgetItem *apellidos = ui->tablaCliente->item(f,2);
        QTableWidgetItem *dni = ui->tablaCliente->item(f,3);
        QTableWidgetItem *telefono = ui->tablaCliente->item(f,4);
        QTableWidgetItem *email = ui->tablaCliente->item(f,5);

        ui->txt_id->setText(idCliente->text());
        ui->txt_nombre->setText(nombre->text());
        ui->txt_apellidos->setText(apellidos->text());
        ui->txt_dni->setText(dni->text());
        ui->txt_telefono->setText(telefono->text());
        ui->txt_email->setText(email->text());

     }

void ClienteView::on_pushButtonSalir_clicked()
{
    this->hide();
    MainWindow w;
    w.show();

}
void ClienteView::limpiarTabla()
{
    ui->tablaCliente->removeRow(0);
}
void ClienteView::on_pushButtonLimpar_clicked()
{
    limpiarTabla();
}
