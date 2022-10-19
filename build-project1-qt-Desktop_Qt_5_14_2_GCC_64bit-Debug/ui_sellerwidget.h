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
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *returnButton;
    QSpacerItem *verticalSpacer;
    QPushButton *mdfinfoButton;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPushButton *rlscommoButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *viewcommoButton;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *rmvcommoButton;
    QSpacerItem *verticalSpacer_3;
    QPushButton *vieworderButton;

    void setupUi(QWidget *sellerWidget)
    {
        if (sellerWidget->objectName().isEmpty())
            sellerWidget->setObjectName(QString::fromUtf8("sellerWidget"));
        sellerWidget->resize(600, 450);
        label = new QLabel(sellerWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 80, 451, 21));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        widget = new QWidget(sellerWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 170, 561, 110));
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

        mdfinfoButton = new QPushButton(widget);
        mdfinfoButton->setObjectName(QString::fromUtf8("mdfinfoButton"));
        mdfinfoButton->setFont(font1);

        verticalLayout->addWidget(mdfinfoButton);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        rlscommoButton = new QPushButton(widget);
        rlscommoButton->setObjectName(QString::fromUtf8("rlscommoButton"));
        rlscommoButton->setFont(font1);

        verticalLayout_2->addWidget(rlscommoButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        viewcommoButton = new QPushButton(widget);
        viewcommoButton->setObjectName(QString::fromUtf8("viewcommoButton"));
        viewcommoButton->setFont(font1);

        verticalLayout_2->addWidget(viewcommoButton);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        rmvcommoButton = new QPushButton(widget);
        rmvcommoButton->setObjectName(QString::fromUtf8("rmvcommoButton"));
        rmvcommoButton->setFont(font1);

        verticalLayout_3->addWidget(rmvcommoButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        vieworderButton = new QPushButton(widget);
        vieworderButton->setObjectName(QString::fromUtf8("vieworderButton"));
        vieworderButton->setFont(font1);

        verticalLayout_3->addWidget(vieworderButton);


        horizontalLayout->addLayout(verticalLayout_3);


        retranslateUi(sellerWidget);

        QMetaObject::connectSlotsByName(sellerWidget);
    } // setupUi

    void retranslateUi(QWidget *sellerWidget)
    {
        sellerWidget->setWindowTitle(QCoreApplication::translate("sellerWidget", "Seller", nullptr));
        label->setText(QString());
        returnButton->setText(QCoreApplication::translate("sellerWidget", "Return", nullptr));
        mdfinfoButton->setText(QCoreApplication::translate("sellerWidget", "Modify information", nullptr));
        rlscommoButton->setText(QCoreApplication::translate("sellerWidget", "Release commodity", nullptr));
        viewcommoButton->setText(QCoreApplication::translate("sellerWidget", "View released commodities", nullptr));
        rmvcommoButton->setText(QCoreApplication::translate("sellerWidget", "Remove commodity", nullptr));
        vieworderButton->setText(QCoreApplication::translate("sellerWidget", "View order history", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sellerWidget: public Ui_sellerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELLERWIDGET_H
