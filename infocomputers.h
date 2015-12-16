#ifndef INFOCOMPUTERS_H
#define INFOCOMPUTERS_H

#include <QDialog>
#include <QMainWindow>
#include "domain.h"

namespace Ui {
class InfoComputers;
}

class InfoComputers : public QDialog
{
    Q_OBJECT

public:
    explicit InfoComputers(QWidget *parent = 0);
    ~InfoComputers();
    void printInfo(QString ID, QString name, QString type, QString wb, QString by, QString info, QString sci);

private:
    Ui::InfoComputers *ui;
};

#endif // INFOCOMPUTERS_H
