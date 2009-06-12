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
int width;
int height;
int density;
int layers;
int con_density;
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

void createRandomScatter(Graph* g, forestParams& params);
void createConnections(Graph* g, int layers, double connectionDensity);


};

#endif // FORESTLOGIC_H
