#include "userwidget.h"
#include "ui_userwidget.h"
#include "buyerwidget.h"
#include "sellerwidget.h"
#include "userinfowidget.h"
#include "user.h"

userWidget::userWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userWidget)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_QuitOnClose, false);
}

userWidget::~userWidget()
{
    delete ui;
}

void userWidget::getUserIndex(int i)
{
    this->index = i;
    UArray uarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    ui->label->setText("Hello, " + QString::fromStdString(uarr[i].get_name()) + "! Please choose your command:");
}

void userWidget::on_buyerButton_clicked()
{
    buyerWidget* b_w = new buyerWidget;
    connect(this,SIGNAL(sendUserIndex(int)),b_w,SLOT(getUserIndex(int)));
    emit sendUserIndex(index);
    b_w->show();
}

void userWidget::on_sellerButton_clicked()
{
    sellerWidget* s_w = new sellerWidget;
    connect(this,SIGNAL(sendUserIndex(int)),s_w,SLOT(getUserIndex(int)));
    emit sendUserIndex(index);
    s_w->show();
}

void userWidget::on_infoButton_clicked()
{
    userinfoWidget* ui_w = new userinfoWidget;
    connect(this,SIGNAL(sendUserIndex(int)),ui_w,SLOT(getUserIndex(int)));
    emit sendUserIndex(index);
    ui_w->show();
}

void userWidget::on_logoutButton_clicked()
{
    this->close();
}
