/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Tue Jun 16 14:50:52 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionExit;
    QAction *actionClear;
    QWidget *centralWidget;
    QWidget *parent_forest_widget;
    QWidget *parent_map_widget;
    QLabel *label_6;
    QLabel *label_7;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextEdit *textEdit;
    QWidget *tab_2;
    QTextEdit *textEdit_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QLabel *label_2;
    QLabel *label;
    QComboBox *cmbCPTreshold;
    QComboBox *cmbNumFightPoints;
    QLabel *label_3;
    QComboBox *cmbLFPMethod;
    QWidget *tab_8;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QWidget *tab_5;
    QWidget *tab_9;
    QPushButton *btnGenerateMap;
    QCheckBox *chkDebug;
    QPushButton *btnExecuteLFPFinder;
    QPushButton *pushButton_6;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_9;
    QPushButton *btnExecuteLFPFinder_2;
    QLabel *label_11;
    QWidget *tab_4;
    QTabWidget *tabWidget_3;
    QWidget *tab_6;
    QLabel *label_8;
    QPushButton *btnGenerateForest;
    QLabel *label_10;
    QComboBox *cmbConnectivity;
    QComboBox *cmbScatteringType;
    QPushButton *btnGenerateForest_2;
    QWidget *tab_7;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *btnForestFullScreen;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1165, 725);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        parent_forest_widget = new QWidget(centralWidget);
        parent_forest_widget->setObjectName(QString::fromUtf8("parent_forest_widget"));
        parent_forest_widget->setGeometry(QRect(10, 60, 581, 321));
        parent_map_widget = new QWidget(centralWidget);
        parent_map_widget->setObjectName(QString::fromUtf8("parent_map_widget"));
        parent_map_widget->setGeometry(QRect(610, 60, 541, 321));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 30, 161, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Palatino Linotype"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_6->setFont(font);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(610, 30, 161, 21));
        label_7->setFont(font);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(8, 547, 721, 141));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 721, 111));
        tabWidget->addTab(tab, QString());
        textEdit->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        textEdit_2 = new QTextEdit(tab_2);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(0, 0, 721, 191));
        tabWidget->addTab(tab_2, QString());
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(120, 0, 111, 31));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(0, 0, 111, 31));
        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(610, 390, 541, 141));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 60, 111, 16));
        label = new QLabel(tab_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 10, 111, 16));
        cmbCPTreshold = new QComboBox(tab_3);
        cmbCPTreshold->setObjectName(QString::fromUtf8("cmbCPTreshold"));
        cmbCPTreshold->setGeometry(QRect(250, 30, 151, 22));
        cmbNumFightPoints = new QComboBox(tab_3);
        cmbNumFightPoints->setObjectName(QString::fromUtf8("cmbNumFightPoints"));
        cmbNumFightPoints->setGeometry(QRect(40, 30, 151, 22));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(250, 10, 121, 16));
        cmbLFPMethod = new QComboBox(tab_3);
        cmbLFPMethod->setObjectName(QString::fromUtf8("cmbLFPMethod"));
        cmbLFPMethod->setGeometry(QRect(40, 80, 151, 22));
        tabWidget_2->addTab(tab_3, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        radioButton = new QRadioButton(tab_8);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(10, 10, 221, 18));
        radioButton_2 = new QRadioButton(tab_8);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 40, 221, 18));
        radioButton_3 = new QRadioButton(tab_8);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, 70, 251, 18));
        tabWidget_2->addTab(tab_8, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tabWidget_2->addTab(tab_5, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        btnGenerateMap = new QPushButton(tab_9);
        btnGenerateMap->setObjectName(QString::fromUtf8("btnGenerateMap"));
        btnGenerateMap->setGeometry(QRect(370, 80, 161, 31));
        QFont font1;
        font1.setPointSize(14);
        btnGenerateMap->setFont(font1);
        chkDebug = new QCheckBox(tab_9);
        chkDebug->setObjectName(QString::fromUtf8("chkDebug"));
        chkDebug->setGeometry(QRect(370, 60, 121, 18));
        btnExecuteLFPFinder = new QPushButton(tab_9);
        btnExecuteLFPFinder->setObjectName(QString::fromUtf8("btnExecuteLFPFinder"));
        btnExecuteLFPFinder->setGeometry(QRect(50, 20, 121, 23));
        pushButton_6 = new QPushButton(tab_9);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(50, 50, 121, 23));
        label_4 = new QLabel(tab_9);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 0, 91, 16));
        label_5 = new QLabel(tab_9);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 20, 46, 14));
        label_5->setFont(font1);
        label_9 = new QLabel(tab_9);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 50, 46, 14));
        label_9->setFont(font1);
        btnExecuteLFPFinder_2 = new QPushButton(tab_9);
        btnExecuteLFPFinder_2->setObjectName(QString::fromUtf8("btnExecuteLFPFinder_2"));
        btnExecuteLFPFinder_2->setGeometry(QRect(200, 20, 121, 23));
        label_11 = new QLabel(tab_9);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(180, 20, 21, 16));
        tabWidget_2->addTab(tab_9, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget_2->addTab(tab_4, QString());
        tabWidget_3 = new QTabWidget(centralWidget);
        tabWidget_3->setObjectName(QString::fromUtf8("tabWidget_3"));
        tabWidget_3->setGeometry(QRect(10, 390, 581, 141));
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        label_8 = new QLabel(tab_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 20, 131, 16));
        btnGenerateForest = new QPushButton(tab_6);
        btnGenerateForest->setObjectName(QString::fromUtf8("btnGenerateForest"));
        btnGenerateForest->setGeometry(QRect(480, 90, 81, 21));
        label_10 = new QLabel(tab_6);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(210, 20, 131, 16));
        cmbConnectivity = new QComboBox(tab_6);
        cmbConnectivity->setObjectName(QString::fromUtf8("cmbConnectivity"));
        cmbConnectivity->setGeometry(QRect(210, 40, 151, 20));
        cmbScatteringType = new QComboBox(tab_6);
        cmbScatteringType->setObjectName(QString::fromUtf8("cmbScatteringType"));
        cmbScatteringType->setGeometry(QRect(30, 40, 151, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Minion Pro Cond"));
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(9);
        cmbScatteringType->setFont(font2);
        btnGenerateForest_2 = new QPushButton(tab_6);
        btnGenerateForest_2->setObjectName(QString::fromUtf8("btnGenerateForest_2"));
        btnGenerateForest_2->setGeometry(QRect(390, 90, 81, 21));
        tabWidget_3->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        pushButton = new QPushButton(tab_7);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 30, 71, 41));
        pushButton_3 = new QPushButton(tab_7);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(100, 30, 71, 41));
        btnForestFullScreen = new QPushButton(tab_7);
        btnForestFullScreen->setObjectName(QString::fromUtf8("btnForestFullScreen"));
        btnForestFullScreen->setGeometry(QRect(390, 80, 171, 23));
        tabWidget_3->addTab(tab_7, QString());
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(3);
        tabWidget_3->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionClear->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Forest Graph", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Map Graph", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Debug info", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Errors", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "LFP search method:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Local Fight Points:", 0, QApplication::UnicodeUTF8));
        cmbCPTreshold->clear();
        cmbCPTreshold->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "> num(nodes)", 0, QApplication::UnicodeUTF8)
        );
        cmbNumFightPoints->clear();
        cmbNumFightPoints->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "3 ", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("MainWindow", "Collision Point Treshold:", 0, QApplication::UnicodeUTF8));
        cmbLFPMethod->clear();
        cmbLFPMethod->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Random", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Find Clusters", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Find Symmetry", 0, QApplication::UnicodeUTF8)
        );
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "Map Structure Params", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("MainWindow", "First Person Shooter Multiplayer Arena", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("MainWindow", "Stealth adventure", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("MainWindow", "Dungeon adventure", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QApplication::translate("MainWindow", "Scenario", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
        btnGenerateMap->setText(QApplication::translate("MainWindow", "Execute All Steps", 0, QApplication::UnicodeUTF8));
        chkDebug->setText(QApplication::translate("MainWindow", "visual debug mode", 0, QApplication::UnicodeUTF8));
        btnExecuteLFPFinder->setText(QApplication::translate("MainWindow", "Find Local fight points", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("MainWindow", "Find Multiple paths", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Step By Step:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "1.", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "2.", 0, QApplication::UnicodeUTF8));
        btnExecuteLFPFinder_2->setText(QApplication::translate("MainWindow", "select LFPS by hand", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "or", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_9), QApplication::translate("MainWindow", "Execute", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Analysis", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Node Scattering Method:", 0, QApplication::UnicodeUTF8));
        btnGenerateForest->setText(QApplication::translate("MainWindow", "Generate ", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Edge Connectivity", 0, QApplication::UnicodeUTF8));
        cmbConnectivity->clear();
        cmbConnectivity->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "dense", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "medium", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "sparse ", 0, QApplication::UnicodeUTF8)
        );
        cmbConnectivity->setStyleSheet(QApplication::translate("MainWindow", "font: 75 8pt \"Minion Pro Cond\";", 0, QApplication::UnicodeUTF8));
        cmbScatteringType->clear();
        cmbScatteringType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Grid Random Scattering", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Clustered Random Scattering", 0, QApplication::UnicodeUTF8)
        );
        cmbScatteringType->setStyleSheet(QApplication::translate("MainWindow", "font: 75 8pt \"Minion Pro Cond\";", 0, QApplication::UnicodeUTF8));
        btnGenerateForest_2->setText(QApplication::translate("MainWindow", "Restore", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_6), QApplication::translate("MainWindow", "Generate Forest", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "add nodes", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "add edges", 0, QApplication::UnicodeUTF8));
        btnForestFullScreen->setText(QApplication::translate("MainWindow", "Show Forest Graph in Fullscreen", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_7), QApplication::translate("MainWindow", "Tools", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
