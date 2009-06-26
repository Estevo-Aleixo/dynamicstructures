#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QFileDialog>
#include <QSound>
#include <QToolBar>
#include <QMenuBar>
#include <QMenu>

#include "forestlogic.h"
#include "scenariohandler.h"
#include "graphwidget.h"

#include "LogDialog.h"


//include boost:

#include "BaseHeaders.h"
#include "graphconcept.h"



namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

    QMenuBar* mMenuBar;
    QMenu* mFileMenu;
    QMenu* mViewMenu;

    void initMenu();
    void initMainToolBar();
    void initGraphManipulationToolBar();

    void initActions();
    void setMapParams();

    void closeEvent(QCloseEvent* e);
private slots:
   void on_bntResultFileName_clicked();
    void on_pushButton_clicked();
    void on_btnExecutePathFinder_clicked();
    void on_btnForestFullScreen_clicked();
    void on_btnExecuteLFPFinder_clicked();
    void on_btnGenerateForest_clicked();

    void addNodes();
    void addEdges();
    void deleteTool();
    void selectTool();
    void clearProblemStructure();
    void openProblem();
    void saveProblem();
    void newProblem();

    void saveResult();
    void createProblemStructure();
    void showLogWindow();

};

#endif // MAINWINDOW_H