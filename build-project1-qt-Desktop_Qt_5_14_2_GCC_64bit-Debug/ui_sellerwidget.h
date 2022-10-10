/********************************************************************************
** Form generated from reading UI file 'sellerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELLERWIDGET_H
#define UI_SELLERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sellerWidget
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *returnButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *rlscommoButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *rmvcommoButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *mdfinfoButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *viewcommoButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *vieworderButton;

    void setupUi(QWidget *sellerWidget)
    {
        if (sellerWidget->objectName().isEmpty())
            sellerWidget->setObjectName(QString::fromUtf8("sellerWidget"));
        sellerWidget->resize(600, 450);
        label = new QLabel(sellerWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 80, 391, 21));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        layoutWidget = new QWidget(sellerWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 170, 571, 141));
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

        rlscommoButton = new QPushButton(layoutWidget);
        rlscommoButton->setObjectName(QString::fromUtf8("rlscommoButton"));
        rlscommoButton->setFont(font1);

        horizontalLayout->addWidget(rlscommoButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        rmvcommoButton = new QPushButton(layoutWidget);
        rmvcommoButton->setObjectName(QString::fromUtf8("rmvcommoButton"));
        rmvcommoButton->setFont(font1);

        horizontalLayout->addWidget(rmvcommoButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        mdfinfoButton = new QPushButton(layoutWidget);
        mdfinfoButton->setObjectName(QString::fromUtf8("mdfinfoButton"));
        mdfinfoButton->setFont(font1);

        horizontalLayout_2->addWidget(mdfinfoButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        viewcommoButton = new QPushButton(layoutWidget);
        viewcommoButton->setObjectName(QString::fromUtf8("viewcommoButton"));
        viewcommoButton->setFont(font1);

        horizontalLayout_2->addWidget(viewcommoButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        vieworderButton = new QPushButton(layoutWidget);
        vieworderButton->setObjectName(QString::fromUtf8("vieworderButton"));
        vieworderButton->setFont(font1);

        horizontalLayout_2->addWidget(vieworderButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(sellerWidget);

        QMetaObject::connectSlotsByName(sellerWidget);
    } // setupUi

    void retranslateUi(QWidget *sellerWidget)
    {
        sellerWidget->setWindowTitle(QCoreApplication::translate("sellerWidget", "Seller", nullptr));
        label->setText(QCoreApplication::translate("sellerWidget", "Hello, seller! Please choose your command:", nullptr));
        returnButton->setText(QCoreApplication::translate("sellerWidget", "Return", nullptr));
        rlscommoButton->setText(QCoreApplication::translate("sellerWidget", "Release commodity", nullptr));
        rmvcommoButton->setText(QCoreApplication::translate("sellerWidget", "Remove commodity", nullptr));
        mdfinfoButton->setText(QCoreApplication::translate("sellerWidget", "Modify information", nullptr));
        viewcommoButton->setText(QCoreApplication::translate("sellerWidget", "View released commodities", nullptr));
        vieworderButton->setText(QCoreApplication::translate("sellerWidget", "View order history", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sellerWidget: public Ui_sellerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELLERWIDGET_H
