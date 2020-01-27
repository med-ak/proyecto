#include "ayadirus.h"
#include "ui_ayadirus.h"

ayadirus::ayadirus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ayadirus)
{
    ui->setupUi(this);
}

ayadirus::~ayadirus()
{
    delete ui;
}

void ayadirus::on_pushButton_3_clicked()
{
    close();
}
