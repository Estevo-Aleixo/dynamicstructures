#include "mainwindow.h"
#include "ui_mainwindow.h"


//QGraphicsScene *scene;
//ForestGraph* forest;
 GraphWidget* graphView;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{

   ui->setupUi(this);

   this->setWindowTitle("Forest Graph Generator");

   // graph widget:
   graphView= new GraphWidget(this);
   graphView->resize(650,650);
   resize(900,900);
   graphView->show();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnGenerate_clicked()
{
    //QGraphicsRectItem *rect = scene.addRect(QRectF(0, 0, 100, 100))
    ForestLogic* forest = new ForestLogic();
   forest->createRandomScatter(graphView);
    graphView->show();

}







