#ifndef ULOGINWIDGET_H
#define ULOGINWIDGET_H

#include <QWidget>
#include "user.h"

namespace Ui {
class uloginWidget;
}

class uloginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit uloginWidget(QWidget *parent = nullptr);
    ~uloginWidget();

private slots:
    void on_commitButton_clicked();

    void on_cancelButton_clicked();

signals:
    void sendUserIndex(int);

private:
    Ui::uloginWidget *ui;
};

#endif // ULOGINWIDGET_H
