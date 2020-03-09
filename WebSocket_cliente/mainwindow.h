#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ixwebsocket/IXWebSocket.h"
#include "ixwebsocket/IXSocketOpenSSL.h"
#include "cliente.h"
#include "clienteview.h"
#include <memory>
#include <map>
#include <functional>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    std::map<int, std::function<void(JSON)>> m_actions;

    std::shared_ptr<ix::WebSocket> m_webSocket;


 private slots:

    void startWSClient();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    JSON respuesta;
    ClienteView* clienteView();


private slots:

    void on_ButtonCliente_clicked();

    void on_pushButton_clicked();

private:

    Ui::MainWindow *ui;
    Cliente *cliente;
    ClienteView *clienteview;


};

#endif // MAINWINDOW_H
