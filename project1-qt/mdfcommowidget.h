#ifndef MDFCOMMOWIDGET_H
#define MDFCOMMOWIDGET_H
#include "commodity.h"

#include <QWidget>

namespace Ui {
class mdfcommoWidget;
}

class mdfcommoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mdfcommoWidget(QWidget *parent = nullptr);
    ~mdfcommoWidget();

private slots:
    void getCommodity(Commodity q);

    void on_commitButton_2_clicked();

    void on_cancelButton_2_clicked();

private:
    Ui::mdfcommoWidget *ui;
};

#endif // MDFCOMMOWIDGET_H
