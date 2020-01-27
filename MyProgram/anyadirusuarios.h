#ifndef ANYADIRUSUARIOS_H
#define ANYADIRUSUARIOS_H

#include <QWidget>

namespace Ui {
class anyadirUsuarios;
}

class anyadirUsuarios : public QWidget
{
    Q_OBJECT

public:
    explicit anyadirUsuarios(QWidget *parent = nullptr);
    ~anyadirUsuarios();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::anyadirUsuarios *ui;
};

#endif // ANYADIRUSUARIOS_H
