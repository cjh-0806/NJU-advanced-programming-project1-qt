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
    ui->label->setText("Hello, " + QString::fromStdString(p.get_name()) + "! Please choose your command:");
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
    UArray uarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    int i;
    for(i = 0; i < uarr.length(); ++i)
        if(p.get_id() == uarr[i].get_id())
            break;
    userinfoWidget* ui_w = new userinfoWidget;
    connect(this,SIGNAL(sendUserIndex(int)),ui_w,SLOT(getUserIndex(int)));
    emit sendUserIndex(i);
    ui_w->show();
}

void userWidget::on_logoutButton_clicked()
{
    this->close();
}
