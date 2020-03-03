/********************************************************************************
** Form generated from reading UI file 'cliente.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTE_H
#define UI_CLIENTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Cliente
{
public:
    QPushButton *ButtonBorrar;
    QTableWidget *tablaCliente;
    QPushButton *ButtonBuscar;
    QPushButton *ButtonAnyadir;
    QLabel *id;
    QLineEdit *txt_id;
    QPushButton *ButtonModificar;

    void setupUi(QDialog *Cliente)
    {
        if (Cliente->objectName().isEmpty())
            Cliente->setObjectName(QStringLiteral("Cliente"));
        Cliente->resize(1276, 604);
        ButtonBorrar = new QPushButton(Cliente);
        ButtonBorrar->setObjectName(QStringLiteral("ButtonBorrar"));
        ButtonBorrar->setGeometry(QRect(960, 250, 200, 43));
        QFont font;
        font.setPointSize(15);
        ButtonBorrar->setFont(font);
        tablaCliente = new QTableWidget(Cliente);
        if (tablaCliente->rowCount() < 1)
            tablaCliente->setRowCount(1);
        tablaCliente->setObjectName(QStringLiteral("tablaCliente"));
        tablaCliente->setGeometry(QRect(10, 390, 1181, 121));
        tablaCliente->setFont(font);
        tablaCliente->setFrameShape(QFrame::StyledPanel);
        tablaCliente->setFrameShadow(QFrame::Plain);
        tablaCliente->setLineWidth(0);
        tablaCliente->setMidLineWidth(0);
        tablaCliente->setShowGrid(true);
        tablaCliente->setSortingEnabled(true);
        tablaCliente->setRowCount(1);
        tablaCliente->setColumnCount(0);
        tablaCliente->horizontalHeader()->setDefaultSectionSize(140);
        ButtonBuscar = new QPushButton(Cliente);
        ButtonBuscar->setObjectName(QStringLiteral("ButtonBuscar"));
        ButtonBuscar->setGeometry(QRect(340, 230, 337, 43));
        ButtonBuscar->setFont(font);
        ButtonAnyadir = new QPushButton(Cliente);
        ButtonAnyadir->setObjectName(QStringLiteral("ButtonAnyadir"));
        ButtonAnyadir->setGeometry(QRect(960, 80, 200, 43));
        ButtonAnyadir->setMinimumSize(QSize(200, 0));
        ButtonAnyadir->setFont(font);
        id = new QLabel(Cliente);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(190, 160, 121, 43));
        id->setFont(font);
        txt_id = new QLineEdit(Cliente);
        txt_id->setObjectName(QStringLiteral("txt_id"));
        txt_id->setGeometry(QRect(340, 160, 337, 41));
        ButtonModificar = new QPushButton(Cliente);
        ButtonModificar->setObjectName(QStringLiteral("ButtonModificar"));
        ButtonModificar->setGeometry(QRect(960, 170, 200, 43));
        ButtonModificar->setFont(font);

        retranslateUi(Cliente);

        QMetaObject::connectSlotsByName(Cliente);
    } // setupUi

    void retranslateUi(QDialog *Cliente)
    {
        Cliente->setWindowTitle(QApplication::translate("Cliente", "Dialog", Q_NULLPTR));
        ButtonBorrar->setText(QApplication::translate("Cliente", "Borrar", Q_NULLPTR));
        ButtonBuscar->setText(QApplication::translate("Cliente", "Buscar", Q_NULLPTR));
        ButtonAnyadir->setText(QApplication::translate("Cliente", "A\303\261adir", Q_NULLPTR));
        id->setText(QApplication::translate("Cliente", "ID", Q_NULLPTR));
        ButtonModificar->setText(QApplication::translate("Cliente", "Modificar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Cliente: public Ui_Cliente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTE_H
