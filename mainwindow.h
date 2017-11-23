#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <vector>

#include "mockproject.h"
#include "mockmeetingdb.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, MockProject *curProject = 0);
    void setupData();
    ~MainWindow();

    MockProject *getCurrentProject() const;

private slots:
    void on_pushButton_clicked();

    void on_projectSelectorBox_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    MockProject *currentProject;
    std::vector<MockProject> _projects;
    MockMeetingDB _meeingDB;
};

#endif // MAINWINDOW_H
