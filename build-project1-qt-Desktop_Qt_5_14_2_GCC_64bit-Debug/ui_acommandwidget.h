/********************************************************************************
** Form generated from reading UI file 'acommandwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACOMMANDWIDGET_H
#define UI_ACOMMANDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_acommandWidget
{
public:
    QPushButton *logoutButton;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *viewuserButton;
    QSpacerItem *verticalSpacer;
    QPushButton *viewcommoButton;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPushButton *banuserButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *srchcommoButton;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *vieworderButton;
    QSpacerItem *verticalSpacer_3;
    QPushButton *rmvcommoButton;

    void setupUi(QWidget *acommandWidget)
    {
        if (acommandWidget->objectName().isEmpty())
            acommandWidget->setObjectName(QString::fromUtf8("acommandWidget"));
        acommandWidget->resize(600, 450);
        acommandWidget->setMinimumSize(QSize(600, 450));
        acommandWidget->setMaximumSize(QSize(600, 450));
        logoutButton = new QPushButton(acommandWidget);
        logoutButton->setObjectName(QString::fromUtf8("logoutButton"));
        logoutButton->setGeometry(QRect(220, 300, 140, 27));
        QFont font;
        font.setPointSize(12);
        logoutButton->setFont(font);
        label = new QLabel(acommandWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 60, 451, 41));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        widget = new QWidget(acommandWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 160, 541, 101));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        viewuserButton = new QPushButton(widget);
        viewuserButton->setObjectName(QString::fromUtf8("viewuserButton"));
        viewuserButton->setFont(font);

        verticalLayout->addWidget(viewuserButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        viewcommoButton = new QPushButton(widget);
        viewcommoButton->setObjectName(QString::fromUtf8("viewcommoButton"));
        viewcommoButton->setFont(font);

        verticalLayout->addWidget(viewcommoButton);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        banuserButton = new QPushButton(widget);
        banuserButton->setObjectName(QString::fromUtf8("banuserButton"));
        banuserButton->setFont(font);

        verticalLayout_2->addWidget(banuserButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        srchcommoButton = new QPushButton(widget);
        srchcommoButton->setObjectName(QString::fromUtf8("srchcommoButton"));
        srchcommoButton->setFont(font);

        verticalLayout_2->addWidget(srchcommoButton);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        vieworderButton = new QPushButton(widget);
        vieworderButton->setObjectName(QString::fromUtf8("vieworderButton"));
        vieworderButton->setFont(font);

        verticalLayout_3->addWidget(vieworderButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        rmvcommoButton = new QPushButton(widget);
        rmvcommoButton->setObjectName(QString::fromUtf8("rmvcommoButton"));
        rmvcommoButton->setFont(font);

        verticalLayout_3->addWidget(rmvcommoButton);


        horizontalLayout->addLayout(verticalLayout_3);


        retranslateUi(acommandWidget);

        QMetaObject::connectSlotsByName(acommandWidget);
    } // setupUi

    void retranslateUi(QWidget *acommandWidget)
    {
        acommandWidget->setWindowTitle(QCoreApplication::translate("acommandWidget", "Form", nullptr));
        logoutButton->setText(QCoreApplication::translate("acommandWidget", "Logout", nullptr));
        label->setText(QCoreApplication::translate("acommandWidget", "Hello,administrator! Please choose your command:", nullptr));
        viewuserButton->setText(QCoreApplication::translate("acommandWidget", "View users", nullptr));
        viewcommoButton->setText(QCoreApplication::translate("acommandWidget", "View commodities", nullptr));
        banuserButton->setText(QCoreApplication::translate("acommandWidget", "Ban users", nullptr));
        srchcommoButton->setText(QCoreApplication::translate("acommandWidget", "Search commodity", nullptr));
        vieworderButton->setText(QCoreApplication::translate("acommandWidget", "View orders", nullptr));
        rmvcommoButton->setText(QCoreApplication::translate("acommandWidget", "Remove commodity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class acommandWidget: public Ui_acommandWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACOMMANDWIDGET_H
