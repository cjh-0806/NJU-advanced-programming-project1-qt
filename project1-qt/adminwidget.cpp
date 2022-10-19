#include "adminwidget.h"
#include "ui_adminwidget.h"
#include "user.h"
#include "commodity.h"
#include "order.h"

#include <QHeaderView>
#include <QInputDialog>
#include <QMessageBox>
#include <QPushButton>

adminWidget::adminWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminWidget),
    vu_tw(nullptr), vc_tw(nullptr), sc_tw(nullptr), vo_tw(nullptr)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_QuitOnClose, false);
}

void adminWidget::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this,"Close widget","Do you want to close this widget?",QMessageBox::Yes|QMessageBox::No);
    if(button == QMessageBox::Yes)
    {
        if(vu_tw) vu_tw->close();
        if(vc_tw) vc_tw->close();
        if(sc_tw) sc_tw->close();
        if(vo_tw) vo_tw->close();
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

adminWidget::~adminWidget()
{
    delete ui;
    delete vu_tw;
    delete vc_tw;
    delete sc_tw;
    delete vo_tw;
}

void adminWidget::on_viewuserButton_clicked()
{
    vu_tw = new QTableWidget;
    vu_tw->setAttribute(Qt::WA_DeleteOnClose);
    vu_tw->setWindowTitle("View users");
    vu_tw->resize(900,450);
    vu_tw->setColumnCount(6);
    QStringList header;
    header << "userID" << "username" << "phoneNumber" << "address" << "balance" << "userstate";
    vu_tw->setHorizontalHeaderLabels(header);
    vu_tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    vu_tw->setEditTriggers(QAbstractItemView::NoEditTriggers); //不可编辑
    UArray uarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    for(int i = 0; i < uarr.length(); ++i)
    {
        int rowCount = vu_tw->rowCount();
        vu_tw->insertRow(rowCount);
        vu_tw->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(uarr[i].get_id())));
        vu_tw->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(uarr[i].get_name())));
        vu_tw->setItem(rowCount, 2, new QTableWidgetItem(QString::fromStdString(uarr[i].get_num())));
        vu_tw->setItem(rowCount, 3, new QTableWidgetItem(QString::fromStdString(uarr[i].get_addr())));
        vu_tw->setItem(rowCount, 4, new QTableWidgetItem(QString::number(uarr[i].get_balance(), 'f', 1)));
        vu_tw->setItem(rowCount, 5, new QTableWidgetItem(QString::fromStdString(uarr[i].get_state())));
    }
    vu_tw->show();
}

void adminWidget::on_banuserButton_clicked()
{
    bool ok;
    QString id = QInputDialog::getText(this,"Ban user","Please input the userID you want to ban:",
                                           QLineEdit::Normal,"",&ok); //输入封禁用户id
    if(!ok)
        return;
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
                QMessageBox::about(this, "Ban user", "Ban successfully!");
            }
            break;
        }
    }
    if(i == uarr.length())
        QMessageBox::warning(this, "Ban user", "This user doesn't exist or has already be banned!");
}

void adminWidget::on_vieworderButton_clicked()
{
    vo_tw = new QTableWidget;
    vo_tw->setAttribute(Qt::WA_DeleteOnClose);
    vo_tw->setWindowTitle("View orders");
    vo_tw->resize(1200,450);
    vo_tw->setColumnCount(8);
    QStringList header;
    header << "orderID" << "commodityID" << "unitPrice" << "bidPrice" << "date" << "sellerID" << "buyerID" << "state";
    vo_tw->setHorizontalHeaderLabels(header);
    vo_tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    vo_tw->setEditTriggers(QAbstractItemView::NoEditTriggers);
    OArray oarr;
    oarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/order.txt");
    for(int i = 0; i < oarr.length(); ++i)
    {
        int rowCount = vo_tw->rowCount();
        vo_tw->insertRow(rowCount);
        vo_tw->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(oarr[i].get_oid())));
        vo_tw->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(oarr[i].get_cid())));
        vo_tw->setItem(rowCount, 2, new QTableWidgetItem(QString::number(oarr[i].get_price(), 'f', 1)));
        vo_tw->setItem(rowCount, 3, new QTableWidgetItem(QString::number(oarr[i].get_bid(), 'f', 1)));
        vo_tw->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(oarr[i].get_date())));
        vo_tw->setItem(rowCount, 5, new QTableWidgetItem(QString::fromStdString(oarr[i].get_sellerid())));
        vo_tw->setItem(rowCount, 6, new QTableWidgetItem(QString::fromStdString(oarr[i].get_buyerid())));
        vo_tw->setItem(rowCount, 7, new QTableWidgetItem(QString::fromStdString(oarr[i].get_state())));
    }
    vo_tw->show();
}

void adminWidget::on_viewcommoButton_clicked()
{
    vc_tw = new QTableWidget;
    vc_tw->setAttribute(Qt::WA_DeleteOnClose);
    vc_tw->setWindowTitle("View commodities");
    vc_tw->resize(1350,450);
    vc_tw->setColumnCount(9);
    QStringList header;
    header << "commodityID" << "commodityname" << "price" << "number" << "attribute"
           << "description" << "sellerID" << "addedDate" << "state";
    vc_tw->setHorizontalHeaderLabels(header);
    vc_tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    vc_tw->setEditTriggers(QAbstractItemView::NoEditTriggers);
    CArray carr;
    carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
    for(int i = 0; i < carr.length(); ++i)
    {
        int rowCount = vc_tw->rowCount();
        vc_tw->insertRow(rowCount);
        vc_tw->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(carr[i].get_id())));
        vc_tw->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(carr[i].get_name())));
        vc_tw->setItem(rowCount, 2, new QTableWidgetItem(QString::number(carr[i].get_price(), 'f', 1)));
        vc_tw->setItem(rowCount, 3, new QTableWidgetItem(QString::number(carr[i].get_num())));
        vc_tw->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(carr[i].get_attr())));
        vc_tw->setItem(rowCount, 5, new QTableWidgetItem(QString::fromStdString(carr[i].get_desc())));
        vc_tw->setItem(rowCount, 6, new QTableWidgetItem(QString::fromStdString(carr[i].get_sid())));
        vc_tw->setItem(rowCount, 7, new QTableWidgetItem(QString::fromStdString(carr[i].get_date())));
        vc_tw->setItem(rowCount, 8, new QTableWidgetItem(QString::fromStdString(carr[i].get_state())));
    }
    vc_tw->show();
}

void adminWidget::on_srchcommoButton_clicked()
{
    QMessageBox* msgBox = new QMessageBox;
    msgBox->setAttribute(Qt::WA_DeleteOnClose);
    msgBox->setWindowTitle("Search commodity");
    msgBox->setText("Please chooose how to search:");
    msgBox->setStandardButtons(QMessageBox::Cancel);
    QPushButton *attrbutton = (msgBox->addButton("attribute", QMessageBox::AcceptRole));
    QPushButton *namebutton = (msgBox->addButton("name", QMessageBox::AcceptRole));
    msgBox->exec();
    if(msgBox->clickedButton() == namebutton)
    { //按名称搜索
        bool ok;
        QString name = QInputDialog::getText(this,"Search commodity","Please input the commodityname you want to search:",
                                            QLineEdit::Normal,"",&ok); //输入名称
        if(!ok)
            return;
        sc_tw = new QTableWidget;
        sc_tw->setAttribute(Qt::WA_DeleteOnClose);
        sc_tw->setWindowTitle("Search commodity");
        sc_tw->resize(1350,450);
        sc_tw->setColumnCount(9);
        QStringList header;
        header << "commodityID" << "commodityname" << "price" << "number" << "attribute"
              << "description" << "sellerID" << "addedDate" << "state";
        sc_tw->setHorizontalHeaderLabels(header);
        sc_tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        sc_tw->setEditTriggers(QAbstractItemView::NoEditTriggers);
        CArray carr;
        carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
        for(int i = 0; i < carr.length(); ++i)
        {
           if (carr[i].get_name().find(name.toStdString()) != -1)
           {
               int rowCount = sc_tw->rowCount();
               sc_tw->insertRow(rowCount);
               sc_tw->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(carr[i].get_id())));
               sc_tw->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(carr[i].get_name())));
               sc_tw->setItem(rowCount, 2, new QTableWidgetItem(QString::number(carr[i].get_price(), 'f', 1)));
               sc_tw->setItem(rowCount, 3, new QTableWidgetItem(QString::number(carr[i].get_num())));
               sc_tw->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(carr[i].get_attr())));
               sc_tw->setItem(rowCount, 5, new QTableWidgetItem(QString::fromStdString(carr[i].get_desc())));
               sc_tw->setItem(rowCount, 6, new QTableWidgetItem(QString::fromStdString(carr[i].get_sid())));
               sc_tw->setItem(rowCount, 7, new QTableWidgetItem(QString::fromStdString(carr[i].get_date())));
               sc_tw->setItem(rowCount, 8, new QTableWidgetItem(QString::fromStdString(carr[i].get_state())));
           }
        }
        sc_tw->show();
    }
    else if(msgBox->clickedButton() == attrbutton)
    { //按属性搜索
        QMessageBox* box2 = new QMessageBox;
        box2->setAttribute(Qt::WA_DeleteOnClose);
        box2->setWindowTitle("Search commodity");
        box2->setText("Please choose the attribute you want to search:");
        box2->setStandardButtons(QMessageBox::Cancel);
        QPushButton *button8 = (box2->addButton("other", QMessageBox::AcceptRole));
        QPushButton *button7 = (box2->addButton("digital", QMessageBox::AcceptRole));
        QPushButton *button6 = (box2->addButton("ornament", QMessageBox::AcceptRole));
        QPushButton *button5 = (box2->addButton("makeup", QMessageBox::AcceptRole));
        QPushButton *button4 = (box2->addButton("clothes", QMessageBox::AcceptRole));
        QPushButton *button3 = (box2->addButton("food", QMessageBox::AcceptRole));
        QPushButton *button2 = (box2->addButton("study", QMessageBox::AcceptRole));
        QPushButton *button1 = (box2->addButton("life", QMessageBox::AcceptRole));
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
        sc_tw = new QTableWidget;
        sc_tw->setAttribute(Qt::WA_DeleteOnClose);
        sc_tw->setWindowTitle("Users");
        sc_tw->resize(1350,450);
        sc_tw->setColumnCount(9);
        QStringList header;
        header << "commodityID" << "commodityname" << "price" << "number" << "attribute"
               << "description" << "sellerID" << "addedDate" << "state";
        sc_tw->setHorizontalHeaderLabels(header);
        sc_tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        sc_tw->setEditTriggers(QAbstractItemView::NoEditTriggers);
        CArray carr;
        carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
        for(int i = 0; i < carr.length(); ++i)
        {
            if (carr[i].get_attr() == category[attr])
            {
                int rowCount = sc_tw->rowCount();
                sc_tw->insertRow(rowCount);
                sc_tw->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(carr[i].get_id())));
                sc_tw->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(carr[i].get_name())));
                sc_tw->setItem(rowCount, 2, new QTableWidgetItem(QString::number(carr[i].get_price(), 'f', 1)));
                sc_tw->setItem(rowCount, 3, new QTableWidgetItem(QString::number(carr[i].get_num())));
                sc_tw->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(carr[i].get_attr())));
                sc_tw->setItem(rowCount, 5, new QTableWidgetItem(QString::fromStdString(carr[i].get_desc())));
                sc_tw->setItem(rowCount, 6, new QTableWidgetItem(QString::fromStdString(carr[i].get_sid())));
                sc_tw->setItem(rowCount, 7, new QTableWidgetItem(QString::fromStdString(carr[i].get_date())));
                sc_tw->setItem(rowCount, 8, new QTableWidgetItem(QString::fromStdString(carr[i].get_state())));
            }
        }
        sc_tw->show();
    }
    else
        return;
}

void adminWidget::on_rmvcommoButton_clicked()
{
    bool ok;
    QString id = QInputDialog::getText(this,"Remove commodity","Please input the commodityID you want to remove:",
                                           QLineEdit::Normal,"",&ok); //输入下架商品id
    if(!ok)
        return;
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

void adminWidget::on_logoutButton_clicked()
{
    this->close();
}
