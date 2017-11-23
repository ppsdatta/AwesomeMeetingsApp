#ifndef USERDETAILSDIALOG_H
#define USERDETAILSDIALOG_H

#include <QDialog>
#include "mockuser.h"

namespace Ui {
class UserDetailsDialog;
}

class UserDetailsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserDetailsDialog(QWidget *parent = 0, const MockUser& user = MockUser{0});
    ~UserDetailsDialog();

private:
    Ui::UserDetailsDialog *ui;
    MockUser _user;
};

#endif // USERDETAILSDIALOG_H
