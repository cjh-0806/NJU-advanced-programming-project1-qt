#include "userwidget.h"
#include "ui_userwidget.h"

#include <QMessageBox>
#include <QCloseEvent>

userWidget::userWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userWidget),
    b_w(nullptr), s_w(nullptr), ui_w(nullptr)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_QuitOnClose, false);
}

void userWidget::closeEvent(QCloseEvent *event)
{
    if(b_w) b_w->close();
    if(s_w) s_w->close();
    if(ui_w) ui_w->close();
    event->accept();
}

userWidget::~userWidget()
{
    delete ui;
    delete b_w;
    delete s_w;
    delete ui_w;
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
    b_w = new buyerWidget;
    connect(this,SIGNAL(sendUserIndex(int)),b_w,SLOT(getUserIndex(int)));
    emit sendUserIndex(index);
    b_w->show();
}

void userWidget::on_sellerButton_clicked()
{
    s_w = new sellerWidget;
    connect(this,SIGNAL(sendUserIndex(int)),s_w,SLOT(getUserIndex(int)));
    emit sendUserIndex(index);
    s_w->show();
}

void userWidget::on_infoButton_clicked()
{
    ui_w = new userinfoWidget;
    connect(this,SIGNAL(sendUserIndex(int)),ui_w,SLOT(getUserIndex(int)));
    emit sendUserIndex(index);
    ui_w->show();
}

void userWidget::on_logoutButton_clicked()
{
    this->close();
}
