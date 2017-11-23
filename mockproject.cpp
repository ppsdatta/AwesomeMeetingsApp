#include "mockproject.h"

MockProject::MockProject() : _name("")
{
}

MockProject::MockProject(const QString &someName) : _name(someName)
{}

QString MockProject::name() const
{
    return _name;
}

qint64 MockProject::getID() const
{
    return ID;
}

void MockProject::setID(const qint64 &value)
{
    ID = value;
}

std::vector<MockProject> MockProject::projects()
{
    std::vector<MockProject> projectVector = std::vector<MockProject>{};

    for (int i = 0; i < 10; i++) {
        auto name = QString{"Project # %1"}.arg(i + 1);
        auto project = MockProject{name};
        project.setID(i + 1);
        projectVector.push_back(project);
    }

    return projectVector;
}
