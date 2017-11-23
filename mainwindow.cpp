#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "detailsviewdialog.h"
#include "mockproject.h"
#include "newmeetingdialog.h"

MainWindow::MainWindow(QWidget *parent, MockProject *curProject) :
    QMainWindow(parent),
    currentProject(curProject),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _projects = MockProject::projects();
    this->setupData();
    _meeingDB = MockMeetingDB{};
    _meeingDB.createDummyMeetings();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupData()
{
    for (auto p : _projects) {
        this->ui->projectSelectorBox->addItem(p.name());
    }

    currentProject = &_projects.at(this->ui->projectSelectorBox->currentIndex());
}

void MainWindow::on_pushButton_clicked()
{
    QDate selectedDate = this->ui->calendar->selectedDate();
    if (selectedDate.isNull()) {
        return;
    }
    DetailsViewDialog *dialog = new DetailsViewDialog(this, this->getCurrentProject(), &this->_meeingDB, selectedDate);
    dialog->show();
}

void MainWindow::on_projectSelectorBox_currentIndexChanged(int index)
{
    currentProject = &_projects.at(index);
}

MockProject *MainWindow::getCurrentProject() const
{
    return currentProject;
}

void MainWindow::on_pushButton_2_clicked()
{
    QDate selectedDate = this->ui->calendar->selectedDate();
    if (selectedDate.isNull()) {
        selectedDate = QDate::currentDate();
    }
    NewMeetingDialog *dialog = new NewMeetingDialog(0, this->currentProject, &this->_meeingDB, selectedDate);
    dialog->show();
}
