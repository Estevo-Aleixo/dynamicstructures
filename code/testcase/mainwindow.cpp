#include "mainwindow.h"
#include "ui_mainwindow.h"

//visual widgets
GraphWidget* graphForestView;
GraphWidget* graphMapView;

ForestLogic* forestGenerator;
ScenarioHandler* mapGenerator;
//Graph* forest, map;

LogWindow* mDebugLog;


//file actions
QAction* newAct;
QAction* saveAct;
QAction* saveResultAct;
QAction* openAct;

//edit tools
QAction* deleteItemAct;
QAction* selectItemAct;
QAction* nodeDrawModeAct;
QAction* edgeDrawModeAct;

//procedure actions
QAction* createProblemStructureAct;




QToolBar* mDrawTools;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{

   ui->setupUi(this);
   this->setWindowTitle("Map Structure Search");
   mDebugLog= new LogWindow(ui->textParentWidget);
   mDebugLog->resize(ui->textParentWidget->width(), ui->textParentWidget->height());

   //QString label="Debug";
   //ui->tabOutput->insertTab(0,mDebugLog,label);
    //ui->tabOutput->setCurrentIndex(0);

   mDebugLog->setReadOnly(true);
   mDebugLog->show();

initActions();
//initMainToolBar();
//initGraphManipulationToolBar();
initMenu();

    //forest graph widget:
   graphForestView= new GraphWidget(ui->parent_forest_widget);

   graphForestView->resize(ui->parent_forest_widget->width(),ui->parent_forest_widget->height());
   graphForestView->show();

   //pre-settings for forest:
    QString param;
   this->ui->editWidth->setText(param.setNum(500));
   this->ui->editHeight->setText(param.setNum(500));
   this->ui->editMaxNodeSpan->setText(param.setNum(100));
   this->ui->editMinNodeSpan->setText(param.setNum(50));
   this->ui->editMinConnections->setText(param.setNum(0));
   this->ui->editMaxConnections->setText(param.setNum(5));
   this->ui->editLocalNeighbourRange->setText(param.setNum(200));
   this->ui->editNodeDensity->setText(param.setNum(70));

   //pre-settings for map:
   this->ui->editLocalFightPoints->setText(param.setNum(4));
   this->ui->editPathIterations->setText(param.setNum(3));


   //map graph widget
   graphMapView= new GraphWidget(ui->parent_map_widget);
   graphMapView->resize(ui->parent_map_widget->width(),ui->parent_map_widget->height());
   graphMapView->show();


    forestGenerator = new ForestLogic();
   // forestGenerator

    mapGenerator= new ScenarioHandler(graphForestView,graphMapView);

    forestGenerator->setDebugTextBox(mDebugLog);
    mapGenerator->setDebugTextBox(mDebugLog);

}

MainWindow::~MainWindow()
{
    delete ui;
	//test
}

void MainWindow::on_btnGenerateForest_clicked()
{
    createProblemStructure();
}

void MainWindow::on_btnExecuteLFPFinder_clicked()
{
    setMapParams();
    mapGenerator->executeLFPfinder();


}

void MainWindow::on_btnForestFullScreen_clicked()
{
    graphForestView->showFullScreen();
}

void MainWindow::on_btnExecutePathFinder_clicked()
{
    setMapParams();
    mapGenerator->executeMultiplePathFinder();


}

void  MainWindow::initMainToolBar()
{


//new
     ui->mainToolBar->addAction(newAct);
//open
     ui->mainToolBar->addAction(openAct);
//save problem
     ui->mainToolBar->addAction(saveAct);
//save result
     ui->mainToolBar->addAction(saveResultAct);
}

void  MainWindow::initGraphManipulationToolBar()
{
    mDrawTools = addToolBar("Edit");
    //add vertex
    mDrawTools->addAction(nodeDrawModeAct);
    //add edge
     mDrawTools->addAction(edgeDrawModeAct);
     //delete item
     mDrawTools->addAction(deleteItemAct);
     //select item
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

void MainWindow::openProblem()
{
    QString fileName;
     fileName = QFileDialog::getOpenFileName(this,
     tr("Open Problem File"), "/Saved", tr("Game Structure Problem (*.gsp)"));

}

void MainWindow::saveProblem()
{
     QString fileName;
     fileName = QFileDialog::getSaveFileName(this,
     tr("Save Problem File"), "Saved", tr("Space Structure Problem (*.ssp)"));
     mapGenerator->getForestWidget()->saveToFile(fileName);

}


void MainWindow::saveResult()
{
     QString fileName;
     fileName = QFileDialog::getSaveFileName(this,
     tr("Save Result File"), "Saved", tr("Space Structure Result(*.ssr)"));
     mapGenerator->getForestWidget()->saveToFile(fileName);

}


void MainWindow::newProblem()
{
    //QString fileName;
    // fileName = QFileDialog::getOpenFileName(this,
    // tr("Open Image"), "/home/jana", tr("Image Files (*.png *.jpg *.bmp)"));
}

void MainWindow::createProblemStructure()
{

    //clear the canvas
    delete graphForestView;
    graphForestView = new GraphWidget(ui->parent_forest_widget);
    graphForestView->resize(ui->parent_forest_widget->width(),ui->parent_forest_widget->height());

    delete graphMapView;
    graphMapView= new GraphWidget(ui->parent_map_widget);
    graphMapView->resize(ui->parent_map_widget->width(),ui->parent_map_widget->height());

    mapGenerator->setForestWidget(graphForestView);
    mapGenerator->setMapWidget(graphMapView);

unsigned int width = this->ui->editWidth->text().toUInt();
unsigned int height =this->ui->editHeight->text().toUInt();

    forestParams f;
    f.density=1;
    f.layers=4;
    f.min_node_span=this->ui->editMinNodeSpan->text().toUInt();
    f.max_node_span=this->ui->editMaxNodeSpan->text().toUInt();
    f.scatterMethod=this->ui->cmbScatterMethod->currentIndex();
    f.min_connections_per_node= this->ui->editMinConnections->text().toUInt();
    f.max_connections_per_node= this->ui->editMaxConnections->text().toUInt();
    f.range_local_neighbours=this->ui->editLocalNeighbourRange->text().toUInt();
    f.node_density= this->ui->editNodeDensity->text().toUInt();
    f.area= QRect(0,0,width,height);

    forestGenerator->createForestGraph(graphForestView, f);
}

void MainWindow::initActions()
{

//new
    newAct = new QAction(QIcon("icons/new.png"), tr("&New..."), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Open an existing configuration"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newProblem()));

//open
    openAct = new QAction(QIcon("icons/open.png"), tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing configuration"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(openProblem()));

//save problem
    saveAct = new QAction(QIcon("icons/save.png"), tr("&Save..."), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save Problem"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(saveProblem()));


//save result
    saveResultAct = new QAction(QIcon("icons/save.png"), tr("&Save Result..."), this);
    saveResultAct->setShortcuts(QKeySequence::Save);
    saveResultAct->setStatusTip(tr("Save Result"));
    connect(saveResultAct, SIGNAL(triggered()), this, SLOT(saveResult()));

    //add vertex
    nodeDrawModeAct = new QAction(QIcon("icons/addnode.png"), tr("&New Node..."), this);
    nodeDrawModeAct->setStatusTip(tr("Place Nodes"));
    connect( nodeDrawModeAct, SIGNAL(triggered()), this, SLOT(addNodes()));



    //add edge
     edgeDrawModeAct = new QAction(QIcon("icons/addedge.png"), tr("&New Edge..."), this);
     edgeDrawModeAct->setStatusTip(tr("Place Nodes"));
    connect(edgeDrawModeAct, SIGNAL(triggered()), this, SLOT(addEdges()));

     //delete item
     deleteItemAct = new QAction(QIcon("icons/delete.png"), tr("&Delete Item..."), this);
     deleteItemAct->setStatusTip(tr("Delete Item"));
     connect(deleteItemAct, SIGNAL(triggered()), this, SLOT(deleteTool()));

     //select item
     selectItemAct = new QAction(QIcon("icons/accept.png"), tr("&Select item..."), this);
     selectItemAct->setStatusTip(tr("Select"));
     connect(selectItemAct, SIGNAL(triggered()), this, SLOT(selectTool()));




}

void MainWindow::setMapParams()
{
    Scenario scenario;
    scenario.local_fight_points = this->ui->editLocalFightPoints->text().toUInt();
    scenario.multiple_path_iterations= this->ui->editPathIterations->text().toUInt();
    mapGenerator->setScenario(scenario);

}

void MainWindow::initMenu()
{
 mMenuBar= new QMenuBar(this);
 mFileMenu= mMenuBar->addMenu(tr("&File"));
 mFileMenu->addAction(saveAct);
 mFileMenu->addAction(saveResultAct);

}

void MainWindow::on_pushButton_clicked()
{
    mDebugLog->clear();
}
