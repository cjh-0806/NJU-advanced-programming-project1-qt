#ifndef USERINFOWIDGET_H
#define USERINFOWIDGET_H

#include <QWidget>

namespace Ui {
class userinfoWidget;
}

class userinfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit userinfoWidget(QWidget *parent = nullptr);
    ~userinfoWidget();

private:
    Ui::userinfoWidget *ui;
};

#endif // USERINFOWIDGET_H
