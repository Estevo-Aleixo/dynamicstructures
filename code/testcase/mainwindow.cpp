#include "mainwindow.h"
#include "ui_mainwindow.h"

//visual widgets
GraphWidget* graphForestView;
GraphWidget* graphMapView;

ForestLogic* forestGenerator;
ScenarioHandler* mapGenerator;
Graph* forest, map;

LogWindow* mDebugLog;

QAction* newAct;
QAction* saveAct;
QAction* openAct;

QAction* deleteItemAct;
QAction* selectItemAct;
QAction* nodeDrawModeAct;
QAction* edgeDrawModeAct;


QToolBar* mDrawTools;


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


initMainToolBar();
initGraphManipulationToolBar();

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
f.area= QRect(0,0,1000,1000);

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

void  MainWindow::initMainToolBar()
{


//new
    newAct = new QAction(QIcon("icons/new.png"), tr("&New..."), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Open an existing configuration"));
    //connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
     ui->mainToolBar->addAction(newAct);

//open
    openAct = new QAction(QIcon("icons/open.png"), tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing configuration"));
    //connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

     ui->mainToolBar->addAction(openAct);

//save
    saveAct = new QAction(QIcon("icons/save.png"), tr("&Save..."), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save configuration"));
    //connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

     ui->mainToolBar->addAction(saveAct);




}

void  MainWindow::initGraphManipulationToolBar()
{
    mDrawTools = addToolBar("Edit");

    //add vertex
    nodeDrawModeAct = new QAction(QIcon("icons/addnode.png"), tr("&New Node..."), this);
    nodeDrawModeAct->setStatusTip(tr("Place Nodes"));
    connect( nodeDrawModeAct, SIGNAL(triggered()), this, SLOT(addNodes()));

    mDrawTools->addAction(nodeDrawModeAct);

    //add edge
     edgeDrawModeAct = new QAction(QIcon("icons/addedge.png"), tr("&New Edge..."), this);
     edgeDrawModeAct->setStatusTip(tr("Place Nodes"));
    connect(edgeDrawModeAct, SIGNAL(triggered()), this, SLOT(addEdges()));
     mDrawTools->addAction(edgeDrawModeAct);

     //delete item
     deleteItemAct = new QAction(QIcon("icons/delete.png"), tr("&Delete Item..."), this);
     deleteItemAct->setStatusTip(tr("Delete Item"));
     connect(deleteItemAct, SIGNAL(triggered()), this, SLOT(deleteTool()));
     mDrawTools->addAction(deleteItemAct);


     //select item
     selectItemAct = new QAction(QIcon("icons/accept.png"), tr("&Select item..."), this);
     selectItemAct->setStatusTip(tr("Select"));
     connect(selectItemAct, SIGNAL(triggered()), this, SLOT(selectTool()));
     mDrawTools->addAction(selectItemAct);

}

void  MainWindow::addNodes()
{
 mDebugLog->log("node draw tool activated");

}
void  MainWindow::addEdges()
{

 mDebugLog->log("edge draw tool activated");


}
void  MainWindow::deleteTool()
{
 mDebugLog->log("delete tool activated");



}
void  MainWindow::selectTool()
{
 mDebugLog->log("select tool activated");

}



