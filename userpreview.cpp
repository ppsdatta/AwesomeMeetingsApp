#include "userpreview.h"
#include "ui_userpreview.h"
#include "userdetailsdialog.h"

UserPreview::UserPreview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserPreview),
    _user(MockUser{0})
{
    ui->setupUi(this);
}

void UserPreview::setUser(const MockUser &user)
{
    _user = user;
    this->ui->buttonUser->setText(QString{"%1, %2"}.arg(_user.firstName(), _user.lastName()));
}

UserPreview::~UserPreview()
{
    delete ui;
}

void UserPreview::on_buttonUser_clicked()
{
    auto view = new UserDetailsDialog{this, _user};
    view->show();
}
