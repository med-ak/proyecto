#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pedidos.h"
#include "anyadir.h"
#include "ayadirus.h"
#include "ayadirpro.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_20_clicked();

    void on_btnNuevoPedido_clicked();


    void on_anyadir_clicked();

    void on_anyadir_4_clicked();

    void on_anyadir_6_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_60_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_56_clicked();

    void on_pushButton_clicked();

    void on_anyadir_11_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_73_clicked();

    void on_anyadir_10_clicked();

    void on_anyadir_5_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_58_clicked();

private:
    Ui::MainWindow *ui;
    pedidos *pedido;
    anyadir *an;
    ayadirus *anu;
    ayadirpro *anp;


};
#endif // MAINWINDOW_H
