#include "buyerwidget.h"
#include "ui_buyerwidget.h"
#include "commodity.h"
#include "order.h"

#include <QHeaderView>
#include <QInputDialog>
#include <QMessageBox>
#include <QPushButton>

#include <sstream>
#include <iomanip>

buyerWidget::buyerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::buyerWidget),
    vc_tw(nullptr), sc_tw(nullptr), vo_tw(nullptr)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_QuitOnClose, false);
}

void buyerWidget::closeEvent(QCloseEvent *event)
{
    if(vc_tw) vc_tw->close();
    if(sc_tw) sc_tw->close();
    if(vo_tw) vo_tw->close();
    event->accept();
}

buyerWidget::~buyerWidget()
{
    delete ui;
    delete vc_tw;
    delete sc_tw;
    delete vo_tw;
}

void buyerWidget::getUserIndex(int i)
{
    this->index = i;
    UArray uarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    ui->label->setText("Hello, buyer " + QString::fromStdString(uarr[index].get_name()) + "! Please choose your command:");
}

void buyerWidget::on_returnButton_clicked()
{
    this->close();
}

void buyerWidget::on_viewcommoButton_clicked()
{
    vc_tw = new QTableWidget;
    vc_tw->setAttribute(Qt::WA_DeleteOnClose);
    vc_tw->setWindowTitle("View commodity");
    vc_tw->resize(900,450);
    vc_tw->setColumnCount(6);
    QStringList header;
    header << "commodityID" << "commodityname" << "basePrice" << "number" << "attribute" << "description";
    vc_tw->setHorizontalHeaderLabels(header);
    vc_tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    vc_tw->setEditTriggers(QAbstractItemView::NoEditTriggers);
    CArray carr;
    carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
    for(int i = 0; i < carr.length(); ++i)
    {
        if(carr[i].get_state() == "onAuction")
        {
            int rowCount = vc_tw->rowCount();
            vc_tw->insertRow(rowCount);
            vc_tw->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(carr[i].get_id())));
            vc_tw->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(carr[i].get_name())));
            vc_tw->setItem(rowCount, 2, new QTableWidgetItem(QString::number(carr[i].get_price(), 'f', 1)));
            vc_tw->setItem(rowCount, 3, new QTableWidgetItem(QString::number(carr[i].get_num())));
            vc_tw->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(carr[i].get_attr())));
            vc_tw->setItem(rowCount, 5, new QTableWidgetItem(QString::fromStdString(carr[i].get_desc())));
        }
    }
    vc_tw->show();
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
        sc_tw = new QTableWidget;
        sc_tw->setAttribute(Qt::WA_DeleteOnClose);
        sc_tw->setWindowTitle("Search commodity");
        sc_tw->resize(900,450);
        sc_tw->setColumnCount(6);
        QStringList header;
        header << "commodityID" << "commodityname" << "price" << "number" << "attribute" << "description";
        sc_tw->setHorizontalHeaderLabels(header);
        sc_tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        sc_tw->setEditTriggers(QAbstractItemView::NoEditTriggers);
        CArray carr;
        carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
        for(int i = 0; i < carr.length(); ++i)
        {
           if (carr[i].get_name().find(name.toStdString()) != -1 && carr[i].get_state() == "onAuction")
           {
               int rowCount = sc_tw->rowCount();
               sc_tw->insertRow(rowCount);
               sc_tw->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(carr[i].get_id())));
               sc_tw->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(carr[i].get_name())));
               sc_tw->setItem(rowCount, 2, new QTableWidgetItem(QString::number(carr[i].get_price(), 'f', 1)));
               sc_tw->setItem(rowCount, 3, new QTableWidgetItem(QString::number(carr[i].get_num())));
               sc_tw->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(carr[i].get_attr())));
               sc_tw->setItem(rowCount, 5, new QTableWidgetItem(QString::fromStdString(carr[i].get_desc())));
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
        sc_tw->setWindowTitle("Search commodity");
        sc_tw->resize(900,450);
        sc_tw->setColumnCount(6);
        QStringList header;
        header << "commodityID" << "commodityname" << "price" << "number" << "attribute" << "description";
        sc_tw->setHorizontalHeaderLabels(header);
        sc_tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        sc_tw->setEditTriggers(QAbstractItemView::NoEditTriggers);
        CArray carr;
        carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
        for(int i = 0; i < carr.length(); ++i)
        {
            if (carr[i].get_attr() == category[attr] && carr[i].get_state() == "onAuction")
            {
                int rowCount = sc_tw->rowCount();
                sc_tw->insertRow(rowCount);
                sc_tw->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(carr[i].get_id())));
                sc_tw->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(carr[i].get_name())));
                sc_tw->setItem(rowCount, 2, new QTableWidgetItem(QString::number(carr[i].get_price(), 'f', 1)));
                sc_tw->setItem(rowCount, 3, new QTableWidgetItem(QString::number(carr[i].get_num())));
                sc_tw->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(carr[i].get_attr())));
                sc_tw->setItem(rowCount, 5, new QTableWidgetItem(QString::fromStdString(carr[i].get_desc())));
            }
        }
        sc_tw->show();
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
    UArray uarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    if(carr[i].get_sid() == uarr[index].get_id())
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
    OArray oarr;
    oarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/order.txt");
    if(msgBox->clickedButton() == bidbutton)
    {
        int j;
        for(j = 0; j < oarr.length(); ++j)
            if(oarr[j].get_buyerid() == uarr[index].get_id() && oarr[j].get_cid() == carr[i].get_id() && oarr[j].get_state() == "unfinished")
            {
                QMessageBox::warning(this, "Auction", "You have already bid for this commodity!");
                return;
            }
        if(uarr[index].get_balance() <= carr[i].get_price())
        {
            QMessageBox::warning(this, "Auction", "Your balance is insufficient!");
            return;
        }
        double bidPrice = QInputDialog::getDouble(this,"Auction","Please input your bidPrice:",0,
                                                  carr[i].get_price(),uarr[index].get_balance(),1,&ok); //出价
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
        oarr.push_back(Order(orderID, carr[i].get_id(), carr[i].get_price(), bidPrice, orderdate, carr[i].get_sid(), uarr[index].get_id(), "unfinished"));
        oarr.array2file("/home/cjh/NJU-advanced-programming-project1-qt/order.txt");
        QMessageBox::information(this, "INFOMATION", "Offer bid successfully!");
    }
    else if(msgBox->clickedButton() == mdfbutton)
    {
        int j;
        for(j = 0; j < oarr.length(); ++j)
            if(oarr[j].get_buyerid() == uarr[index].get_id() && oarr[j].get_cid() == carr[i].get_id() && oarr[j].get_state() == "unfinished")
                break;
        if(j == oarr.length())
        {
            QMessageBox::warning(this, "Auction", "You haven't bid for this commodity!");
            return;
        }
        if(uarr[index].get_balance() <= carr[i].get_price())
        {
            QMessageBox::warning(this, "Auction", "Your balance is insufficient!");
            return;
        }
        double bidPrice = QInputDialog::getDouble(this,"Auction","Please input your modified bidPrice:",0,
                                                          carr[i].get_price(),uarr[index].get_balance(),1,&ok);
        if(!ok)
            return;
        oarr[j].set_bid(bidPrice);
        oarr.array2file("/home/cjh/NJU-advanced-programming-project1-qt/order.txt");
        QMessageBox::information(this, "INFOMATION", "Modify bid successfully!");
    }
    else if(msgBox->clickedButton() == cancelbutton)
    {
        int j;
        for(j = 0; j < oarr.length(); ++j)
            if(oarr[j].get_buyerid() == uarr[index].get_id() && oarr[j].get_cid() == carr[i].get_id() && oarr[j].get_state() == "unfinished")
            {
                oarr[j].set_state("canceled");
                oarr.array2file("/home/cjh/NJU-advanced-programming-project1-qt/order.txt");
                QMessageBox::information(this, "INFOMATION", "Cancel bid successfully!");
            }
        if(j == oarr.length())
        {
            QMessageBox::warning(this, "Auction", "You haven't bid for this commodity!");
            return;
        }
    }
}

void buyerWidget::on_vieworderButton_clicked()
{
    vo_tw = new QTableWidget;
    vo_tw->setAttribute(Qt::WA_DeleteOnClose);
    UArray uarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    QString title = QString::fromStdString(uarr[index].get_name()) + "'s history orders";
    vo_tw->setWindowTitle(title);
    vo_tw->resize(900,450);
    vo_tw->setColumnCount(6);
    QStringList header;
    header << "orderID" << "commodityID" << "unitPrice" << "bidPrice" << "date" << "state";
    vo_tw->setHorizontalHeaderLabels(header);
    vo_tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    vo_tw->setEditTriggers(QAbstractItemView::NoEditTriggers);
    OArray oarr;
    oarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/order.txt");
    for(int i = 0; i < oarr.length(); ++i)
    {
        if(oarr[i].get_buyerid() == uarr[index].get_id())
        {
            int rowCount = vo_tw->rowCount();
            vo_tw->insertRow(rowCount);
            vo_tw->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(oarr[i].get_oid())));
            vo_tw->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(oarr[i].get_cid())));
            vo_tw->setItem(rowCount, 2, new QTableWidgetItem(QString::number(oarr[i].get_price(), 'f', 1)));
            vo_tw->setItem(rowCount, 3, new QTableWidgetItem(QString::number(oarr[i].get_bid(), 'f', 1)));
            vo_tw->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(oarr[i].get_date())));
            vo_tw->setItem(rowCount, 5, new QTableWidgetItem(QString::fromStdString(oarr[i].get_state())));
        }
    }
    vo_tw->show();
}
