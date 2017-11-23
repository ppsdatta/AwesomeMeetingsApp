#include "detailsviewdialog.h"
#include "ui_detailsviewdialog.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QSize>
#include <QScroller>

#include "meetingpreview.h"
#include "mockmeetingdb.h"
#include "newmeetingdialog.h"

#include <vector>
#include <iostream>

DetailsViewDialog::DetailsViewDialog(QWidget *parent, MockProject *project, MockMeetingDB *meetingDB, QDate selDate) :
    QDialog(parent),
    _project(project),
    _meetingDB(meetingDB),
    _selDate(selDate),
    ui(new Ui::DetailsViewDialog)
{
    ui->setupUi(this);

    QScroller::grabGesture(this->ui->meetingsArea->viewport(), QScroller::LeftMouseButtonGesture);

    auto meetings = _meetingDB->getMeetings(_project->getID(), MockMeetingDB::getKey(_selDate));

    auto layout = new QVBoxLayout();

    for (auto m : meetings) {
        MeetingPreview *preview = new MeetingPreview(m, this);
        preview->setMinimumHeight(200);
        preview->setMinimumWidth(80);
        layout->addWidget(preview);
    }

    QWidget *scrollWidget = new QWidget;
    scrollWidget->setLayout(layout);

    ui->meetingsArea->setWidget(scrollWidget);
    ui->meetingsArea->setWidgetResizable(true);
    this->ui->textLabel->setText(_selDate.toString());
}

DetailsViewDialog::~DetailsViewDialog()
{
    delete ui;
}

void DetailsViewDialog::on_toolButton_clicked()
{
    this->close();
}

void DetailsViewDialog::on_toolButton_2_clicked()
{
    NewMeetingDialog *dialog = new NewMeetingDialog(0, _project, _meetingDB, _selDate);
    dialog->show();
    this->close();
}
