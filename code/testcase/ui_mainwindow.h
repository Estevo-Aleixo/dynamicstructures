/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Wed Jul 1 17:33:27 2009
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
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
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
    QLabel *label_6;
    QLabel *label_7;
    QTabWidget *tabWidget_2;
    QWidget *tab_9;
    QPushButton *btnExecuteSpanningStep;
    QPushButton *btnExecutePathFinder;
    QLabel *label_5;
    QLabel *label_9;
    QLineEdit *editSpanningPoints;
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
    QPushButton *btnLocateFightPoints;
    QLabel *label_30;
    QLabel *label_32;
    QComboBox *cmbSpanMethod;
    QLabel *label_33;
    QLineEdit *editLocalFightPoints;
    QLabel *label_37;
    QComboBox *cmbLFPMethod;
    QLabel *label_38;
    QPushButton *btnResetCanvas;
    QWidget *tab_7;
    QCheckBox *chkDebug;
    QPushButton *btnGenerateMap;
    QLineEdit *editSpanningPoints_2;
    QLabel *label_39;
    QLineEdit *editLocalFightPoints_2;
    QLabel *label_40;
    QLabel *label_41;
    QLabel *label_42;
    QLabel *label_43;
    QLineEdit *editPathIterations_2;
    QComboBox *cmbSpanMethod_2;
    QComboBox *cmbLFPMethod_2;
    QLabel *label_44;
    QLabel *label_45;
    QLabel *label_46;
    QLabel *label_47;
    QLineEdit *lineEdit_3;
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QLabel *label_48;
    QWidget *tab_3;
    QLabel *label_2;
    QComboBox *comboBox;
    QWidget *tab_5;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QWidget *tab_4;
    QCheckBox *chkMinimumSpanningTreeSolution;
    QWidget *tab;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QCheckBox *checkBox_5;
    QLabel *label_31;
    QLineEdit *lineFilenameSave;
    QPushButton *bntResultFileName;
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
    QPushButton *btnLoadPreset;
    QWidget *tab_2;
    QCheckBox *chkMinimumSpanningTreeProblem;
    QWidget *loadproblem;
    QLabel *label_34;
    QLineEdit *lineEdit_2;
    QPushButton *btnSelectProblemStructure;
    QPushButton *pushButton_4;
    QTableWidget *tableWidget;
    QLabel *label_35;
    QLabel *label_36;
    QTableWidget *tableWidget_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QWidget *problemWidget;
    QWidget *parent_forest_widget;
    QWidget *solutionWidget;
    QWidget *parent_map_widget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1357, 759);
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
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 40, 161, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Palatino Linotype"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_6->setFont(font);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(680, 40, 261, 21));
        label_7->setFont(font);
        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setEnabled(true);
        tabWidget_2->setGeometry(QRect(670, 520, 661, 201));
        tabWidget_2->setTabPosition(QTabWidget::North);
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        btnExecuteSpanningStep = new QPushButton(tab_9);
        btnExecuteSpanningStep->setObjectName(QString::fromUtf8("btnExecuteSpanningStep"));
        btnExecuteSpanningStep->setGeometry(QRect(50, 10, 121, 23));
        btnExecutePathFinder = new QPushButton(tab_9);
        btnExecutePathFinder->setObjectName(QString::fromUtf8("btnExecutePathFinder"));
        btnExecutePathFinder->setGeometry(QRect(50, 43, 121, 20));
        label_5 = new QLabel(tab_9);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 40, 46, 14));
        QFont font1;
        font1.setPointSize(14);
        label_5->setFont(font1);
        label_9 = new QLabel(tab_9);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 70, 46, 14));
        label_9->setFont(font1);
        editSpanningPoints = new QLineEdit(tab_9);
        editSpanningPoints->setObjectName(QString::fromUtf8("editSpanningPoints"));
        editSpanningPoints->setGeometry(QRect(280, 10, 81, 20));
        label = new QLabel(tab_9);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 10, 111, 16));
        label_10 = new QLabel(tab_9);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setEnabled(true);
        label_10->setGeometry(QRect(180, 40, 101, 16));
        editPathIterations = new QLineEdit(tab_9);
        editPathIterations->setObjectName(QString::fromUtf8("editPathIterations"));
        editPathIterations->setEnabled(true);
        editPathIterations->setGeometry(QRect(280, 40, 81, 20));
        label_3 = new QLabel(tab_9);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(370, 40, 51, 16));
        label_27 = new QLabel(tab_9);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(370, 10, 51, 16));
        label_11 = new QLabel(tab_9);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setEnabled(false);
        label_11->setGeometry(QRect(20, 100, 20, 20));
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
        checkBox->setGeometry(QRect(240, 120, 111, 18));
        btnLocateFightPoints = new QPushButton(tab_9);
        btnLocateFightPoints->setObjectName(QString::fromUtf8("btnLocateFightPoints"));
        btnLocateFightPoints->setGeometry(QRect(50, 70, 121, 23));
        label_30 = new QLabel(tab_9);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(20, 10, 46, 14));
        label_30->setFont(font1);
        label_32 = new QLabel(tab_9);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(420, 10, 46, 20));
        cmbSpanMethod = new QComboBox(tab_9);
        cmbSpanMethod->setObjectName(QString::fromUtf8("cmbSpanMethod"));
        cmbSpanMethod->setGeometry(QRect(470, 10, 171, 22));
        label_33 = new QLabel(tab_9);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(180, 70, 101, 16));
        editLocalFightPoints = new QLineEdit(tab_9);
        editLocalFightPoints->setObjectName(QString::fromUtf8("editLocalFightPoints"));
        editLocalFightPoints->setEnabled(true);
        editLocalFightPoints->setGeometry(QRect(280, 70, 81, 20));
        label_37 = new QLabel(tab_9);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(370, 70, 51, 16));
        cmbLFPMethod = new QComboBox(tab_9);
        cmbLFPMethod->setObjectName(QString::fromUtf8("cmbLFPMethod"));
        cmbLFPMethod->setGeometry(QRect(470, 70, 171, 22));
        label_38 = new QLabel(tab_9);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(420, 70, 46, 20));
        btnResetCanvas = new QPushButton(tab_9);
        btnResetCanvas->setObjectName(QString::fromUtf8("btnResetCanvas"));
        btnResetCanvas->setGeometry(QRect(520, 140, 101, 23));
        tabWidget_2->addTab(tab_9, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        chkDebug = new QCheckBox(tab_7);
        chkDebug->setObjectName(QString::fromUtf8("chkDebug"));
        chkDebug->setEnabled(false);
        chkDebug->setGeometry(QRect(360, 150, 121, 18));
        btnGenerateMap = new QPushButton(tab_7);
        btnGenerateMap->setObjectName(QString::fromUtf8("btnGenerateMap"));
        btnGenerateMap->setEnabled(false);
        btnGenerateMap->setGeometry(QRect(10, 130, 161, 31));
        btnGenerateMap->setFont(font1);
        editSpanningPoints_2 = new QLineEdit(tab_7);
        editSpanningPoints_2->setObjectName(QString::fromUtf8("editSpanningPoints_2"));
        editSpanningPoints_2->setEnabled(false);
        editSpanningPoints_2->setGeometry(QRect(110, 10, 81, 20));
        label_39 = new QLabel(tab_7);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setEnabled(false);
        label_39->setGeometry(QRect(250, 70, 46, 20));
        editLocalFightPoints_2 = new QLineEdit(tab_7);
        editLocalFightPoints_2->setObjectName(QString::fromUtf8("editLocalFightPoints_2"));
        editLocalFightPoints_2->setEnabled(false);
        editLocalFightPoints_2->setGeometry(QRect(110, 70, 81, 20));
        label_40 = new QLabel(tab_7);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setEnabled(false);
        label_40->setGeometry(QRect(200, 40, 51, 16));
        label_41 = new QLabel(tab_7);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setEnabled(false);
        label_41->setGeometry(QRect(10, 10, 111, 16));
        label_42 = new QLabel(tab_7);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setEnabled(false);
        label_42->setGeometry(QRect(10, 70, 101, 16));
        label_43 = new QLabel(tab_7);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setEnabled(false);
        label_43->setGeometry(QRect(10, 40, 101, 16));
        editPathIterations_2 = new QLineEdit(tab_7);
        editPathIterations_2->setObjectName(QString::fromUtf8("editPathIterations_2"));
        editPathIterations_2->setEnabled(false);
        editPathIterations_2->setGeometry(QRect(110, 40, 81, 20));
        cmbSpanMethod_2 = new QComboBox(tab_7);
        cmbSpanMethod_2->setObjectName(QString::fromUtf8("cmbSpanMethod_2"));
        cmbSpanMethod_2->setEnabled(false);
        cmbSpanMethod_2->setGeometry(QRect(300, 10, 151, 22));
        cmbLFPMethod_2 = new QComboBox(tab_7);
        cmbLFPMethod_2->setObjectName(QString::fromUtf8("cmbLFPMethod_2"));
        cmbLFPMethod_2->setEnabled(false);
        cmbLFPMethod_2->setGeometry(QRect(300, 70, 151, 22));
        label_44 = new QLabel(tab_7);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setEnabled(false);
        label_44->setGeometry(QRect(200, 70, 51, 16));
        label_45 = new QLabel(tab_7);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setEnabled(false);
        label_45->setGeometry(QRect(250, 10, 46, 20));
        label_46 = new QLabel(tab_7);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setEnabled(false);
        label_46->setGeometry(QRect(200, 10, 51, 16));
        label_47 = new QLabel(tab_7);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setEnabled(false);
        label_47->setGeometry(QRect(10, 100, 121, 20));
        lineEdit_3 = new QLineEdit(tab_7);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        lineEdit_3->setGeometry(QRect(120, 100, 81, 20));
        listWidget = new QListWidget(tab_7);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(696, 192, 20, 20));
        listWidget_2 = new QListWidget(tab_7);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(480, 40, 161, 131));
        label_48 = new QLabel(tab_7);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(480, 20, 121, 16));
        tabWidget_2->addTab(tab_7, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 46, 14));
        comboBox = new QComboBox(tab_3);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(50, 10, 131, 22));
        tabWidget_2->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        checkBox_2 = new QCheckBox(tab_5);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 10, 231, 18));
        checkBox_3 = new QCheckBox(tab_5);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(10, 30, 171, 18));
        checkBox_4 = new QCheckBox(tab_5);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(10, 50, 231, 18));
        tabWidget_2->addTab(tab_5, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        chkMinimumSpanningTreeSolution = new QCheckBox(tab_4);
        chkMinimumSpanningTreeSolution->setObjectName(QString::fromUtf8("chkMinimumSpanningTreeSolution"));
        chkMinimumSpanningTreeSolution->setGeometry(QRect(20, 20, 181, 21));
        tabWidget_2->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(380, 140, 141, 23));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 110, 381, 20));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 110, 131, 16));
        checkBox_5 = new QCheckBox(tab);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(140, 90, 111, 18));
        label_31 = new QLabel(tab);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(20, 60, 46, 14));
        lineFilenameSave = new QLineEdit(tab);
        lineFilenameSave->setObjectName(QString::fromUtf8("lineFilenameSave"));
        lineFilenameSave->setGeometry(QRect(140, 60, 221, 20));
        bntResultFileName = new QPushButton(tab);
        bntResultFileName->setObjectName(QString::fromUtf8("bntResultFileName"));
        bntResultFileName->setGeometry(QRect(370, 60, 81, 23));
        tabWidget_2->addTab(tab, QString());
        tabWidget_3 = new QTabWidget(centralWidget);
        tabWidget_3->setObjectName(QString::fromUtf8("tabWidget_3"));
        tabWidget_3->setGeometry(QRect(10, 500, 641, 221));
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        label_8 = new QLabel(tab_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 10, 131, 16));
        btnGenerateForest = new QPushButton(tab_6);
        btnGenerateForest->setObjectName(QString::fromUtf8("btnGenerateForest"));
        btnGenerateForest->setGeometry(QRect(470, 160, 81, 21));
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
        btnLoadPreset = new QPushButton(tab_6);
        btnLoadPreset->setObjectName(QString::fromUtf8("btnLoadPreset"));
        btnLoadPreset->setGeometry(QRect(470, 130, 81, 21));
        tabWidget_3->addTab(tab_6, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        chkMinimumSpanningTreeProblem = new QCheckBox(tab_2);
        chkMinimumSpanningTreeProblem->setObjectName(QString::fromUtf8("chkMinimumSpanningTreeProblem"));
        chkMinimumSpanningTreeProblem->setGeometry(QRect(10, 10, 181, 21));
        tabWidget_3->addTab(tab_2, QString());
        loadproblem = new QWidget();
        loadproblem->setObjectName(QString::fromUtf8("loadproblem"));
        label_34 = new QLabel(loadproblem);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(10, 20, 61, 16));
        lineEdit_2 = new QLineEdit(loadproblem);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(70, 20, 211, 20));
        btnSelectProblemStructure = new QPushButton(loadproblem);
        btnSelectProblemStructure->setObjectName(QString::fromUtf8("btnSelectProblemStructure"));
        btnSelectProblemStructure->setGeometry(QRect(290, 20, 75, 23));
        pushButton_4 = new QPushButton(loadproblem);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(470, 160, 75, 23));
        tableWidget = new QTableWidget(loadproblem);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(false);
        tableWidget->setGeometry(QRect(280, 80, 271, 61));
        tableWidget->setFrameShape(QFrame::NoFrame);
        label_35 = new QLabel(loadproblem);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setEnabled(false);
        label_35->setGeometry(QRect(280, 60, 61, 16));
        label_36 = new QLabel(loadproblem);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setEnabled(false);
        label_36->setGeometry(QRect(10, 60, 61, 16));
        tableWidget_2 = new QTableWidget(loadproblem);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setEnabled(false);
        tableWidget_2->setGeometry(QRect(70, 60, 201, 131));
        tabWidget_3->addTab(loadproblem, QString());
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(670, 500, 151, 18));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(centralWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setEnabled(false);
        radioButton_2->setGeometry(QRect(830, 500, 191, 18));
        radioButton_3 = new QRadioButton(centralWidget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setEnabled(false);
        radioButton_3->setGeometry(QRect(1010, 500, 201, 18));
        problemWidget = new QWidget(centralWidget);
        problemWidget->setObjectName(QString::fromUtf8("problemWidget"));
        problemWidget->setGeometry(QRect(10, 60, 641, 431));
        parent_forest_widget = new QWidget(problemWidget);
        parent_forest_widget->setObjectName(QString::fromUtf8("parent_forest_widget"));
        parent_forest_widget->setGeometry(QRect(0, 60, 641, 371));
        solutionWidget = new QWidget(centralWidget);
        solutionWidget->setObjectName(QString::fromUtf8("solutionWidget"));
        solutionWidget->setGeometry(QRect(670, 60, 671, 431));
        parent_map_widget = new QWidget(solutionWidget);
        parent_map_widget->setObjectName(QString::fromUtf8("parent_map_widget"));
        parent_map_widget->setGeometry(QRect(0, 60, 671, 371));
        MainWindow->setCentralWidget(centralWidget);
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
        btnExecuteSpanningStep->setText(QApplication::translate("MainWindow", "Find Structure Pillars", 0, QApplication::UnicodeUTF8));
        btnExecutePathFinder->setText(QApplication::translate("MainWindow", "Find Multiple paths", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "2.", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "3.", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Pillar Points:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Path Find Iterations:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "(1-5)", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindow", "(2-10)", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "4.", 0, QApplication::UnicodeUTF8));
        btnExecutePathFinder_2->setText(QApplication::translate("MainWindow", "Generate Properties and Labels", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindow", "properties define appearance and function of nodes and edges", 0, QApplication::UnicodeUTF8));
        btnExecutePathFinder_3->setText(QApplication::translate("MainWindow", "Reposition  path nodes", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindow", "5.", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "Force Symmetry", 0, QApplication::UnicodeUTF8));
        btnLocateFightPoints->setText(QApplication::translate("MainWindow", "Find Local Fight Points", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MainWindow", "1.", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("MainWindow", "Method:", 0, QApplication::UnicodeUTF8));
        cmbSpanMethod->clear();
        cmbSpanMethod->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Random Vertices", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Random High Degree Treshold", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Highest Degree Vertices", 0, QApplication::UnicodeUTF8)
        );
        label_33->setText(QApplication::translate("MainWindow", "Local Fight Points:", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("MainWindow", "(2-10)", 0, QApplication::UnicodeUTF8));
        cmbLFPMethod->clear();
        cmbLFPMethod->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Random Vertices", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Random High Degree Treshold", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Highest Degree Vertices", 0, QApplication::UnicodeUTF8)
        );
        label_38->setText(QApplication::translate("MainWindow", "Method:", 0, QApplication::UnicodeUTF8));
        btnResetCanvas->setText(QApplication::translate("MainWindow", "Reset Canvas", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_9), QApplication::translate("MainWindow", "Execute Step by Step", 0, QApplication::UnicodeUTF8));
        chkDebug->setText(QApplication::translate("MainWindow", "visual debug mode", 0, QApplication::UnicodeUTF8));
        btnGenerateMap->setText(QApplication::translate("MainWindow", "Execute All Steps", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("MainWindow", "Method:", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("MainWindow", "(1-5)", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("MainWindow", "Pillar Points:", 0, QApplication::UnicodeUTF8));
        label_42->setText(QApplication::translate("MainWindow", "Local Fight Points:", 0, QApplication::UnicodeUTF8));
        label_43->setText(QApplication::translate("MainWindow", "Path Find Iterations:", 0, QApplication::UnicodeUTF8));
        cmbSpanMethod_2->clear();
        cmbSpanMethod_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Random Vertices", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Random High Degree Treshold", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Highest Degree Vertices", 0, QApplication::UnicodeUTF8)
        );
        cmbLFPMethod_2->clear();
        cmbLFPMethod_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Random Vertices", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Random High Degree Treshold", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Highest Degree Vertices", 0, QApplication::UnicodeUTF8)
        );
        label_44->setText(QApplication::translate("MainWindow", "(2-10)", 0, QApplication::UnicodeUTF8));
        label_45->setText(QApplication::translate("MainWindow", "Method:", 0, QApplication::UnicodeUTF8));
        label_46->setText(QApplication::translate("MainWindow", "(2-10)", 0, QApplication::UnicodeUTF8));
        label_47->setText(QApplication::translate("MainWindow", "Candidate Structures:", 0, QApplication::UnicodeUTF8));
        label_48->setText(QApplication::translate("MainWindow", "Candidates:", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("MainWindow", "Multiple Candidates", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Style: ", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Forest ", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Urban outdoor", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Urban indoor", 0, QApplication::UnicodeUTF8)
        );
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("MainWindow", "View Corresponding Properties", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("MainWindow", "View Debug Text", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("MainWindow", "View Stylized impression", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "View preferences", 0, QApplication::UnicodeUTF8));
        chkMinimumSpanningTreeSolution->setText(QApplication::translate("MainWindow", "Show Minimum Spanning Tree", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Analyze", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Load (and save)", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Extra command options:", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("MainWindow", "Cinematic View", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("MainWindow", "Save to: ", 0, QApplication::UnicodeUTF8));
        bntResultFileName->setText(QApplication::translate("MainWindow", "Select File..", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QApplication::translate("MainWindow", "to 3D geometry", 0, QApplication::UnicodeUTF8));
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
        btnLoadPreset->setText(QApplication::translate("MainWindow", "Load preset", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_6), QApplication::translate("MainWindow", "Generate Forest", 0, QApplication::UnicodeUTF8));
        chkMinimumSpanningTreeProblem->setText(QApplication::translate("MainWindow", "Show Minimum Spanning Tree", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_2), QApplication::translate("MainWindow", "Analyze", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("MainWindow", "File:", 0, QApplication::UnicodeUTF8));
        btnSelectProblemStructure->setText(QApplication::translate("MainWindow", "select file", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "Generate", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("MainWindow", "Description:", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("MainWindow", "Properties:", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(loadproblem), QApplication::translate("MainWindow", "Load Problem Structure", 0, QApplication::UnicodeUTF8));
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
