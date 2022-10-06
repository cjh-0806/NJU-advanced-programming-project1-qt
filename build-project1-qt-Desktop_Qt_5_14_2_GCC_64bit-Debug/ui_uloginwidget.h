/********************************************************************************
** Form generated from reading UI file 'uloginwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ULOGINWIDGET_H
#define UI_ULOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_uloginWidget
{
public:
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *commitButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *cancelButton;
    QLabel *label;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *pswdLabel;
    QLineEdit *pswdLineEdit;

    void setupUi(QWidget *uloginWidget)
    {
        if (uloginWidget->objectName().isEmpty())
            uloginWidget->setObjectName(QString::fromUtf8("uloginWidget"));
        uloginWidget->resize(600, 450);
        layoutWidget_2 = new QWidget(uloginWidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(120, 370, 274, 27));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        commitButton = new QPushButton(layoutWidget_2);
        commitButton->setObjectName(QString::fromUtf8("commitButton"));

        horizontalLayout_2->addWidget(commitButton);

        horizontalSpacer_5 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        cancelButton = new QPushButton(layoutWidget_2);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_2->addWidget(cancelButton);

        label = new QLabel(uloginWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 50, 360, 50));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        widget = new QWidget(uloginWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 140, 361, 151));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        usernameLabel = new QLabel(widget);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        usernameLabel->setFont(font);

        horizontalLayout->addWidget(usernameLabel);

        usernameLineEdit = new QLineEdit(widget);
        usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));
        usernameLineEdit->setFont(font);

        horizontalLayout->addWidget(usernameLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pswdLabel = new QLabel(widget);
        pswdLabel->setObjectName(QString::fromUtf8("pswdLabel"));
        pswdLabel->setFont(font);

        horizontalLayout_5->addWidget(pswdLabel);

        pswdLineEdit = new QLineEdit(widget);
        pswdLineEdit->setObjectName(QString::fromUtf8("pswdLineEdit"));
        pswdLineEdit->setFont(font);

        horizontalLayout_5->addWidget(pswdLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(uloginWidget);

        QMetaObject::connectSlotsByName(uloginWidget);
    } // setupUi

    void retranslateUi(QWidget *uloginWidget)
    {
        uloginWidget->setWindowTitle(QCoreApplication::translate("uloginWidget", "user login", nullptr));
        commitButton->setText(QCoreApplication::translate("uloginWidget", "Commit", nullptr));
        cancelButton->setText(QCoreApplication::translate("uloginWidget", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("uloginWidget", "Please input the infomation below:", nullptr));
        usernameLabel->setText(QCoreApplication::translate("uloginWidget", "username:", nullptr));
        pswdLabel->setText(QCoreApplication::translate("uloginWidget", "password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class uloginWidget: public Ui_uloginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ULOGINWIDGET_H
