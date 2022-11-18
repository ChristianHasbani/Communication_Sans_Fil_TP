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
    QLineEdit *prenomText_2;
    QGroupBox *groupBox_3;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QLabel *versionLabel;
    QPushButton *readCardBtn;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QString::fromUtf8("Window"));
        Window->resize(800, 600);
        groupBox = new QGroupBox(Window);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(300, 80, 391, 131));
        prenomLabel = new QLabel(groupBox);
        prenomLabel->setObjectName(QString::fromUtf8("prenomLabel"));
        prenomLabel->setGeometry(QRect(20, 80, 51, 20));
        updateButton = new QPushButton(groupBox);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        updateButton->setGeometry(QRect(290, 70, 91, 29));
        nomlabel = new QLabel(groupBox);
        nomlabel->setObjectName(QString::fromUtf8("nomlabel"));
        nomlabel->setGeometry(QRect(30, 40, 41, 20));
        nomText = new QLineEdit(groupBox);
        nomText->setObjectName(QString::fromUtf8("nomText"));
        nomText->setGeometry(QRect(120, 40, 113, 28));
        nomText->setReadOnly(false);
        prenomText = new QLineEdit(groupBox);
        prenomText->setObjectName(QString::fromUtf8("prenomText"));
        prenomText->setGeometry(QRect(120, 80, 113, 28));
        prenomText->setReadOnly(false);
        groupBox_2 = new QGroupBox(Window);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(300, 230, 391, 121));
        nbunitsLabel = new QLabel(groupBox_2);
        nbunitsLabel->setObjectName(QString::fromUtf8("nbunitsLabel"));
        nbunitsLabel->setGeometry(QRect(30, 40, 111, 20));
        prenomText_2 = new QLineEdit(groupBox_2);
        prenomText_2->setObjectName(QString::fromUtf8("prenomText_2"));
        prenomText_2->setGeometry(QRect(180, 40, 41, 28));
        prenomText_2->setReadOnly(true);
        groupBox_3 = new QGroupBox(Window);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(300, 380, 391, 121));
        connectButton = new QPushButton(Window);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(20, 520, 91, 29));
        disconnectButton = new QPushButton(Window);
        disconnectButton->setObjectName(QString::fromUtf8("disconnectButton"));
        disconnectButton->setGeometry(QRect(120, 520, 91, 29));
        versionLabel = new QLabel(Window);
        versionLabel->setObjectName(QString::fromUtf8("versionLabel"));
        versionLabel->setGeometry(QRect(30, 490, 181, 20));
        readCardBtn = new QPushButton(Window);
        readCardBtn->setObjectName(QString::fromUtf8("readCardBtn"));
        readCardBtn->setGeometry(QRect(20, 560, 191, 29));

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
        groupBox_3->setTitle(QCoreApplication::translate("Window", "D\303\251cr\303\251menter le porte monnaie", nullptr));
        connectButton->setText(QCoreApplication::translate("Window", "Connect", nullptr));
        disconnectButton->setText(QCoreApplication::translate("Window", "Disconnect", nullptr));
        versionLabel->setText(QString());
        readCardBtn->setText(QCoreApplication::translate("Window", "Read Card", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
