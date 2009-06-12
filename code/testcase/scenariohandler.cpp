#include "scenariohandler.h"


ScenarioHandler::ScenarioHandler(Graph* forestGraph, Graph* mapGraph, GraphWidget* forestWidget, GraphWidget* mapWidget)
{

mForestGraph=forestGraph;
mMapGraph=mapGraph;
mForestWidget=forestWidget;
mMapWidget=mapWidget;



}

void ScenarioHandler::runScenario()
{

 //mDebugText << "running scenario...";

//step 1: findLFPs
lfpVertices= findLFPs(mForestGraph, mMapGraph);

//step 2:generateMultiplePaths
generateMultiplePaths( mForestGraph,lfpVertices, mMapGraph);

//step 3:
//...

}



std::vector<vertex_descriptor>* ScenarioHandler::findLFPs(Graph* forestGraph, Graph* mapGraph)
{
std::vector<vertex_descriptor>* LFPs;



return LFPs;
}




void ScenarioHandler::generateMultiplePaths(Graph* g, std::vector<vertex_descriptor>* lfpVertices, Graph* mapGraph)
{

    vertex_descriptor predecessor;
    vertex_descriptor current;


 bool notdone=true;

    while(notdone)
    {
        notdone=false;

        //for each LFP in LFPVertices
        std::vector<vertex_descriptor>::iterator i,j,n;

        //iterate over all local fight points:
        for(i=lfpVertices->begin(); i!=lfpVertices->end();i++)
        {
            //perform dijkstra on the current local fight point

           std::vector<vertex_descriptor> pred(num_vertices(*g));
           std::vector<vertex_descriptor> vertices(num_vertices(*g));
           std::vector<double> d(num_vertices(*g));

            dijkstra_shortest_paths(*g,(*i), predecessor_map(&pred[0]).distance_map(&d[0]));

            //traverse paths of all local fight points that have been reached
            for(j = lfpVertices->begin(); j != lfpVertices->end(); j++)
            {

                //n holds current vertex in the path that is traversed
                //starting at the current local fight point
                n=j;

                if (n!=i) //KIJK NIET NAAR ZELF
                {    
                   while((*n)!=(*i) && n!=pred.end()) //TRAVERSE TOTDAT WE BIJ DE SOURCE NODE ZIJN
                   {   

                        predecessor = pred[*n];
                        *n= pred[*n];

                   }
                }

            }



        }

    }



}
