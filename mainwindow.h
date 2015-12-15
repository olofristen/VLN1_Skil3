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
    void onInputFilterSciTextChanged(const QString &arg1);

    void onScientistListClicked(const QModelIndex &index);

    void onRemoveButtonClicked();

    void onButtonAddNewSciClicked();

    void onIsDeadToggled(bool checked);

    void onButtonAddNewCompClicked();

    void onComputerListClicked(const QModelIndex &index);

    void onRemoveCompClicked();

    void onInputFilterCompTextChanged(const QString &arg1);

    void onLinkButtonClicked();

    void onInputFilterSci2TextChanged();

    void onInputFilterComp2TextChanged();

    void onScientistListCurrentRowChanged(int currentRow);

    void onComputerListCurrentRowChanged(int currentRow);

    void onScientistList2CurrentRowChanged(int currentRow);

    void onComputerList2CurrentRowChanged(int currentRow);

    void onInputFilterLinkTextChanged(const QString &arg1);

    void onRemoveLinkButtonClicked();

    void onLinkTableClicked(const QModelIndex &index);

    void onLinkTableCurrentCellChanged();

private:
    Ui::MainWindow *ui;
    Domain myDom;

    vector<Person> currentlyDisplayedScientists;
    vector<Computer> currentlyDisplayedComputers;
    vector<Person> currentlyDisplayedSciLink;
    vector<Computer> currentlyDisplayedCompLink;
    vector<pair<Person, Computer> > currentlyDisplayedLinks;

    void displayAllScientists();
    void displayAllComputers();
    void displayScientists(vector<Person> sci);
    void displayComputers(vector<Computer> comp);
    void displayScientistsLink(vector<Person> sci);
    void displayComputersLink(vector<Computer> comp);
    void displayLinkTable(vector<pair<Person, Computer> > vlink);

    void isHeDead();
    void setLinkEnabled();
    void displayCombos();
    void scientistListScroll();
    void computerListScroll();
    void enableLinkButton();
    pair<Person, Computer> returnLinkFromNames(string pName, string cName);

};

#endif // MAINWINDOW_H
