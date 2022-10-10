#include "sellerwidget.h"
#include "ui_sellerwidget.h"
#include "rlscommowidget.h"
#include "mdfcommowidget.h"
#include "user.h"
#include "commodity.h"
#include "order.h"

#include <QInputDialog>
#include <QMessageBox>
#include <QTableWidget>
#include <QHeaderView>

sellerWidget::sellerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sellerWidget)
{
    ui->setupUi(this);
}

sellerWidget::~sellerWidget()
{
    delete ui;
}

void sellerWidget::getUser(User p)
{
    this->p = p;
}

void sellerWidget::on_returnButton_clicked()
{
    this->close();
}

void sellerWidget::on_rlscommoButton_clicked()
{
    rlscommoWidget* rc_w = new rlscommoWidget;
    connect(this,SIGNAL(sendUser(User)),rc_w,SLOT(getUser(User)));
    emit sendUser(p);
    rc_w->show();
}

void sellerWidget::on_rmvcommoButton_clicked()
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
        if (carr[i].get_id() == id.toStdString() && carr[i].get_sid() == p.get_id() && carr[i].get_state() == "onAuction")
        { //显示下架商品信息
            QString text = "commodityname:" + QString::fromStdString(carr[i].get_name())
                    + "\nprice:" + QString::number(carr[i].get_price(),'f', 1)
                    + "\nattribute:" + QString::fromStdString(carr[i].get_attr())
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

void sellerWidget::on_mdfinfoButton_clicked()
{
    bool ok;
    QString id = QInputDialog::getText(this,"Modify commodity information","Please input the commodityID you want to modify:",
                                           QLineEdit::Normal,"",&ok); //输入下架商品id
    if(!ok)
        return;
    CArray carr;
    carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
    int i;
    for(i = 0; i < carr.length(); ++i)
        if(carr[i].get_id() == id.toStdString() && carr[i].get_sid() == p.get_id() && carr[i].get_state() == "onAuction")
            break;
    if (i == carr.length())
    {
        QMessageBox::warning(this, "Modify commodity information", "This commodity doesn't exist!");\
        return;
    }
    mdfcommoWidget* mc_w = new mdfcommoWidget;
    connect(this, SIGNAL(sendCommodity(Commodity)),mc_w,SLOT(getCommodity(Commodity)));
    emit sendCommodity(carr[i]);
    mc_w->show();
}

void sellerWidget::on_viewcommoButton_clicked()
{
    QTableWidget* tw = new QTableWidget;
    tw->setAttribute(Qt::WA_DeleteOnClose);
    tw->setWindowTitle("Users");
    tw->resize(800,450);
    tw->setColumnCount(8);
    QStringList header;
    header << "commodityID" << "commodityname" << "price" << "number"
           << "attribute" << "description" << "addedDate" << "state";
    tw->setHorizontalHeaderLabels(header);
    tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tw->setEditTriggers(QAbstractItemView::NoEditTriggers);
    CArray carr;
    carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
    for(int i = 0; i < carr.length(); ++i)
    {
        if(carr[i].get_sid() == p.get_id())
        {
            int rowCount = tw->rowCount();
            tw->insertRow(rowCount);
            tw->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(carr[i].get_id())));
            tw->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(carr[i].get_name())));
            tw->setItem(rowCount, 2, new QTableWidgetItem(QString::number(carr[i].get_price(), 'f', 1)));
            tw->setItem(rowCount, 3, new QTableWidgetItem(QString::number(carr[i].get_num())));
            tw->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(carr[i].get_attr())));
            tw->setItem(rowCount, 5, new QTableWidgetItem(QString::fromStdString(carr[i].get_desc())));
            tw->setItem(rowCount, 6, new QTableWidgetItem(QString::fromStdString(carr[i].get_date())));
            tw->setItem(rowCount, 7, new QTableWidgetItem(QString::fromStdString(carr[i].get_state())));
        }
    }
    tw->show();
}

void sellerWidget::on_vieworderButton_clicked()
{
    QTableWidget* tw = new QTableWidget;
    tw->setAttribute(Qt::WA_DeleteOnClose);
    tw->setWindowTitle("Users");
    tw->resize(500,450);
    tw->setColumnCount(5);
    QStringList header;
    header << "orderID" << "commodityID" << "unitPrice" << "bidPrice" << "date";
    tw->setHorizontalHeaderLabels(header);
    tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tw->setEditTriggers(QAbstractItemView::NoEditTriggers);
    OArray oarr;
    oarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/order.txt");
    for(int i = 0; i < oarr.length(); ++i)
    {
        if(oarr[i].get_sellerid() == p.get_id() && oarr[i].get_state() == "finished")
        {
            int rowCount = tw->rowCount();
            tw->insertRow(rowCount);
            tw->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(oarr[i].get_oid())));
            tw->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(oarr[i].get_cid())));
            tw->setItem(rowCount, 2, new QTableWidgetItem(QString::number(oarr[i].get_price(), 'f', 1)));
            tw->setItem(rowCount, 3, new QTableWidgetItem(QString::number(oarr[i].get_bid(), 'f', 1)));
            tw->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(oarr[i].get_date())));
        }
    }
    tw->show();
}
