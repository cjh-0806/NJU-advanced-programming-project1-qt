#include "userwidget.h"
#include "ui_userwidget.h"
#include "buyerwidget.h"
#include "sellerwidget.h"
#include "userinfowidget.h"

userWidget::userWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userWidget)
{
    ui->setupUi(this);
}

userWidget::~userWidget()
{
    delete ui;
}

void userWidget::on_buyerButton_clicked()
{
    buyerWidget* b_w = new buyerWidget;
    b_w->show();
}

void userWidget::on_sellerButton_clicked()
{
    sellerWidget* s_w = new sellerWidget;
    s_w->show();
}

void userWidget::on_infoButton_clicked()
{
    userinfoWidget* ui_w = new userinfoWidget;
    ui_w->show();
}

void userWidget::on_logoutButton_clicked()
{
    this->close();
}

void userWidget::getUser(User p)
{
    this->p = p;
}
