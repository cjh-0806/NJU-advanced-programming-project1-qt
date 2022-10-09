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
    void on_returnButton_clicked();

    void on_viewcommoButton_clicked();

    void on_srchcommoButton_clicked();

    void on_auctionButton_clicked();

    void on_vieworderButton_clicked(User& p);

private:
    Ui::buyerWidget *ui;
};

#endif // BUYERWIDGET_H
