#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "domain.h"
#include "infoscientist.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString showScientistsFromLinks(int cid);
    QString showComputersFromLinks(int pid);

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

    void on_inputFilterSci2_textChanged();

    void on_inputFilterComp2_textChanged();

    void on_scientistList_currentRowChanged(int currentRow);

    void on_computerList_currentRowChanged(int currentRow);

    void on_scientistList2_currentRowChanged(int currentRow);

    void on_computerList2_currentRowChanged(int currentRow);

    void on_inputFilterLink_textChanged(const QString &arg1);

    void on_removeLinkButton_clicked();

    void on_linkTable_clicked(const QModelIndex &index);

    void on_linkTable_currentCellChanged();

    void on_inputFilterComputers_textChanged(const QString &arg1);

    void on_dropDownSearch_currentIndexChanged(const QString &arg1);

    void on_tableComputers_clicked(const QModelIndex &index);

    void on_tableScientists_clicked(const QModelIndex &index);

    void on_lineEditScientists_textChanged(const QString &arg1);

    void on_dropDownScientists_currentIndexChanged(const QString &arg1);

    void on_tableScientists_currentCellChanged();

    void on_tableComputers_currentCellChanged();

    void on_tableScientists_doubleClicked();

private:
    Ui::MainWindow *ui;
    string getCurrentScientistSearch();
    string getCurrentComputerSearch();
    void displayAllScientistsST();
    void displayScientistsST(vector<Person> scientists);
    void displayAllComputersST();
    void displayComputersST(vector<Computer> computers);
    void displayInfo(int row);
    void displayBio(int row);
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
};

#endif // MAINWINDOW_H
