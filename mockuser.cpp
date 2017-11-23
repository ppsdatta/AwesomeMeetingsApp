#include "mockuser.h"

MockUser::MockUser(qint64 id) : ID(id), _firstName("Unknown"), _lastName("Unknown"), _email("Unknown")
{}

MockUser::MockUser(qint64 id, const QString &fname, const QString &lname, const QString &email) : ID(id), _firstName(fname), _lastName(lname), _email(email)
{}

QString MockUser::firstName() const
{
    return _firstName;
}

QString MockUser::lastName() const
{
    return _lastName;
}

QString MockUser::email() const
{
    return _email;
}

std::vector<MockUser> MockUser::users()
{
    auto userVector = std::vector<MockUser>{};

    for (int i = 0; i < 8; i++) {
        QString fname = "Marvin";
        QString lname = QString{"Minsk%1"}.arg(i + 1);
        QString email = QString{"marvin.minsk%1@funstuff.com"}.arg(i + 1);
        userVector.push_back(MockUser{i + 1, fname, lname, email});
    }

    return userVector;
}

