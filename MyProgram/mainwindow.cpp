#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pedidos.h"
#include "anyadir.h"
#include "ayadirpro.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_20_clicked()
{
     close();
}


void MainWindow::on_btnNuevoPedido_clicked()
{
    pedido = new pedidos(this);
    pedido->show();
}

void MainWindow::on_anyadir_clicked()
{
    an = new anyadir(this);
    an->show();
}

void MainWindow::on_anyadir_4_clicked()
{
    an = new anyadir(this);
    an->show();
}

void MainWindow::on_anyadir_6_clicked()
{
    an = new anyadir(this);
    an->show();
}

void MainWindow::on_pushButton_16_clicked()
{
    an = new anyadir(this);
    an->show();
}

void MainWindow::on_pushButton_60_clicked()
{
    an = new anyadir(this);
    an->show();
}

void MainWindow::on_pushButton_7_clicked()
{
    an = new anyadir(this);
    an->show();
}

void MainWindow::on_pushButton_56_clicked()
{
    an = new anyadir(this);
    an->show();
}

void MainWindow::on_pushButton_clicked()
{
    close();
}

void MainWindow::on_anyadir_11_clicked()
{
    anu = new ayadirus(this);
    anu->show();
}

void MainWindow::on_pushButton_19_clicked()
{
    anu = new ayadirus(this);
    anu->show();
}

void MainWindow::on_pushButton_73_clicked()
{
    anu = new ayadirus(this);
    anu->show();
}

void MainWindow::on_anyadir_10_clicked()
{
    pedido = new pedidos(this);
    pedido->show();
}

void MainWindow::on_anyadir_5_clicked()
{
    anp = new ayadirpro(this);
    anp->show();
}

void MainWindow::on_pushButton_15_clicked()
{
    anp = new ayadirpro(this);
    anp->show();
}

void MainWindow::on_pushButton_58_clicked()
{
    anp = new ayadirpro(this);
    anp->show();
}
