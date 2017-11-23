#include "meetingpreview.h"
#include "ui_meetingpreview.h"
#include "meetingdetailsview.h"

MeetingPreview::MeetingPreview(MockMeeting meeting, QWidget *parent) :
    QWidget(parent),
    _meeting(meeting),
    ui(new Ui::MeetingPreview)
{
    ui->setupUi(this);
    ui->meetingNameLabel->setText(_meeting.meetingName());
    ui->meetingDate->setText(_meeting.meetingDate().toString());
    ui->fromLabel->setText(_meeting.meetingStart().toString());
    ui->toLabel->setText(_meeting.meetingEnd().toString());
}

MeetingPreview::~MeetingPreview()
{
    delete ui;
}

void MeetingPreview::on_pushButton_clicked()
{
    MeetingDetailsView *view = new MeetingDetailsView(_meeting, 0);
    view->show();
}
