#ifndef ACOMMANDWIDGET_H
#define ACOMMANDWIDGET_H

#include <QWidget>

namespace Ui {
class acommandWidget;
}

class acommandWidget : public QWidget
{
    Q_OBJECT

public:
    explicit acommandWidget(QWidget *parent = nullptr);
    ~acommandWidget();

private slots:
    void on_viewuserButton_clicked();

    void on_banuserButton_clicked();

    void on_vieworderButton_clicked();

    void on_viewcommoButton_clicked();

    void on_srchcommoButton_clicked();

    void on_rmvcommoButton_clicked();

    void on_logoutButton_clicked();

private:
    Ui::acommandWidget *ui;
};

#endif // ACOMMANDWIDGET_H
