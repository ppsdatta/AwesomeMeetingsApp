#ifndef MOCKPROJECT_H
#define MOCKPROJECT_H

#include <vector>
#include <QString>

class MockProject
{
public:
    MockProject();
    MockProject(const QString& someName);
    static std::vector<MockProject> projects();
    QString name() const;
    qint64 getID() const;
    void setID(const qint64 &value);
private:
    QString _name;
    qint64 ID;
};

#endif // MOCKPROJECT_H
