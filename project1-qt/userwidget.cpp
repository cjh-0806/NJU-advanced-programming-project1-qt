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

void userWidget::getUser(User p)
{
    this->p = p;
}

void userWidget::on_buyerButton_clicked()
{
    buyerWidget* b_w = new buyerWidget;
    connect(this,SIGNAL(sendUser(User)),b_w,SLOT(getUser(User)));
    emit sendUser(p);
    b_w->show();
}

void userWidget::on_sellerButton_clicked()
{
    sellerWidget* s_w = new sellerWidget;
    connect(this,SIGNAL(sendUser(User)),s_w,SLOT(getUser(User)));
    emit sendUser(p);
    s_w->show();
}

void userWidget::on_infoButton_clicked()
{
    userinfoWidget* ui_w = new userinfoWidget;
    connect(this,SIGNAL(sendUser(User)),ui_w,SLOT(getUser(User)));
    emit sendUser(p);
    ui_w->show();
}

void userWidget::on_logoutButton_clicked()
{
    this->close();
}
