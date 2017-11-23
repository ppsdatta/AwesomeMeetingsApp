#include "newmeetingdialog.h"
#include "ui_newmeetingdialog.h"

#include <QList>
#include <QMessageBox>

NewMeetingDialog::NewMeetingDialog(QWidget *parent, MockProject *project, MockMeetingDB *db, const QDate& date) :
    QWidget(parent),
    _project(project),
    _meetingDB(db),
    _date(date),
    ui(new Ui::NewMeetingDialog)
{
    ui->setupUi(this);

    ui->nmDate->setDate(_date);

    _remainingUsers = MockUser::users();

    ui->nmDesc->setReadOnly(false);

    for (auto u : _remainingUsers) {
        ui->nmUsers->addItem(QString("%1 %2").arg(u.firstName()).arg(u.lastName()));
    }

    ui->nmFrom->setTime(QTime::currentTime());
    ui->nmTo->setTime(QTime::currentTime().addSecs(30 * 60));

    _users = std::vector<MockUser>{};
    //this->setAttribute(Qt::WA_DeleteOnClose);
}

NewMeetingDialog::~NewMeetingDialog()
{
    delete ui;
}

void NewMeetingDialog::on_toolButton_clicked()
{
    this->close();
}

void NewMeetingDialog::resetView()
{
    ui->nmName->setText(QString("New meeting"));
    ui->nmDesc->setPlainText(QString(""));
    ui->nmUsers->clear();
    ui->nmDate->setDate(QDate::currentDate());
    ui->nmFrom->setTime(QTime::currentTime());
    ui->nmTo->setTime(QTime::currentTime().addSecs(30 * 60));
    ui->nmName->selectAll();
}

void NewMeetingDialog::on_toolButton_2_clicked()
{
    QString name = ui->nmName->text();
    QString desc = ui->nmDesc->toPlainText();
    QDate startDate = ui->nmDate->date();
    QTime from = ui->nmFrom->time();
    QTime to = ui->nmTo->time();

    if (name.isNull() or name.isEmpty()) {
        name = "Unnamed meeting";
    }

    MockMeeting newMeeting = MockMeeting();
    newMeeting.setMeetingDate(startDate);
    newMeeting.setMeetingDesc(desc);
    newMeeting.setMeetingEnd(to);
    newMeeting.setMeetingName(name);
    newMeeting.setMeetingStart(from);
    newMeeting.setMeetingUsers(_users);

    _meetingDB->addMeeting(_project->getID(), newMeeting);

    close();
}


void NewMeetingDialog::on_pushButton_clicked()
{
    int selectedIndex = ui->nmUsers->currentIndex();
    QString selectedText = ui->nmUsers->currentText();

    ui->nmUsersSel->addItem(selectedText);
    ui->nmUsers->removeItem(selectedIndex);

    _users.push_back(_remainingUsers.at(selectedIndex));
    _remainingUsers.erase(_remainingUsers.begin() + selectedIndex);
}
