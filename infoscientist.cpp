#include "infoscientist.h"
#include "ui_infoscientist.h"

InfoScientist::InfoScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoScientist)
{
    ui->setupUi(this);
}

InfoScientist::~InfoScientist()
{
    delete ui;
}
