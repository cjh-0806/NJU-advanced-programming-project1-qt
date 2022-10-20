#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
#include "user.h"
#include "buyerwidget.h"
#include "sellerwidget.h"
#include "userinfowidget.h"

namespace Ui {
class userWidget;
}

class userWidget : public QWidget
{
    Q_OBJECT

public:
    explicit userWidget(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent *event);
    ~userWidget();

private slots:
    void getUserIndex(int i);

    void on_buyerButton_clicked();

    void on_sellerButton_clicked();

    void on_infoButton_clicked();

    void on_logoutButton_clicked();

signals:
    void sendUserIndex(int);
    void sendReshowSignal();

private:
    Ui::userWidget *ui;
    int index;
    buyerWidget *b_w;
    sellerWidget *s_w;
    userinfoWidget *ui_w;
};

#endif // USERWIDGET_H
