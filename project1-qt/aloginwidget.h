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

private slots:
    void on_commitButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::aloginWidget *ui;
};

#endif // ALOGINWIDGET_H
