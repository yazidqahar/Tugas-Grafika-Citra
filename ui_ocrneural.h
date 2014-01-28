/********************************************************************************
** Form generated from reading UI file 'ocrneural.ui'
**
** Created: Tue Jan 28 19:09:26 2014
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OCRNEURAL_H
#define UI_OCRNEURAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QRadioButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OCRNeural
{
public:
    QAction *action_Training;
    QAction *actionLoad_Image;
    QAction *actionRun_OCR;
    QAction *actionLoad_Neural;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QSpinBox *thresholdVal;
    QLabel *label;
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QLabel *label_3;
    QRadioButton *showThresholdAction;
    QRadioButton *ShowBoxAction;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTextEdit *resultOCR;
    QLabel *gambarshow;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OCRNeural)
    {
        if (OCRNeural->objectName().isEmpty())
            OCRNeural->setObjectName(QString::fromUtf8("OCRNeural"));
        OCRNeural->resize(618, 411);
        OCRNeural->setFocusPolicy(Qt::WheelFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/C:/Users/Asus/Pictures/download.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        OCRNeural->setWindowIcon(icon);
        OCRNeural->setLayoutDirection(Qt::LeftToRight);
        action_Training = new QAction(OCRNeural);
        action_Training->setObjectName(QString::fromUtf8("action_Training"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/C:/Users/Asus/Pictures/learning_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Training->setIcon(icon1);
        actionLoad_Image = new QAction(OCRNeural);
        actionLoad_Image->setObjectName(QString::fromUtf8("actionLoad_Image"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Images/C:/Users/Asus/Pictures/openicon2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad_Image->setIcon(icon2);
        actionRun_OCR = new QAction(OCRNeural);
        actionRun_OCR->setObjectName(QString::fromUtf8("actionRun_OCR"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Images/C:/Users/Asus/Pictures/gearicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun_OCR->setIcon(icon3);
        actionLoad_Neural = new QAction(OCRNeural);
        actionLoad_Neural->setObjectName(QString::fromUtf8("actionLoad_Neural"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Images/C:/Users/Asus/Pictures/brain.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad_Neural->setIcon(icon4);
        centralWidget = new QWidget(OCRNeural);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(440, 10, 171, 71));
        thresholdVal = new QSpinBox(groupBox);
        thresholdVal->setObjectName(QString::fromUtf8("thresholdVal"));
        thresholdVal->setGeometry(QRect(120, 30, 42, 22));
        thresholdVal->setMaximum(255);
        thresholdVal->setValue(145);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 33, 91, 16));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(440, 100, 171, 101));
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
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 431, 181));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 429, 179));
        scrollArea->setWidget(scrollAreaWidgetContents);
        resultOCR = new QTextEdit(centralWidget);
        resultOCR->setObjectName(QString::fromUtf8("resultOCR"));
        resultOCR->setGeometry(QRect(10, 190, 421, 151));
        gambarshow = new QLabel(centralWidget);
        gambarshow->setObjectName(QString::fromUtf8("gambarshow"));
        gambarshow->setGeometry(QRect(30, 10, 131, 51));
        OCRNeural->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(OCRNeural);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        OCRNeural->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(OCRNeural);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        OCRNeural->setStatusBar(statusBar);

        mainToolBar->addAction(action_Training);
        mainToolBar->addAction(actionLoad_Image);
        mainToolBar->addAction(actionLoad_Neural);
        mainToolBar->addAction(actionRun_OCR);

        retranslateUi(OCRNeural);

        QMetaObject::connectSlotsByName(OCRNeural);
    } // setupUi

    void retranslateUi(QMainWindow *OCRNeural)
    {
        OCRNeural->setWindowTitle(QApplication::translate("OCRNeural", "Running OCR", 0, QApplication::UnicodeUTF8));
        action_Training->setText(QApplication::translate("OCRNeural", "&Training", 0, QApplication::UnicodeUTF8));
        actionLoad_Image->setText(QApplication::translate("OCRNeural", "Load Image", 0, QApplication::UnicodeUTF8));
        actionRun_OCR->setText(QApplication::translate("OCRNeural", "Run OCR", 0, QApplication::UnicodeUTF8));
        actionLoad_Neural->setText(QApplication::translate("OCRNeural", "Load Weight Neural", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("OCRNeural", "Konfigurasi", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OCRNeural", "Threshold Value", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("OCRNeural", "Aksi", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("OCRNeural", "Show Threshold", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("OCRNeural", "Show Box Chars", 0, QApplication::UnicodeUTF8));
        showThresholdAction->setText(QString());
        ShowBoxAction->setText(QString());
        gambarshow->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OCRNeural: public Ui_OCRNeural {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OCRNEURAL_H
