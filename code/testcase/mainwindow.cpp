#include "mainwindow.h"
#include "ui_mainwindow.h"

//visual widgets
GraphWidget* graphForestView;
GraphWidget* graphMapView;

ForestLogic* forestGenerator;

Graph* forest, map;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{

   ui->setupUi(this);

   this->setWindowTitle("Map Structure Search");

    //forest graph widget:
   graphForestView= new GraphWidget(ui->parent_forest_widget);
   graphForestView->resize(200,200);
   graphForestView->show();

   //map graph widget
   graphMapView= new GraphWidget(ui->parent_map_widget);
   graphMapView->resize(200,200);
   graphMapView->show();

}

MainWindow::~MainWindow()
{
    delete ui;
	//test
}

void MainWindow::on_btnGenerateForest_clicked()
{

    forestGenerator = new ForestLogic();

    delete graphForestView;
    graphForestView= new GraphWidget(ui->parent_forest_widget);
    graphForestView->resize(200,200);

    forestGenerator->createRandomScatter(graphForestView);
    graphForestView->show();

}







