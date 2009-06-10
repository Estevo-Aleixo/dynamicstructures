#include "scenariohandler.h"

ScenarioHandler::ScenarioHandler(Graph& forestGraph, Graph& mapGraph, GraphWidget& forestWidget, GraphWidget& mapWidget):
mForestGraph(forestGraph),mMapGraph(mapGraph), mForestWidget(forestWidget), mMapWidget(mapWidget)
{






}

void ScenarioHandler::runScenario()
{

 mDebugText << "running scenario...";

//step 1: findLFPs
lfpVertices= findLFPs(mForestGraph, mMapGraph);

//step 2:generateMultiplePaths
generateMultiplePaths( mForestGraph,lfpVertices, mMapGraph);

//step 3:
//...

}



VertexList ScenarioHandler::findLFPs(Graph& forestGraph, Graph& mapGraph)
{
VertexList LFPs;



return LFPs;
}




void ScenarioHandler::generateMultiplePaths(Graph& forestGraph, VertexList& lfpVertices, Graph& mapGraph)
{
bool notdone=true;

    while(notdone)
    {
        //one iteration:
        //for each LFP in LFPVertices
        VertexList::iterator i;
        for(i=lfpVertices.begin(); i!=lfpVertices.end();i++)
        {
             //for this vertex execute dijkstra shortest paths in the forestGraph graph:
            PredecessorMap predMap;

            dijkstra_shortest_paths(forestGraph,(*i), predMap);

            //retrieve presedence tree.

            //backtrack through precence tree for all LFP nodes != current_node


        }

    }



}
