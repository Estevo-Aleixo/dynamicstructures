/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Wed Jun 24 17:17:58 2009
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
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
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
    QTabWidget *tabWidget_2;
    QWidget *tab_9;
    QPushButton *btnGenerateMap;
    QCheckBox *chkDebug;
    QPushButton *btnExecuteLFPFinder;
    QPushButton *btnExecutePathFinder;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_9;
    QLineEdit *editLocalFightPoints;
    QLabel *label;
    QLabel *label_10;
    QLineEdit *editPathIterations;
    QLabel *label_3;
    QLabel *label_27;
    QLabel *label_11;
    QPushButton *btnExecutePathFinder_2;
    QLabel *label_28;
    QPushButton *btnExecutePathFinder_3;
    QLabel *label_29;
    QCheckBox *checkBox;
    QWidget *tab_3;
    QWidget *tab_5;
    QWidget *tab_4;
    QTabWidget *tabWidget_3;
    QWidget *tab_6;
    QLabel *label_8;
    QPushButton *btnGenerateForest;
    QComboBox *cmbScatterMethod;
    QLineEdit *editWidth;
    QLineEdit *editHeight;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_12;
    QLabel *label_17;
    QLineEdit *editMinNodeSpan;
    QLineEdit *editMaxNodeSpan;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *editMinConnections;
    QLineEdit *editMaxConnections;
    QLabel *label_23;
    QLabel *label_24;
    QLineEdit *editLocalNeighbourRange;
    QLabel *label_25;
    QLineEdit *editNodeDensity;
    QLabel *label_26;
    QWidget *textParentWidget;
    QLabel *label_2;
    QPushButton *pushButton;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1165, 933);
        MainWindow->setBaseSize(QSize(100, 60));
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8("release/icons/accept.png")), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
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
        label_6->setGeometry(QRect(10, 30, 161, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Palatino Linotype"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_6->setFont(font);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(610, 30, 261, 21));
        label_7->setFont(font);
        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setEnabled(true);
        tabWidget_2->setGeometry(QRect(610, 410, 541, 201));
        tabWidget_2->setTabPosition(QTabWidget::North);
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        btnGenerateMap = new QPushButton(tab_9);
        btnGenerateMap->setObjectName(QString::fromUtf8("btnGenerateMap"));
        btnGenerateMap->setEnabled(false);
        btnGenerateMap->setGeometry(QRect(370, 140, 161, 31));
        QFont font1;
        font1.setPointSize(14);
        btnGenerateMap->setFont(font1);
        chkDebug = new QCheckBox(tab_9);
        chkDebug->setObjectName(QString::fromUtf8("chkDebug"));
        chkDebug->setEnabled(false);
        chkDebug->setGeometry(QRect(250, 150, 121, 18));
        btnExecuteLFPFinder = new QPushButton(tab_9);
        btnExecuteLFPFinder->setObjectName(QString::fromUtf8("btnExecuteLFPFinder"));
        btnExecuteLFPFinder->setGeometry(QRect(50, 40, 121, 23));
        btnExecutePathFinder = new QPushButton(tab_9);
        btnExecutePathFinder->setObjectName(QString::fromUtf8("btnExecutePathFinder"));
        btnExecutePathFinder->setGeometry(QRect(50, 70, 121, 23));
        label_4 = new QLabel(tab_9);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 20, 91, 16));
        label_5 = new QLabel(tab_9);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 40, 46, 14));
        label_5->setFont(font1);
        label_9 = new QLabel(tab_9);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 70, 46, 14));
        label_9->setFont(font1);
        editLocalFightPoints = new QLineEdit(tab_9);
        editLocalFightPoints->setObjectName(QString::fromUtf8("editLocalFightPoints"));
        editLocalFightPoints->setGeometry(QRect(280, 40, 113, 20));
        label = new QLabel(tab_9);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 40, 111, 16));
        label_10 = new QLabel(tab_9);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setEnabled(true);
        label_10->setGeometry(QRect(180, 70, 121, 16));
        editPathIterations = new QLineEdit(tab_9);
        editPathIterations->setObjectName(QString::fromUtf8("editPathIterations"));
        editPathIterations->setEnabled(true);
        editPathIterations->setGeometry(QRect(280, 70, 113, 20));
        label_3 = new QLabel(tab_9);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(400, 70, 51, 16));
        label_27 = new QLabel(tab_9);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(400, 40, 51, 16));
        label_11 = new QLabel(tab_9);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setEnabled(false);
        label_11->setGeometry(QRect(20, 100, 46, 14));
        label_11->setFont(font1);
        btnExecutePathFinder_2 = new QPushButton(tab_9);
        btnExecutePathFinder_2->setObjectName(QString::fromUtf8("btnExecutePathFinder_2"));
        btnExecutePathFinder_2->setEnabled(false);
        btnExecutePathFinder_2->setGeometry(QRect(50, 100, 161, 23));
        label_28 = new QLabel(tab_9);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setEnabled(false);
        label_28->setGeometry(QRect(220, 100, 311, 16));
        btnExecutePathFinder_3 = new QPushButton(tab_9);
        btnExecutePathFinder_3->setObjectName(QString::fromUtf8("btnExecutePathFinder_3"));
        btnExecutePathFinder_3->setEnabled(false);
        btnExecutePathFinder_3->setGeometry(QRect(50, 130, 161, 23));
        label_29 = new QLabel(tab_9);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setEnabled(false);
        label_29->setGeometry(QRect(20, 130, 46, 14));
        label_29->setFont(font1);
        checkBox = new QCheckBox(tab_9);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setEnabled(false);
        checkBox->setGeometry(QRect(280, 10, 201, 18));
        tabWidget_2->addTab(tab_9, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget_2->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tabWidget_2->addTab(tab_5, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget_2->addTab(tab_4, QString());
        tabWidget_3 = new QTabWidget(centralWidget);
        tabWidget_3->setObjectName(QString::fromUtf8("tabWidget_3"));
        tabWidget_3->setGeometry(QRect(10, 390, 591, 221));
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        label_8 = new QLabel(tab_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 10, 131, 16));
        btnGenerateForest = new QPushButton(tab_6);
        btnGenerateForest->setObjectName(QString::fromUtf8("btnGenerateForest"));
        btnGenerateForest->setGeometry(QRect(490, 160, 81, 21));
        cmbScatterMethod = new QComboBox(tab_6);
        cmbScatterMethod->setObjectName(QString::fromUtf8("cmbScatterMethod"));
        cmbScatterMethod->setGeometry(QRect(10, 30, 151, 22));
        editWidth = new QLineEdit(tab_6);
        editWidth->setObjectName(QString::fromUtf8("editWidth"));
        editWidth->setGeometry(QRect(280, 70, 113, 20));
        editHeight = new QLineEdit(tab_6);
        editHeight->setObjectName(QString::fromUtf8("editHeight"));
        editHeight->setGeometry(QRect(280, 100, 113, 20));
        label_13 = new QLabel(tab_6);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(190, 70, 31, 16));
        label_14 = new QLabel(tab_6);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(190, 100, 46, 14));
        label_15 = new QLabel(tab_6);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(400, 70, 61, 16));
        label_16 = new QLabel(tab_6);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(400, 100, 61, 16));
        label_12 = new QLabel(tab_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(190, 40, 81, 16));
        label_17 = new QLabel(tab_6);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(190, 10, 81, 16));
        editMinNodeSpan = new QLineEdit(tab_6);
        editMinNodeSpan->setObjectName(QString::fromUtf8("editMinNodeSpan"));
        editMinNodeSpan->setGeometry(QRect(280, 10, 113, 20));
        editMaxNodeSpan = new QLineEdit(tab_6);
        editMaxNodeSpan->setObjectName(QString::fromUtf8("editMaxNodeSpan"));
        editMaxNodeSpan->setGeometry(QRect(280, 40, 113, 20));
        label_18 = new QLabel(tab_6);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(400, 10, 61, 16));
        label_19 = new QLabel(tab_6);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(400, 40, 61, 16));
        label_20 = new QLabel(tab_6);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(190, 130, 91, 16));
        label_21 = new QLabel(tab_6);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(400, 160, 61, 16));
        label_22 = new QLabel(tab_6);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(190, 160, 91, 16));
        editMinConnections = new QLineEdit(tab_6);
        editMinConnections->setObjectName(QString::fromUtf8("editMinConnections"));
        editMinConnections->setGeometry(QRect(280, 130, 113, 20));
        editMaxConnections = new QLineEdit(tab_6);
        editMaxConnections->setObjectName(QString::fromUtf8("editMaxConnections"));
        editMaxConnections->setGeometry(QRect(280, 160, 113, 20));
        label_23 = new QLabel(tab_6);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(400, 130, 61, 16));
        label_24 = new QLabel(tab_6);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 120, 131, 16));
        editLocalNeighbourRange = new QLineEdit(tab_6);
        editLocalNeighbourRange->setObjectName(QString::fromUtf8("editLocalNeighbourRange"));
        editLocalNeighbourRange->setGeometry(QRect(10, 140, 111, 20));
        label_25 = new QLabel(tab_6);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(10, 70, 151, 20));
        editNodeDensity = new QLineEdit(tab_6);
        editNodeDensity->setObjectName(QString::fromUtf8("editNodeDensity"));
        editNodeDensity->setGeometry(QRect(10, 90, 113, 20));
        label_26 = new QLabel(tab_6);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(130, 90, 46, 14));
        tabWidget_3->addTab(tab_6, QString());
        textParentWidget = new QWidget(centralWidget);
        textParentWidget->setObjectName(QString::fromUtf8("textParentWidget"));
        textParentWidget->setGeometry(QRect(10, 650, 1141, 241));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 630, 81, 16));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 620, 111, 23));
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(610, 390, 151, 18));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(centralWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setEnabled(false);
        radioButton_2->setGeometry(QRect(770, 390, 191, 18));
        radioButton_3 = new QRadioButton(centralWidget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setEnabled(false);
        radioButton_3->setGeometry(QRect(950, 390, 201, 18));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setBaseSize(QSize(1000, 68));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget_2->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(0);


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
        label_6->setText(QApplication::translate("MainWindow", "Problem Structure", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Solution: map structure", 0, QApplication::UnicodeUTF8));
        btnGenerateMap->setText(QApplication::translate("MainWindow", "Execute All Steps", 0, QApplication::UnicodeUTF8));
        chkDebug->setText(QApplication::translate("MainWindow", "visual debug mode", 0, QApplication::UnicodeUTF8));
        btnExecuteLFPFinder->setText(QApplication::translate("MainWindow", "Find Local fight points", 0, QApplication::UnicodeUTF8));
        btnExecutePathFinder->setText(QApplication::translate("MainWindow", "Find Multiple paths", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Step By Step:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "1.", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "2.", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Local Fight Points:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Path Find Iterations:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "(1-5)", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindow", "(2-10)", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "3.", 0, QApplication::UnicodeUTF8));
        btnExecutePathFinder_2->setText(QApplication::translate("MainWindow", "Generate Properties and Labels", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindow", "properties define appearance and function of nodes and edges", 0, QApplication::UnicodeUTF8));
        btnExecutePathFinder_3->setText(QApplication::translate("MainWindow", "Reposition  path nodes", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindow", "4.", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "Force Symmetry", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_9), QApplication::translate("MainWindow", "Execute", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "Map Structure Params", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "View preferences", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Analysis", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Node Scattering Method:", 0, QApplication::UnicodeUTF8));
        btnGenerateForest->setText(QApplication::translate("MainWindow", "Generate ", 0, QApplication::UnicodeUTF8));
        cmbScatterMethod->clear();
        cmbScatterMethod->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Simple Grid ", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Random Forest Scatter", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Variable Sized Squares Grid(not finished)", 0, QApplication::UnicodeUTF8)
        );
        label_13->setText(QApplication::translate("MainWindow", "Width", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "Height", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "(200- 1000)", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "(200- 1000)", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Max Node Span", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "Min Node Span", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "(10-100)", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "(10-100)", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "Min Connections", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "(3-8)", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "Max Connections", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "(0-4)", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "range neighbour nodes", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", "node density (type 3 scatter)", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "(10-100)", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_6), QApplication::translate("MainWindow", "Generate Forest", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Debug output:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Clear Debug output", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("MainWindow", "Multiplayer Arena Scenario", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("MainWindow", "Dungeon Adventure Scenario", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("MainWindow", "Stealth Strategy Scenario", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
