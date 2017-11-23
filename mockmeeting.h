#ifndef MOCKMEETING_H
#define MOCKMEETING_H

#include <QString>
#include <QDate>
#include <QTime>

#include <vector>

#include "mockuser.h"
#include "mockproject.h"

class MockMeeting
{
public:
    MockMeeting();
    QTime meetingStart() const;
    void setMeetingStart(const QTime &meetingStart);

    QTime meetingEnd() const;
    void setMeetingEnd(const QTime &meetingEnd);

    QString meetingName() const;
    void setMeetingName(const QString &meetingName);

    QString meetingDesc() const;
    void setMeetingDesc(const QString &meetingDesc);

    QDate meetingDate() const;
    void setMeetingDate(const QDate &meetingDate);

    std::vector<MockUser> meetingUsers() const;
    void setMeetingUsers(const std::vector<MockUser> &meetingUsers);

private:
    QString _meetingName;
    QString _meetingDesc;
    QDate _meetingDate;
    QTime _meetingStart, _meetingEnd;
    std::vector<MockUser> _meetingUsers;
};

#endif // MOCKMEETING_H
