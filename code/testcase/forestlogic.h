#ifndef FORESTLOGIC_H
#define FORESTLOGIC_H


#include "mainwindow.h"
#include "BaseHeaders.h"

#include "Layer.h"

#include "graphwidget.h"

#include "QtEdgeItem.h"
#include "QtVertexItem.h"

class ForestLogic
{
public:
    ForestLogic();

std::vector<Layer*> layers;
std::vector<QtVertexItem*> nodes;

//Graph_qt* createRandomScatter(GraphWidget* graphView);

Graph* createForestGraph(int layers, double connectionDensity);
Graph* createRandomScatter();
void createConnections(Graph*, double density);

};

#endif // FORESTLOGIC_H
