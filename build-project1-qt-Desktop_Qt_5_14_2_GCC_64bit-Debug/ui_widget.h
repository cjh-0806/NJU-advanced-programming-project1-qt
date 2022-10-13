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
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *uloginButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *registerButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *aloginButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *exitButton;
    QLabel *picLabel;

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
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 410, 641, 121));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        uloginButton = new QPushButton(layoutWidget);
        uloginButton->setObjectName(QString::fromUtf8("uloginButton"));
        uloginButton->setMinimumSize(QSize(95, 30));
        uloginButton->setMaximumSize(QSize(95, 30));
        uloginButton->setFont(font);

        horizontalLayout->addWidget(uloginButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        registerButton = new QPushButton(layoutWidget);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setFont(font);

        horizontalLayout->addWidget(registerButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        aloginButton = new QPushButton(layoutWidget);
        aloginButton->setObjectName(QString::fromUtf8("aloginButton"));
        aloginButton->setFont(font);

        horizontalLayout->addWidget(aloginButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        exitButton = new QPushButton(layoutWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setFont(font);

        horizontalLayout->addWidget(exitButton);

        picLabel = new QLabel(Widget);
        picLabel->setObjectName(QString::fromUtf8("picLabel"));
        picLabel->setGeometry(QRect(260, 190, 200, 200));
        picLabel->setMinimumSize(QSize(200, 200));
        picLabel->setMaximumSize(QSize(200, 200));
        picLabel->setScaledContents(true);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Main window", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">Welcome commodity auction platform!</span></p></body></html>", nullptr));
        uloginButton->setText(QCoreApplication::translate("Widget", "User login", nullptr));
        registerButton->setText(QCoreApplication::translate("Widget", "User register", nullptr));
        aloginButton->setText(QCoreApplication::translate("Widget", "Administrator login", nullptr));
        exitButton->setText(QCoreApplication::translate("Widget", "Exit", nullptr));
        picLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
