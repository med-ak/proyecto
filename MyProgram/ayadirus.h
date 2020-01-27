#ifndef AYADIRUS_H
#define AYADIRUS_H

#include <QDialog>

namespace Ui {
class ayadirus;
}

class ayadirus : public QDialog
{
    Q_OBJECT

public:
    explicit ayadirus(QWidget *parent = nullptr);
    ~ayadirus();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::ayadirus *ui;
};

#endif // AYADIRUS_H
