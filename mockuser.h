#ifndef MOCKUSER_H
#define MOCKUSER_H

#include <vector>
#include <Qstring>

class MockUser
{
public:
    MockUser(qint64 id);
    MockUser(qint64 id, const QString& fname, const QString& lname, const QString& email);

    QString firstName() const;
    QString lastName() const;
    QString email() const;
    static std::vector<MockUser> users();
private:
    QString _firstName, _lastName, _email;
    qint64 ID;
};

#endif // MOCKUSER_H
