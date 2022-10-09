#ifndef SELLERWIDGET_H
#define SELLERWIDGET_H

#include <QWidget>

namespace Ui {
class sellerWidget;
}

class sellerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit sellerWidget(QWidget *parent = nullptr);
    ~sellerWidget();

private:
    Ui::sellerWidget *ui;
};

#endif // SELLERWIDGET_H
