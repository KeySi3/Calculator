/********************************************************************************
** Form generated from reading UI file 'Calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalculatorClass
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_21;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_14;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_15;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton_22;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QVBoxLayout *verticalLayout_6;
    QPushButton *pushButton_20;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CalculatorClass)
    {
        if (CalculatorClass->objectName().isEmpty())
            CalculatorClass->setObjectName(QString::fromUtf8("CalculatorClass"));
        CalculatorClass->resize(420, 454);
        centralWidget = new QWidget(CalculatorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 10, 401, 386));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMinimumSize(QSize(0, 70));
        lineEdit->setStyleSheet(QString::fromUtf8("font: 14pt \"MS Shell Dlg 2\";"));
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit->setReadOnly(true);

        verticalLayout->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton = new QPushButton(horizontalLayoutWidget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(70, 70));
        pushButton->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(226, 226, 226);"));

        verticalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setMinimumSize(QSize(70, 70));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";background-color: rgb(226, 226, 226);"));

        verticalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setMinimumSize(QSize(70, 70));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";background-color: rgb(226, 226, 226);"));

        verticalLayout_2->addWidget(pushButton_3);

        pushButton_21 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));
        sizePolicy1.setHeightForWidth(pushButton_21->sizePolicy().hasHeightForWidth());
        pushButton_21->setSizePolicy(sizePolicy1);
        pushButton_21->setMinimumSize(QSize(70, 70));
        pushButton_21->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";background-color: rgb(233, 228, 130);"));

        verticalLayout_2->addWidget(pushButton_21);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton_4 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        pushButton_4->setMinimumSize(QSize(70, 70));
        pushButton_4->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";background-color: rgb(226, 226, 226);"));

        verticalLayout_3->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);
        pushButton_5->setMinimumSize(QSize(70, 70));
        pushButton_5->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";background-color: rgb(226, 226, 226);"));

        verticalLayout_3->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        pushButton_6->setMinimumSize(QSize(70, 70));
        pushButton_6->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";background-color: rgb(226, 226, 226);"));

        verticalLayout_3->addWidget(pushButton_6);

        pushButton_14 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        sizePolicy1.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy1);
        pushButton_14->setMinimumSize(QSize(70, 70));
        pushButton_14->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";background-color: rgb(226, 226, 226);"));

        verticalLayout_3->addWidget(pushButton_14);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        pushButton_7 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);
        pushButton_7->setMinimumSize(QSize(70, 70));
        pushButton_7->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";background-color: rgb(226, 226, 226);"));

        verticalLayout_4->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy1.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy1);
        pushButton_8->setMinimumSize(QSize(70, 70));
        pushButton_8->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";background-color: rgb(226, 226, 226);"));

        verticalLayout_4->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        sizePolicy1.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy1);
        pushButton_9->setMinimumSize(QSize(70, 70));
        pushButton_9->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";background-color: rgb(226, 226, 226);"));

        verticalLayout_4->addWidget(pushButton_9);

        pushButton_15 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        sizePolicy1.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy1);
        pushButton_15->setMinimumSize(QSize(70, 70));
        pushButton_15->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";background-color: rgb(233, 228, 130);"));

        verticalLayout_4->addWidget(pushButton_15);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        pushButton_22 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_22->setObjectName(QString::fromUtf8("pushButton_22"));
        sizePolicy1.setHeightForWidth(pushButton_22->sizePolicy().hasHeightForWidth());
        pushButton_22->setSizePolicy(sizePolicy1);
        pushButton_22->setMinimumSize(QSize(70, 70));
        pushButton_22->setStyleSheet(QString::fromUtf8("font: 16pt \"MS Shell Dlg 2\";background-color: rgb(233, 228, 130);"));

        verticalLayout_5->addWidget(pushButton_22);

        pushButton_10 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        sizePolicy1.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy1);
        pushButton_10->setMinimumSize(QSize(70, 70));
        pushButton_10->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";background-color: rgb(233, 177, 130);"));

        verticalLayout_5->addWidget(pushButton_10);

        pushButton_11 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        sizePolicy1.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy1);
        pushButton_11->setMinimumSize(QSize(70, 70));
        pushButton_11->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";background-color: rgb(233, 177, 130);"));

        verticalLayout_5->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        sizePolicy1.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy1);
        pushButton_12->setMinimumSize(QSize(70, 70));
        pushButton_12->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";background-color: rgb(233, 177, 130);"));

        verticalLayout_5->addWidget(pushButton_12);

        pushButton_13 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        sizePolicy1.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy1);
        pushButton_13->setMinimumSize(QSize(70, 70));
        pushButton_13->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(233, 177, 130);"));

        verticalLayout_5->addWidget(pushButton_13);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        pushButton_20 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));
        sizePolicy1.setHeightForWidth(pushButton_20->sizePolicy().hasHeightForWidth());
        pushButton_20->setSizePolicy(sizePolicy1);
        pushButton_20->setMinimumSize(QSize(70, 70));
        pushButton_20->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";background-color: rgb(233, 228, 130);"));

        verticalLayout_6->addWidget(pushButton_20);

        pushButton_16 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        sizePolicy1.setHeightForWidth(pushButton_16->sizePolicy().hasHeightForWidth());
        pushButton_16->setSizePolicy(sizePolicy1);
        pushButton_16->setMinimumSize(QSize(70, 70));
        pushButton_16->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";background-color: rgb(233, 177, 130);"));

        verticalLayout_6->addWidget(pushButton_16);

        pushButton_17 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        sizePolicy1.setHeightForWidth(pushButton_17->sizePolicy().hasHeightForWidth());
        pushButton_17->setSizePolicy(sizePolicy1);
        pushButton_17->setMinimumSize(QSize(70, 70));
        pushButton_17->setStyleSheet(QString::fromUtf8("font: 16pt \"MS Shell Dlg 2\";background-color: rgb(233, 177, 130);"));

        verticalLayout_6->addWidget(pushButton_17);

        pushButton_18 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        sizePolicy1.setHeightForWidth(pushButton_18->sizePolicy().hasHeightForWidth());
        pushButton_18->setSizePolicy(sizePolicy1);
        pushButton_18->setMinimumSize(QSize(70, 70));
        pushButton_18->setStyleSheet(QString::fromUtf8("font: 16pt \"MS Shell Dlg 2\";background-color: rgb(233, 177, 130);"));

        verticalLayout_6->addWidget(pushButton_18);

        pushButton_19 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        sizePolicy1.setHeightForWidth(pushButton_19->sizePolicy().hasHeightForWidth());
        pushButton_19->setSizePolicy(sizePolicy1);
        pushButton_19->setMinimumSize(QSize(70, 70));
        pushButton_19->setStyleSheet(QString::fromUtf8("font: 20pt \"MS Shell Dlg 2\";background-color: rgb(233, 228, 130);"));

        verticalLayout_6->addWidget(pushButton_19);


        horizontalLayout_3->addLayout(verticalLayout_6);

        CalculatorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CalculatorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 420, 26));
        CalculatorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CalculatorClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CalculatorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CalculatorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CalculatorClass->setStatusBar(statusBar);

        retranslateUi(CalculatorClass);

        QMetaObject::connectSlotsByName(CalculatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *CalculatorClass)
    {
        CalculatorClass->setWindowTitle(QCoreApplication::translate("CalculatorClass", "Calculator", nullptr));
        pushButton->setText(QCoreApplication::translate("CalculatorClass", "7", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CalculatorClass", "4", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CalculatorClass", "1", nullptr));
        pushButton_21->setText(QCoreApplication::translate("CalculatorClass", "( )", nullptr));
        pushButton_4->setText(QCoreApplication::translate("CalculatorClass", "8", nullptr));
        pushButton_5->setText(QCoreApplication::translate("CalculatorClass", "5", nullptr));
        pushButton_6->setText(QCoreApplication::translate("CalculatorClass", "2", nullptr));
        pushButton_14->setText(QCoreApplication::translate("CalculatorClass", "0", nullptr));
        pushButton_7->setText(QCoreApplication::translate("CalculatorClass", "9", nullptr));
        pushButton_8->setText(QCoreApplication::translate("CalculatorClass", "6", nullptr));
        pushButton_9->setText(QCoreApplication::translate("CalculatorClass", "3", nullptr));
        pushButton_15->setText(QCoreApplication::translate("CalculatorClass", ".", nullptr));
        pushButton_22->setText(QCoreApplication::translate("CalculatorClass", "DEL", nullptr));
        pushButton_10->setText(QCoreApplication::translate("CalculatorClass", "*", nullptr));
        pushButton_11->setText(QCoreApplication::translate("CalculatorClass", "/", nullptr));
        pushButton_12->setText(QCoreApplication::translate("CalculatorClass", "+", nullptr));
        pushButton_13->setText(QCoreApplication::translate("CalculatorClass", "-", nullptr));
        pushButton_20->setText(QCoreApplication::translate("CalculatorClass", "\320\241", nullptr));
        pushButton_16->setText(QCoreApplication::translate("CalculatorClass", "^", nullptr));
        pushButton_17->setText(QCoreApplication::translate("CalculatorClass", "sin", nullptr));
        pushButton_18->setText(QCoreApplication::translate("CalculatorClass", "cos", nullptr));
        pushButton_19->setText(QCoreApplication::translate("CalculatorClass", "=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalculatorClass: public Ui_CalculatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
