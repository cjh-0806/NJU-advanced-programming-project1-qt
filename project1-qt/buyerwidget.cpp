#include "buyerwidget.h"
#include "ui_buyerwidget.h"
#include "commodity.h"
#include "order.h"

#include <QTableWidget>
#include <QHeaderView>
#include <QInputDialog>
#include <QMessageBox>
#include <QPushButton>

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

void buyerWidget::on_returnButton_clicked()
{
    this->close();
}

void buyerWidget::on_viewcommoButton_clicked()
{
    QTableWidget* tw = new QTableWidget;
    tw->setAttribute(Qt::WA_DeleteOnClose);
    tw->setWindowTitle("Users");
    tw->resize(600,450);
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
           tw->resize(600,450);
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
        tw->resize(600,450);
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

}

void buyerWidget::on_vieworderButton_clicked(User& p)
{
    QTableWidget* tw = new QTableWidget;
    tw->setAttribute(Qt::WA_DeleteOnClose);
    tw->setWindowTitle("Users");
    tw->resize(600,450);
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
