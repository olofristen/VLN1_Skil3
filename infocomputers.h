#ifndef INFOCOMPUTERS_H
#define INFOCOMPUTERS_H

#include <QDialog>

namespace Ui {
class InfoComputers;
}

class InfoComputers : public QDialog
{
    Q_OBJECT

public:
    explicit InfoComputers(QWidget *parent = 0);
    ~InfoComputers();

private:
    Ui::InfoComputers *ui;
};

#endif // INFOCOMPUTERS_H
