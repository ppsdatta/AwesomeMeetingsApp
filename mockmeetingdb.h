#ifndef MOCKMEETINGDB_H
#define MOCKMEETINGDB_H

#include <vector>
#include <unordered_map>
#include <map>

#include <Qstring>
#include <QDate>
#include <QTime>

#include "mockmeeting.h"

#define GENDUMMYMEETINGS 0

class MockMeetingDB
{
public:
    using MeetingContainer = std::map<qint64, std::map<QString, std::vector<MockMeeting>>>;

    MockMeetingDB();
    static QString getKey(const QDate& date);
    void addMeeting(qint64 project_id, const MockMeeting& meeting);
    std::vector<MockMeeting> getMeetings(qint64 project_id, QString onDateKey = "");
    void createDummyMeetings();
private:
    MeetingContainer meetings;
};

#endif // MOCKMEETINGDB_H
