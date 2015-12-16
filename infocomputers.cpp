#include "mainwindow.h"
#include "infocomputers.h"
#include "ui_infocomputers.h"

InfoComputers::InfoComputers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoComputers)
{
    ui->setupUi(this);
}

InfoComputers::~InfoComputers()
{
    qDebug() << ID;
    delete ui;
}

void InfoComputers::printInfo(QString ID, QString name, QString type, QString wb, QString by, QString info, QString sci)
{
    this->ID = ID.toInt();
    ui->sciLink->setText(sci);
    ui->nameBox->setText(name);
    ui->typeBox->setText(type);
    ui->wbBox->setText(wb);
    ui->byBox->setText(by);
    ui->infoBox->setText(info);
}
