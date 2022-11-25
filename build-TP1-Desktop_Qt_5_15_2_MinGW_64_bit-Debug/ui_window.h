/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QGroupBox *groupBox;
    QLabel *prenomLabel;
    QPushButton *updateButton;
    QLabel *nomlabel;
    QLineEdit *nomText;
    QLineEdit *prenomText;
    QGroupBox *groupBox_2;
    QLabel *nbunitsLabel;
    QLineEdit *nbUnitText;
    QLabel *nbDecLabel;
    QSpinBox *nbDecSpinner;
    QPushButton *payBtn;
    QGroupBox *groupBox_3;
    QSpinBox *incrementSpinner;
    QPushButton *chargeBtn;
    QLabel *nbIncreDescLabel;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QLabel *versionLabel;
    QPushButton *readCardBtn;
    QPushButton *quitBtn;
    QLabel *titleDescLabel;
    QLabel *textWLinkLabel;
    QLabel *titleLabel;
    QLabel *bigImgLabel;
    QLabel *smallPicLabel;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QString::fromUtf8("Window"));
        Window->resize(1005, 736);
        Window->setWindowOpacity(1.000000000000000);
        Window->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        groupBox = new QGroupBox(Window);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(520, 130, 461, 131));
        prenomLabel = new QLabel(groupBox);
        prenomLabel->setObjectName(QString::fromUtf8("prenomLabel"));
        prenomLabel->setGeometry(QRect(20, 80, 51, 20));
        updateButton = new QPushButton(groupBox);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        updateButton->setGeometry(QRect(330, 70, 111, 29));
        nomlabel = new QLabel(groupBox);
        nomlabel->setObjectName(QString::fromUtf8("nomlabel"));
        nomlabel->setGeometry(QRect(30, 40, 41, 20));
        nomText = new QLineEdit(groupBox);
        nomText->setObjectName(QString::fromUtf8("nomText"));
        nomText->setGeometry(QRect(120, 40, 191, 28));
        nomText->setReadOnly(false);
        prenomText = new QLineEdit(groupBox);
        prenomText->setObjectName(QString::fromUtf8("prenomText"));
        prenomText->setGeometry(QRect(120, 80, 191, 28));
        prenomText->setReadOnly(false);
        groupBox_2 = new QGroupBox(Window);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(520, 280, 461, 121));
        nbunitsLabel = new QLabel(groupBox_2);
        nbunitsLabel->setObjectName(QString::fromUtf8("nbunitsLabel"));
        nbunitsLabel->setGeometry(QRect(30, 40, 111, 20));
        nbUnitText = new QLineEdit(groupBox_2);
        nbUnitText->setObjectName(QString::fromUtf8("nbUnitText"));
        nbUnitText->setGeometry(QRect(280, 40, 51, 28));
        nbUnitText->setReadOnly(true);
        nbDecLabel = new QLabel(groupBox_2);
        nbDecLabel->setObjectName(QString::fromUtf8("nbDecLabel"));
        nbDecLabel->setGeometry(QRect(30, 80, 221, 20));
        nbDecSpinner = new QSpinBox(groupBox_2);
        nbDecSpinner->setObjectName(QString::fromUtf8("nbDecSpinner"));
        nbDecSpinner->setGeometry(QRect(280, 80, 61, 29));
        payBtn = new QPushButton(groupBox_2);
        payBtn->setObjectName(QString::fromUtf8("payBtn"));
        payBtn->setGeometry(QRect(350, 80, 101, 29));
        payBtn->setStyleSheet(QString::fromUtf8(""));
        groupBox_3 = new QGroupBox(Window);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(520, 430, 461, 121));
        incrementSpinner = new QSpinBox(groupBox_3);
        incrementSpinner->setObjectName(QString::fromUtf8("incrementSpinner"));
        incrementSpinner->setGeometry(QRect(280, 60, 61, 29));
        chargeBtn = new QPushButton(groupBox_3);
        chargeBtn->setObjectName(QString::fromUtf8("chargeBtn"));
        chargeBtn->setGeometry(QRect(350, 60, 101, 29));
        chargeBtn->setStyleSheet(QString::fromUtf8(""));
        nbIncreDescLabel = new QLabel(groupBox_3);
        nbIncreDescLabel->setObjectName(QString::fromUtf8("nbIncreDescLabel"));
        nbIncreDescLabel->setGeometry(QRect(30, 60, 221, 20));
        connectButton = new QPushButton(Window);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(70, 490, 131, 29));
        disconnectButton = new QPushButton(Window);
        disconnectButton->setObjectName(QString::fromUtf8("disconnectButton"));
        disconnectButton->setGeometry(QRect(230, 489, 131, 29));
        versionLabel = new QLabel(Window);
        versionLabel->setObjectName(QString::fromUtf8("versionLabel"));
        versionLabel->setGeometry(QRect(80, 580, 281, 20));
        readCardBtn = new QPushButton(Window);
        readCardBtn->setObjectName(QString::fromUtf8("readCardBtn"));
        readCardBtn->setGeometry(QRect(70, 530, 291, 29));
        quitBtn = new QPushButton(Window);
        quitBtn->setObjectName(QString::fromUtf8("quitBtn"));
        quitBtn->setGeometry(QRect(892, 630, 101, 29));
        quitBtn->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        titleDescLabel = new QLabel(Window);
        titleDescLabel->setObjectName(QString::fromUtf8("titleDescLabel"));
        titleDescLabel->setGeometry(QRect(30, 50, 321, 61));
        titleDescLabel->setWordWrap(true);
        textWLinkLabel = new QLabel(Window);
        textWLinkLabel->setObjectName(QString::fromUtf8("textWLinkLabel"));
        textWLinkLabel->setGeometry(QRect(50, 620, 391, 61));
        textWLinkLabel->setWordWrap(true);
        titleLabel = new QLabel(Window);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(30, 20, 191, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        titleLabel->setFont(font);
        bigImgLabel = new QLabel(Window);
        bigImgLabel->setObjectName(QString::fromUtf8("bigImgLabel"));
        bigImgLabel->setGeometry(QRect(20, 110, 391, 351));
        bigImgLabel->setFrameShape(QFrame::NoFrame);
        bigImgLabel->setPixmap(QPixmap(QString::fromUtf8("../IMGs/bigPic.png")));
        smallPicLabel = new QLabel(Window);
        smallPicLabel->setObjectName(QString::fromUtf8("smallPicLabel"));
        smallPicLabel->setGeometry(QRect(800, 30, 171, 81));
        smallPicLabel->setPixmap(QPixmap(QString::fromUtf8("../IMGs/smallPic.png")));

        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QCoreApplication::translate("Window", "ODALI Porte monnaie", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Window", "Identit\303\251", nullptr));
        prenomLabel->setText(QCoreApplication::translate("Window", "Prenom", nullptr));
        updateButton->setText(QCoreApplication::translate("Window", "Mise \303\240 jour ", nullptr));
        nomlabel->setText(QCoreApplication::translate("Window", "Nom", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Window", "D\303\251cr\303\251menter le porte monnaie", nullptr));
        nbunitsLabel->setText(QCoreApplication::translate("Window", "Nombre d'unit\303\251s", nullptr));
        nbDecLabel->setText(QCoreApplication::translate("Window", "Nombre d'unit\303\251s \303\240 d\303\251cr\303\251menter", nullptr));
        payBtn->setText(QCoreApplication::translate("Window", "Payer", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Window", "Incr\303\251menter le porte monnaie", nullptr));
        chargeBtn->setText(QCoreApplication::translate("Window", "Charger", nullptr));
        nbIncreDescLabel->setText(QCoreApplication::translate("Window", "Nombre d'unit\303\251s \303\240 d\303\251cr\303\251menter", nullptr));
        connectButton->setText(QCoreApplication::translate("Window", "Connect", nullptr));
        disconnectButton->setText(QCoreApplication::translate("Window", "Disconnect", nullptr));
        versionLabel->setText(QString());
        readCardBtn->setText(QCoreApplication::translate("Window", "Selectionner la carte", nullptr));
        quitBtn->setText(QCoreApplication::translate("Window", "Quitter", nullptr));
        titleDescLabel->setText(QCoreApplication::translate("Window", "Cette application montre le fonctionnement d'un porte monnaie \303\251lectronique sur carte MIFARE Classic 1k", nullptr));
        textWLinkLabel->setText(QString());
        titleLabel->setText(QCoreApplication::translate("Window", "Porte monnaie", nullptr));
        bigImgLabel->setText(QString());
        smallPicLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
