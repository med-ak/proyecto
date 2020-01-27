#include "pedidos.h"
#include "ui_pedidos.h"

pedidos::pedidos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pedidos)
{
    ui->setupUi(this);
}

pedidos::~pedidos()
{
    delete ui;
}

void pedidos::on_pushButton_clicked()
{
    close();
}
