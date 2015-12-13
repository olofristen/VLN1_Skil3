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

private:
    Ui::InfoScientist *ui;
};

#endif // INFOSCIENTIST_H
