#include "ForestLogic.h"

#include <QGraphicsTextItem>

ForestLogic::ForestLogic()
{



}


Graph*  ForestLogic::createRandomScatter(GraphWidget* graphView)
 {

    Graph* lGraph= new Graph();

    double averageTreeSpan= 40.0;
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

int i=0;

Node* node;
Node* node_dest;
     for (int ix=0; ix < cols; ix++){
               for (int iy=0; iy < rows; iy++)
                  {
                i++;
                                        offsetX = 0;//(-p + ((double)(qrand()%100)/100.0) * (2*p))*(xd * 0.5);
                                        offsetY = 0;//(-p + ((double)(qrand()%100)/100.0) * (2*p))*(yd * 0.5);
                                        pos.setX(0 + xd * ix + offsetX * ix);
                                        pos.setY(0 + yd * iy + offsetY * iy);
                                        node= graphView->addNode(pos);
                                        node_dest= graphView->getClosestNodeTo(node);

                                        int n= (int)((qrand()%100)/100.0)*(i-1);
                                        int m= (int)((qrand()%100)/100.0)*(i-1);
                                        if (i > 1)
                                    {
                                        //    graphView->addEdge(n,m,0);
                                        }
                                }
                            }
    return lGraph;
}
