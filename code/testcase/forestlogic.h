#ifndef FORESTLOGIC_H
#define FORESTLOGIC_H


#include "mainwindow.h"
#include "BaseHeaders.h"

#include "Layer.h"

#include "graphwidget.h"

#include "QtEdgeItem.h"
#include "QtVertexItem.h"

struct forestParams
{
int density;
int layers;
int con_density;
QRect area;
};


//creates graph structure for the forestgraph


class ForestLogic
{
public:
    ForestLogic();

std::vector<Layer*> layers;
std::vector<QtVertexItem*> nodes;

Graph* createForestGraph(GraphWidget* graphView, forestParams& params);
void initForestGraph(Graph* g, GraphWidget* graphView, forestParams& params);

void createRandomScatter(GraphWidget* gWidget, forestParams& params);
void createConnections(GraphWidget* gWidget, forestParams& params);

Graph* getForestGraph(){return forestGraph;}
vertex_iterator returnRandomNeighbour(vertex_descriptor v, Graph* g, int range);
private:

Graph* forestGraph;


};

#endif // FORESTLOGIC_H
