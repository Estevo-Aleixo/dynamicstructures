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

     for (int ix=0; ix < cols; ix++){
               for (int iy=0; iy < rows; iy++)
                  {


                                        offsetX = (-p + ((double)(qrand()%100)/100.0) * (2*p))*(xd * 0.5);
                                        offsetY = (-p + ((double)(qrand()%100)/100.0) * (2*p))*(yd * 0.5);
                                        pos.setX(0 + xd * ix + offsetX * ix);
                                        pos.setY(0 + yd * iy + offsetY * iy);
                                        graphView->createNode(pos);
                                }
                            }
}
