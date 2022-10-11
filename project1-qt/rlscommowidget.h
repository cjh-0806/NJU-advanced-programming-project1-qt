#ifndef RLSCOMMOWIDGET_H
#define RLSCOMMOWIDGET_H

#include "user.h"
#include <QWidget>

namespace Ui {
class rlscommoWidget;
}

class rlscommoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit rlscommoWidget(QWidget *parent = nullptr);
    ~rlscommoWidget();

private slots:
    void getUser(User p);

    void on_commitButton_2_clicked();

    void on_cancelButton_2_clicked();

private:
    Ui::rlscommoWidget *ui;
    User p;
};

#endif // RLSCOMMOWIDGET_H
