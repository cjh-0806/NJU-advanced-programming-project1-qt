/********************************************************************************
** Form generated from reading UI file 'userwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWIDGET_H
#define UI_USERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userWidget
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *buyerButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *sellerButton;
    QPushButton *infoButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *logoutButton;

    void setupUi(QWidget *userWidget)
    {
        if (userWidget->objectName().isEmpty())
            userWidget->setObjectName(QString::fromUtf8("userWidget"));
        userWidget->resize(600, 450);
        userWidget->setMinimumSize(QSize(600, 450));
        userWidget->setMaximumSize(QSize(600, 450));
        label = new QLabel(userWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 80, 451, 21));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        layoutWidget = new QWidget(userWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 140, 311, 191));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        buyerButton = new QPushButton(layoutWidget);
        buyerButton->setObjectName(QString::fromUtf8("buyerButton"));
        buyerButton->setFont(font);

        gridLayout->addWidget(buyerButton, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        sellerButton = new QPushButton(layoutWidget);
        sellerButton->setObjectName(QString::fromUtf8("sellerButton"));
        sellerButton->setFont(font);

        gridLayout->addWidget(sellerButton, 0, 2, 1, 1);

        infoButton = new QPushButton(layoutWidget);
        infoButton->setObjectName(QString::fromUtf8("infoButton"));
        infoButton->setFont(font);

        gridLayout->addWidget(infoButton, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        logoutButton = new QPushButton(layoutWidget);
        logoutButton->setObjectName(QString::fromUtf8("logoutButton"));
        logoutButton->setFont(font);

        gridLayout->addWidget(logoutButton, 1, 2, 1, 1);


        retranslateUi(userWidget);

        QMetaObject::connectSlotsByName(userWidget);
    } // setupUi

    void retranslateUi(QWidget *userWidget)
    {
        userWidget->setWindowTitle(QCoreApplication::translate("userWidget", "User", nullptr));
        label->setText(QString());
        buyerButton->setText(QCoreApplication::translate("userWidget", "Buyer", nullptr));
        sellerButton->setText(QCoreApplication::translate("userWidget", "Seller", nullptr));
        infoButton->setText(QCoreApplication::translate("userWidget", "Information", nullptr));
        logoutButton->setText(QCoreApplication::translate("userWidget", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userWidget: public Ui_userWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWIDGET_H
