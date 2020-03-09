#ifndef CLIENTEVIEW_H
#define CLIENTEVIEW_H

#include "cliente.h"

#include <QDialog>
#include <QTableWidgetItem>

namespace Ui {
class ClienteView;
}

class ClienteView : public QDialog, public Cliente
{
   Q_OBJECT

public:
    explicit ClienteView(QWidget *parent = nullptr);
    ~ClienteView();

    void mensajeErrorSignal(QString mensaje);

private:
    Ui::ClienteView *ui;
    QTimer *timer;


public slots:

    void on_ButtonBuscar_clicked();
    void on_ButtonAnyadir_clicked();
    void on_ButtonBorrar_clicked();
    void on_ButtonModificar_clicked();
    void rellenarTabla(DatosCliente datosCliente);
    void mensajeError(QString mensaje);


signals:
    void mensajeErrorS(QString mensaje);

private slots:

    void on_pushButtonLimpar_clicked();
    void on_pushButtonVolver_clicked();
    void on_tablaCliente_itemClicked(QTableWidgetItem *item);
    void comprobarParaBuscarYmodificar(const QString &text);



private:
    MainWindow *mainwindow;
    int intID =0;
    std::string txtNombre {""};
    std::string txtApellidos {""};
    std::string txtDni {""};
    std::string txtTelefono{""};
    std::string txtEmail {""};
    void clear();
    void limpiarTabla();



};

#endif // CLIENTEVIEW_H
