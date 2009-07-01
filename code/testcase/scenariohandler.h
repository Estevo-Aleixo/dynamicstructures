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

    void findSpanningPoints();
    void executeLFPfinder();
    void executeMultiplePathFinder();
    void reset();

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

    //methods
    void findRandomVertices(int num_vertices, std::vector<vertex_descriptor>& vertices, GraphWidget* from, GraphWidget* to=0, VertexType type = normal_type);                    //used for LFP's and spanning points
    void findHighDegreeVertices(int num_vertices, std::vector<vertex_descriptor>& vertices, GraphWidget* from, GraphWidget* to=0, VertexType type = normal_type);               //used for LFP's and spanning points
    void findHighestDegreeVertices(int num_vertices, std::vector<vertex_descriptor>& vertices, GraphWidget* from, GraphWidget* to=0, VertexType type = normal_type);               //used for LFP's and spanning points


    //TODO
    void findImportantSteinerGraphVertices(int num_vertices, std::vector<vertex_descriptor>& vertices, GraphWidget* from, GraphWidget* to=0, VertexType type = normal_type);    //used for LFP's and spanning points

    void generateMultiplePaths(std::vector<vertex_descriptor>& vertices);

    void TraverseAndStorePath(Graph* g, vertex_descriptor i, vertex_descriptor j, std::vector<vertex_descriptor>& pred, std::vector<edge_descriptor>& edges);


    Scenario mScenario;

    Graph*  mFG;
    Graph*  mMG;
    GraphWidget* mForestWidget;
    GraphWidget* mMapWidget;

    std::vector<vertex_descriptor> spanVertices;
    std::vector<vertex_descriptor> lfpVertices;

    LogWindow* mDebugText;

    QSound* soundDone;

};

#endif // SCENARIOHANDLER_H
