#ifndef NEWMEETINGDIALOG_H
#define NEWMEETINGDIALOG_H

#include <QWidget>
#include <QDate>

#include "mockmeeting.h"
#include "mockmeetingdb.h"
#include "mockuser.h"
#include "mockproject.h"

#include <vector>

namespace Ui {
class NewMeetingDialog;
}

class NewMeetingDialog : public QWidget
{
    Q_OBJECT

public:
    explicit NewMeetingDialog(QWidget *parent = 0, MockProject *project = 0, MockMeetingDB *db = 0, const QDate& date = QDate::currentDate());
    ~NewMeetingDialog();
    void resetView();

private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::NewMeetingDialog *ui;
    MockProject *_project;
    MockMeetingDB *_meetingDB;
    QDate _date;
    std::vector<MockUser> _users, _remainingUsers;
};

#endif // NEWMEETINGDIALOG_H
