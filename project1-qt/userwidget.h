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
    void getUser(User p);

    void on_buyerButton_clicked();

    void on_sellerButton_clicked();

    void on_infoButton_clicked();

    void on_logoutButton_clicked();

signals:
    void sendUser(User);

private:
    User p;
    Ui::userWidget *ui;
};

#endif // USERWIDGET_H
