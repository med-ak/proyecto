#ifndef CLIENTE_H
#define CLIENTE_H

#include <QDialog>
#include <memory>
#include "ixwebsocket/IXWebSocket.h"
namespace Ui {
class Cliente;
}

class Cliente : public QDialog
{
    Q_OBJECT
    std::shared_ptr<ix::WebSocket> m_webSocket;

public:
    explicit Cliente(QWidget *parent = nullptr);
    ~Cliente();
    void setWebSocket(std::shared_ptr<ix::WebSocket> webSocket);

private slots:

    void on_ButtonBuscar_clicked();


private:
    Ui::Cliente *ui;
    int txtID =0;
};

#endif // CLIENTE_H
