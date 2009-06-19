#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>


#include "forestlogic.h"
#include "scenariohandler.h"
#include "graphwidget.h"
#include "logwindow.h"

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

private slots:
    void on_btnExecutePathFinder_clicked();
    void on_btnForestFullScreen_clicked();
    void on_btnExecuteLFPFinder_clicked();
    void on_btnGenerateForest_clicked();
};

#endif // MAINWINDOW_H
