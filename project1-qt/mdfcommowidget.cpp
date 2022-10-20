#include "mdfcommowidget.h"
#include "ui_mdfcommowidget.h"
#include "commodity.h"

#include <QRegExpValidator>
#include <QMessageBox>
#include <QButtonGroup>

#include <sstream>
#include <iomanip>

mdfcommoWidget::mdfcommoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mdfcommoWidget)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_QuitOnClose, false);
    ui->cnameLineEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z ]{1,20}")));
    ui->priceLineEdit->setValidator(new QDoubleValidator(0, 1000000, 1));
    ui->numLineEdit->setValidator(new QIntValidator(0, 1000));
    ui->descLineEdit->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z0-9 ]{1,200}")));
    //回车
    ui->cnameLineEdit->setFocus();
    connect(ui->cnameLineEdit,SIGNAL(returnPressed()),ui->priceLineEdit,SLOT(setFocus()));
    connect(ui->priceLineEdit,SIGNAL(returnPressed()),ui->numLineEdit,SLOT(setFocus()));
    connect(ui->numLineEdit,SIGNAL(returnPressed()),ui->descLineEdit,SLOT(setFocus()));
    connect(ui->descLineEdit,SIGNAL(returnPressed()),this,SLOT(on_commitButton_2_clicked()));
}

mdfcommoWidget::~mdfcommoWidget()
{
    delete ui;
}

void mdfcommoWidget::getCommodityIndex(int i)
{
    this->index = i;
    CArray carr;
    carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
    ui->cnameLineEdit->setPlaceholderText(QString::fromStdString(carr[i].get_name()));
    ui->priceLineEdit->setPlaceholderText(QString::number(carr[i].get_price(),'f', 1));
    ui->numLineEdit->setPlaceholderText(QString::number(carr[i].get_num()));
    ui->descLineEdit->setPlaceholderText(QString::fromStdString(carr[i].get_desc()));
    int j;
    for(j = 1; j <= 8; ++j)
        if(carr[i].get_attr() == category[j])
            break;
    switch(j)
    {
    case 1: ui->lifeButton->setChecked(true); break;
    case 2: ui->studyButton->setChecked(true); break;
    case 3: ui->foodButton->setChecked(true); break;
    case 4: ui->clothesButton->setChecked(true); break;
    case 5: ui->makeupButton->setChecked(true); break;
    case 6: ui->ornaButton->setChecked(true); break;
    case 7: ui->digiButton->setChecked(true); break;
    case 8: ui->otherButton->setChecked(true); break;
    }
}

void mdfcommoWidget::on_commitButton_2_clicked()
{
    CArray carr;
    carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
    if(carr[index].get_state() == "removed")
    {
        QMessageBox::warning(this, "Modify commodity", "This commodity has already been removed!");
        return;
    }
    QString cname = ui->cnameLineEdit->text();
    QString price = ui->priceLineEdit->text();
    if(!price.isEmpty() && carr[index].get_price() < price.toFloat())
    {
        QMessageBox::warning(this, "WARNING", "You can't increase the price!");
        return;
    }
    QString num = ui->numLineEdit->text();
    QString desc = ui->descLineEdit->text();
    QButtonGroup *btnGroup = new QButtonGroup;
    btnGroup->addButton(ui->lifeButton, 0);
    btnGroup->addButton(ui->studyButton, 1);
    btnGroup->addButton(ui->foodButton, 2);
    btnGroup->addButton(ui->clothesButton, 3);
    btnGroup->addButton(ui->makeupButton, 4);
    btnGroup->addButton(ui->ornaButton, 5);
    btnGroup->addButton(ui->digiButton, 6);
    btnGroup->addButton(ui->otherButton, 7);
    int attr;
    switch(btnGroup->checkedId())
    {
    case 0: attr = 1; break;
    case 1: attr = 2; break;
    case 2: attr = 3; break;
    case 3: attr = 4; break;
    case 4: attr = 5; break;
    case 5: attr = 6; break;
    case 6: attr = 7; break;
    case 7: attr = 8; break;
    }
    if(!cname.isEmpty())
        carr[index].set_name(cname.toStdString());
    if(!price.isEmpty())
        carr[index].set_price(price.toFloat());
    if(!num.isEmpty())
        carr[index].set_num(num.toInt());
    if(!desc.isEmpty())
        carr[index].set_attr(desc.toStdString());
    carr[index].set_attr(category[attr]);
    carr.array2file("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
    QMessageBox::information(this, "INFOMATION", "Modify successfully!");
    this->close();
}

void mdfcommoWidget::on_cancelButton_2_clicked()
{
    this->close();
}
