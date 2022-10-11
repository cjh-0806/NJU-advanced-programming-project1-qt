#ifndef MDFCOMMOWIDGET_H
#define MDFCOMMOWIDGET_H

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
    void getCommodityIndex(int i);

    void on_commitButton_2_clicked();

    void on_cancelButton_2_clicked();

private:
    Ui::mdfcommoWidget *ui;
    int i;
};

#endif // MDFCOMMOWIDGET_H
