#ifndef REGIWIDGET_H
#define REGIWIDGET_H

#include <QWidget>
#include "user.h"

namespace Ui {
class regiWidget;
}

class regiWidget : public QWidget
{
    Q_OBJECT

public:
    explicit regiWidget(QWidget *parent = nullptr);
    ~regiWidget();

private slots:
    void on_commitButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::regiWidget *ui;
};

#endif // REGIWIDGET_H
