#include "mainwindow.h"
#include "ui_mainwindow.h"

//visual widgets
GraphWidget* graphForestView;
GraphWidget* graphMapView;

ForestLogic* forestGenerator;
ScenarioHandler* mapGenerator;
Graph* forest, map;

LogWindow* mDebugLog;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{

   ui->setupUi(this);
   this->setWindowTitle("Map Structure Search");
   mDebugLog= new LogWindow();

   QString label="Debug";
   ui->tabOutput->insertTab(0,mDebugLog,label);
    ui->tabOutput->setCurrentIndex(0);
   mDebugLog->setReadOnly(true);
   mDebugLog->show();

    //forest graph widget:
   graphForestView= new GraphWidget(ui->parent_forest_widget);

   graphForestView->resize(ui->parent_forest_widget->width(),ui->parent_forest_widget->height());
   graphForestView->show();

   //map graph widget
   graphMapView= new GraphWidget(ui->parent_map_widget);
   graphMapView->resize(ui->parent_map_widget->width(),ui->parent_map_widget->height());
   graphMapView->show();

    Graph* forestStructure;
    Graph* mapStructure;

    forestGenerator = new ForestLogic();

forestParams f;
f.con_density=1;
f.density=1;
f.layers=4;
f.area= QRect(0,0,400,400);

    forestStructure = forestGenerator->createForestGraph(graphForestView, f);

    mapGenerator= new ScenarioHandler(graphForestView,graphMapView);
    mapGenerator->setDebugTextBox(mDebugLog);

}

MainWindow::~MainWindow()
{
    delete ui;
	//test
}

void MainWindow::on_btnGenerateForest_clicked()
{


    delete graphForestView;

    graphForestView= new GraphWidget(ui->parent_forest_widget);
    graphForestView->resize(200,200);

   // forestGenerator->createRandomScatter(graphForestView);
    graphForestView->show();

}

void MainWindow::on_btnExecuteLFPFinder_clicked()
{

    mapGenerator->executeLFPfinder();


}

void MainWindow::on_btnForestFullScreen_clicked()
{
    graphForestView->showFullScreen();
}

void MainWindow::on_btnExecutePathFinder_clicked()
{
    mapGenerator->executeMultiplePathFinder();
}
