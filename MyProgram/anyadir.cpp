#include "anyadir.h"
#include "ui_anyadir.h"

anyadir::anyadir(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::anyadir)
{
    ui->setupUi(this);
}

anyadir::~anyadir()
{
    delete ui;
}

void anyadir::on_pushButton_3_clicked()
{
     close();
}
