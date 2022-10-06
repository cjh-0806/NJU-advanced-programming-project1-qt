#ifndef REGIWIDGET_H
#define REGIWIDGET_H

#include <QWidget>

namespace Ui {
class regiwidget;
}

class regiwidget : public QWidget
{
    Q_OBJECT

public:
    explicit regiwidget(QWidget *parent = nullptr);
    ~regiwidget();

private:
    Ui::regiwidget *ui;
};

#endif // REGIWIDGET_H
