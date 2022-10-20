#include "rlscommowidget.h"
#include "ui_rlscommowidget.h"
#include "commodity.h"

#include <QRegExpValidator>
#include <QMessageBox>
#include <QButtonGroup>

#include <sstream>
#include <iomanip>

rlscommoWidget::rlscommoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rlscommoWidget)
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

rlscommoWidget::~rlscommoWidget()
{
    delete ui;
}

void rlscommoWidget::getUserIndex(int i)
{
    this->index = i;
}

void rlscommoWidget::on_commitButton_2_clicked()
{
    CArray carr;
    carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
    QString cname = ui->cnameLineEdit->text();
    QString price = ui->priceLineEdit->text();
    QString num = ui->numLineEdit->text();
    QString desc = ui->descLineEdit->text();
    if(cname.isEmpty() || price.isEmpty() || num.isEmpty() || desc.isEmpty())
    {
        QMessageBox::warning(this, "WARNING", "The input can't be empty!");
        return;
    }
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
    default: {
        QMessageBox::warning(this, "WARNING", "Please choose one attribute!");
        return;
    }break;
    }
    stringstream ss;
    ss << 'M' << setfill('0') << setw(3) << carr.length() + 1;
    string commodityID = ss.str();
    time_t tt = time(NULL);
    struct tm* t= localtime(&tt);
    char date[20];
    strftime(date, sizeof(date), "%F %T", t);
    string addedDate = date;
    string state = "onAuction";
    QString text = "commodityname:" + cname
            + "\nprice:" + price
            + "\nnumber:" + num
            + "\nattribute:" + QString::fromStdString(category[attr])
            + "\ndescription:" + desc;
    if (QMessageBox::Yes == QMessageBox::question(this, "Are you sure to release this commodity?", text))
    {
        UArray uarr;
        uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
        carr.push_back(Commodity(commodityID, cname.toStdString(), price.toFloat(), num.toInt(),
                                 category[attr], desc.toStdString(), uarr[index].get_id(), addedDate, state));
        carr.array2file("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
        QMessageBox::information(this, "INFOMATION", "Release successfully!");
    }
    this->close();
}

void rlscommoWidget::on_cancelButton_2_clicked()
{
    this->close();
}
