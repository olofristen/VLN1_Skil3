#include "infoscientist.h"
#include "mainwindow.h"
#include "ui_infoscientist.h"

InfoScientist::InfoScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoScientist)
{
    ui->setupUi(this);
}

void InfoScientist::printInfo(QString ID, QString name, QString gender, QString yob, QString yod, QString bio, QString comps)
{
    this->ID = ID.toInt();
    ui->compLink->setText(comps);
    ui->nameBox->setText(name);
    ui->genderBox->setText(gender);
    ui->yobBox->setText(yob);
    ui->yodBox->setText(yod);
    ui->bioBox->setText(bio);

}
InfoScientist::~InfoScientist()
{
    qDebug() << ID;
    delete ui;
}
