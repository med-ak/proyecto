#include "anyadirusuarios.h"
#include "ui_anyadirusuarios.h"

anyadirUsuarios::anyadirUsuarios(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::anyadirUsuarios)
{
    ui->setupUi(this);
}

anyadirUsuarios::~anyadirUsuarios()
{
    delete ui;
}

void anyadirUsuarios::on_pushButton_3_clicked()
{
    close();
}
