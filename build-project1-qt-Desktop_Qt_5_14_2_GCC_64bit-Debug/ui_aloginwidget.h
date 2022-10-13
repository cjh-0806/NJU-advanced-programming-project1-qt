/********************************************************************************
** Form generated from reading UI file 'aloginwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALOGINWIDGET_H
#define UI_ALOGINWIDGET_H

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

class Ui_aloginWidget
{
public:
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *commitButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *cancelButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *adminnameLabel;
    QLineEdit *adminnameLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *pswdLabel;
    QLineEdit *pswdLineEdit;
    QLabel *label;

    void setupUi(QWidget *aloginWidget)
    {
        if (aloginWidget->objectName().isEmpty())
            aloginWidget->setObjectName(QString::fromUtf8("aloginWidget"));
        aloginWidget->resize(600, 450);
        aloginWidget->setMinimumSize(QSize(600, 450));
        aloginWidget->setMaximumSize(QSize(600, 450));
        layoutWidget_2 = new QWidget(aloginWidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(120, 360, 274, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        commitButton = new QPushButton(layoutWidget_2);
        commitButton->setObjectName(QString::fromUtf8("commitButton"));
        QFont font;
        font.setPointSize(12);
        commitButton->setFont(font);

        horizontalLayout_2->addWidget(commitButton);

        horizontalSpacer_5 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        cancelButton = new QPushButton(layoutWidget_2);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setFont(font);

        horizontalLayout_2->addWidget(cancelButton);

        layoutWidget = new QWidget(aloginWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 150, 361, 151));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        adminnameLabel = new QLabel(layoutWidget);
        adminnameLabel->setObjectName(QString::fromUtf8("adminnameLabel"));
        QFont font1;
        font1.setPointSize(14);
        adminnameLabel->setFont(font1);

        horizontalLayout->addWidget(adminnameLabel);

        adminnameLineEdit = new QLineEdit(layoutWidget);
        adminnameLineEdit->setObjectName(QString::fromUtf8("adminnameLineEdit"));
        adminnameLineEdit->setFont(font1);

        horizontalLayout->addWidget(adminnameLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pswdLabel = new QLabel(layoutWidget);
        pswdLabel->setObjectName(QString::fromUtf8("pswdLabel"));
        pswdLabel->setFont(font1);

        horizontalLayout_5->addWidget(pswdLabel);

        pswdLineEdit = new QLineEdit(layoutWidget);
        pswdLineEdit->setObjectName(QString::fromUtf8("pswdLineEdit"));
        pswdLineEdit->setFont(font1);

        horizontalLayout_5->addWidget(pswdLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        label = new QLabel(aloginWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 60, 360, 21));
        label->setFont(font1);

        retranslateUi(aloginWidget);

        QMetaObject::connectSlotsByName(aloginWidget);
    } // setupUi

    void retranslateUi(QWidget *aloginWidget)
    {
        aloginWidget->setWindowTitle(QCoreApplication::translate("aloginWidget", "Administrator login", nullptr));
        commitButton->setText(QCoreApplication::translate("aloginWidget", "Commit", nullptr));
        cancelButton->setText(QCoreApplication::translate("aloginWidget", "Cancel", nullptr));
        adminnameLabel->setText(QCoreApplication::translate("aloginWidget", "adminname:", nullptr));
        pswdLabel->setText(QCoreApplication::translate("aloginWidget", "password:", nullptr));
        label->setText(QCoreApplication::translate("aloginWidget", "Administrator login:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aloginWidget: public Ui_aloginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALOGINWIDGET_H
