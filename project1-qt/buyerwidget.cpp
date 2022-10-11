#include "buyerwidget.h"
#include "ui_buyerwidget.h"
#include "commodity.h"
#include "order.h"

#include <QTableWidget>
#include <QHeaderView>
#include <QInputDialog>
#include <QMessageBox>
#include <QPushButton>

#include <sstream>
#include <iomanip>

buyerWidget::buyerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::buyerWidget)
{
    ui->setupUi(this);
}

buyerWidget::~buyerWidget()
{
    delete ui;
}

void buyerWidget::getUser(User p)
{
    this->p = p;
    ui->label->setText("Hello, buyer " + QString::fromStdString(p.get_name()) + "! Please choose your command:");
}

void buyerWidget::on_returnButton_clicked()
{
    this->close();
}

void buyerWidget::on_viewcommoButton_clicked()
{
    QTableWidget* tw = new QTableWidget;
    tw->setAttribute(Qt::WA_DeleteOnClose);
    tw->setWindowTitle("View commodity");
    tw->resize(900,450);
    tw->setColumnCount(6);
    QStringList header;
    header << "commodityID" << "commodityname" << "basePrice" << "number" << "attribute" << "description";
    tw->setHorizontalHeaderLabels(header);
    tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tw->setEditTriggers(QAbstractItemView::NoEditTriggers);
    CArray carr;
    carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
    for(int i = 0; i < carr.length(); ++i)
    {
        if(carr[i].get_state() == "onAuction")
        {
            int rowCount = tw->rowCount();
            tw->insertRow(rowCount);
            tw->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(carr[i].get_id())));
            tw->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(carr[i].get_name())));
            tw->setItem(rowCount, 2, new QTableWidgetItem(QString::number(carr[i].get_price(), 'f', 1)));
            tw->setItem(rowCount, 3, new QTableWidgetItem(QString::number(carr[i].get_num())));
            tw->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(carr[i].get_attr())));
            tw->setItem(rowCount, 5, new QTableWidgetItem(QString::fromStdString(carr[i].get_desc())));
        }
    }
    tw->show();
}

void buyerWidget::on_srchcommoButton_clicked()
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
        QTableWidget* tw = new QTableWidget;
        tw->setAttribute(Qt::WA_DeleteOnClose);
        tw->setWindowTitle("Users");
        tw->resize(900,450);
        tw->setColumnCount(6);
        QStringList header;
        header << "commodityID" << "commodityname" << "price" << "number" << "attribute" << "description";
        tw->setHorizontalHeaderLabels(header);
        tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        tw->setEditTriggers(QAbstractItemView::NoEditTriggers);
        CArray carr;
        carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
        for(int i = 0; i < carr.length(); ++i)
        {
           if (carr[i].get_name().find(name.toStdString()) != -1 && carr[i].get_state() == "onAuction")
           {
               int rowCount = tw->rowCount();
               tw->insertRow(rowCount);
               tw->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(carr[i].get_id())));
               tw->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(carr[i].get_name())));
               tw->setItem(rowCount, 2, new QTableWidgetItem(QString::number(carr[i].get_price(), 'f', 1)));
               tw->setItem(rowCount, 3, new QTableWidgetItem(QString::number(carr[i].get_num())));
               tw->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(carr[i].get_attr())));
               tw->setItem(rowCount, 5, new QTableWidgetItem(QString::fromStdString(carr[i].get_desc())));
           }
        }
        tw->show();
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
        QTableWidget* tw = new QTableWidget;
        tw->setAttribute(Qt::WA_DeleteOnClose);
        tw->setWindowTitle("Search commodity");
        tw->resize(900,450);
        tw->setColumnCount(6);
        QStringList header;
        header << "commodityID" << "commodityname" << "price" << "number" << "attribute" << "description";
        tw->setHorizontalHeaderLabels(header);
        tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        tw->setEditTriggers(QAbstractItemView::NoEditTriggers);
        CArray carr;
        carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
        for(int i = 0; i < carr.length(); ++i)
        {
            if (carr[i].get_attr() == category[attr] && carr[i].get_state() == "onAuction")
            {
                int rowCount = tw->rowCount();
                tw->insertRow(rowCount);
                tw->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(carr[i].get_id())));
                tw->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(carr[i].get_name())));
                tw->setItem(rowCount, 2, new QTableWidgetItem(QString::number(carr[i].get_price(), 'f', 1)));
                tw->setItem(rowCount, 3, new QTableWidgetItem(QString::number(carr[i].get_num())));
                tw->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(carr[i].get_attr())));
                tw->setItem(rowCount, 5, new QTableWidgetItem(QString::fromStdString(carr[i].get_desc())));
            }
        }
        tw->show();
    }
    else
        return;
}

void buyerWidget::on_auctionButton_clicked()
{
    bool ok;
    QString cid = QInputDialog::getText(this,"Auction","Please input the commodityID you want to auction:",
                                        QLineEdit::Normal,"",&ok); //输入商品ID
    if(!ok)
        return;
    CArray carr;
    carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
    int i;
    for(i = 0; i < carr.length(); ++i)
        if (carr[i].get_id() == cid.toStdString() && carr[i].get_state() == "onAuction")
            break;
    if (i == carr.length())
    {
        QMessageBox::warning(this, "Auction", "Find nothing!");
        return;
    }
    if(carr[i].get_sid() == p.get_id())
    {
        QMessageBox::warning(this, "Auction", "The commodity is released by you!!!");
        return;
    }
    //显示商品信息
    QString text = "Commodity information:\nname:" + QString::fromStdString(carr[i].get_name())
            + "\nbasePrice:" + QString::number(carr[i].get_price(),'f', 1)
            + "\nnumber:" + QString::number(carr[i].get_num())
            + "\nattribute:" + QString::fromStdString(carr[i].get_attr())
            + "\ndescription:" + QString::fromStdString(carr[i].get_desc());
    QMessageBox* msgBox = new QMessageBox;
    msgBox->setAttribute(Qt::WA_DeleteOnClose);
    msgBox->setWindowTitle("Auction");
    msgBox->setText(text);
    msgBox->setStandardButtons(QMessageBox::Close);
    QPushButton *bidbutton = (msgBox->addButton("offer bid", QMessageBox::AcceptRole));
    QPushButton *mdfbutton = (msgBox->addButton("modify bid", QMessageBox::AcceptRole));
    QPushButton *cancelbutton = (msgBox->addButton("cancel bid", QMessageBox::AcceptRole));
    msgBox->exec();
    if(msgBox->clickedButton() == bidbutton)
    {
        double bidPrice = QInputDialog::getDouble(this,"Auction","Please input your bidPrice:",0,
                                                  carr[i].get_price(),p.get_balance(),1,&ok); //出价
        if(!ok)
            return;
        OArray oarr;
        oarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/order.txt");
        stringstream ss;
        ss << 'T' << setfill('0') << setw(3) << oarr.length() + 1;
        string orderID = ss.str();
        time_t tt = time(NULL);
        struct tm* t= localtime(&tt);
        char date[20];
        strftime(date, sizeof(date), "%F %T", t);
        string orderdate = date;
        oarr.push_back(Order(orderID, carr[i].get_id(), carr[i].get_price(), bidPrice, orderdate, carr[i].get_sid(), p.get_id(), "unfinished"));
        oarr.array2file("/home/cjh/NJU-advanced-programming-project1-qt/order.txt");
        QMessageBox::information(this, "INFOMATION", "Offer bid successfully!");
    }
    else if(msgBox->clickedButton() == mdfbutton)
    {
        OArray oarr;
        oarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/order.txt");
        int j;
        for(j = 0; j < oarr.length(); ++j)
            if(oarr[j].get_buyerid() == p.get_id() && oarr[j].get_cid() == carr[i].get_id() && oarr[j].get_state() == "unfinished")
                break;
        if(j == oarr.length())
        {
            QMessageBox::warning(this, "Auction", "You haven't bid for this commodity!");
            return;
        }
        double bidPrice = QInputDialog::getDouble(this,"Auction","Please input your modified bidPrice:",0,
                                                          carr[i].get_price(),p.get_balance(),1,&ok);
        if(!ok)
            return;
        oarr[j].set_bid(bidPrice);
        oarr.array2file("/home/cjh/NJU-advanced-programming-project1-qt/order.txt");
        QMessageBox::information(this, "INFOMATION", "Modify bid successfully!");
    }
    else if(msgBox->clickedButton() == cancelbutton)
    {
        int j;
        OArray oarr;
        oarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/order.txt");
        for(j = 0; j < oarr.length(); ++j)
            if(oarr[j].get_buyerid() == p.get_id() && oarr[j].get_cid() == carr[i].get_id() && oarr[j].get_state() == "unfinished")
            {
                oarr[j].set_state("canceled");
                oarr.array2file("/home/cjh/NJU-advanced-programming-project1-qt/order.txt");
                QMessageBox::information(this, "INFOMATION", "Cancel bid successfully!");
            }
    }
}

void buyerWidget::on_vieworderButton_clicked()
{
    QTableWidget* tw = new QTableWidget;
    tw->setAttribute(Qt::WA_DeleteOnClose);
    QString title = QString::fromStdString(p.get_name()) + "'s history orders";
    tw->setWindowTitle(title);
    tw->resize(900,450);
    tw->setColumnCount(6);
    QStringList header;
    header << "orderID" << "commodityID" << "unitPrice" << "bidPrice" << "date" << "state";
    tw->setHorizontalHeaderLabels(header);
    tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tw->setEditTriggers(QAbstractItemView::NoEditTriggers);
    OArray oarr;
    oarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/order.txt");
    for(int i = 0; i < oarr.length(); ++i)
    {
        if(oarr[i].get_buyerid() == p.get_id())
        {
            int rowCount = tw->rowCount();
            tw->insertRow(rowCount);
            tw->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(oarr[i].get_oid())));
            tw->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(oarr[i].get_cid())));
            tw->setItem(rowCount, 2, new QTableWidgetItem(QString::number(oarr[i].get_price(), 'f', 1)));
            tw->setItem(rowCount, 3, new QTableWidgetItem(QString::number(oarr[i].get_bid(), 'f', 1)));
            tw->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(oarr[i].get_date())));
            tw->setItem(rowCount, 5, new QTableWidgetItem(QString::fromStdString(oarr[i].get_state())));
        }
    }
    tw->show();
}
