#include "ForestLogic.h"

#include <QGraphicsTextItem>

ForestLogic::ForestLogic()
{



}

void  ForestLogic::createRandomScatter(GraphWidget* gWidget,forestParams& params)
 {

    double averageTreeSpan= 100.0;
    double mDensity=params.density;

//cols
int cols = (int) (params.area.width()/ (averageTreeSpan / mDensity));
//rows
int rows = (int) (params.area.height() / (averageTreeSpan / mDensity));

double xd= averageTreeSpan / mDensity;
double yd= averageTreeSpan / mDensity;

QPointF pos;

double p= 1.0;
double offsetX;
double offsetY;

int i=0;


QtVertexItem* node;
QtVertexItem* node_dest;

QString name="Node";

     for (int ix=0; ix < cols; ix++){
               for (int iy=0; iy < rows; iy++)
                  {
                i++;
                                        offsetX = 0;//(-p + ((double)(qrand()%100)/100.0) * (2*p))*(xd * 0.5);
                                        offsetY = 0;//(-p + ((double)(qrand()%100)/100.0) * (2*p))*(yd * 0.5);
                                        pos.setX(0 + xd * ix + offsetX * ix);
                                        pos.setY(0 + yd * iy + offsetY * iy);

                                        gWidget->addNode(pos,name);


                                        // int n= (int)((qrand()%100)/100.0)*(i-1);
                                       // int m= (int)((qrand()%100)/100.0)*(i-1);
                                       // if (i > 1)
                                       // {
                                       //
                                       // }
                                }
                            }

      gWidget->show();
}


Graph*  ForestLogic::createForestGraph(GraphWidget* graphView, forestParams& params)
{

    Graph* g;
    g= new Graph();
    forestGraph= g;


    initForestGraph(g, graphView,params);
    createRandomScatter(graphView,params);
    createConnections(graphView, params);

    return g;
}

void ForestLogic::initForestGraph(Graph* g, GraphWidget* graphView, forestParams& params)
{
     graphView->setGraphStructure(g);
     graphView->setArea(params.area);

    graphView->show();
}


void ForestLogic::createConnections(GraphWidget* gWidget, forestParams& params)
{
    Graph* g= gWidget->getGraph();
    std::pair<vertex_iterator, vertex_iterator> iterator_range= vertices((*gWidget->getGraph()));
    vertex_iterator start=iterator_range.first;
    vertex_iterator end=iterator_range.second;
    vertex_iterator i;
    vertex_iterator dest;

    //iterate over vertexlist

    for (i=start;i!=end;++i)
    {
      dest = returnRandomNeighbour(*i,g,300);

     // if (dest!=end)
      vertex_descriptor v= *i;
      vertex_descriptor u= *dest;

            gWidget->addEdge(v,u,0);
    }


}

vertex_iterator ForestLogic::returnRandomNeighbour(vertex_descriptor v, Graph* g, int range)
{
    vertex_descriptor u;

    std::pair<vertex_iterator, vertex_iterator> iterator_range= vertices(*g);
    vertex_iterator start=iterator_range.first;
    vertex_iterator end=iterator_range.second;
    vertex_iterator i;

    vd_list neighbours;
QtVertexItem* item=(*g)[v].vertexItem;
QtVertexItem* item2;

    QPointF pos= QPointF(item->x(),item->y());

    for (i=start;i!=end;++i)
    {
        item2=(*g)[*i].vertexItem;
        QPointF pos2= QPointF(item2->x(),item2->y());

        if (((pos.x() - pos2.x())*(pos.x() - pos2.x())+(pos.y() - pos2.y())*(pos.y() - pos2.y()))< range * range )
        {
            return i;
        }

    }

    return end;
}

/*
vertex_descriptor ForestLogic::returnRandomNeighbour(vertex_descriptor v, GraphWidget* gWidget, int range)
{


}

*/
