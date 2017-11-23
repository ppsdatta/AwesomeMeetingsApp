#ifndef MEETINGPREVIEW_H
#define MEETINGPREVIEW_H

#include <QWidget>

#include "mockmeeting.h"

namespace Ui {
class MeetingPreview;
}

class MeetingPreview : public QWidget
{
    Q_OBJECT

public:
    explicit MeetingPreview(MockMeeting meeting, QWidget *parent = 0);
    ~MeetingPreview();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MeetingPreview *ui;
    MockMeeting _meeting;
};

#endif // MEETINGPREVIEW_H
