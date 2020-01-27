#ifndef PEDIDOS_H
#define PEDIDOS_H

#include <QDialog>

namespace Ui {
class pedidos;
}

class pedidos : public QDialog
{
    Q_OBJECT

public:
    explicit pedidos(QWidget *parent = nullptr);
    ~pedidos();

private slots:
    void on_pushButton_clicked();

private:
    Ui::pedidos *ui;
};

#endif // PEDIDOS_H
