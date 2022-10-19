#ifndef SELLERWIDGET_H
#define SELLERWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QCloseEvent>

#include "user.h"
#include "commodity.h"
#include "rlscommowidget.h"
#include "mdfcommowidget.h"

namespace Ui {
class sellerWidget;
}

class sellerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit sellerWidget(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent *event);
    ~sellerWidget();

private slots:
    void getUserIndex(int i);

    void on_returnButton_clicked();

    void on_rlscommoButton_clicked();

    void on_rmvcommoButton_clicked();

    void on_mdfinfoButton_clicked();

    void on_viewcommoButton_clicked();

    void on_vieworderButton_clicked();

signals:
    void sendUserIndex(int);
    void sendCommodityIndex(int);

private:
    Ui::sellerWidget *ui;
    int index;
    rlscommoWidget* rc_w;
    mdfcommoWidget* mc_w;
    QTableWidget* vc_tw;
    QTableWidget* vo_tw;
};

#endif // SELLERWIDGET_H
