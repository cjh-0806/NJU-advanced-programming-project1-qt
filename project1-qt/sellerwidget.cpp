#include "sellerwidget.h"
#include "ui_sellerwidget.h"
#include "user.h"
#include "commodity.h"
#include "order.h"

#include <QInputDialog>
#include <QMessageBox>
#include <QHeaderView>

sellerWidget::sellerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sellerWidget)
{
    ui->setupUi(this);
    //setAttribute(Qt::WA_QuitOnClose, false);
}

sellerWidget::~sellerWidget()
{
    delete ui;
}

void sellerWidget::getUserIndex(int i)
{
    this->index = i;
    UArray uarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    ui->label->setText("Hello, seller " + QString::fromStdString(uarr[index].get_name()) + "! Please choose your command:");
}

void sellerWidget::on_returnButton_clicked()
{
    this->close();
}

void sellerWidget::on_rlscommoButton_clicked()
{
    rlscommoWidget *rc_w = new rlscommoWidget;
    rc_w->setAttribute(Qt::WA_DeleteOnClose);
    rc_w->setWindowModality(Qt::ApplicationModal);
    connect(this,SIGNAL(sendUserIndex(int)),rc_w,SLOT(getUserIndex(int)));
    emit sendUserIndex(index);
    rc_w->show();
}

void sellerWidget::on_rmvcommoButton_clicked()
{
    bool ok;
    QString id = QInputDialog::getText(this,"Remove commodity","Please input the commodityID you want to remove:",
                                           QLineEdit::Normal,"",&ok); //输入下架商品id
    if(!ok)
        return;
    UArray uarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    CArray carr;
    carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
    int i;
    for(i = 0; i < carr.length(); ++i)
    {
        if (carr[i].get_id() == id.toStdString() && carr[i].get_sid() == uarr[index].get_id() && carr[i].get_state() == "onAuction")
        { //显示下架商品信息
            QString text = "commodityname:" + QString::fromStdString(carr[i].get_name())
                    + "\nprice:" + QString::number(carr[i].get_price(),'f', 1)
                    + "\nattribute:" + QString::fromStdString(carr[i].get_attr())
                    + "\ndescription:" + QString::fromStdString(carr[i].get_desc());
            if (QMessageBox::Yes == QMessageBox::question(this, "Are you sure to remove this commodity?", text))
            { //确认下架商品
                carr.clear();
                carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
                if(carr[i].get_state() == "removed")
                {
                    QMessageBox::warning(this, "Remove commodity", "This commodity has already been removed!");
                    return;
                }
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

void sellerWidget::on_mdfinfoButton_clicked()
{
    bool ok;
    QString id = QInputDialog::getText(this,"Modify commodity information","Please input the commodityID you want to modify:",
                                           QLineEdit::Normal,"",&ok); //输入要修改的商品id
    if(!ok)
        return;
    UArray uarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    CArray carr;
    carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
    int i;
    for(i = 0; i < carr.length(); ++i)
        if(carr[i].get_id() == id.toStdString() && carr[i].get_sid() == uarr[index].get_id() && carr[i].get_state() == "onAuction")
            break;
    if (i == carr.length())
    {
        QMessageBox::warning(this, "Modify commodity information", "This commodity doesn't exist!");
        return;
    }
    mdfcommoWidget *mc_w = new mdfcommoWidget;
    mc_w->setAttribute(Qt::WA_DeleteOnClose);
    mc_w->setWindowModality(Qt::ApplicationModal);
    connect(this, SIGNAL(sendCommodityIndex(int)),mc_w,SLOT(getCommodityIndex(int)));
    emit sendCommodityIndex(i);
    mc_w->show();
}

void sellerWidget::on_viewcommoButton_clicked()
{
    QTableWidget *vc_tw = new QTableWidget;
    vc_tw->setAttribute(Qt::WA_DeleteOnClose);
    vc_tw->setWindowModality(Qt::ApplicationModal);
    vc_tw->setWindowTitle("View released commodity");
    vc_tw->resize(1200,450);
    vc_tw->setColumnCount(8);
    QStringList header;
    header << "commodityID" << "commodityname" << "basePrice" << "number"
           << "attribute" << "description" << "addedDate" << "state";
    vc_tw->setHorizontalHeaderLabels(header);
    vc_tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    vc_tw->setEditTriggers(QAbstractItemView::NoEditTriggers);
    UArray uarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    CArray carr;
    carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
    for(int i = 0; i < carr.length(); ++i)
    {
        if(carr[i].get_sid() == uarr[index].get_id())
        {
            int rowCount = vc_tw->rowCount();
            vc_tw->insertRow(rowCount);
            vc_tw->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(carr[i].get_id())));
            vc_tw->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(carr[i].get_name())));
            vc_tw->setItem(rowCount, 2, new QTableWidgetItem(QString::number(carr[i].get_price(), 'f', 1)));
            vc_tw->setItem(rowCount, 3, new QTableWidgetItem(QString::number(carr[i].get_num())));
            vc_tw->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(carr[i].get_attr())));
            vc_tw->setItem(rowCount, 5, new QTableWidgetItem(QString::fromStdString(carr[i].get_desc())));
            vc_tw->setItem(rowCount, 6, new QTableWidgetItem(QString::fromStdString(carr[i].get_date())));
            vc_tw->setItem(rowCount, 7, new QTableWidgetItem(QString::fromStdString(carr[i].get_state())));
        }
    }
    vc_tw->show();
}

void sellerWidget::on_vieworderButton_clicked()
{
    QTableWidget *vo_tw = new QTableWidget;
    vo_tw->setAttribute(Qt::WA_DeleteOnClose);
    vo_tw->setWindowModality(Qt::ApplicationModal);
    UArray uarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    QString title = QString::fromStdString(uarr[index].get_name()) + "'s history orders(finished)";
    vo_tw->setWindowTitle(title);
    vo_tw->resize(900,450);
    vo_tw->setColumnCount(6);
    QStringList header;
    header << "orderID" << "commodityID" << "unitPrice" << "bidPrice" << "buyerID" << "date";
    vo_tw->setHorizontalHeaderLabels(header);
    vo_tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    vo_tw->setEditTriggers(QAbstractItemView::NoEditTriggers);
    OArray oarr;
    oarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/order.txt");
    for(int i = 0; i < oarr.length(); ++i)
    {
        if(oarr[i].get_sellerid() == uarr[index].get_id() && oarr[i].get_state() == "get")
        {
            int rowCount = vo_tw->rowCount();
            vo_tw->insertRow(rowCount);
            vo_tw->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(oarr[i].get_oid())));
            vo_tw->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(oarr[i].get_cid())));
            vo_tw->setItem(rowCount, 2, new QTableWidgetItem(QString::number(oarr[i].get_price(), 'f', 1)));
            vo_tw->setItem(rowCount, 3, new QTableWidgetItem(QString::number(oarr[i].get_bid(), 'f', 1)));
            vo_tw->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(oarr[i].get_buyerid())));
            vo_tw->setItem(rowCount, 5, new QTableWidgetItem(QString::fromStdString(oarr[i].get_date())));
        }
    }
    vo_tw->show();
}
