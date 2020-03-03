#include "clienteview.h"
#include "ui_clienteview.h"

ClienteView::ClienteView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClienteView)
{
    ui->setupUi(this);
}

ClienteView::~ClienteView()
{
    delete ui;
}
