#include "meetingdetailsview.h"
#include "ui_meetingdetailsview.h"
#include "userpreview.h"

MeetingDetailsView::MeetingDetailsView(MockMeeting meeting, QWidget *parent) :
    QWidget(parent),
    _meeting(meeting),
    ui(new Ui::MeetingDetailsView)
{
    ui->setupUi(this);

    ui->nmName->setText(_meeting.meetingName());
    ui->nmDate->setDate(_meeting.meetingDate());
    ui->nmDesc->setPlainText(_meeting.meetingDesc());
    ui->nmFrom->setTime(_meeting.meetingStart());
    ui->nmTo->setTime(_meeting.meetingEnd());

    for (auto u : _meeting.meetingUsers()) {
        ui->nmUsers->addItem(QString("%1, %2  [%3]").arg(u.firstName()).arg(u.lastName()).arg(u.email()));
    }

    ui->nmDate->setReadOnly(true);
    ui->nmDesc->setReadOnly(true);
    ui->nmFrom->setReadOnly(true);
    ui->nmTo->setReadOnly(true);
}

MeetingDetailsView::~MeetingDetailsView()
{
    delete ui;
}

void MeetingDetailsView::on_toolButton_clicked()
{
    this->close();
}
