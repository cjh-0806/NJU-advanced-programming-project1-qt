#ifndef MDFUSERWIDGET_H
#define MDFUSERWIDGET_H

#include <QWidget>

namespace Ui {
class mdfuserWidget;
}

class mdfuserWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mdfuserWidget(QWidget *parent = nullptr);
    ~mdfuserWidget();

private slots:
    void getUserIndex(int i);

    void on_commitButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::mdfuserWidget *ui;
    int index;
};

#endif // MDFUSERWIDGET_H
