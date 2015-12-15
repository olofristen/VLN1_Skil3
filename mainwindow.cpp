#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "domain.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dropDownScientists->addItem("Name");
    ui->dropDownScientists->addItem("Gender");
    ui->dropDownScientists->addItem("Year of birth");
    ui->dropDownScientists->addItem("Year of death");
    ui->dropDownScientists->addItem("Bio");
    ui->dropDownSearch->addItem("Name");
    ui->dropDownSearch->addItem("Type");
    ui->dropDownSearch->addItem("Was built");
    ui->dropDownSearch->addItem("Building year");
    ui->dropDownSearch->addItem("Info");
    displayAllComputers();
    displayAllScientists();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionHome_triggered()
{

}

void MainWindow::displayAllScientists()
{
    vector<Person> scientists = domain.returnAllScientists();
    displayScientists(scientists);
}

void MainWindow::displayAllComputers()
{
    vector<Computer> computers = domain.returnAllComputers();
    displayComputers(computers);
}

void MainWindow::displayScientists(vector<Person> scientists)
{
    ui->tableScientists->clearContents();
    ui->tableScientists->setRowCount(scientists.size());
   for(int row = 0; row < scientists.size(); row++)
   {
       Person currentScientist = scientists.at(row);
       QString dye;
       QString name = QString::fromStdString(currentScientist.getName());
       QString gender = QString::fromStdString(currentScientist.getGender());
       QString by = QString::number(currentScientist.getBirthYear());
       QString dy = QString::number(currentScientist.getDeathYear());
       if(dy == "-1")
       {
           dye = "Alive and kicking";
       }
       else
       {
           dye = dy;
       }
       QString bio = QString::fromStdString(currentScientist.getBio());

       ui->tableScientists->setItem(row, 0, new QTableWidgetItem(name));
       ui->tableScientists->setItem(row, 1, new QTableWidgetItem(gender));
       ui->tableScientists->setItem(row, 2, new QTableWidgetItem(by));
       ui->tableScientists->setItem(row, 3, new QTableWidgetItem(dye));
       ui->tableScientists->setItem(row, 4, new QTableWidgetItem(bio));
   }
}

void MainWindow::displayComputers(vector<Computer> computers)
{
    ui->tableComputers->clearContents();
    ui->tableComputers->setRowCount(computers.size());
   for(unsigned int row = 0; row < computers.size(); row++)
   {
       Computer currentComputer = computers.at(row);
       QString wbu;
       QString name = QString::fromStdString(currentComputer.getName());
       QString type = QString::fromStdString(currentComputer.getType());
       QString wb = QString::number(currentComputer.getWasBuilt());
       if(wb == "1")
       {
           wbu = "Yes";
       }
       else
       {
           wbu = "No";
       }
       QString by = QString::number(currentComputer.getBuildYear());

       ui->tableComputers->setItem(row, 0, new QTableWidgetItem(name));
       ui->tableComputers->setItem(row, 1, new QTableWidgetItem(type));
       ui->tableComputers->setItem(row, 2, new QTableWidgetItem(wbu));
       ui->tableComputers->setItem(row, 3, new QTableWidgetItem(by));
   }
}
void MainWindow::displayBio(int row)
{
    vector<Person> scientists = domain.returnAllScientists();
    Person currentScientist = scientists.at(row);

    QString bio = QString::fromStdString(currentScientist.getBio());
    ui->textBrowserBio->setText(bio);
}
void MainWindow::displayInfo(unsigned int row)
{
    vector<Computer> computers = domain.returnAllComputers();
    Computer currentComputer = computers.at(row);

    QString info = QString::fromStdString(currentComputer.getInfo());
    ui->textBrowserInfo->setText(info);
}

void MainWindow::on_lineEditScientists_textChanged(const QString &arg1)
{
    string userInput = ui->lineEditScientists->text().toStdString();
    string dropDownValue = getCurrentScientistSearch();
    vector<Person> scientist = domain.filterScientist(dropDownValue, userInput);
    displayScientists(scientist);
}

void MainWindow::on_inputFilterComputers_textChanged(const QString &arg1)
{
    string userInput = ui->inputFilterComputers->text().toStdString();
    string dropDownValue = getCurrentComputerSearch();
    vector<Computer> computer = domain.filterComputer(dropDownValue, userInput);
    displayComputers(computer);
}

void MainWindow::on_dropDownScientists_currentIndexChanged(const QString &arg1)
{
    string userInput = ui->lineEditScientists->text().toStdString();
    string dropDownValue = getCurrentScientistSearch();
    vector<Person> scientist = domain.filterScientist(dropDownValue, userInput);
    displayScientists(scientist);
}

void MainWindow::on_dropDownSearch_currentIndexChanged(const QString &arg1)
{
    string userInput = ui->inputFilterComputers->text().toStdString();
    string dropDownValue = getCurrentComputerSearch();
    vector<Computer> computer = domain.filterComputer(dropDownValue, userInput);
    displayComputers(computer);
}

string MainWindow::getCurrentScientistSearch()
{
    string currentValueSearch = ui->dropDownScientists->currentText().toStdString();
    if(currentValueSearch == "Name")
    {
        return "name";
    }
    else if(currentValueSearch == "Gender")
    {
        return "gender";
    }
    else if(currentValueSearch == "Year of birth")
    {
        return "dob";
    }
    else if(currentValueSearch == "Year of death")
    {
        return "dod";
    }
    else if(currentValueSearch == "Bio")
    {
        return "bio";
    }
}
string MainWindow::getCurrentComputerSearch()
{
    string currentValueSearch = ui->dropDownSearch->currentText().toStdString();
    if(currentValueSearch == "Name")
    {
        return "name";
    }
    else if(currentValueSearch == "Type")
    {
        return "type";
    }
    else if(currentValueSearch == "Was built")
    {
        return "wb";
    }
    else if(currentValueSearch == "Building year")
    {
        return "by";
    }
    else if(currentValueSearch == "Info")
    {
        return "info";
    }
}

void MainWindow::on_tableComputers_clicked(const QModelIndex &index)
{
    unsigned int currentIndex = ui->tableComputers->currentIndex().row();
    displayInfo(currentIndex);
}

void MainWindow::on_tableScientists_clicked(const QModelIndex &index)
{
    unsigned int currentIndex = ui->tableScientists->currentIndex().row();
    displayBio(currentIndex);
}
