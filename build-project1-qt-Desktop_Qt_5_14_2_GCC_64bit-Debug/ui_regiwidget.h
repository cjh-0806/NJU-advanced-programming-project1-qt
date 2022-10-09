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

class Ui_regiWidget
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

    void setupUi(QWidget *regiWidget)
    {
        if (regiWidget->objectName().isEmpty())
            regiWidget->setObjectName(QString::fromUtf8("regiWidget"));
        regiWidget->resize(600, 450);
        regiWidget->setMinimumSize(QSize(600, 450));
        regiWidget->setMaximumSize(QSize(600, 450));
        label = new QLabel(regiWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 60, 360, 21));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        layoutWidget = new QWidget(regiWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 120, 564, 222));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        usernameLabel = new QLabel(layoutWidget);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        QFont font1;
        font1.setPointSize(12);
        usernameLabel->setFont(font1);

        verticalLayout->addWidget(usernameLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        pswdLabel = new QLabel(layoutWidget);
        pswdLabel->setObjectName(QString::fromUtf8("pswdLabel"));
        pswdLabel->setFont(font1);

        verticalLayout->addWidget(pswdLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        phonenumLabel = new QLabel(layoutWidget);
        phonenumLabel->setObjectName(QString::fromUtf8("phonenumLabel"));
        phonenumLabel->setFont(font1);

        verticalLayout->addWidget(phonenumLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_3);

        addrLabel = new QLabel(layoutWidget);
        addrLabel->setObjectName(QString::fromUtf8("addrLabel"));
        addrLabel->setFont(font1);

        verticalLayout->addWidget(addrLabel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_4);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        usernameLineEdit = new QLineEdit(layoutWidget);
        usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));
        usernameLineEdit->setFont(font1);

        verticalLayout_2->addWidget(usernameLineEdit);

        usernameTip = new QLabel(layoutWidget);
        usernameTip->setObjectName(QString::fromUtf8("usernameTip"));

        verticalLayout_2->addWidget(usernameTip);

        pswdLineEdit = new QLineEdit(layoutWidget);
        pswdLineEdit->setObjectName(QString::fromUtf8("pswdLineEdit"));
        pswdLineEdit->setFont(font1);

        verticalLayout_2->addWidget(pswdLineEdit);

        pswdTip = new QLabel(layoutWidget);
        pswdTip->setObjectName(QString::fromUtf8("pswdTip"));

        verticalLayout_2->addWidget(pswdTip);

        phonenumLineEdit = new QLineEdit(layoutWidget);
        phonenumLineEdit->setObjectName(QString::fromUtf8("phonenumLineEdit"));
        phonenumLineEdit->setFont(font1);

        verticalLayout_2->addWidget(phonenumLineEdit);

        phonenumTip = new QLabel(layoutWidget);
        phonenumTip->setObjectName(QString::fromUtf8("phonenumTip"));

        verticalLayout_2->addWidget(phonenumTip);

        addrLineEdit = new QLineEdit(layoutWidget);
        addrLineEdit->setObjectName(QString::fromUtf8("addrLineEdit"));
        addrLineEdit->setFont(font1);

        verticalLayout_2->addWidget(addrLineEdit);

        addrTip = new QLabel(layoutWidget);
        addrTip->setObjectName(QString::fromUtf8("addrTip"));

        verticalLayout_2->addWidget(addrTip);


        horizontalLayout->addLayout(verticalLayout_2);

        layoutWidget_2 = new QWidget(regiWidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(130, 390, 281, 41));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        commitButton = new QPushButton(layoutWidget_2);
        commitButton->setObjectName(QString::fromUtf8("commitButton"));
        commitButton->setFont(font1);

        horizontalLayout_2->addWidget(commitButton);

        horizontalSpacer_5 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        cancelButton = new QPushButton(layoutWidget_2);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setFont(font1);

        horizontalLayout_2->addWidget(cancelButton);


        retranslateUi(regiWidget);

        QMetaObject::connectSlotsByName(regiWidget);
    } // setupUi

    void retranslateUi(QWidget *regiWidget)
    {
        regiWidget->setWindowTitle(QCoreApplication::translate("regiWidget", "user register", nullptr));
        label->setText(QCoreApplication::translate("regiWidget", "User register:", nullptr));
        usernameLabel->setText(QCoreApplication::translate("regiWidget", "username:", nullptr));
        pswdLabel->setText(QCoreApplication::translate("regiWidget", "password:", nullptr));
        phonenumLabel->setText(QCoreApplication::translate("regiWidget", "phonenumber:", nullptr));
        addrLabel->setText(QCoreApplication::translate("regiWidget", "address:", nullptr));
        usernameTip->setText(QCoreApplication::translate("regiWidget", "<html><head/><body><p><span style=\" color:#204a87;\">(no more than 10 letters)</span></p></body></html>", nullptr));
        pswdTip->setText(QCoreApplication::translate("regiWidget", "<html><head/><body><p><span style=\" color:#204a87;\">(no more than 20 characters, only lowercase letters and numbers)</span></p></body></html>", nullptr));
        phonenumTip->setText(QCoreApplication::translate("regiWidget", "<html><head/><body><p><span style=\" color:#204a87;\">(no more than 20 numbers)</span></p></body></html>", nullptr));
        addrTip->setText(QCoreApplication::translate("regiWidget", "<html><head/><body><p><span style=\" color:#204a87;\">(no more than 40 letters)</span></p></body></html>", nullptr));
        commitButton->setText(QCoreApplication::translate("regiWidget", "Commit", nullptr));
        cancelButton->setText(QCoreApplication::translate("regiWidget", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class regiWidget: public Ui_regiWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGIWIDGET_H
