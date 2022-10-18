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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *returnButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *viewcommoButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *srchcommoButton;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *auctionButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *vieworderButton;
    QSpacerItem *horizontalSpacer_5;

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
        layoutWidget = new QWidget(buyerWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 150, 491, 191));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        returnButton = new QPushButton(layoutWidget);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        QFont font1;
        font1.setPointSize(12);
        returnButton->setFont(font1);

        horizontalLayout->addWidget(returnButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        viewcommoButton = new QPushButton(layoutWidget);
        viewcommoButton->setObjectName(QString::fromUtf8("viewcommoButton"));
        viewcommoButton->setFont(font1);

        horizontalLayout->addWidget(viewcommoButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        srchcommoButton = new QPushButton(layoutWidget);
        srchcommoButton->setObjectName(QString::fromUtf8("srchcommoButton"));
        srchcommoButton->setFont(font1);

        horizontalLayout->addWidget(srchcommoButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        auctionButton = new QPushButton(layoutWidget);
        auctionButton->setObjectName(QString::fromUtf8("auctionButton"));
        auctionButton->setFont(font1);

        horizontalLayout_2->addWidget(auctionButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        vieworderButton = new QPushButton(layoutWidget);
        vieworderButton->setObjectName(QString::fromUtf8("vieworderButton"));
        vieworderButton->setFont(font1);

        horizontalLayout_2->addWidget(vieworderButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(buyerWidget);

        QMetaObject::connectSlotsByName(buyerWidget);
    } // setupUi

    void retranslateUi(QWidget *buyerWidget)
    {
        buyerWidget->setWindowTitle(QCoreApplication::translate("buyerWidget", "Buyer", nullptr));
        label->setText(QString());
        returnButton->setText(QCoreApplication::translate("buyerWidget", "Return", nullptr));
        viewcommoButton->setText(QCoreApplication::translate("buyerWidget", "View commodity", nullptr));
        srchcommoButton->setText(QCoreApplication::translate("buyerWidget", "Search commodity", nullptr));
        auctionButton->setText(QCoreApplication::translate("buyerWidget", "Auction", nullptr));
        vieworderButton->setText(QCoreApplication::translate("buyerWidget", "View order history", nullptr));
    } // retranslateUi

};

namespace Ui {
    class buyerWidget: public Ui_buyerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYERWIDGET_H
