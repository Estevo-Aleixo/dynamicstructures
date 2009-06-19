#include "scenariohandler.h"
#include "LogWindow.h"


ScenarioHandler::ScenarioHandler(GraphWidget* forestWidget, GraphWidget* mapWidget)
{

mForestWidget=forestWidget;
mFG=forestWidget->getGraph();


//maak nieuwe Graph aan voor de mapwidget;
mMG= new Graph();
mapWidget->setGraphStructure(mMG);
mMapWidget=mapWidget;
mDebugText=0;


}

void ScenarioHandler::runScenario()
{
 //mDebugText << "running scenario...";

//step 1: findLFPs
lfpVertices= findLFPs();

//step 2:generateMultiplePaths
generateMultiplePaths( mFG,lfpVertices, mMG);

//step 3:
//...

}

void ScenarioHandler::executeLFPfinder()
{
    //step 1: findLFPs
    if (mDebugText!=0)
        mDebugText->log("initiating LFP finder");


    lfpVertices= findLFPs();
}

void ScenarioHandler::executeMultiplePathFinder()
{
      if (mDebugText!=0)
        mDebugText->log("initiating path finder");

    //step 2:generateMultiplePaths
    generateMultiplePaths( mFG,lfpVertices, mMG);

}


std::vector<vertex_descriptor>* ScenarioHandler::findLFPs()
{

std::vector<vertex_descriptor>* LFPs= new std::vector<vertex_descriptor>();

  int LFPcount=3;
  int count=0;

  QList<QGraphicsItem*> vertexList= mForestWidget->scene->items();
  QtVertexItem* vItem;
   while((count < LFPcount)==true)
  {
    int i= rand() % vertexList.size();
    if (vItem= qgraphicsitem_cast<QtVertexItem*>(vertexList[i]))
    {
       // vItem->setState(important); //SET LFP FLAG
        vItem->setType(LFP_type);
        LFPs->push_back(vItem->getVertexDescriptor());
        vItem->copyTo(mMapWidget);
        mDebugText->log(QString("added to LFP list:") + vItem->strLabel);
        count++;
    }
  }
 //mForestWidget->shear(0.5,0.4);
 mForestWidget->show();
 //mForestWidget->cursor();


   mForestWidget->repaint();

   /*
 std::pair<vertex_iterator, vertex_iterator> iterator_range= vertices((*mFG));
    vertex_iterator start=iterator_range.first;
    vertex_iterator end=iterator_range.second;
    vertex_iterator i;
    vertex_iterator dest;

    //iterate over vertexlist

    start+= (int)(rand()%100)/20;
//start+=1;
    if (start!=end)
    {
        QtVertexItem* vItem= (*mFG)[*start].vertexItem;
        vItem->setState(important);

    }
*/



return LFPs;
}




void ScenarioHandler::generateMultiplePaths(Graph* g, std::vector<vertex_descriptor>* lfpVertices, Graph* mapGraph)
{

    vertex_descriptor predecessor;
    vertex_descriptor current;

 bool notdone=true;

    //while(notdone)
    //{
      //  notdone=false;

        //for each LFP in LFPVertices
        std::vector<vertex_descriptor>::iterator i,j,n;

        //iterate over all local fight points:
        for(i=lfpVertices->begin(); i!=lfpVertices->end();i++)
        {
            //perform dijkstra on the current local fight point

           std::vector<vertex_descriptor> pred(num_vertices(*g));
           std::vector<vertex_descriptor> vertices(num_vertices(*g));
           std::vector<double> d(num_vertices(*g));

           //dijkstra_shortest_paths(*g,(*i), predecessor_map(&pred[0]).weight_map(get(&Connection::distance,*g)).distance_map(&d[0]));

            //traverse paths of all local fight points that have been reached
            for(j = lfpVertices->begin(); j != lfpVertices->end(); j++)
            {

                //n holds current vertex in the path that is traversed
                //starting at the current local fight point
                /*n=j;

                if (n!=i) //KIJK NIET NAAR ZELF
                {    
                   while((*n)!=(*i) && n!=pred.end()) //TRAVERSE TOTDAT WE BIJ DE SOURCE NODE ZIJN
                   {   

                        predecessor = pred[*n];
                        *n= pred[*n];

                        if (mDebugText!=0)
                             mDebugText->log("traversing through preds of  node");

                   }
                }
                */

            }



        }

  //  }



}
