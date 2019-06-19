/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *VolumeLayout;
    QSlider *volumeSlider;
    QLabel *volume;
    QPushButton *m_pButton1;
    QPushButton *m_pButton2;
    QPushButton *m_pButton3;
    QPushButton *m_pButtonA;
    QPushButton *m_pButton5;
    QPushButton *m_pButtonB;
    QPushButton *m_pButton4;
    QPushButton *m_pButton6;
    QPushButton *m_pButton8;
    QPushButton *m_pButtonC;
    QPushButton *m_pButton7;
    QPushButton *m_pButton9;
    QPushButton *m_pButton0;
    QPushButton *m_pButtonD;
    QPushButton *m_pButtonAst;
    QPushButton *m_pButtonNum;
    QPushButton *m_pButtonHang;
    QListView *listNumbers;
    QTextEdit *txtNumber;
    QLabel *volume_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(925, 463);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 90, 51, 251));
        VolumeLayout = new QHBoxLayout(horizontalLayoutWidget);
        VolumeLayout->setSpacing(6);
        VolumeLayout->setContentsMargins(11, 11, 11, 11);
        VolumeLayout->setObjectName(QStringLiteral("VolumeLayout"));
        VolumeLayout->setContentsMargins(0, 0, 0, 0);
        volumeSlider = new QSlider(horizontalLayoutWidget);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setEnabled(false);
        volumeSlider->setMaximum(50);
        volumeSlider->setOrientation(Qt::Vertical);
        volumeSlider->setTickPosition(QSlider::TicksBothSides);

        VolumeLayout->addWidget(volumeSlider);

        volume = new QLabel(centralWidget);
        volume->setObjectName(QStringLiteral("volume"));
        volume->setGeometry(QRect(10, 340, 67, 17));
        m_pButton1 = new QPushButton(centralWidget);
        m_pButton1->setObjectName(QStringLiteral("m_pButton1"));
        m_pButton1->setGeometry(QRect(100, 90, 51, 41));
        m_pButton2 = new QPushButton(centralWidget);
        m_pButton2->setObjectName(QStringLiteral("m_pButton2"));
        m_pButton2->setGeometry(QRect(160, 90, 51, 41));
        m_pButton3 = new QPushButton(centralWidget);
        m_pButton3->setObjectName(QStringLiteral("m_pButton3"));
        m_pButton3->setGeometry(QRect(220, 90, 51, 41));
        m_pButtonA = new QPushButton(centralWidget);
        m_pButtonA->setObjectName(QStringLiteral("m_pButtonA"));
        m_pButtonA->setGeometry(QRect(280, 90, 51, 41));
        m_pButton5 = new QPushButton(centralWidget);
        m_pButton5->setObjectName(QStringLiteral("m_pButton5"));
        m_pButton5->setGeometry(QRect(160, 140, 51, 41));
        m_pButtonB = new QPushButton(centralWidget);
        m_pButtonB->setObjectName(QStringLiteral("m_pButtonB"));
        m_pButtonB->setGeometry(QRect(280, 140, 51, 41));
        m_pButton4 = new QPushButton(centralWidget);
        m_pButton4->setObjectName(QStringLiteral("m_pButton4"));
        m_pButton4->setGeometry(QRect(100, 140, 51, 41));
        m_pButton6 = new QPushButton(centralWidget);
        m_pButton6->setObjectName(QStringLiteral("m_pButton6"));
        m_pButton6->setGeometry(QRect(220, 140, 51, 41));
        m_pButton8 = new QPushButton(centralWidget);
        m_pButton8->setObjectName(QStringLiteral("m_pButton8"));
        m_pButton8->setGeometry(QRect(160, 190, 51, 41));
        m_pButtonC = new QPushButton(centralWidget);
        m_pButtonC->setObjectName(QStringLiteral("m_pButtonC"));
        m_pButtonC->setGeometry(QRect(280, 190, 51, 41));
        m_pButton7 = new QPushButton(centralWidget);
        m_pButton7->setObjectName(QStringLiteral("m_pButton7"));
        m_pButton7->setGeometry(QRect(100, 190, 51, 41));
        m_pButton9 = new QPushButton(centralWidget);
        m_pButton9->setObjectName(QStringLiteral("m_pButton9"));
        m_pButton9->setGeometry(QRect(220, 190, 51, 41));
        m_pButton0 = new QPushButton(centralWidget);
        m_pButton0->setObjectName(QStringLiteral("m_pButton0"));
        m_pButton0->setGeometry(QRect(160, 240, 51, 41));
        m_pButtonD = new QPushButton(centralWidget);
        m_pButtonD->setObjectName(QStringLiteral("m_pButtonD"));
        m_pButtonD->setGeometry(QRect(280, 240, 51, 41));
        m_pButtonAst = new QPushButton(centralWidget);
        m_pButtonAst->setObjectName(QStringLiteral("m_pButtonAst"));
        m_pButtonAst->setGeometry(QRect(100, 240, 51, 41));
        m_pButtonNum = new QPushButton(centralWidget);
        m_pButtonNum->setObjectName(QStringLiteral("m_pButtonNum"));
        m_pButtonNum->setGeometry(QRect(220, 240, 51, 41));
        m_pButtonHang = new QPushButton(centralWidget);
        m_pButtonHang->setObjectName(QStringLiteral("m_pButtonHang"));
        m_pButtonHang->setGeometry(QRect(100, 290, 231, 51));
        listNumbers = new QListView(centralWidget);
        listNumbers->setObjectName(QStringLiteral("listNumbers"));
        listNumbers->setGeometry(QRect(350, 90, 131, 251));
        txtNumber = new QTextEdit(centralWidget);
        txtNumber->setObjectName(QStringLiteral("txtNumber"));
        txtNumber->setEnabled(false);
        txtNumber->setGeometry(QRect(100, 40, 231, 31));
        QFont font;
        font.setPointSize(14);
        txtNumber->setFont(font);
        volume_2 = new QLabel(centralWidget);
        volume_2->setObjectName(QStringLiteral("volume_2"));
        volume_2->setGeometry(QRect(380, 70, 67, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 925, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        volume->setText(QApplication::translate("MainWindow", "Volumen", 0));
        m_pButton1->setText(QApplication::translate("MainWindow", "1", 0));
        m_pButton2->setText(QApplication::translate("MainWindow", "2", 0));
        m_pButton3->setText(QApplication::translate("MainWindow", "3", 0));
        m_pButtonA->setText(QApplication::translate("MainWindow", "A", 0));
        m_pButton5->setText(QApplication::translate("MainWindow", "5", 0));
        m_pButtonB->setText(QApplication::translate("MainWindow", "B", 0));
        m_pButton4->setText(QApplication::translate("MainWindow", "4", 0));
        m_pButton6->setText(QApplication::translate("MainWindow", "6", 0));
        m_pButton8->setText(QApplication::translate("MainWindow", "8", 0));
        m_pButtonC->setText(QApplication::translate("MainWindow", "C", 0));
        m_pButton7->setText(QApplication::translate("MainWindow", "7", 0));
        m_pButton9->setText(QApplication::translate("MainWindow", "9", 0));
        m_pButton0->setText(QApplication::translate("MainWindow", "0", 0));
        m_pButtonD->setText(QApplication::translate("MainWindow", "D", 0));
        m_pButtonAst->setText(QApplication::translate("MainWindow", "*", 0));
        m_pButtonNum->setText(QApplication::translate("MainWindow", "#", 0));
        m_pButtonHang->setText(QApplication::translate("MainWindow", "Descolgar", 0));
        txtNumber->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        volume_2->setText(QApplication::translate("MainWindow", "Registro", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
