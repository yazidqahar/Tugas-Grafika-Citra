/********************************************************************************
** Form generated from reading UI file 'ftraining.ui'
**
** Created: Tue Jan 28 16:10:37 2014
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTRAINING_H
#define UI_FTRAINING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QRadioButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FTraining
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionRun_Learning;
    QAction *actionLoad_Weight_Neuron;
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QSpinBox *thresholdVal;
    QLabel *label;
    QLabel *label_4;
    QDoubleSpinBox *targetErrorVal;
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QLabel *label_3;
    QRadioButton *showThresholdAction;
    QRadioButton *ShowBoxAction;
    QLabel *gambarshow;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *groupBox_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *iterationVal;
    QLabel *CurrErrorVal;
    QLabel *CompleteVal;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *FTraining)
    {
        if (FTraining->objectName().isEmpty())
            FTraining->setObjectName(QString::fromUtf8("FTraining"));
        FTraining->resize(637, 430);
        FTraining->setFocusPolicy(Qt::StrongFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/C:/Users/Asus/Pictures/download.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        FTraining->setWindowIcon(icon);
        actionOpen = new QAction(FTraining);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/C:/Users/Asus/Pictures/openicon2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(FTraining);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Images/C:/Users/Asus/Pictures/saveicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionRun_Learning = new QAction(FTraining);
        actionRun_Learning->setObjectName(QString::fromUtf8("actionRun_Learning"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Images/C:/Users/Asus/Pictures/gearicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun_Learning->setIcon(icon3);
        actionLoad_Weight_Neuron = new QAction(FTraining);
        actionLoad_Weight_Neuron->setObjectName(QString::fromUtf8("actionLoad_Weight_Neuron"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Images/C:/Users/Asus/Pictures/brain.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad_Weight_Neuron->setIcon(icon4);
        centralwidget = new QWidget(FTraining);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(450, 10, 171, 111));
        thresholdVal = new QSpinBox(groupBox);
        thresholdVal->setObjectName(QString::fromUtf8("thresholdVal"));
        thresholdVal->setGeometry(QRect(120, 30, 42, 22));
        thresholdVal->setMaximum(255);
        thresholdVal->setValue(145);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 33, 91, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 72, 61, 16));
        targetErrorVal = new QDoubleSpinBox(groupBox);
        targetErrorVal->setObjectName(QString::fromUtf8("targetErrorVal"));
        targetErrorVal->setGeometry(QRect(100, 70, 62, 22));
        targetErrorVal->setDecimals(6);
        targetErrorVal->setMinimum(1e-06);
        targetErrorVal->setMaximum(0.999999);
        targetErrorVal->setSingleStep(1e-06);
        targetErrorVal->setValue(0.001);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(450, 130, 171, 101));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 30, 81, 16));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 60, 91, 16));
        showThresholdAction = new QRadioButton(groupBox_2);
        showThresholdAction->setObjectName(QString::fromUtf8("showThresholdAction"));
        showThresholdAction->setGeometry(QRect(140, 30, 16, 17));
        ShowBoxAction = new QRadioButton(groupBox_2);
        ShowBoxAction->setObjectName(QString::fromUtf8("ShowBoxAction"));
        ShowBoxAction->setGeometry(QRect(140, 57, 16, 20));
        gambarshow = new QLabel(centralwidget);
        gambarshow->setObjectName(QString::fromUtf8("gambarshow"));
        gambarshow->setGeometry(QRect(10, 10, 131, 51));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 431, 361));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 429, 359));
        scrollArea->setWidget(scrollAreaWidgetContents);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(450, 240, 171, 111));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 23, 71, 16));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 50, 71, 16));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 77, 71, 16));
        iterationVal = new QLabel(groupBox_3);
        iterationVal->setObjectName(QString::fromUtf8("iterationVal"));
        iterationVal->setGeometry(QRect(95, 24, 61, 16));
        CurrErrorVal = new QLabel(groupBox_3);
        CurrErrorVal->setObjectName(QString::fromUtf8("CurrErrorVal"));
        CurrErrorVal->setGeometry(QRect(95, 50, 61, 16));
        CompleteVal = new QLabel(groupBox_3);
        CompleteVal->setObjectName(QString::fromUtf8("CompleteVal"));
        CompleteVal->setGeometry(QRect(95, 76, 61, 16));
        FTraining->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(FTraining);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FTraining->setStatusBar(statusbar);
        toolBar = new QToolBar(FTraining);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        FTraining->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionLoad_Weight_Neuron);
        toolBar->addAction(actionRun_Learning);

        retranslateUi(FTraining);

        QMetaObject::connectSlotsByName(FTraining);
    } // setupUi

    void retranslateUi(QMainWindow *FTraining)
    {
        FTraining->setWindowTitle(QApplication::translate("FTraining", "Learning Neural Network", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("FTraining", "Open Image Learning", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("FTraining", "Open image Learning", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSave->setText(QApplication::translate("FTraining", "Save Weight Neuron", 0, QApplication::UnicodeUTF8));
        actionRun_Learning->setText(QApplication::translate("FTraining", "Run Learning", 0, QApplication::UnicodeUTF8));
        actionLoad_Weight_Neuron->setText(QApplication::translate("FTraining", "Load Weight Neuron", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("FTraining", "Konfigurasi", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FTraining", "Threshold Value", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FTraining", "Target Error", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("FTraining", "Aksi", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FTraining", "Show Threshold", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("FTraining", "Show Box Chars", 0, QApplication::UnicodeUTF8));
        showThresholdAction->setText(QString());
        ShowBoxAction->setText(QString());
        gambarshow->setText(QString());
        groupBox_3->setTitle(QApplication::translate("FTraining", "GroupBox", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("FTraining", "Iteration", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("FTraining", "Current Error", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("FTraining", "Complete", 0, QApplication::UnicodeUTF8));
        iterationVal->setText(QApplication::translate("FTraining", "0", 0, QApplication::UnicodeUTF8));
        CurrErrorVal->setText(QApplication::translate("FTraining", "0", 0, QApplication::UnicodeUTF8));
        CompleteVal->setText(QApplication::translate("FTraining", "0", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("FTraining", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FTraining: public Ui_FTraining {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTRAINING_H
