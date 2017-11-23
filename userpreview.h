#ifndef USERPREVIEW_H
#define USERPREVIEW_H

#include <QWidget>
#include "mockuser.h"

namespace Ui {
class UserPreview;
}

class UserPreview : public QWidget
{
    Q_OBJECT

public:
    explicit UserPreview(QWidget *parent = 0);
    void setUser(const MockUser& user);
    ~UserPreview();

private slots:
    void on_buttonUser_clicked();

private:
    Ui::UserPreview *ui;
    MockUser _user;
};

#endif // USERPREVIEW_H
