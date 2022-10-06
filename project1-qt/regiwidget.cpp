#include "regiwidget.h"
#include "ui_regiwidget.h"

regiwidget::regiwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::regiwidget)
{
    ui->setupUi(this);
}

regiwidget::~regiwidget()
{
    delete ui;
}
