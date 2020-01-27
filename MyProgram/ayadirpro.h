#ifndef AYADIRPRO_H
#define AYADIRPRO_H

#include <QDialog>

namespace Ui {
class ayadirpro;
}

class ayadirpro : public QDialog
{
    Q_OBJECT

public:
    explicit ayadirpro(QWidget *parent = nullptr);
    ~ayadirpro();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::ayadirpro *ui;
};

#endif // AYADIRPRO_H
