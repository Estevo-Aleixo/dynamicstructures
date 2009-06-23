#include "ForestLogic.h"

#include <QGraphicsTextItem>
#include "LogWindow.h"
ForestLogic::ForestLogic()
{



}

void  ForestLogic::createRandomScatter(GraphWidget* gWidget,forestParams& params)
 {
    mDebugText->log("createRandomScatter()",very_important_msg);
    double averageTreeSpan= (params.min_node_span + params.max_node_span)/2;
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

                                        gWidget->addNode(pos);


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


void ForestLogic::createGridScatter(GraphWidget* gWidget, forestParams& params)
{
    mDebugText->log("createGridScatter()",very_important_msg);
    createRandomScatter(gWidget,params);

}

void ForestLogic::createForestGraph(GraphWidget* graphView, forestParams& params)
{
    forestGraph= graphView->getGraph();
    initForestGraph(graphView,params);

switch(params.scatterMethod)
{
    case FORESTSCATTER:
        createRandomScatter(graphView,params);
        createConnections(graphView, params);
    break;
    case URBANSCATTER:
        createGridScatter(graphView,params);
        createConnections(graphView, params);
    break;
}

}

void ForestLogic::initForestGraph(GraphWidget* gWidget, forestParams& params)
{
     gWidget->setArea(params.area);
     gWidget->show();
}


void ForestLogic::createConnections(GraphWidget* gWidget, forestParams& params)
{
    mDebugText->log("createConnections()",very_important_msg);
    Graph* g= gWidget->getGraph();
    std::pair<vertex_iterator, vertex_iterator> iterator_range= vertices((*gWidget->getGraph()));
    vertex_iterator start=iterator_range.first;
    vertex_iterator end=iterator_range.second;
    vertex_iterator i;
    vertex_iterator dest;

    std::vector<vertex_descriptor> localNodes;

srand(time(NULL));

    //connect nodes in local vincinity
    for (i=start;i!=end;++i)
    {
        std::vector<vertex_descriptor>::iterator nodeItr;
        QtVertexItem* item= (*g)[*i].vertexItem;
        QPointF pos= QPointF(item->x(),item->y());

        nodesInArea(g,localNodes,pos, params.range_local_neighbours);
        int connections = 0;
        int maxConnections = params.min_connections_per_node + (rand() % (params.max_connections_per_node - params.min_connections_per_node));


        while(!localNodes.empty() && connections < maxConnections)
        {
          int num = rand()% (int)localNodes.size();
          nodeItr=localNodes.begin();
          nodeItr+=num;
          vertex_descriptor v=(*i);
          vertex_descriptor u=(*nodeItr);
          gWidget->addEdge(u,v,0);
          localNodes.erase(nodeItr);
          connections++;
        }




        localNodes.clear();
    }

}

void ForestLogic::nodesInArea(Graph* g, std::vector<vertex_descriptor>& nodes, QPointF& pos, int range)
{
    vertex_descriptor u;

    std::pair<vertex_iterator, vertex_iterator> iterator_range= vertices(*g);
    vertex_iterator start=iterator_range.first;
    vertex_iterator end=iterator_range.second;
    vertex_iterator i;

    QtVertexItem* item2;

    for (i=start;i!=end;++i)
    {
        item2=(*g)[*i].vertexItem;
        QPointF pos2= QPointF(item2->x(),item2->y());

        if (((pos.x() - pos2.x())*(pos.x() - pos2.x())+(pos.y() - pos2.y())*(pos.y() - pos2.y()))< range * range )
        {
            nodes.push_back(*i);
        }
    }

}

