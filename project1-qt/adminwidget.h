#ifndef ADMINWIDGET_H
#define ADMINWIDGET_H

#include <QWidget>

namespace Ui {
class adminWidget;
}

class adminWidget : public QWidget
{
    Q_OBJECT

public:
    explicit adminWidget(QWidget *parent = nullptr);
    ~adminWidget();

private slots:
    void on_viewuserButton_clicked();

    void on_banuserButton_clicked();

    void on_vieworderButton_clicked();

    void on_viewcommoButton_clicked();

    void on_srchcommoButton_clicked();

    void on_rmvcommoButton_clicked();

    void on_logoutButton_clicked();

private:
    Ui::adminWidget *ui;
};

#endif // ADMINWIDGET_H
