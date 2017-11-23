#include "mockmeetingdb.h"

MockMeetingDB::MockMeetingDB() : meetings({})
{

}

QString MockMeetingDB::getKey(const QDate &date)
{
    return QString{"%1%2%3"}.arg(date.day()).arg(date.month()).arg(date.year());
}

void MockMeetingDB::addMeeting(qint64 project_id, const MockMeeting &meeting)
{
    QString key = MockMeetingDB::getKey(meeting.meetingDate());

    auto find1 = meetings.find(project_id);

    if (find1 == meetings.end()) {
        meetings[project_id] = std::map<QString, std::vector<MockMeeting>>{};
    }

    auto m1 = meetings[project_id];

    auto find2 = m1.find(key);

    if (find2 == m1.end()) {
        meetings[project_id][key] = std::vector<MockMeeting>{};
    }

    meetings[project_id][key].push_back(meeting);
}

std::vector<MockMeeting> MockMeetingDB::getMeetings(qint64 project_id, QString onDateKey)
{
    std::vector<MockMeeting> empty;

    auto found = meetings.find(project_id);

    if (found != meetings.end()) {
        auto m1 = (*found).second;
        auto foundAgain = m1.find(onDateKey);

        if (foundAgain != m1.end()) {
            return (*foundAgain).second;
        }
        else {
            return empty;
        }
    }
    else {
        return empty;
    }
}

void MockMeetingDB::createDummyMeetings()
{
    // Don't generate dummy meetings for now
#if GENDUMMYMEETINGS
    for (int i = 0; i < 8; i++) {
        MockMeeting m1{};

        m1.setMeetingDate(QDate::currentDate());
        m1.setMeetingName("Hi ho!");
        m1.setMeetingDesc("Some boring description which nobody will read");
        m1.setMeetingStart(QTime::currentTime());
        m1.setMeetingEnd(QTime::currentTime().addSecs(2 * 60 * 60));

        addMeeting(1, m1);
    }
#endif
}
