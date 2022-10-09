#include "adminwidget.h"
#include "ui_adminwidget.h"
#include "user.h"
#include "commodity.h"
#include "order.h"

#include <QTableWidget>
#include <QHeaderView>
#include <QFile>
#include <QTextStream>
#include <QInputDialog>
#include <QMessageBox>
#include <QPushButton>

adminWidget::adminWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminWidget)
{
    ui->setupUi(this);
}

adminWidget::~adminWidget()
{
    delete ui;
}

void adminWidget::on_viewuserButton_clicked()
{
    QTableWidget* tw = new QTableWidget;
    tw->setAttribute(Qt::WA_DeleteOnClose);
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

void adminWidget::on_banuserButton_clicked()
{
    bool ok;
    QString id = QInputDialog::getText(this,"Ban a user","Please input the userID you want to ban:",
                                           QLineEdit::Normal,"",&ok); //输入封禁用户id
    if(ok)
    {
        UArray uarr;
        uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
        int i;
        for(i = 0; i < uarr.length(); ++i)
        {
            if (uarr[i].get_id() == id.toStdString() && uarr[i].get_state() == "active")
            { //显示封禁用户信息
                QString text = "username:" + QString::fromStdString(uarr[i].get_name())
                        + "\nphone number:" + QString::fromStdString(uarr[i].get_num())
                        + "\naddress:" + QString::fromStdString(uarr[i].get_addr());
                if (QMessageBox::Yes == QMessageBox::question(this, "Are you sure to ban this user?", text))
                { //确认封禁用户
                    uarr[i].set_state("inactive");
                    CArray carr;
                    carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
                    for(int j = 0; j < carr.length(); ++j)
                        if(carr[j].get_sid() == id.toStdString() && carr[j].get_state() == "onAuction")
                            carr[j].set_state("removed");
                    OArray oarr;
                    oarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/order.txt");
                    for(int k = 0; k < oarr.length(); ++k)
                    {
                        if(oarr[k].get_sellerid() == id.toStdString() && oarr[k].get_state() == "unfinished")
                            oarr[k].set_state("removed");
                        if(oarr[k].get_buyerid() == id.toStdString() && oarr[k].get_state() == "unfinished")
                            oarr[k].set_state("removed");
                    }
                    uarr.array2file("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
                    carr.array2file("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
                    oarr.array2file("/home/cjh/NJU-advanced-programming-project1-qt/order.txt");
                    QMessageBox::about(this, "Ban a user", "Ban successfully!");
                }
                break;
            }
        }
        if(i == uarr.length())
            QMessageBox::warning(this, "Ban a user", "This user doesn't exist or has already be banned!");
    }
}

void adminWidget::on_vieworderButton_clicked()
{
    QTableWidget* tw = new QTableWidget;
    tw->setAttribute(Qt::WA_DeleteOnClose);
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

void adminWidget::on_viewcommoButton_clicked()
{
    QTableWidget* tw = new QTableWidget;
    tw->setAttribute(Qt::WA_DeleteOnClose);
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

void adminWidget::on_srchcommoButton_clicked()
{
    QMessageBox* msgBox = new QMessageBox;
    msgBox->setAttribute(Qt::WA_DeleteOnClose);
    msgBox->setWindowTitle(tr("Search commodity"));
    msgBox->setText(tr("Please chooose how to search:"));
    msgBox->setStandardButtons(QMessageBox::Cancel);
    QPushButton *attrbutton = (msgBox->addButton(tr("attribute"), QMessageBox::AcceptRole));
    QPushButton *namebutton = (msgBox->addButton(tr("name"), QMessageBox::AcceptRole));
    msgBox->exec();
    if(msgBox->clickedButton() == namebutton)
    { //按名称搜索
        bool ok;
        QString name = QInputDialog::getText(this,"Search commodity","Please input the commodityname you want to search:",
                                            QLineEdit::Normal,"",&ok); //输入名称
        if(ok)
        {
           QTableWidget* tw = new QTableWidget;
           tw->setAttribute(Qt::WA_DeleteOnClose);
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
               if (carr[i].get_name().find(name.toStdString()) != -1)
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
           }
           tw->show();
        }
    }
    else if(msgBox->clickedButton() == attrbutton)
    { //按属性搜索
        QMessageBox* box2 = new QMessageBox;
        box2->setAttribute(Qt::WA_DeleteOnClose);
        box2->setWindowTitle(tr("Search commodity"));
        box2->setText(tr("Please choose the attribute you want to search:"));
        box2->setStandardButtons(QMessageBox::Cancel);
        QPushButton *button8 = (box2->addButton(tr("other"), QMessageBox::AcceptRole));
        QPushButton *button7 = (box2->addButton(tr("digital"), QMessageBox::AcceptRole));
        QPushButton *button6 = (box2->addButton(tr("ornament"), QMessageBox::AcceptRole));
        QPushButton *button5 = (box2->addButton(tr("makeup"), QMessageBox::AcceptRole));
        QPushButton *button4 = (box2->addButton(tr("clothes"), QMessageBox::AcceptRole));
        QPushButton *button3 = (box2->addButton(tr("food"), QMessageBox::AcceptRole));
        QPushButton *button2 = (box2->addButton(tr("study"), QMessageBox::AcceptRole));
        QPushButton *button1 = (box2->addButton(tr("life"), QMessageBox::AcceptRole));
        box2->exec();
        int attr;
        if(box2->clickedButton() == button1) attr = 1;
        else if(box2->clickedButton() == button2) attr = 2;
        else if(box2->clickedButton() == button3) attr = 3;
        else if(box2->clickedButton() == button4) attr = 4;
        else if(box2->clickedButton() == button5) attr = 5;
        else if(box2->clickedButton() == button6) attr = 6;
        else if(box2->clickedButton() == button7) attr = 7;
        else if(box2->clickedButton() == button8) attr = 8;
        else return;
        QTableWidget* tw = new QTableWidget;
        tw->setAttribute(Qt::WA_DeleteOnClose);
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
            if (carr[i].get_attr() == category[attr])
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
        }
        tw->show();
    }
    else
        return;
}

void adminWidget::on_rmvcommoButton_clicked()
{
    bool ok;
    QString id = QInputDialog::getText(this,"Remove commodity","Please input the commodityID you want to remove:",
                                           QLineEdit::Normal,"",&ok); //输入下架商品id
    if(ok)
    {
        CArray carr;
        carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
        int i;
        for(i = 0; i < carr.length(); ++i)
        {
            if (carr[i].get_id() == id.toStdString() && carr[i].get_state() == "onAuction")
            { //显示下架商品信息
                QString text = "commodityname:" + QString::fromStdString(carr[i].get_name())
                        + "\nprice:" + QString::number(carr[i].get_price(),'f', 1)
                        + "\nattribute:" + QString::fromStdString(carr[i].get_attr())
                        + "\nsellerID:" + QString::fromStdString(carr[i].get_sid())
                        + "\ndescription:" + QString::fromStdString(carr[i].get_desc());

                if (QMessageBox::Yes == QMessageBox::question(this, "Are you sure to remove this commodity?", text))
                { //确认下架商品
                    carr[i].set_state("removed");
                    OArray oarr;
                    oarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/order.txt");
                    for(int j = 0; j < oarr.length(); ++j)
                    {
                        if(oarr[j].get_cid() == id.toStdString() && oarr[j].get_state() == "unfinished")
                            oarr[j].set_state("removed");
                    }
                    carr.array2file("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
                    oarr.array2file("/home/cjh/NJU-advanced-programming-project1-qt/order.txt");
                    QMessageBox::about(this, "Remove commodity", "Remove successfully!");
                }
                break;
            }
        }
        if(i == carr.length())
            QMessageBox::warning(this, "Remove commodity", "This commodity doesn't exist or has already be removed!");
    }
}

void adminWidget::on_logoutButton_clicked()
{
    this->close();
}
