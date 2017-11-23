#ifndef MEETINGDETAILSVIEW_H
#define MEETINGDETAILSVIEW_H

#include <QWidget>

#include "mockmeeting.h"

namespace Ui {
class MeetingDetailsView;
}

class MeetingDetailsView : public QWidget
{
    Q_OBJECT

public:
    explicit MeetingDetailsView(MockMeeting meeting, QWidget *parent = 0);
    ~MeetingDetailsView();

private slots:
    void on_toolButton_clicked();

private:
    Ui::MeetingDetailsView *ui;
    MockMeeting _meeting;
};

#endif // MEETINGDETAILSVIEW_H
