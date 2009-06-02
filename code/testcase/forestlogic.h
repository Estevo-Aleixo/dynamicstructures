#ifndef FORESTLOGIC_H
#define FORESTLOGIC_H


#include "mainwindow.h"
#include "BaseHeaders.h"
#include "graphwidget.h"
#include "Node.h"
#include "Layer.h"

class ForestLogic
{
public:
    ForestLogic();

std::vector<Layer*> layers;
std::vector<Node*> nodes;

void createRandomScatter(GraphWidget* graphView);

};

#endif // FORESTLOGIC_H
