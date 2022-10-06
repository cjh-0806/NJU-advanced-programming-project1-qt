#ifndef ALOGINWIDGET_H
#define ALOGINWIDGET_H

#include <QWidget>

namespace Ui {
class aloginWidget;
}

class aloginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit aloginWidget(QWidget *parent = nullptr);
    ~aloginWidget();

private:
    Ui::aloginWidget *ui;
};

#endif // ALOGINWIDGET_H
