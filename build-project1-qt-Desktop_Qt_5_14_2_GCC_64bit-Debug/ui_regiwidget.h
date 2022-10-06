/********************************************************************************
** Form generated from reading UI file 'regiwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGIWIDGET_H
#define UI_REGIWIDGET_H

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

class Ui_regiwidget
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *usernameLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *pswdLabel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *phonenumLabel;
    QSpacerItem *horizontalSpacer_3;
    QLabel *addrLabel;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *usernameLineEdit;
    QLabel *usernameTip;
    QLineEdit *pswdLineEdit;
    QLabel *pswdTip;
    QLineEdit *phonenumLineEdit;
    QLabel *phonenumTip;
    QLineEdit *addrLineEdit;
    QLabel *addrTip;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *commitButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *cancelButton;

    void setupUi(QWidget *regiwidget)
    {
        if (regiwidget->objectName().isEmpty())
            regiwidget->setObjectName(QString::fromUtf8("regiwidget"));
        regiwidget->resize(600, 450);
        regiwidget->setMinimumSize(QSize(600, 450));
        regiwidget->setMaximumSize(QSize(600, 450));
        label = new QLabel(regiwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 50, 360, 50));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        layoutWidget = new QWidget(regiwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 110, 558, 251));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        usernameLabel = new QLabel(layoutWidget);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));

        verticalLayout->addWidget(usernameLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        pswdLabel = new QLabel(layoutWidget);
        pswdLabel->setObjectName(QString::fromUtf8("pswdLabel"));

        verticalLayout->addWidget(pswdLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        phonenumLabel = new QLabel(layoutWidget);
        phonenumLabel->setObjectName(QString::fromUtf8("phonenumLabel"));

        verticalLayout->addWidget(phonenumLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_3);

        addrLabel = new QLabel(layoutWidget);
        addrLabel->setObjectName(QString::fromUtf8("addrLabel"));

        verticalLayout->addWidget(addrLabel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_4);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        usernameLineEdit = new QLineEdit(layoutWidget);
        usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));

        verticalLayout_2->addWidget(usernameLineEdit);

        usernameTip = new QLabel(layoutWidget);
        usernameTip->setObjectName(QString::fromUtf8("usernameTip"));

        verticalLayout_2->addWidget(usernameTip);

        pswdLineEdit = new QLineEdit(layoutWidget);
        pswdLineEdit->setObjectName(QString::fromUtf8("pswdLineEdit"));

        verticalLayout_2->addWidget(pswdLineEdit);

        pswdTip = new QLabel(layoutWidget);
        pswdTip->setObjectName(QString::fromUtf8("pswdTip"));

        verticalLayout_2->addWidget(pswdTip);

        phonenumLineEdit = new QLineEdit(layoutWidget);
        phonenumLineEdit->setObjectName(QString::fromUtf8("phonenumLineEdit"));

        verticalLayout_2->addWidget(phonenumLineEdit);

        phonenumTip = new QLabel(layoutWidget);
        phonenumTip->setObjectName(QString::fromUtf8("phonenumTip"));

        verticalLayout_2->addWidget(phonenumTip);

        addrLineEdit = new QLineEdit(layoutWidget);
        addrLineEdit->setObjectName(QString::fromUtf8("addrLineEdit"));

        verticalLayout_2->addWidget(addrLineEdit);

        addrTip = new QLabel(layoutWidget);
        addrTip->setObjectName(QString::fromUtf8("addrTip"));

        verticalLayout_2->addWidget(addrTip);


        horizontalLayout->addLayout(verticalLayout_2);

        layoutWidget_2 = new QWidget(regiwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(130, 390, 281, 41));
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


        retranslateUi(regiwidget);

        QMetaObject::connectSlotsByName(regiwidget);
    } // setupUi

    void retranslateUi(QWidget *regiwidget)
    {
        regiwidget->setWindowTitle(QCoreApplication::translate("regiwidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("regiwidget", "Please input the infomation below:", nullptr));
        usernameLabel->setText(QCoreApplication::translate("regiwidget", "Username:", nullptr));
        pswdLabel->setText(QCoreApplication::translate("regiwidget", "password:", nullptr));
        phonenumLabel->setText(QCoreApplication::translate("regiwidget", "phonenumber:", nullptr));
        addrLabel->setText(QCoreApplication::translate("regiwidget", "address:", nullptr));
        usernameTip->setText(QCoreApplication::translate("regiwidget", "(no more than 10 letters)", nullptr));
        pswdTip->setText(QCoreApplication::translate("regiwidget", "(no more than 20 characters, only lowercase letters and numbers)", nullptr));
        phonenumTip->setText(QCoreApplication::translate("regiwidget", "(no more than 20 numbers)", nullptr));
        addrTip->setText(QCoreApplication::translate("regiwidget", "(no more than 40 letters)", nullptr));
        commitButton->setText(QCoreApplication::translate("regiwidget", "Commit", nullptr));
        cancelButton->setText(QCoreApplication::translate("regiwidget", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class regiwidget: public Ui_regiwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGIWIDGET_H
