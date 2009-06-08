/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Mon Jun 8 15:39:56 2009
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
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
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
    QGroupBox *groupBox;
    QPushButton *btnGenerateForest;
    QComboBox *cmbScatteringType;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *cmbLayers;
    QLabel *label_10;
    QComboBox *cmbConnectivity;
    QWidget *parent_forest_widget;
    QWidget *parent_map_widget;
    QLabel *label_6;
    QLabel *label_7;
    QGroupBox *groupBox_2;
    QCheckBox *chkDebug;
    QPushButton *btnGenerateMap;
    QComboBox *cmbNumFightPoints;
    QLabel *label;
    QComboBox *cmbLFPMethod;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *cmbCPTreshold;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(881, 591);
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
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(40, 390, 381, 161));
        btnGenerateForest = new QPushButton(groupBox);
        btnGenerateForest->setObjectName(QString::fromUtf8("btnGenerateForest"));
        btnGenerateForest->setGeometry(QRect(260, 130, 101, 23));
        cmbScatteringType = new QComboBox(groupBox);
        cmbScatteringType->setObjectName(QString::fromUtf8("cmbScatteringType"));
        cmbScatteringType->setGeometry(QRect(10, 50, 151, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Minion Pro Cond"));
        font.setPointSize(8);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        cmbScatteringType->setFont(font);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 30, 131, 16));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 80, 131, 16));
        cmbLayers = new QComboBox(groupBox);
        cmbLayers->setObjectName(QString::fromUtf8("cmbLayers"));
        cmbLayers->setGeometry(QRect(10, 100, 151, 20));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(190, 30, 131, 16));
        cmbConnectivity = new QComboBox(groupBox);
        cmbConnectivity->setObjectName(QString::fromUtf8("cmbConnectivity"));
        cmbConnectivity->setGeometry(QRect(190, 50, 151, 20));
        parent_forest_widget = new QWidget(centralWidget);
        parent_forest_widget->setObjectName(QString::fromUtf8("parent_forest_widget"));
        parent_forest_widget->setGeometry(QRect(40, 60, 381, 321));
        parent_map_widget = new QWidget(centralWidget);
        parent_map_widget->setObjectName(QString::fromUtf8("parent_map_widget"));
        parent_map_widget->setGeometry(QRect(470, 60, 401, 321));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 30, 161, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Palatino Linotype"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_6->setFont(font1);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(470, 30, 161, 21));
        label_7->setFont(font1);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(470, 390, 401, 161));
        chkDebug = new QCheckBox(groupBox_2);
        chkDebug->setObjectName(QString::fromUtf8("chkDebug"));
        chkDebug->setGeometry(QRect(280, 110, 91, 18));
        btnGenerateMap = new QPushButton(groupBox_2);
        btnGenerateMap->setObjectName(QString::fromUtf8("btnGenerateMap"));
        btnGenerateMap->setGeometry(QRect(280, 130, 101, 23));
        cmbNumFightPoints = new QComboBox(groupBox_2);
        cmbNumFightPoints->setObjectName(QString::fromUtf8("cmbNumFightPoints"));
        cmbNumFightPoints->setGeometry(QRect(10, 50, 151, 22));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 111, 16));
        cmbLFPMethod = new QComboBox(groupBox_2);
        cmbLFPMethod->setObjectName(QString::fromUtf8("cmbLFPMethod"));
        cmbLFPMethod->setGeometry(QRect(10, 110, 151, 22));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 90, 111, 16));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(220, 30, 121, 16));
        cmbCPTreshold = new QComboBox(groupBox_2);
        cmbCPTreshold->setObjectName(QString::fromUtf8("cmbCPTreshold"));
        cmbCPTreshold->setGeometry(QRect(220, 50, 151, 22));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

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
        groupBox->setTitle(QApplication::translate("MainWindow", "Parameters Forest Structure", 0, QApplication::UnicodeUTF8));
        btnGenerateForest->setText(QApplication::translate("MainWindow", "Generate Forest", 0, QApplication::UnicodeUTF8));
        cmbScatteringType->clear();
        cmbScatteringType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Grid Random Scattering", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Clustered Random Scattering", 0, QApplication::UnicodeUTF8)
        );
        cmbScatteringType->setStyleSheet(QApplication::translate("MainWindow", "font: 75 8pt \"Minion Pro Cond\";", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Node Scattering Method:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Layers:", 0, QApplication::UnicodeUTF8));
        cmbLayers->clear();
        cmbLayers->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1 layer", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2 layers", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3 layers", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4 layers", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5 layers", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "6 layers", 0, QApplication::UnicodeUTF8)
        );
        cmbLayers->setStyleSheet(QApplication::translate("MainWindow", "font: 75 8pt \"Minion Pro Cond\";", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Edge Connectivity", 0, QApplication::UnicodeUTF8));
        cmbConnectivity->clear();
        cmbConnectivity->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "dense", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "medium", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "sparse ", 0, QApplication::UnicodeUTF8)
        );
        cmbConnectivity->setStyleSheet(QApplication::translate("MainWindow", "font: 75 8pt \"Minion Pro Cond\";", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Forest Graph", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Map Graph", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Map generation", 0, QApplication::UnicodeUTF8));
        chkDebug->setText(QApplication::translate("MainWindow", "Debug Mode", 0, QApplication::UnicodeUTF8));
        btnGenerateMap->setText(QApplication::translate("MainWindow", "Generate Map", 0, QApplication::UnicodeUTF8));
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
        label->setText(QApplication::translate("MainWindow", "Local Fight Points:", 0, QApplication::UnicodeUTF8));
        cmbLFPMethod->clear();
        cmbLFPMethod->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Random", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Find Clusters", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Find Symmetry", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("MainWindow", "LFP search method:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Collision Point Treshold:", 0, QApplication::UnicodeUTF8));
        cmbCPTreshold->clear();
        cmbCPTreshold->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "> num(nodes)", 0, QApplication::UnicodeUTF8)
        );
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
