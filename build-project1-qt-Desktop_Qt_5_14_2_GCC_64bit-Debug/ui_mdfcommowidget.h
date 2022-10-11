/********************************************************************************
** Form generated from reading UI file 'mdfcommowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MDFCOMMOWIDGET_H
#define UI_MDFCOMMOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mdfcommoWidget
{
public:
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *commitButton_2;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *cancelButton_2;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *usernameLabel_2;
    QSpacerItem *horizontalSpacer_6;
    QLabel *pswdLabel_2;
    QSpacerItem *horizontalSpacer_7;
    QLabel *phonenumLabel_2;
    QSpacerItem *horizontalSpacer_8;
    QLabel *addrLabel_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_12;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *cnameLineEdit;
    QLabel *usernameTip_2;
    QLineEdit *priceLineEdit;
    QLabel *pswdTip_2;
    QLineEdit *numLineEdit;
    QLabel *phonenumTip_2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *lifeButton;
    QRadioButton *studyButton;
    QRadioButton *foodButton;
    QRadioButton *clothesButton;
    QRadioButton *makeupButton;
    QRadioButton *ornaButton;
    QRadioButton *digiButton;
    QRadioButton *otherButton;
    QLineEdit *descLineEdit;
    QLabel *addrTip_2;

    void setupUi(QWidget *mdfcommoWidget)
    {
        if (mdfcommoWidget->objectName().isEmpty())
            mdfcommoWidget->setObjectName(QString::fromUtf8("mdfcommoWidget"));
        mdfcommoWidget->resize(800, 450);
        mdfcommoWidget->setMinimumSize(QSize(800, 450));
        mdfcommoWidget->setMaximumSize(QSize(800, 450));
        layoutWidget_2 = new QWidget(mdfcommoWidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(240, 400, 281, 41));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        commitButton_2 = new QPushButton(layoutWidget_2);
        commitButton_2->setObjectName(QString::fromUtf8("commitButton_2"));
        QFont font;
        font.setPointSize(12);
        commitButton_2->setFont(font);

        horizontalLayout_4->addWidget(commitButton_2);

        horizontalSpacer_10 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        cancelButton_2 = new QPushButton(layoutWidget_2);
        cancelButton_2->setObjectName(QString::fromUtf8("cancelButton_2"));
        cancelButton_2->setFont(font);

        horizontalLayout_4->addWidget(cancelButton_2);

        label = new QLabel(mdfcommoWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 360, 21));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        layoutWidget = new QWidget(mdfcommoWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 70, 758, 321));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        usernameLabel_2 = new QLabel(layoutWidget);
        usernameLabel_2->setObjectName(QString::fromUtf8("usernameLabel_2"));
        usernameLabel_2->setFont(font);

        verticalLayout_3->addWidget(usernameLabel_2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_6);

        pswdLabel_2 = new QLabel(layoutWidget);
        pswdLabel_2->setObjectName(QString::fromUtf8("pswdLabel_2"));
        pswdLabel_2->setFont(font);

        verticalLayout_3->addWidget(pswdLabel_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_7);

        phonenumLabel_2 = new QLabel(layoutWidget);
        phonenumLabel_2->setObjectName(QString::fromUtf8("phonenumLabel_2"));
        phonenumLabel_2->setFont(font);

        verticalLayout_3->addWidget(phonenumLabel_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_8);

        addrLabel_2 = new QLabel(layoutWidget);
        addrLabel_2->setObjectName(QString::fromUtf8("addrLabel_2"));
        addrLabel_2->setFont(font);

        verticalLayout_3->addWidget(addrLabel_2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_3->addWidget(label_2);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_12);


        horizontalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        cnameLineEdit = new QLineEdit(layoutWidget);
        cnameLineEdit->setObjectName(QString::fromUtf8("cnameLineEdit"));
        cnameLineEdit->setFont(font);

        verticalLayout_4->addWidget(cnameLineEdit);

        usernameTip_2 = new QLabel(layoutWidget);
        usernameTip_2->setObjectName(QString::fromUtf8("usernameTip_2"));

        verticalLayout_4->addWidget(usernameTip_2);

        priceLineEdit = new QLineEdit(layoutWidget);
        priceLineEdit->setObjectName(QString::fromUtf8("priceLineEdit"));
        priceLineEdit->setFont(font);

        verticalLayout_4->addWidget(priceLineEdit);

        pswdTip_2 = new QLabel(layoutWidget);
        pswdTip_2->setObjectName(QString::fromUtf8("pswdTip_2"));

        verticalLayout_4->addWidget(pswdTip_2);

        numLineEdit = new QLineEdit(layoutWidget);
        numLineEdit->setObjectName(QString::fromUtf8("numLineEdit"));
        numLineEdit->setFont(font);

        verticalLayout_4->addWidget(numLineEdit);

        phonenumTip_2 = new QLabel(layoutWidget);
        phonenumTip_2->setObjectName(QString::fromUtf8("phonenumTip_2"));

        verticalLayout_4->addWidget(phonenumTip_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lifeButton = new QRadioButton(layoutWidget);
        lifeButton->setObjectName(QString::fromUtf8("lifeButton"));
        lifeButton->setFont(font);

        horizontalLayout_3->addWidget(lifeButton);

        studyButton = new QRadioButton(layoutWidget);
        studyButton->setObjectName(QString::fromUtf8("studyButton"));
        studyButton->setFont(font);

        horizontalLayout_3->addWidget(studyButton);

        foodButton = new QRadioButton(layoutWidget);
        foodButton->setObjectName(QString::fromUtf8("foodButton"));
        foodButton->setFont(font);

        horizontalLayout_3->addWidget(foodButton);

        clothesButton = new QRadioButton(layoutWidget);
        clothesButton->setObjectName(QString::fromUtf8("clothesButton"));
        clothesButton->setFont(font);

        horizontalLayout_3->addWidget(clothesButton);

        makeupButton = new QRadioButton(layoutWidget);
        makeupButton->setObjectName(QString::fromUtf8("makeupButton"));
        makeupButton->setFont(font);

        horizontalLayout_3->addWidget(makeupButton);

        ornaButton = new QRadioButton(layoutWidget);
        ornaButton->setObjectName(QString::fromUtf8("ornaButton"));
        ornaButton->setFont(font);

        horizontalLayout_3->addWidget(ornaButton);

        digiButton = new QRadioButton(layoutWidget);
        digiButton->setObjectName(QString::fromUtf8("digiButton"));
        digiButton->setFont(font);

        horizontalLayout_3->addWidget(digiButton);

        otherButton = new QRadioButton(layoutWidget);
        otherButton->setObjectName(QString::fromUtf8("otherButton"));
        otherButton->setFont(font);

        horizontalLayout_3->addWidget(otherButton);


        verticalLayout_4->addLayout(horizontalLayout_3);

        descLineEdit = new QLineEdit(layoutWidget);
        descLineEdit->setObjectName(QString::fromUtf8("descLineEdit"));
        descLineEdit->setFont(font);

        verticalLayout_4->addWidget(descLineEdit);

        addrTip_2 = new QLabel(layoutWidget);
        addrTip_2->setObjectName(QString::fromUtf8("addrTip_2"));

        verticalLayout_4->addWidget(addrTip_2);


        horizontalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(mdfcommoWidget);

        QMetaObject::connectSlotsByName(mdfcommoWidget);
    } // setupUi

    void retranslateUi(QWidget *mdfcommoWidget)
    {
        mdfcommoWidget->setWindowTitle(QCoreApplication::translate("mdfcommoWidget", "Form", nullptr));
        commitButton_2->setText(QCoreApplication::translate("mdfcommoWidget", "Commit", nullptr));
        cancelButton_2->setText(QCoreApplication::translate("mdfcommoWidget", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("mdfcommoWidget", "Modify commodity information:", nullptr));
        usernameLabel_2->setText(QCoreApplication::translate("mdfcommoWidget", "commodity name:", nullptr));
        pswdLabel_2->setText(QCoreApplication::translate("mdfcommoWidget", "price:", nullptr));
        phonenumLabel_2->setText(QCoreApplication::translate("mdfcommoWidget", "number:", nullptr));
        addrLabel_2->setText(QCoreApplication::translate("mdfcommoWidget", "attribute:", nullptr));
        label_2->setText(QCoreApplication::translate("mdfcommoWidget", "description:", nullptr));
        usernameTip_2->setText(QCoreApplication::translate("mdfcommoWidget", "<html><head/><body><p><span style=\" color:#204a87;\">(no more than 20 letters)</span></p></body></html>", nullptr));
        pswdTip_2->setText(QCoreApplication::translate("mdfcommoWidget", "<html><head/><body><p><span style=\" color:#204a87;\">(base price for this commodity, no more than 1 decimal)</span></p></body></html>", nullptr));
        phonenumTip_2->setText(QCoreApplication::translate("mdfcommoWidget", "<html><head/><body><p><span style=\" color:#204a87;\">(the quantity of commodity)</span></p></body></html>", nullptr));
        lifeButton->setText(QCoreApplication::translate("mdfcommoWidget", "life", nullptr));
        studyButton->setText(QCoreApplication::translate("mdfcommoWidget", "study", nullptr));
        foodButton->setText(QCoreApplication::translate("mdfcommoWidget", "food", nullptr));
        clothesButton->setText(QCoreApplication::translate("mdfcommoWidget", "clothes", nullptr));
        makeupButton->setText(QCoreApplication::translate("mdfcommoWidget", "makeup", nullptr));
        ornaButton->setText(QCoreApplication::translate("mdfcommoWidget", "ornament", nullptr));
        digiButton->setText(QCoreApplication::translate("mdfcommoWidget", "digital", nullptr));
        otherButton->setText(QCoreApplication::translate("mdfcommoWidget", "other", nullptr));
        addrTip_2->setText(QCoreApplication::translate("mdfcommoWidget", "<html><head/><body><p><span style=\" color:#204a87;\">(no more than 200 letters)</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mdfcommoWidget: public Ui_mdfcommoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MDFCOMMOWIDGET_H
