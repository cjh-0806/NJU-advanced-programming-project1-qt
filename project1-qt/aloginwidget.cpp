#include "aloginwidget.h"
#include "ui_aloginwidget.h"
#include "admin.h"
#include "acommandwidget.h"
#include <QMessageBox>

aloginWidget::aloginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aloginWidget)
{
    ui->setupUi(this);
}

aloginWidget::~aloginWidget()
{
    delete ui;
}

void aloginWidget::on_commitButton_clicked()
{
    Admin admin;
    QString name = ui->adminnameLineEdit->text();
    QString pswd = ui->pswdLineEdit->text();
    if(admin.get_name() == name.toStdString() && admin.get_pswd() == pswd.toStdString())
    {
        this->close();
        acommandWidget* ac_w = new acommandWidget;
        ac_w->show();
    }
    else
        QMessageBox::warning(this, tr("WARNING"), tr("Administrator name or password is wrong!"), QMessageBox::Close);
}

void aloginWidget::on_cancelButton_clicked()
{
    this->close();
}
