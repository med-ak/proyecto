#ifndef CLIENTEVIEW_H
#define CLIENTEVIEW_H

#include "cliente.h"
#include <QWidget>

namespace Ui {
class ClienteView;
}

class ClienteView : public QWidget, public Cliente
{
   Q_OBJECT

public:
    explicit ClienteView(QWidget *parent = nullptr);
    ~ClienteView();




private:
    Ui::ClienteView *ui;
    QTimer *timer;

public slots:

    void on_ButtonBuscar_clicked();
    void on_ButtonAnyadir_clicked();
    void on_ButtonBorrar_clicked();
    void on_ButtonModificar_clicked();
    void rellenarTabla(DatosCliente datosCliente);


private:

    int txtID =0;
    std::string txtNombre {""};
    std::string txtApellidos {""};
    std::string txtDni {""};
    std::string txtTelefono{""};
    std::string txtEmail {""};
    void clear();



};

#endif // CLIENTEVIEW_H
