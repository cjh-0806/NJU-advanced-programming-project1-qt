#ifndef SELLERWIDGET_H
#define SELLERWIDGET_H

#include <QWidget>
#include "user.h"
#include "commodity.h"

namespace Ui {
class sellerWidget;
}

class sellerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit sellerWidget(QWidget *parent = nullptr);
    ~sellerWidget();

private slots:
    void getUser(User p);

    void on_returnButton_clicked();

    void on_rlscommoButton_clicked();

    void on_rmvcommoButton_clicked();

    void on_mdfinfoButton_clicked();

    void on_viewcommoButton_clicked();

    void on_vieworderButton_clicked();

signals:
    void sendUser(User);
    void sendCommodityIndex(int);

private:
    Ui::sellerWidget *ui;
    User p;
};

#endif // SELLERWIDGET_H
