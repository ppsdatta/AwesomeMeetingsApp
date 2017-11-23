#ifndef DETAILSVIEWDIALOG_H
#define DETAILSVIEWDIALOG_H

#include <QDialog>
#include <QDate>

#include "mockproject.h"
#include "mockmeetingdb.h"

namespace Ui {
class DetailsViewDialog;
}

class DetailsViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DetailsViewDialog(QWidget *parent = 0, MockProject *project = 0, MockMeetingDB *meetingDB = 0, QDate selDate = QDate::currentDate());
    ~DetailsViewDialog();

private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

private:
    Ui::DetailsViewDialog *ui;
    MockProject *_project;
    MockMeetingDB *_meetingDB;
    QDate _selDate;
};

#endif // DETAILSVIEWDIALOG_H
