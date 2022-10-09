/********************************************************************************
** Form generated from reading UI file 'userinfowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFOWIDGET_H
#define UI_USERINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userinfoWidget
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *rechargeButton;
    QPushButton *viewinfoButton;
    QPushButton *returnButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *mdfinfoButton;

    void setupUi(QWidget *userinfoWidget)
    {
        if (userinfoWidget->objectName().isEmpty())
            userinfoWidget->setObjectName(QString::fromUtf8("userinfoWidget"));
        userinfoWidget->resize(600, 450);
        userinfoWidget->setMinimumSize(QSize(600, 450));
        userinfoWidget->setMaximumSize(QSize(600, 450));
        label = new QLabel(userinfoWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 80, 371, 21));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        layoutWidget = new QWidget(userinfoWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 160, 361, 191));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        rechargeButton = new QPushButton(layoutWidget);
        rechargeButton->setObjectName(QString::fromUtf8("rechargeButton"));
        rechargeButton->setFont(font);

        gridLayout->addWidget(rechargeButton, 1, 0, 1, 1);

        viewinfoButton = new QPushButton(layoutWidget);
        viewinfoButton->setObjectName(QString::fromUtf8("viewinfoButton"));
        viewinfoButton->setFont(font);

        gridLayout->addWidget(viewinfoButton, 0, 2, 1, 1);

        returnButton = new QPushButton(layoutWidget);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        returnButton->setFont(font);

        gridLayout->addWidget(returnButton, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        mdfinfoButton = new QPushButton(layoutWidget);
        mdfinfoButton->setObjectName(QString::fromUtf8("mdfinfoButton"));
        mdfinfoButton->setFont(font);

        gridLayout->addWidget(mdfinfoButton, 1, 2, 1, 1);


        retranslateUi(userinfoWidget);

        QMetaObject::connectSlotsByName(userinfoWidget);
    } // setupUi

    void retranslateUi(QWidget *userinfoWidget)
    {
        userinfoWidget->setWindowTitle(QCoreApplication::translate("userinfoWidget", "User infomation", nullptr));
        label->setText(QCoreApplication::translate("userinfoWidget", "Hello, user! Please choose your command:", nullptr));
        rechargeButton->setText(QCoreApplication::translate("userinfoWidget", "Recharge", nullptr));
        viewinfoButton->setText(QCoreApplication::translate("userinfoWidget", "View information", nullptr));
        returnButton->setText(QCoreApplication::translate("userinfoWidget", "Return", nullptr));
        mdfinfoButton->setText(QCoreApplication::translate("userinfoWidget", "Modify information", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userinfoWidget: public Ui_userinfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFOWIDGET_H
