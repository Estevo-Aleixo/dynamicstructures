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




void ScenarioHandler::generateMultiplePaths(Graph& forestGraph, std::list<Vertex>& lfpVertices, Graph& mapGraph)
{

 bool notdone=true;

std::list<Vertex> pred(num_vertices(g));
std::list<Vertex> vertices(num_vertices(g));

std::list<double> d(num_vertices(g));

    while(notdone)
    {
        //one iteration:
        //for each LFP in LFPVertices
        std::list<Vertex>::iterator i,j,n;

        //iterate over all local fight points:
        for(i=lfpVertices.begin(); i!=lfpVertices.end();i++)
        {
            //perform dijkstra on the current local fight point
            dijkstra_shortest_paths(forestGraph,(*i), predecessor_map(&p[0]).distance_map(&d[0]));

            //traverse paths of all local fight points that have been reached
            for(j = lfpVertices.begin(); j != lfpVertices.end(); j++)
            {
                //std::vector<Edge> edgeList;

                //n holds current vertex in the path that is traversed
                //starting at the current local fight point
                n=j;

                if (n!=i)
                {    
                   while((*n)!=(*i) && n!=pred.end())
                   {   
                       //get current edge
                        //*n          //iterator of current node
                        //pred[*n]       //parent of current node


                        //get the iterator from the edge list

                       //get current vertex:

                        //get parent vertex:
                   }
                }
            }



        }

    }



}
