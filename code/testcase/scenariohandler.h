#ifndef SCENARIOHANDLER_H
#define SCENARIOHANDLER_H


#include "MainWindow.h"

#include <qtextedit.h>
#include "GraphConcept.h"
#include "GraphWidget.h"

#include "fpsscenario.h"

class LogWindow;

//creates graph structure for the mapgraph


class ScenarioHandler
{
public:
    ScenarioHandler(GraphWidget* forestWidget, GraphWidget* mapWidget);

    //LFP
    void setScenario(Scenario& scenario){mScenario = scenario;}
    Scenario& getScenario(){return mScenario;}

    void runScenario();
    void executeLFPfinder();
    void executeMultiplePathFinder();

    void setDebugTextBox(LogWindow* log){mDebugText=log;}

    Graph* getMapGraph(){return mMG;}


    void setMapWidget( GraphWidget* gWidget)
    {
        mMapWidget=gWidget;
        mMG= gWidget->getGraph();
    }

    void setForestWidget( GraphWidget* gWidget)
    {
        mForestWidget=gWidget;
        mFG=gWidget->getGraph();
    }

    GraphWidget* getForestWidget(){return mForestWidget;}
    GraphWidget* getMapWidget(){return mMapWidget;}

  private:
    std::vector<vertex_descriptor>* findLFPs();

    void generateMultiplePaths(std::vector<vertex_descriptor>* lfpVertices);

    void TraverseAndStorePath(Graph* g, vertex_descriptor i, vertex_descriptor j, std::vector<vertex_descriptor>& pred, std::vector<edge_descriptor>& edges);


    Scenario mScenario;

    Graph*  mFG;
    Graph*  mMG;
    GraphWidget* mForestWidget;
    GraphWidget* mMapWidget;

    std::vector<vertex_descriptor>* lfpVertices;

    LogWindow* mDebugText;

    QSound* soundDone;

};

#endif // SCENARIOHANDLER_H