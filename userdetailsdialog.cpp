#include "userdetailsdialog.h"
#include "ui_userdetailsdialog.h"

UserDetailsDialog::UserDetailsDialog(QWidget *parent, const MockUser& user) :
    QDialog(parent),
    _user(user),
    ui(new Ui::UserDetailsDialog)
{
    ui->setupUi(this);
    ui->firstNameLabel->setText(_user.firstName());
    ui->lastNameLabel->setText(_user.lastName());
    ui->emailLabel->setText(_user.email());
}

UserDetailsDialog::~UserDetailsDialog()
{
    delete ui;
}
