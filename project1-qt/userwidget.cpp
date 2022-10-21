#include "userwidget.h"
#include "ui_userwidget.h"

#include <QMessageBox>
#include <QDebug>

userWidget::userWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userWidget)
{
    ui->setupUi(this);
    //setAttribute(Qt::WA_QuitOnClose, false);
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
    buyerWidget *b_w = new buyerWidget;
    b_w->setAttribute(Qt::WA_DeleteOnClose);
    b_w->setWindowModality(Qt::ApplicationModal);
    connect(this,SIGNAL(sendUserIndex(int)),b_w,SLOT(getUserIndex(int)));
    emit sendUserIndex(index);
    b_w->show();
}

void userWidget::on_sellerButton_clicked()
{
    sellerWidget *s_w = new sellerWidget;
    s_w->setAttribute(Qt::WA_DeleteOnClose);
    s_w->setWindowModality(Qt::ApplicationModal);
    connect(this,SIGNAL(sendUserIndex(int)),s_w,SLOT(getUserIndex(int)));
    emit sendUserIndex(index);
    s_w->show();
}

void userWidget::on_infoButton_clicked()
{
    userinfoWidget *ui_w = new userinfoWidget;
    ui_w->setAttribute(Qt::WA_DeleteOnClose);
    ui_w->setWindowModality(Qt::ApplicationModal);
    connect(this,SIGNAL(sendUserIndex(int)),ui_w,SLOT(getUserIndex(int)));
    emit sendUserIndex(index);
    ui_w->show();
}

void userWidget::on_logoutButton_clicked()
{
    this->close();
}
