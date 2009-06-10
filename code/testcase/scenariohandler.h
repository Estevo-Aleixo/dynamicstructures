#ifndef SCENARIOHANDLER_H
#define SCENARIOHANDLER_H


#include "MainWindow.h"
#include <qtextedit.h>
//#include "GraphConcept.h"
//#include "GraphWidget.h"



class ScenarioHandler
{
public:
    ScenarioHandler(Graph& forestGraph, Graph& mapGraph, GraphWidget& forestWidget, GraphWidget& mapWidget);

    //LFP

    void runScenario();

    void setDebugTextBox(int text);

    //{mDebugText= text;}


  private:
    VertexList findLFPs(Graph& forestGraph, Graph& mapGraph);

    void generateMultiplePaths(Graph& forestGraph, VertexList& lfpVertices, Graph& mapGraph);


    Graph  mForestGraph,mMapGraph;
    GraphWidget mForestWidget, mMapWidget;

    VertexList lfpVertices;

    QTextEdit* mDebugText;


};

#endif // SCENARIOHANDLER_H
