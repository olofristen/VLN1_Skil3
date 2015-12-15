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
    delete ui;
}
