#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    displayAllScientists();
    displayAllComputers();

    displayCombos();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::displayCombos()
{
    ui->compTypeCombo->addItem("Electronic");
    ui->compTypeCombo->addItem("Mechanic");
    ui->compTypeCombo->addItem("Transistor");
    ui->compTypeCombo->addItem("Other");

    ui->genderCombo->addItem("Male");
    ui->genderCombo->addItem("Female");
}

void MainWindow::on_buttonAddNewSci_clicked()
{
    string name = ui->inputName->text().toStdString();
    string gender = ui->genderCombo->currentText().toStdString();
    int birthyear = ui->inputBY->text().toInt();
    int deathyear = ui->inputDY->text().toInt();
    string bio = ui->inputBio->text().toStdString();

    if(name == "" || birthyear == 0 || birthyear < 1600 || birthyear > 2010 || (deathyear != 0 && deathyear < birthyear) || deathyear > 2015 || (ui->isDead->isChecked() && deathyear == 0))
    {
        ui->errorMess->setText("These values are invalid! Try again...");
        return;
    }
    if(deathyear == 0)       deathyear = -1;        // Not dead yet!

    myDom.addNewPerson(name, gender, birthyear, deathyear, bio);
    displayAllScientists();

    ui->inputName->clear();
    ui->inputBY->clear();
    ui->inputDY->clear();
    ui->inputBio->clear();
    ui->isDead->setChecked(false);
    ui->errorMess->clear();
    ui->statusBar->showMessage("New scientist successfully added to the database!", 1500);
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
    ui->scientistList2->clear();
    vector<Person> sci = myDom.returnAllScientists();
    sort(sci.begin(), sci.end());
    currentlyDisplayedScientists = sci;

    for(int i = 0; i < sci.size(); i++)
    {
        ui->scientistList->addItem(QString::fromStdString(sci[i].getName()));
        ui->scientistList2->addItem(QString::fromStdString(sci[i].getName()));
    }
    ui->counter->setText(QString::number(sci.size()) + " found!!");
    ui->counterSci2->setText(QString::number(sci.size()) + " found!!");
}

void MainWindow::displayAllComputers()
{
    ui->computerList->clear();
    ui->computerList2->clear();
    vector<Computer> comp = myDom.returnAllComputers();
    sort(comp.begin(), comp.end());
    currentlyDisplayedComputers = comp;

    for(int i = 0; i < comp.size(); i++)
    {
        ui->computerList->addItem(QString::fromStdString(comp[i].getName()));
        ui->computerList2->addItem(QString::fromStdString(comp[i].getName()));
    }
    ui->counterComp->setText(QString::number(comp.size()) + " found!!");
    ui->counterComp2->setText(QString::number(comp.size()) + " found!!");
}

void MainWindow::displayScientists(vector<Person> sci)
{
    ui->scientistList->clear();
    ui->scientistList2->clear();
    sort(sci.begin(), sci.end());
    for (int i = 0 ; i < sci.size(); i++) {
        ui->scientistList->addItem(QString::fromStdString(sci[i].getName()));
        ui->scientistList2->addItem(QString::fromStdString(sci[i].getName()));
    }
    currentlyDisplayedScientists = sci;
}
void MainWindow::displayComputers(vector<Computer> comp)
{
    ui->computerList->clear();
    ui->computerList2->clear();
    sort(comp.begin(), comp.end());
    for(int i = 0; i < comp.size(); i++)
    {
        ui->computerList->addItem(QString::fromStdString(comp[i].getName()));
        ui->computerList2->addItem(QString::fromStdString(comp[i].getName()));
    }
    currentlyDisplayedComputers = comp;
}

void MainWindow::on_input_filter_sci_textChanged(const QString &arg1)
{
    string userInput = ui->input_filter_sci->text().toStdString();
    vector<Person> sci = myDom.searchStringScientist("1",userInput);
    displayScientists(sci);
    ui->counter->setText(QString::number(sci.size()) + " found!!");
}

void MainWindow::scientistListScroll()
{
    ui->removeButton->setEnabled(true);

    int currentIndex = ui->scientistList->currentIndex().row();
    Person currentlySelectedScientist = currentlyDisplayedScientists.at(currentIndex);

    QString death;
    if(currentlySelectedScientist.getDeathYear() == -1)
    {
        death = "\nDefinately NOT dead!";
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

void MainWindow::on_scientistList_clicked(const QModelIndex &index)
{
    scientistListScroll();
}

void MainWindow::on_scientistList_currentRowChanged(int currentRow)
{
    if(currentRow < 0)
    {
        ui->detailsBox->clear();
        return;
    }
    scientistListScroll();

}

void MainWindow::on_removeButton_clicked()
{
    int currentIndex = ui->scientistList->currentIndex().row();
    Person currentlySelectedScientist = currentlyDisplayedScientists.at(currentIndex);

    int answer = QMessageBox::question(this, "Confirm removal", "Are you sure you want to remove this scientist from the database?");
    if(answer == QMessageBox::No)
    {
        return;
    }
    bool success = myDom.removeScientist(currentlySelectedScientist);

    if(success)
    {
        ui->input_filter_sci->setText("");
        displayAllScientists();

        ui->removeButton->setEnabled(false);
        ui->detailsBox->clear();
    }
    ui->statusBar->showMessage("This scientist was successfully removed from the database", 1500);
}


void MainWindow::on_buttonAddNewComp_clicked()
{
    string name = ui->inputNameComp->text().toStdString();
    string type = ui->compTypeCombo->currentText().toStdString();
    bool wasbuilt = ui->wasBuilt->isChecked();
    int year = ui->inputYComp->text().toInt();
    string info = ui->inputInfo->text().toStdString();

    if(name == "" || year < 1600 || year > 2015)
    {
        ui->errorMessComp->setText("These values are invalid! Try again...");
        return;
    }
    myDom.addNewComputer(name, year, type, wasbuilt, info);
    displayAllComputers();

    ui->inputNameComp->clear();
    ui->compTypeCombo->setCurrentIndex(0);
    ui->inputYComp->clear();
    ui->inputInfo->clear();
    ui->wasBuilt->setChecked(false);
    ui->errorMessComp->clear();
    ui->statusBar->showMessage("New computer added to the database!", 1500);
}
void MainWindow::computerListScroll()
{
    ui->removeComp->setEnabled(true);

    int currentIndex = ui->computerList->currentIndex().row();
    Computer currentlySelectedComp = currentlyDisplayedComputers.at(currentIndex);

    QString wasBuilt;
    if(currentlySelectedComp.getWasBuilt())
    {
        wasBuilt = "\nIt was built in " + QString::number(currentlySelectedComp.getBuildYear());
    }
    else
    {
        wasBuilt = "\nIt was NEVER built, but documented in " + QString::number(currentlySelectedComp.getBuildYear());
    }

    ui->detailsBoxComp->setText("Name: " + QString::fromStdString(currentlySelectedComp.getName()) +
                            "\nType: " + QString::fromStdString(currentlySelectedComp.getType()) +
                            wasBuilt + "\n\nShort info:\n" + QString::fromStdString(currentlySelectedComp.getInfo()));

}

void MainWindow::on_computerList_clicked(const QModelIndex &index)
{
    computerListScroll();
}


void MainWindow::on_computerList_currentRowChanged(int currentRow)
{
    if(currentRow < 0)
    {
        ui->detailsBoxComp->clear();
        return;
    }
    computerListScroll();
}

void MainWindow::on_removeComp_clicked()
{
    int currentIndex = ui->computerList->currentIndex().row();
    Computer currentlySelectedComp = currentlyDisplayedComputers.at(currentIndex);

    int answer = QMessageBox::question(this, "Confirm removal", "Are you sure you want to remove this computer from the database?");
    if(answer == QMessageBox::No)
    {
        return;
    }
    bool success = myDom.removeComputer(currentlySelectedComp);

    if(success)
    {
        ui->inputFilterComp->clear();
        displayAllComputers();

        ui->removeComp->setEnabled(false);
        ui->detailsBoxComp->clear();
    }
    ui->statusBar->showMessage("This computer was successfully removed from the database", 1500);
}

void MainWindow::on_inputFilterComp_textChanged(const QString &arg1)
{
    string userInput = ui->inputFilterComp->text().toStdString();
    vector<Computer> comp = myDom.searchStringComputer("1",userInput);
    displayComputers(comp);
    ui->counterComp->setText(QString::number(comp.size()) + " found!!");
}


void MainWindow::on_linkButton_clicked()
{
    ui->detailsLinks->clear();
    int currentIndex = ui->scientistList2->currentIndex().row();
    Person currentlySelectedScientist = currentlyDisplayedScientists.at(currentIndex);
    currentIndex = ui->computerList2->currentIndex().row();
    Computer currentlySelectedComp = currentlyDisplayedComputers.at(currentIndex);

    bool success = myDom.addNewLink(currentlySelectedScientist, currentlySelectedComp);
    if(success)
    {
        ui->detailsLinks->setText("Worked! We linked together:\n\n" + QString::fromStdString(currentlySelectedScientist.getName()) + " + " + QString::fromStdString(currentlySelectedComp.getName()));
    }
    else
    {
        ui->detailsLinks->setText("This link already exists! \n\nTry again!");
    }
    ui->inputFilterSci2->clear();
    ui->inputFilterComp2->clear();
}

/*bool MainWindow::on_scientistList2_clicked()
{
    ui->computerList2->setEnabled(true);
    ui->inputFilterComp2->setEnabled(true);
    return true;
}

void MainWindow::on_computerList2_clicked()
{
    if(on_scientistList2_clicked())
    {
        ui->linkButton->setEnabled(true);
    }
}*/
void MainWindow::enableLinkButton()
{
    if(ui->scientistList2->currentIndex().row() > -1 && ui->computerList2->currentIndex().row() > -1)
    {
        ui->linkButton->setEnabled(true);
    }
    else
    {
        ui->linkButton->setDisabled(true);
    }
}

void MainWindow::on_inputFilterSci2_textChanged()
{
    string userInput = ui->inputFilterSci2->text().toStdString();
    vector<Person> sci = myDom.searchStringScientist("1",userInput);
    displayScientists(sci);
    ui->counterSci2->setText(QString::number(sci.size()) + " found!!");

}

void MainWindow::on_inputFilterComp2_textChanged()
{
    string userInput = ui->inputFilterComp2->text().toStdString();
    vector<Computer> comp = myDom.searchStringComputer("1",userInput);
    displayComputers(comp);
    ui->counterComp2->setText(QString::number(comp.size()) + " found!!");

}

void MainWindow::on_scientistList2_currentRowChanged(int currentRow)
{
    enableLinkButton();
}

void MainWindow::on_computerList2_currentRowChanged(int currentRow)
{
    enableLinkButton();
}
