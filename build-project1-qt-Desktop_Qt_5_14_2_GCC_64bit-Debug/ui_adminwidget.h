/********************************************************************************
** Form generated from reading UI file 'adminwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWIDGET_H
#define UI_ADMINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminWidget
{
public:
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *logoutButton;
    QSpacerItem *verticalSpacer;
    QPushButton *viewcommoButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *vieworderButton;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *viewuserButton;
    QSpacerItem *verticalSpacer_3;
    QPushButton *srchcommoButton;
    QSpacerItem *verticalSpacer_4;
    QPushButton *srchorderButton;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *banuserButton;
    QSpacerItem *verticalSpacer_5;
    QPushButton *rmvcommoButton;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *adminWidget)
    {
        if (adminWidget->objectName().isEmpty())
            adminWidget->setObjectName(QString::fromUtf8("adminWidget"));
        adminWidget->resize(600, 450);
        adminWidget->setMinimumSize(QSize(600, 450));
        adminWidget->setMaximumSize(QSize(600, 450));
        label = new QLabel(adminWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 80, 451, 21));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        widget = new QWidget(adminWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 140, 551, 211));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        logoutButton = new QPushButton(widget);
        logoutButton->setObjectName(QString::fromUtf8("logoutButton"));
        QFont font1;
        font1.setPointSize(12);
        logoutButton->setFont(font1);

        verticalLayout->addWidget(logoutButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        viewcommoButton = new QPushButton(widget);
        viewcommoButton->setObjectName(QString::fromUtf8("viewcommoButton"));
        viewcommoButton->setFont(font1);

        verticalLayout->addWidget(viewcommoButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        vieworderButton = new QPushButton(widget);
        vieworderButton->setObjectName(QString::fromUtf8("vieworderButton"));
        vieworderButton->setFont(font1);

        verticalLayout->addWidget(vieworderButton);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        viewuserButton = new QPushButton(widget);
        viewuserButton->setObjectName(QString::fromUtf8("viewuserButton"));
        viewuserButton->setFont(font1);

        verticalLayout_2->addWidget(viewuserButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        srchcommoButton = new QPushButton(widget);
        srchcommoButton->setObjectName(QString::fromUtf8("srchcommoButton"));
        srchcommoButton->setFont(font1);

        verticalLayout_2->addWidget(srchcommoButton);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        srchorderButton = new QPushButton(widget);
        srchorderButton->setObjectName(QString::fromUtf8("srchorderButton"));
        srchorderButton->setFont(font1);

        verticalLayout_2->addWidget(srchorderButton);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        banuserButton = new QPushButton(widget);
        banuserButton->setObjectName(QString::fromUtf8("banuserButton"));
        banuserButton->setFont(font1);

        verticalLayout_3->addWidget(banuserButton);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        rmvcommoButton = new QPushButton(widget);
        rmvcommoButton->setObjectName(QString::fromUtf8("rmvcommoButton"));
        rmvcommoButton->setFont(font1);

        verticalLayout_3->addWidget(rmvcommoButton);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);

        horizontalSpacer = new QSpacerItem(40, 27, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer);


        horizontalLayout->addLayout(verticalLayout_3);


        retranslateUi(adminWidget);

        QMetaObject::connectSlotsByName(adminWidget);
    } // setupUi

    void retranslateUi(QWidget *adminWidget)
    {
        adminWidget->setWindowTitle(QCoreApplication::translate("adminWidget", "Administrator", nullptr));
        label->setText(QCoreApplication::translate("adminWidget", "Hello, administrator! Please choose your command:", nullptr));
        logoutButton->setText(QCoreApplication::translate("adminWidget", "Logout", nullptr));
        viewcommoButton->setText(QCoreApplication::translate("adminWidget", "View commodities", nullptr));
        vieworderButton->setText(QCoreApplication::translate("adminWidget", "View orders", nullptr));
        viewuserButton->setText(QCoreApplication::translate("adminWidget", "View users", nullptr));
        srchcommoButton->setText(QCoreApplication::translate("adminWidget", "Search commodity", nullptr));
        srchorderButton->setText(QCoreApplication::translate("adminWidget", "Search order", nullptr));
        banuserButton->setText(QCoreApplication::translate("adminWidget", "Ban users", nullptr));
        rmvcommoButton->setText(QCoreApplication::translate("adminWidget", "Remove commodity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminWidget: public Ui_adminWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWIDGET_H
