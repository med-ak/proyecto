#ifndef ANYADIR_H
#define ANYADIR_H

#include <QDialog>

namespace Ui {
class anyadir;
}

class anyadir : public QDialog
{
    Q_OBJECT

public:
    explicit anyadir(QWidget *parent = nullptr);
    ~anyadir();

private slots:
    void on_pushButton_2_windowIconChanged(const QIcon &icon);

    void on_pushButton_3_clicked();

private:
    Ui::anyadir *ui;
};

#endif // ANYADIR_H
