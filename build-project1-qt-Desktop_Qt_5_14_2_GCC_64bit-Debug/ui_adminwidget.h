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
    QPushButton *logoutButton;
    QLabel *label;
    QWidget *layoutWidget;
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

    void setupUi(QWidget *adminWidget)
    {
        if (adminWidget->objectName().isEmpty())
            adminWidget->setObjectName(QString::fromUtf8("adminWidget"));
        adminWidget->resize(600, 450);
        adminWidget->setMinimumSize(QSize(600, 450));
        adminWidget->setMaximumSize(QSize(600, 450));
        logoutButton = new QPushButton(adminWidget);
        logoutButton->setObjectName(QString::fromUtf8("logoutButton"));
        logoutButton->setGeometry(QRect(220, 300, 140, 27));
        QFont font;
        font.setPointSize(12);
        logoutButton->setFont(font);
        label = new QLabel(adminWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 80, 451, 21));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        layoutWidget = new QWidget(adminWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 160, 541, 101));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        viewuserButton = new QPushButton(layoutWidget);
        viewuserButton->setObjectName(QString::fromUtf8("viewuserButton"));
        viewuserButton->setFont(font);

        verticalLayout->addWidget(viewuserButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        viewcommoButton = new QPushButton(layoutWidget);
        viewcommoButton->setObjectName(QString::fromUtf8("viewcommoButton"));
        viewcommoButton->setFont(font);

        verticalLayout->addWidget(viewcommoButton);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        banuserButton = new QPushButton(layoutWidget);
        banuserButton->setObjectName(QString::fromUtf8("banuserButton"));
        banuserButton->setFont(font);

        verticalLayout_2->addWidget(banuserButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        srchcommoButton = new QPushButton(layoutWidget);
        srchcommoButton->setObjectName(QString::fromUtf8("srchcommoButton"));
        srchcommoButton->setFont(font);

        verticalLayout_2->addWidget(srchcommoButton);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        vieworderButton = new QPushButton(layoutWidget);
        vieworderButton->setObjectName(QString::fromUtf8("vieworderButton"));
        vieworderButton->setFont(font);

        verticalLayout_3->addWidget(vieworderButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        rmvcommoButton = new QPushButton(layoutWidget);
        rmvcommoButton->setObjectName(QString::fromUtf8("rmvcommoButton"));
        rmvcommoButton->setFont(font);

        verticalLayout_3->addWidget(rmvcommoButton);


        horizontalLayout->addLayout(verticalLayout_3);


        retranslateUi(adminWidget);

        QMetaObject::connectSlotsByName(adminWidget);
    } // setupUi

    void retranslateUi(QWidget *adminWidget)
    {
        adminWidget->setWindowTitle(QCoreApplication::translate("adminWidget", "Administrator", nullptr));
        logoutButton->setText(QCoreApplication::translate("adminWidget", "Logout", nullptr));
        label->setText(QCoreApplication::translate("adminWidget", "Hello, administrator! Please choose your command:", nullptr));
        viewuserButton->setText(QCoreApplication::translate("adminWidget", "View users", nullptr));
        viewcommoButton->setText(QCoreApplication::translate("adminWidget", "View commodities", nullptr));
        banuserButton->setText(QCoreApplication::translate("adminWidget", "Ban users", nullptr));
        srchcommoButton->setText(QCoreApplication::translate("adminWidget", "Search commodity", nullptr));
        vieworderButton->setText(QCoreApplication::translate("adminWidget", "View orders", nullptr));
        rmvcommoButton->setText(QCoreApplication::translate("adminWidget", "Remove commodity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminWidget: public Ui_adminWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWIDGET_H
