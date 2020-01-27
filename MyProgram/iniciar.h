#ifndef INICIAR_H
#define INICIAR_H

#include <QDialog>
#include"mainwindow.h"

namespace Ui {
class Iniciar;
}

class Iniciar : public QDialog
{
    Q_OBJECT

public:
    explicit Iniciar(QWidget *parent = nullptr);
    ~Iniciar();
    int web();

private slots:
    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

private:
    Ui::Iniciar *ui;
    MainWindow *mainwindow;
};

#endif // INICIAR_H
