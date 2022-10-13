#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
#include "user.h"

namespace Ui {
class userWidget;
}

class userWidget : public QWidget
{
    Q_OBJECT

public:
    explicit userWidget(QWidget *parent = nullptr);
    ~userWidget();

private slots:
    void getUserIndex(int i);

    void on_buyerButton_clicked();

    void on_sellerButton_clicked();

    void on_infoButton_clicked();

    void on_logoutButton_clicked();

signals:
    void sendUserIndex(int);

private:
    Ui::userWidget *ui;
    int index;
};

#endif // USERWIDGET_H
