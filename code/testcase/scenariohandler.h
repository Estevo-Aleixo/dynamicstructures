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
    ScenarioHandler(GraphWidget* forestWidget, GraphWidget* mapWidget);

    //LFP

    void runScenario();

    void executeLFPfinder();
    void executeMultiplePathFinder();

    void setDebugTextBox(int text);

    Graph* getMapGraph(){return mMG;}

  private:
    std::vector<vertex_descriptor>* findLFPs();

    void generateMultiplePaths(Graph* forestGraph, std::vector<vertex_descriptor>* lfpVertices, Graph* mapGraph);


    Graph*  mFG;
    Graph*  mMG;
    GraphWidget* mForestWidget;
    GraphWidget* mMapWidget;

    std::vector<vertex_descriptor>* lfpVertices;

    QTextEdit* mDebugText;


};

#endif // SCENARIOHANDLER_H
