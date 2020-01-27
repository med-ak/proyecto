#include "ayadirpro.h"
#include "ui_ayadirpro.h"

ayadirpro::ayadirpro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ayadirpro)
{
    ui->setupUi(this);
}

ayadirpro::~ayadirpro()
{
    delete ui;
}

void ayadirpro::on_pushButton_3_clicked()
{
    close();
}
