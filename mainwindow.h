#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "domain.h"

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

private slots:
    void on_actionHome_triggered();

    void on_inputFilterComputers_textChanged(const QString &arg1);

    void on_dropDownSearch_currentIndexChanged(const QString &arg1);

    void on_tableComputers_clicked(const QModelIndex &index);

    void on_tableScientists_clicked(const QModelIndex &index);

    void on_lineEditScientists_textChanged(const QString &arg1);

    void on_dropDownScientists_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    string getCurrentScientistSearch();
    string getCurrentComputerSearch();
    void displayAllScientists();
    void displayScientists(vector<Person> scientists);
    void displayAllComputers();
    void displayComputers(std::vector<Computer> computers);
    void displayInfo(unsigned int row);
    void displayBio(int row);
    Domain domain;
};

#endif // MAINWINDOW_H
