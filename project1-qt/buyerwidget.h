#ifndef BUYERWIDGET_H
#define BUYERWIDGET_H

#include <QWidget>
#include "user.h"

namespace Ui {
class buyerWidget;
}

class buyerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit buyerWidget(QWidget *parent = nullptr);
    ~buyerWidget();

private slots:
    void getUser(User p);

    void on_returnButton_clicked();

    void on_viewcommoButton_clicked();

    void on_srchcommoButton_clicked();

    void on_auctionButton_clicked();

    void on_vieworderButton_clicked();

private:
    Ui::buyerWidget *ui;
    User p;
};

#endif // BUYERWIDGET_H
