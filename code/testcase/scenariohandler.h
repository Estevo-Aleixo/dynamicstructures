#ifndef SCENARIOHANDLER_H
#define SCENARIOHANDLER_H


//#include "MainWindow.h"

#include <qtextedit.h>
#include "GraphConcept.h"
#include "GraphWidget.h"


//creates graph structure for the mapgraph


class ScenarioHandler
{
public:
    ScenarioHandler(Graph* forestGraph, Graph* mapGraph, GraphWidget* forestWidget, GraphWidget* mapWidget);

    //LFP

    void runScenario();

    void setDebugTextBox(int text);
    //{mDebugText= text;}

  private:
    std::vector<vertex_descriptor>* findLFPs(Graph* forestGraph, Graph* mapGraph);

    void generateMultiplePaths(Graph* forestGraph, std::vector<vertex_descriptor>* lfpVertices, Graph* mapGraph);


    Graph*  mForestGraph;
    Graph*  mMapGraph;
    GraphWidget* mForestWidget;
    GraphWidget* mMapWidget;

    std::vector<vertex_descriptor>* lfpVertices;

    QTextEdit* mDebugText;


};

#endif // SCENARIOHANDLER_H
