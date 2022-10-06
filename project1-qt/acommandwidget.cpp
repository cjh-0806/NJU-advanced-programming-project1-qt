#include "acommandwidget.h"
#include "ui_acommandwidget.h"
#include "user.h"
#include "commodity.h"
#include "order.h"

#include <QTableWidget>
#include <QHeaderView>
#include <QFile>
#include <QTextStream>
#include <QInputDialog>

acommandWidget::acommandWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::acommandWidget)
{
    ui->setupUi(this);
}

acommandWidget::~acommandWidget()
{
    delete ui;
}

void acommandWidget::on_viewuserButton_clicked()
{
    QTableWidget* tw = new QTableWidget;
    tw->setWindowTitle("Users");
    tw->resize(600,450);
    tw->setColumnCount(6);
    QStringList header;
    header << "userID" << "username" << "phoneNumber" << "address" << "balance" << "userstate";
    tw->setHorizontalHeaderLabels(header);
    tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tw->setEditTriggers(QAbstractItemView::NoEditTriggers);
    UArray uarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    for(int i = 0; i < uarr.length(); ++i)
    {
        int rowCount = tw->rowCount();
        tw->insertRow(rowCount);
        tw->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(uarr[i].get_id())));
        tw->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(uarr[i].get_name())));
        tw->setItem(rowCount, 2, new QTableWidgetItem(QString::fromStdString(uarr[i].get_num())));
        tw->setItem(rowCount, 3, new QTableWidgetItem(QString::fromStdString(uarr[i].get_addr())));
        tw->setItem(rowCount, 4, new QTableWidgetItem(QString::number(uarr[i].get_balance(), 'f', 1)));
        tw->setItem(rowCount, 5, new QTableWidgetItem(QString::fromStdString(uarr[i].get_state())));
    }
    tw->show();
}

void acommandWidget::on_banuserButton_clicked()
{
    QString text = QInputDialog::getText(this,"明天放假","请输入数据：",QLineEdit::Password);
    //让这个返回的字符串输出到label
    ui->label->setText(text);
}

void acommandWidget::on_vieworderButton_clicked()
{
    QTableWidget* tw = new QTableWidget;
    tw->setWindowTitle("Users");
    tw->resize(800,450);
    tw->setColumnCount(8);
    QStringList header;
    header << "orderID" << "commodityID" << "unitPrice" << "bidPrice" << "date" << "sellerID" << "buyerID" << "state";
    tw->setHorizontalHeaderLabels(header);
    tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tw->setEditTriggers(QAbstractItemView::NoEditTriggers);
    OArray oarr;
    oarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/order.txt");
    for(int i = 0; i < oarr.length(); ++i)
    {
        int rowCount = tw->rowCount();
        tw->insertRow(rowCount);
        tw->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(oarr[i].get_oid())));
        tw->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(oarr[i].get_cid())));
        tw->setItem(rowCount, 2, new QTableWidgetItem(QString::number(oarr[i].get_price(), 'f', 1)));
        tw->setItem(rowCount, 3, new QTableWidgetItem(QString::number(oarr[i].get_bid(), 'f', 1)));
        tw->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(oarr[i].get_date())));
        tw->setItem(rowCount, 5, new QTableWidgetItem(QString::fromStdString(oarr[i].get_sellerid())));
        tw->setItem(rowCount, 6, new QTableWidgetItem(QString::fromStdString(oarr[i].get_buyerid())));
        tw->setItem(rowCount, 7, new QTableWidgetItem(QString::fromStdString(oarr[i].get_state())));
    }
    tw->show();
}

void acommandWidget::on_viewcommoButton_clicked()
{
    QTableWidget* tw = new QTableWidget;
    tw->setWindowTitle("Users");
    tw->resize(900,450);
    tw->setColumnCount(9);
    QStringList header;
    header << "commodityID" << "commodityname" << "price" << "number" << "attribute"
           << "description" << "sellerID" << "addedDate" << "state";
    tw->setHorizontalHeaderLabels(header);
    tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tw->setEditTriggers(QAbstractItemView::NoEditTriggers);
    CArray carr;
    carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
    for(int i = 0; i < carr.length(); ++i)
    {
        int rowCount = tw->rowCount();
        tw->insertRow(rowCount);
        tw->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(carr[i].get_id())));
        tw->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(carr[i].get_name())));
        tw->setItem(rowCount, 2, new QTableWidgetItem(QString::number(carr[i].get_price(), 'f', 1)));
        tw->setItem(rowCount, 3, new QTableWidgetItem(QString::number(carr[i].get_num())));
        tw->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(carr[i].get_attr())));
        tw->setItem(rowCount, 5, new QTableWidgetItem(QString::fromStdString(carr[i].get_desc())));
        tw->setItem(rowCount, 6, new QTableWidgetItem(QString::fromStdString(carr[i].get_sid())));
        tw->setItem(rowCount, 7, new QTableWidgetItem(QString::fromStdString(carr[i].get_date())));
        tw->setItem(rowCount, 8, new QTableWidgetItem(QString::fromStdString(carr[i].get_state())));
    }
    tw->show();
}

void acommandWidget::on_srchcommoButton_clicked()
{

}

void acommandWidget::on_rmvcommoButton_clicked()
{

}

void acommandWidget::on_logoutButton_clicked()
{
    this->close();
}
