#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    displayAllScientists();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonAddNewSci_clicked()
{
    string name = ui->inputName->text().toStdString();
    string gender = ui->inputGender->text().toStdString();
    int birthyear = ui->inputBY->text().toInt();
    int deathyear = ui->inputDY->text().toInt();
    string bio = ui->inputBio->text().toStdString();

    myDom.addNewPerson(name, gender, birthyear, deathyear, bio);
    displayAllScientists();

    ui->inputName->clear();
    ui->inputGender->clear();
    ui->inputBY->clear();
    ui->inputDY->clear();
    ui->inputBio->clear();
    ui->isDead->setChecked(false);
}


void MainWindow::on_isDead_toggled(bool checked)
{
    ui->inputDY->setText("");
    if(checked)
    {
        ui->inputDY->setEnabled(true);
    }
    else
    {
        ui->inputDY->setEnabled(false);
    }
}

void MainWindow::displayAllScientists()
{
    ui->scientistList->clear();
    vector<Person> sci = myDom.returnAllScientists();
    sort(sci.begin(), sci.end());
    currentlyDisplayedScientists = sci;

    for(int i = 0; i < sci.size(); i++)
    {
         ui->scientistList->addItem(QString::fromStdString(sci[i].getName()));
    }


    ui->counter->setText(QString::number(sci.size()) + " found!!");
}

void MainWindow::displayScientists(vector<Person> sci)
{
    ui->scientistList->clear();
    sort(sci.begin(), sci.end());
    for (int i = 0 ; i < sci.size(); i++) {
        ui->scientistList->addItem(QString::fromStdString(sci[i].getName()));
    }
    currentlyDisplayedScientists = sci;
}

void MainWindow::on_input_filter_sci_textChanged(const QString &arg1)
{
    string userInput = ui->input_filter_sci->text().toStdString();
    vector<Person> sci = myDom.searchStringScientist("1",userInput);
    displayScientists(sci);
    ui->counter->setText(QString::number(sci.size()) + " found!!");
}

void MainWindow::on_scientistList_clicked(const QModelIndex &index)
{
    ui->removeButton->setEnabled(true);

    int currentIndex = ui->scientistList->currentIndex().row();
    Person currentlySelectedScientist = currentlyDisplayedScientists.at(currentIndex);

    QString death;
    if(currentlySelectedScientist.getDeathYear() == -1)
    {
        death = "\nDefinately NOT dead!\n";
    }
    else
    {
        death = "\nYear of death: " + QString::number(currentlySelectedScientist.getDeathYear());
    }

    ui->detailsBox->setText("Name: " + QString::fromStdString(currentlySelectedScientist.getName()) +
                            "\nGender: " + QString::fromStdString(currentlySelectedScientist.getGender()) +
                            "\n\nYear of birth: " + QString::number(currentlySelectedScientist.getBirthYear()) +
                            death + "\n\nShort Bio: " + QString::fromStdString(currentlySelectedScientist.getBio()));
}

void MainWindow::on_removeButton_clicked()
{
    int currentIndex = ui->scientistList->currentIndex().row();
    Person currentlySelectedScientist = currentlyDisplayedScientists.at(currentIndex);
    bool success = myDom.removeScientist(currentlySelectedScientist);

    if(success)
    {
        ui->input_filter_sci->setText("");
        displayAllScientists();

        ui->removeButton->setEnabled(false);
        ui->detailsBox->clear();
    }
}



void MainWindow::on_actionHome_triggered()
{

}
