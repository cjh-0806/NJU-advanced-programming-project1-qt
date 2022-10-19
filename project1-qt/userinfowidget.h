#ifndef USERINFOWIDGET_H
#define USERINFOWIDGET_H
#include "user.h"
#include "mdfuserwidget.h"

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class userinfoWidget;
}

class userinfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit userinfoWidget(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent *event);
    ~userinfoWidget();

private slots:
    void getUserIndex(int);

    void on_returnButton_clicked();

    void on_viewinfoButton_clicked();

    void on_rechargeButton_clicked();

    void on_mdfinfoButton_clicked();

signals:
    void sendUserIndex(int);

private:
    Ui::userinfoWidget *ui;
    int index;
    mdfuserWidget* mu_w;
};

#endif // USERINFOWIDGET_H
