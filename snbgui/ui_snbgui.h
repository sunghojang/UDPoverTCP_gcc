/********************************************************************************
** Form generated from reading UI file 'snbgui.ui'
**
** Created: Fri Aug 24 12:21:48 2018
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNBGUI_H
#define UI_SNBGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
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
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SNBGui
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tabUT;
    QFormLayout *formLayout_2;
    QFormLayout *formLayout;
    QLabel *labelUdpListenPort;
    QSpinBox *spinBoxUdpListenPort;
    QLabel *labelTcpServerPort;
    QSpinBox *spinBoxTcpServerPort;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *buttonUTStartStop;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *checkBoxUTBidirectionalEnabled;
    QWidget *tabTU;
    QFormLayout *formLayout_4;
    QFormLayout *formLayout_3;
    QLabel *labelTcpServerAddress;
    QLineEdit *lineEditTcpServerAddress;
    QLabel *labelTcpServerPort_2;
    QSpinBox *spinBoxTcpClientPort;
    QLabel *labelUdpBroadcastPort;
    QSpinBox *spinBoxUdpBroadcastPort;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *buttonTUStartStop;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *checkBoxTUBidirectionalEnabled;
    QTextEdit *textEditLogger;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonClearLogger;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SNBGui)
    {
        if (SNBGui->objectName().isEmpty())
            SNBGui->setObjectName(QString::fromUtf8("SNBGui"));
        SNBGui->resize(801, 488);
        centralWidget = new QWidget(SNBGui);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabUT = new QWidget();
        tabUT->setObjectName(QString::fromUtf8("tabUT"));
        formLayout_2 = new QFormLayout(tabUT);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));

        formLayout_2->setLayout(1, QFormLayout::LabelRole, formLayout);

        labelUdpListenPort = new QLabel(tabUT);
        labelUdpListenPort->setObjectName(QString::fromUtf8("labelUdpListenPort"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, labelUdpListenPort);

        spinBoxUdpListenPort = new QSpinBox(tabUT);
        spinBoxUdpListenPort->setObjectName(QString::fromUtf8("spinBoxUdpListenPort"));
        spinBoxUdpListenPort->setMinimum(1000);
        spinBoxUdpListenPort->setMaximum(100000);
        spinBoxUdpListenPort->setSingleStep(10);
        spinBoxUdpListenPort->setValue(5670);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, spinBoxUdpListenPort);

        labelTcpServerPort = new QLabel(tabUT);
        labelTcpServerPort->setObjectName(QString::fromUtf8("labelTcpServerPort"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, labelTcpServerPort);

        spinBoxTcpServerPort = new QSpinBox(tabUT);
        spinBoxTcpServerPort->setObjectName(QString::fromUtf8("spinBoxTcpServerPort"));
        spinBoxTcpServerPort->setMinimum(1000);
        spinBoxTcpServerPort->setMaximum(100000);
        spinBoxTcpServerPort->setSingleStep(10);
        spinBoxTcpServerPort->setValue(60000);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, spinBoxTcpServerPort);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        buttonUTStartStop = new QPushButton(tabUT);
        buttonUTStartStop->setObjectName(QString::fromUtf8("buttonUTStartStop"));

        horizontalLayout_2->addWidget(buttonUTStartStop);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        formLayout_2->setLayout(5, QFormLayout::FieldRole, horizontalLayout_2);

        checkBoxUTBidirectionalEnabled = new QCheckBox(tabUT);
        checkBoxUTBidirectionalEnabled->setObjectName(QString::fromUtf8("checkBoxUTBidirectionalEnabled"));
        checkBoxUTBidirectionalEnabled->setChecked(true);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, checkBoxUTBidirectionalEnabled);

        tabWidget->addTab(tabUT, QString());
        tabTU = new QWidget();
        tabTU->setObjectName(QString::fromUtf8("tabTU"));
        formLayout_4 = new QFormLayout(tabTU);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));

        formLayout_4->setLayout(0, QFormLayout::LabelRole, formLayout_3);

        labelTcpServerAddress = new QLabel(tabTU);
        labelTcpServerAddress->setObjectName(QString::fromUtf8("labelTcpServerAddress"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, labelTcpServerAddress);

        lineEditTcpServerAddress = new QLineEdit(tabTU);
        lineEditTcpServerAddress->setObjectName(QString::fromUtf8("lineEditTcpServerAddress"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, lineEditTcpServerAddress);

        labelTcpServerPort_2 = new QLabel(tabTU);
        labelTcpServerPort_2->setObjectName(QString::fromUtf8("labelTcpServerPort_2"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, labelTcpServerPort_2);

        spinBoxTcpClientPort = new QSpinBox(tabTU);
        spinBoxTcpClientPort->setObjectName(QString::fromUtf8("spinBoxTcpClientPort"));
        spinBoxTcpClientPort->setMinimum(1000);
        spinBoxTcpClientPort->setMaximum(100000);
        spinBoxTcpClientPort->setSingleStep(10);
        spinBoxTcpClientPort->setValue(60000);

        formLayout_4->setWidget(2, QFormLayout::FieldRole, spinBoxTcpClientPort);

        labelUdpBroadcastPort = new QLabel(tabTU);
        labelUdpBroadcastPort->setObjectName(QString::fromUtf8("labelUdpBroadcastPort"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, labelUdpBroadcastPort);

        spinBoxUdpBroadcastPort = new QSpinBox(tabTU);
        spinBoxUdpBroadcastPort->setObjectName(QString::fromUtf8("spinBoxUdpBroadcastPort"));
        spinBoxUdpBroadcastPort->setMinimum(1000);
        spinBoxUdpBroadcastPort->setMaximum(100000);
        spinBoxUdpBroadcastPort->setSingleStep(10);
        spinBoxUdpBroadcastPort->setValue(5670);

        formLayout_4->setWidget(3, QFormLayout::FieldRole, spinBoxUdpBroadcastPort);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        buttonTUStartStop = new QPushButton(tabTU);
        buttonTUStartStop->setObjectName(QString::fromUtf8("buttonTUStartStop"));

        horizontalLayout_3->addWidget(buttonTUStartStop);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        formLayout_4->setLayout(5, QFormLayout::FieldRole, horizontalLayout_3);

        checkBoxTUBidirectionalEnabled = new QCheckBox(tabTU);
        checkBoxTUBidirectionalEnabled->setObjectName(QString::fromUtf8("checkBoxTUBidirectionalEnabled"));
        checkBoxTUBidirectionalEnabled->setChecked(true);

        formLayout_4->setWidget(4, QFormLayout::FieldRole, checkBoxTUBidirectionalEnabled);

        tabWidget->addTab(tabTU, QString());

        verticalLayout_2->addWidget(tabWidget);

        textEditLogger = new QTextEdit(centralWidget);
        textEditLogger->setObjectName(QString::fromUtf8("textEditLogger"));
        textEditLogger->setUndoRedoEnabled(false);
        textEditLogger->setReadOnly(true);

        verticalLayout_2->addWidget(textEditLogger);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonClearLogger = new QPushButton(centralWidget);
        buttonClearLogger->setObjectName(QString::fromUtf8("buttonClearLogger"));

        horizontalLayout->addWidget(buttonClearLogger);


        verticalLayout_2->addLayout(horizontalLayout);

        SNBGui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SNBGui);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 801, 29));
        SNBGui->setMenuBar(menuBar);
        statusBar = new QStatusBar(SNBGui);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SNBGui->setStatusBar(statusBar);
        QWidget::setTabOrder(buttonClearLogger, tabWidget);
        QWidget::setTabOrder(tabWidget, spinBoxUdpListenPort);
        QWidget::setTabOrder(spinBoxUdpListenPort, spinBoxTcpServerPort);
        QWidget::setTabOrder(spinBoxTcpServerPort, checkBoxUTBidirectionalEnabled);
        QWidget::setTabOrder(checkBoxUTBidirectionalEnabled, buttonUTStartStop);
        QWidget::setTabOrder(buttonUTStartStop, lineEditTcpServerAddress);
        QWidget::setTabOrder(lineEditTcpServerAddress, spinBoxTcpClientPort);
        QWidget::setTabOrder(spinBoxTcpClientPort, spinBoxUdpBroadcastPort);
        QWidget::setTabOrder(spinBoxUdpBroadcastPort, checkBoxTUBidirectionalEnabled);
        QWidget::setTabOrder(checkBoxTUBidirectionalEnabled, buttonTUStartStop);
        QWidget::setTabOrder(buttonTUStartStop, textEditLogger);

        retranslateUi(SNBGui);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SNBGui);
    } // setupUi

    void retranslateUi(QMainWindow *SNBGui)
    {
        SNBGui->setWindowTitle(QApplication::translate("SNBGui", "SNBGui", 0, QApplication::UnicodeUTF8));
        labelUdpListenPort->setText(QApplication::translate("SNBGui", "UDP Listen Port:", 0, QApplication::UnicodeUTF8));
        labelTcpServerPort->setText(QApplication::translate("SNBGui", "TCP Server Port:", 0, QApplication::UnicodeUTF8));
        buttonUTStartStop->setText(QApplication::translate("SNBGui", "Start", 0, QApplication::UnicodeUTF8));
        checkBoxUTBidirectionalEnabled->setText(QApplication::translate("SNBGui", "Bidirectional communication", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabUT), QApplication::translate("SNBGui", "UDP to TCP", 0, QApplication::UnicodeUTF8));
        labelTcpServerAddress->setText(QApplication::translate("SNBGui", "TCP Server Address:", 0, QApplication::UnicodeUTF8));
        lineEditTcpServerAddress->setText(QApplication::translate("SNBGui", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        labelTcpServerPort_2->setText(QApplication::translate("SNBGui", "TCP Server Port:", 0, QApplication::UnicodeUTF8));
        labelUdpBroadcastPort->setText(QApplication::translate("SNBGui", "UDP Broadcast Port:", 0, QApplication::UnicodeUTF8));
        buttonTUStartStop->setText(QApplication::translate("SNBGui", "Start", 0, QApplication::UnicodeUTF8));
        checkBoxTUBidirectionalEnabled->setText(QApplication::translate("SNBGui", "Bidirectional communication", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabTU), QApplication::translate("SNBGui", "TCP to UDP", 0, QApplication::UnicodeUTF8));
        buttonClearLogger->setText(QApplication::translate("SNBGui", "Clear", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SNBGui: public Ui_SNBGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNBGUI_H
