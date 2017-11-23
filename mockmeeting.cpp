#include "mockmeeting.h"

MockMeeting::MockMeeting()
{

}

QTime MockMeeting::meetingStart() const
{
    return _meetingStart;
}

void MockMeeting::setMeetingStart(const QTime &meetingStart)
{
    _meetingStart = meetingStart;
}

QTime MockMeeting::meetingEnd() const
{
    return _meetingEnd;
}

void MockMeeting::setMeetingEnd(const QTime &meetingEnd)
{
    _meetingEnd = meetingEnd;
}

QString MockMeeting::meetingName() const
{
    return _meetingName;
}

void MockMeeting::setMeetingName(const QString &meetingName)
{
    _meetingName = meetingName;
}

QString MockMeeting::meetingDesc() const
{
    return _meetingDesc;
}

void MockMeeting::setMeetingDesc(const QString &meetingDesc)
{
    _meetingDesc = meetingDesc;
}

QDate MockMeeting::meetingDate() const
{
    return _meetingDate;
}

void MockMeeting::setMeetingDate(const QDate &meetingDate)
{
    _meetingDate = meetingDate;
}

std::vector<MockUser> MockMeeting::meetingUsers() const
{
    return _meetingUsers;
}

void MockMeeting::setMeetingUsers(const std::vector<MockUser> &meetingUsers)
{
    _meetingUsers = meetingUsers;
}
