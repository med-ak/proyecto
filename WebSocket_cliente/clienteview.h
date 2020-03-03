#ifndef CLIENTEVIEW_H
#define CLIENTEVIEW_H

#include <QWidget>

namespace Ui {
class ClienteView;
}

class ClienteView : public QWidget
{
    Q_OBJECT

public:
    explicit ClienteView(QWidget *parent = nullptr);
    ~ClienteView();

private:
    Ui::ClienteView *ui;
};

#endif // CLIENTEVIEW_H
