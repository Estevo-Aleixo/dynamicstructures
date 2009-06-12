#include "ForestLogic.h"

#include <QGraphicsTextItem>

ForestLogic::ForestLogic()
{



}

void  ForestLogic::createRandomScatter(Graph* g,forestParams& params)
 {


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

QtVertexItem* node;
QtVertexItem* node_dest;
     for (int ix=0; ix < cols; ix++){
               for (int iy=0; iy < rows; iy++)
                  {
                i++;
                                        offsetX = 0;//(-p + ((double)(qrand()%100)/100.0) * (2*p))*(xd * 0.5);
                                        offsetY = 0;//(-p + ((double)(qrand()%100)/100.0) * (2*p))*(yd * 0.5);
                                        pos.setX(0 + xd * ix + offsetX * ix);
                                        pos.setY(0 + yd * iy + offsetY * iy);
                                        //node= graphView->addNode(pos);
                                        //node_dest= graphView->getClosestNodeTo(node);

                                        int n= (int)((qrand()%100)/100.0)*(i-1);
                                        int m= (int)((qrand()%100)/100.0)*(i-1);
                                        if (i > 1)
                                    {
                                        //    graphView->addEdge(n,m,0);
                                        }
                                }
                            }
}


Graph*  ForestLogic::createForestGraph(GraphWidget* graphView, forestParams& params)
{

    Graph* newGraph;

    initForestGraph(newGraph, graphView,params);
    createRandomScatter(newGraph,params);
    createConnections(newGraph, params.layers, params.con_density);

    return newGraph;
}

void ForestLogic::initForestGraph(Graph* g, GraphWidget* graphView, forestParams& params)
{

   /*
  const int num_nodes = 5;
  enum nodes { A, B, C, D, E };
  char name[] = "ABCDE";
typedef std::pair<int, int> Edge;

  Edge edge_array[] = { Edge(A, C), Edge(B, B), Edge(B, D), Edge(B, E),
    Edge(C, B), Edge(C, D), Edge(D, E), Edge(E, A), Edge(E, B)
  };
  int weights[] = { 1, 2, 1, 2, 7, 3, 1, 1, 1 };
  int num_arcs = sizeof(edge_array) / sizeof(Edge);

  Graph mygraph(edge_array, edge_array + num_arcs, weights, num_nodes);
  property_map<Graph, edge_weight_t>::type weightmap = get(edge_weight, *g);
*/
 // g= new Graph(edge_array, edge_array + num_arcs, weights, num_nodes);

}


void ForestLogic::createConnections(Graph* g, int layers, double connectionDensity)
{









}



