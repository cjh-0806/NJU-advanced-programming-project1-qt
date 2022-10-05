/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *welcomeLabel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *uloginButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *registerButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *aloginButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *exitButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        Widget->setMinimumSize(QSize(800, 600));
        Widget->setMaximumSize(QSize(800, 600));
        welcomeLabel = new QLabel(Widget);
        welcomeLabel->setObjectName(QString::fromUtf8("welcomeLabel"));
        welcomeLabel->setGeometry(QRect(120, 70, 500, 120));
        welcomeLabel->setMinimumSize(QSize(500, 120));
        welcomeLabel->setMaximumSize(QSize(500, 120));
        QFont font;
        font.setPointSize(14);
        welcomeLabel->setFont(font);
        welcomeLabel->setLayoutDirection(Qt::LeftToRight);
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(70, 370, 641, 121));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        uloginButton = new QPushButton(widget);
        uloginButton->setObjectName(QString::fromUtf8("uloginButton"));
        uloginButton->setMinimumSize(QSize(95, 30));
        uloginButton->setMaximumSize(QSize(95, 30));
        uloginButton->setFont(font);

        horizontalLayout->addWidget(uloginButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        registerButton = new QPushButton(widget);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setFont(font);

        horizontalLayout->addWidget(registerButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        aloginButton = new QPushButton(widget);
        aloginButton->setObjectName(QString::fromUtf8("aloginButton"));
        aloginButton->setFont(font);

        horizontalLayout->addWidget(aloginButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        exitButton = new QPushButton(widget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setFont(font);

        horizontalLayout->addWidget(exitButton);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">Welcome commodity auction platform!</span></p></body></html>", nullptr));
        uloginButton->setText(QCoreApplication::translate("Widget", "User login", nullptr));
        registerButton->setText(QCoreApplication::translate("Widget", "User register", nullptr));
        aloginButton->setText(QCoreApplication::translate("Widget", "Administrator login", nullptr));
        exitButton->setText(QCoreApplication::translate("Widget", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
