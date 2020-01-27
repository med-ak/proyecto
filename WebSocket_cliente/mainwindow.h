#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ixwebsocket/IXWebSocket.h"

#include "cliente.h"
#include <memory>

//using JSON = nlohmann::json;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    std::shared_ptr<ix::WebSocket> m_webSocket;

 private slots:
    void startWSServer();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_ButtonCliente_clicked();

private:
    Ui::MainWindow *ui;
    Cliente *cliente;

};

#endif // MAINWINDOW_H
