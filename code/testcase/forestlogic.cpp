#include "ForestLogic.h"

#include <QGraphicsTextItem>

ForestLogic::ForestLogic()
{



}


 void  ForestLogic::createRandomScatter(GraphWidget* graphView)
 {
    double averageTreeSpan= 50.0;
    double mDensity=1;


//cols
int cols = (int) (400 / (averageTreeSpan / mDensity));
//rows
int rows = (int) (400 / (averageTreeSpan / mDensity));

double xd= averageTreeSpan / mDensity;
double yd= averageTreeSpan / mDensity;

QPointF pos;

double p= 1.0;
double offsetX;
double offsetY;

Node* node;
Node* node_dest;
     for (int ix=0; ix < cols; ix++){
               for (int iy=0; iy < rows; iy++)
                  {

                                        offsetX = (-p + ((double)(qrand()%100)/100.0) * (2*p))*(xd * 0.5);
                                        offsetY = (-p + ((double)(qrand()%100)/100.0) * (2*p))*(yd * 0.5);
                                        pos.setX(0 + xd * ix + offsetX * ix);
                                        pos.setY(0 + yd * iy + offsetY * iy);
                                        node= graphView->createNode(pos);
                                        node_dest= graphView->getClosestNodeTo(node);
                                        if (node_dest!=0)
                                            graphView->createEdge(node,node_dest);

                                }
                            }
}
