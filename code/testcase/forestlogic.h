#ifndef FORESTLOGIC_H
#define FORESTLOGIC_H


#include "mainwindow.h"
#include "BaseHeaders.h"

#include "Layer.h"

#include "graphwidget.h"

#include "QtEdgeItem.h"
#include "QtVertexItem.h"

class LogWindow;


enum ScatterType{FORESTSCATTER,URBANSCATTER};

struct forestParams
{
unsigned int density;
unsigned int layers;
unsigned int con_density;
unsigned int min_node_span;
unsigned int max_node_span;
unsigned int min_connections_per_node;
unsigned int max_connections_per_node;
unsigned int range_local_neighbours;
int scatterMethod;
QRect area;
};


//creates graph structure for the forestgraph


class ForestLogic
{
public:
    ForestLogic();

std::vector<Layer*> layers;
std::vector<QtVertexItem*> nodes;

void createForestGraph(GraphWidget* graphView, forestParams& params);
void initForestGraph(GraphWidget* gWidget, forestParams& params);

void createRandomScatter(GraphWidget* gWidget, forestParams& params);
void createGridScatter(GraphWidget* gWidget, forestParams& params);

void createConnections(GraphWidget* gWidget, forestParams& params);

Graph* getForestGraph(){return forestGraph;}
void nodesInArea(Graph* g, std::vector<vertex_descriptor>& nodes, QPointF& pos, int range);

void setDebugTextBox(LogWindow* log){mDebugText=log;}

private:

LogWindow* mDebugText;
Graph* forestGraph;


};

#endif // FORESTLOGIC_H
