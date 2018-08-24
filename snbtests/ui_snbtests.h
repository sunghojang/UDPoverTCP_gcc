/********************************************************************************
** Form generated from reading UI file 'snbtests.ui'
**
** Created: Fri Aug 24 12:22:00 2018
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNBTESTS_H
#define UI_SNBTESTS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SNBTests
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_2;
    QSpinBox *spinBoxBroadcastPort;
    QLabel *label;
    QSpinBox *spinBoxListenPort;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonSend;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QTextEdit *textEditLogger;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *buttonClearLogger;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SNBTests)
    {
        if (SNBTests->objectName().isEmpty())
            SNBTests->setObjectName(QString::fromUtf8("SNBTests"));
        SNBTests->resize(400, 357);
        centralWidget = new QWidget(SNBTests);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        spinBoxBroadcastPort = new QSpinBox(centralWidget);
        spinBoxBroadcastPort->setObjectName(QString::fromUtf8("spinBoxBroadcastPort"));
        spinBoxBroadcastPort->setMinimum(1000);
        spinBoxBroadcastPort->setMaximum(100000);
        spinBoxBroadcastPort->setSingleStep(10);
        spinBoxBroadcastPort->setValue(5670);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBoxBroadcastPort);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        spinBoxListenPort = new QSpinBox(centralWidget);
        spinBoxListenPort->setObjectName(QString::fromUtf8("spinBoxListenPort"));
        spinBoxListenPort->setMinimum(1000);
        spinBoxListenPort->setMaximum(100000);
        spinBoxListenPort->setSingleStep(10);
        spinBoxListenPort->setValue(5670);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBoxListenPort);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonSend = new QPushButton(centralWidget);
        buttonSend->setObjectName(QString::fromUtf8("buttonSend"));

        horizontalLayout->addWidget(buttonSend);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);


        verticalLayout->addLayout(formLayout);

        textEditLogger = new QTextEdit(centralWidget);
        textEditLogger->setObjectName(QString::fromUtf8("textEditLogger"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEditLogger->sizePolicy().hasHeightForWidth());
        textEditLogger->setSizePolicy(sizePolicy);
        textEditLogger->setUndoRedoEnabled(false);
        textEditLogger->setReadOnly(true);

        verticalLayout->addWidget(textEditLogger);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        buttonClearLogger = new QPushButton(centralWidget);
        buttonClearLogger->setObjectName(QString::fromUtf8("buttonClearLogger"));

        horizontalLayout_2->addWidget(buttonClearLogger);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        SNBTests->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SNBTests);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 29));
        SNBTests->setMenuBar(menuBar);
        statusBar = new QStatusBar(SNBTests);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SNBTests->setStatusBar(statusBar);
        QWidget::setTabOrder(spinBoxBroadcastPort, spinBoxListenPort);
        QWidget::setTabOrder(spinBoxListenPort, lineEdit);
        QWidget::setTabOrder(lineEdit, buttonSend);
        QWidget::setTabOrder(buttonSend, buttonClearLogger);
        QWidget::setTabOrder(buttonClearLogger, textEditLogger);

        retranslateUi(SNBTests);

        QMetaObject::connectSlotsByName(SNBTests);
    } // setupUi

    void retranslateUi(QMainWindow *SNBTests)
    {
        SNBTests->setWindowTitle(QApplication::translate("SNBTests", "SNBTests", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SNBTests", "UDP Broadcast Port:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SNBTests", "UDP Listen Port:", 0, QApplication::UnicodeUTF8));
        buttonSend->setText(QApplication::translate("SNBTests", "Send", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("SNBTests", "example", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SNBTests", "Send Message:", 0, QApplication::UnicodeUTF8));
        buttonClearLogger->setText(QApplication::translate("SNBTests", "Clear", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SNBTests: public Ui_SNBTests {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNBTESTS_H
