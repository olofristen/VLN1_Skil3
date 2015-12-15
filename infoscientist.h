#ifndef INFOSCIENTIST_H
#define INFOSCIENTIST_H

#include <QMainWindow>
#include <QDialog>
#include "domain.h"


namespace Ui {
class InfoScientist;
}

class InfoScientist : public QDialog
{
    Q_OBJECT

public:
    explicit InfoScientist(QWidget *parent = 0);
    ~InfoScientist();
    void printInfo(QString ID, QString name, QString gender, QString yob, QString yod, QString bio, QString comps);

private:
    Ui::InfoScientist *ui;
    int ID;
};

#endif // INFOSCIENTIST_H
