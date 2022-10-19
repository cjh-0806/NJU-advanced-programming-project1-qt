/********************************************************************************
** Form generated from reading UI file 'buyerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYERWIDGET_H
#define UI_BUYERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_buyerWidget
{
public:
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *returnButton;
    QSpacerItem *verticalSpacer;
    QPushButton *auctionButton;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *viewcommoButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *vieworderButton;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *srchcommoButton;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *buyerWidget)
    {
        if (buyerWidget->objectName().isEmpty())
            buyerWidget->setObjectName(QString::fromUtf8("buyerWidget"));
        buyerWidget->resize(600, 450);
        buyerWidget->setMinimumSize(QSize(600, 450));
        buyerWidget->setMaximumSize(QSize(600, 450));
        label = new QLabel(buyerWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 80, 451, 21));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        widget = new QWidget(buyerWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 160, 501, 141));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        returnButton = new QPushButton(widget);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        QFont font1;
        font1.setPointSize(12);
        returnButton->setFont(font1);

        verticalLayout->addWidget(returnButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        auctionButton = new QPushButton(widget);
        auctionButton->setObjectName(QString::fromUtf8("auctionButton"));
        auctionButton->setFont(font1);

        verticalLayout->addWidget(auctionButton);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        viewcommoButton = new QPushButton(widget);
        viewcommoButton->setObjectName(QString::fromUtf8("viewcommoButton"));
        viewcommoButton->setFont(font1);

        verticalLayout_2->addWidget(viewcommoButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        vieworderButton = new QPushButton(widget);
        vieworderButton->setObjectName(QString::fromUtf8("vieworderButton"));
        vieworderButton->setFont(font1);

        verticalLayout_2->addWidget(vieworderButton);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        srchcommoButton = new QPushButton(widget);
        srchcommoButton->setObjectName(QString::fromUtf8("srchcommoButton"));
        srchcommoButton->setFont(font1);

        verticalLayout_3->addWidget(srchcommoButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer);


        horizontalLayout->addLayout(verticalLayout_3);


        retranslateUi(buyerWidget);

        QMetaObject::connectSlotsByName(buyerWidget);
    } // setupUi

    void retranslateUi(QWidget *buyerWidget)
    {
        buyerWidget->setWindowTitle(QCoreApplication::translate("buyerWidget", "Buyer", nullptr));
        label->setText(QString());
        returnButton->setText(QCoreApplication::translate("buyerWidget", "Return", nullptr));
        auctionButton->setText(QCoreApplication::translate("buyerWidget", "Auction", nullptr));
        viewcommoButton->setText(QCoreApplication::translate("buyerWidget", "View commodity", nullptr));
        vieworderButton->setText(QCoreApplication::translate("buyerWidget", "View order history", nullptr));
        srchcommoButton->setText(QCoreApplication::translate("buyerWidget", "Search commodity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class buyerWidget: public Ui_buyerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYERWIDGET_H
