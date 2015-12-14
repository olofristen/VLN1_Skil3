#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "domain.h"
#include "infoscientist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_input_filter_sci_textChanged(const QString &arg1);

    void on_scientistList_clicked(const QModelIndex &index);

    void on_removeButton_clicked();

    void on_buttonAddNewSci_clicked();

    void on_isDead_toggled(bool checked);

    void on_buttonAddNewComp_clicked();

    void on_computerList_clicked(const QModelIndex &index);

    void on_removeComp_clicked();

    void on_inputFilterComp_textChanged(const QString &arg1);

    void on_linkButton_clicked();

    bool on_scientistList2_clicked();

    void on_computerList2_clicked();

    void on_inputFilterSci2_textChanged();

    void on_inputFilterComp2_textChanged();

private:
    Ui::MainWindow *ui;

    void displayScientists(vector<Person> sci);
    void displayAllScientists();
    void displayAllComputers();
    void displayComputers(vector<Computer> comp);
    void isHeDead();
    Domain myDom;

    vector<Person> currentlyDisplayedScientists;
    vector<Computer> currentlyDisplayedComputers;
    void setLinkEnabled();
    void displayCombos();
};

#endif // MAINWINDOW_H
