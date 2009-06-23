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
//mScenario=0;


}

void ScenarioHandler::runScenario()
{
 //mDebugText << "running scenario...";

//step 1: findLFPs
lfpVertices= findLFPs();

//step 2:generateMultiplePaths
generateMultiplePaths(lfpVertices);

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
    generateMultiplePaths(lfpVertices);

}


std::vector<vertex_descriptor>* ScenarioHandler::findLFPs()
{

std::vector<vertex_descriptor>* LFPs= new std::vector<vertex_descriptor>();

  int LFPcount= mScenario.local_fight_points;
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
        mDebugText->log(QString("added to LFP list:") + vItem->strLabel);
        vItem->copyTo(mMapWidget);

        count++;
    }
  }

 mForestWidget->show();
 mForestWidget->repaint();




return LFPs;
}




void ScenarioHandler::generateMultiplePaths(std::vector<vertex_descriptor>* lfpVertices)
{

    Graph* g= this->mForestWidget->getGraph();
    Graph* mapGraph= this->mMapWidget->getGraph();
    std::vector<edge_descriptor> best_edges;
    vertex_descriptor predecessor;
    vertex_descriptor current;
    QtVertexItem* currentItem;
    QtVertexItem* predItem;
    QtEdgeItem* curEdgeItem;


    mDebugText->log(QString("generateMultiplePaths()"),very_important_msg);


    bool notdone=true;

    int iterations=0;

    while(notdone)
    {
        std::vector<vertex_descriptor> pred(num_vertices(*g));

        iterations++;

        if (iterations==3)
         notdone=false;


        mDebugText->log(QString("iteration ") + QString::number(iterations),very_important_msg);



        //for each LFP in LFPVertices
        std::vector<vertex_descriptor>::iterator i,j,n;

        //iterate over all local fight points:
        for(i=lfpVertices->begin(); i!=lfpVertices->end();i++)
        {

            int highest_traverse_rate=0;

            QtVertexItem* v=  (*g)[*i].vertexItem;
             mDebugText->log(QString("current source LFP: ") + v->strLabel,important_msg);



           //std::vector<vertex_descriptor> vertices(num_vertices(*g));

            //perform dijkstra on the current local fight point
           dijkstra_shortest_paths(*g,(*i), predecessor_map(&pred[0]).weight_map(get(&Connection::distance,*g)));

            //traverse paths of all local fight points that have been reached
            for(j = lfpVertices->begin(); j != lfpVertices->end(); j++)
            {

                //n holds current vertex in the path that is traversed
                //starting at the current local fight point
                current=*j;
                currentItem= (*g)[current].vertexItem;

                if (current!=*i) //KIJK NIET NAAR ZELF
                {    
                   mDebugText->log("predecessor path for: " + currentItem->strLabel + " to source " + v->strLabel, important_msg);

                   while(current!=(*i)) //TRAVERSE TOTDAT WE BIJ DE SOURCE NODE ZIJN
                   {    mDebugText->log("*", failure_msg);
                        if (current == pred[current])
                        {
                             mDebugText->log("current==pred[current]: node is not connected to source node", failure_msg);
                            break;
                        }
                        else
                        {
                            currentItem=(*g)[current].vertexItem;
                            predItem= (*g)[pred[current]].vertexItem;

                            //get edge:
                            edge_c retPair = edge(current, pred[current], *g);

                            QtEdgeItem* edgeItem= (*g)[retPair.first].edgeItem;


                            //moet anders!!!
                           // if (edgeItem->isEnabled() == false) //dit betekend dat de gekozen route niet kan
                           // {
                           //     break;
                           // }

                            (*g)[retPair.first].traverseRate+=1;

                            //add to importantedges vector
                            best_edges.push_back(retPair.first);

                            curEdgeItem = (*g)[retPair.first].edgeItem;
                            curEdgeItem->setState(selected_edge);

                            mDebugText->log("The predecessor of " +currentItem->strLabel + " is " + predItem->strLabel, sub_msg);
                            current= pred[current];
                        }
                   }

                }


            }
              pred.clear();


        }
            //add best edges to the mapstructure and remove them from the foreststructure
            std::vector<edge_descriptor>::iterator e;

          QString num;
            if (best_edges.size()> 0)
                mDebugText->log("moving " + num.setNum((int)best_edges.size()) + " edges to mapgraph", important_msg);
            else
                mDebugText->log("no new edges for mapstructure", failure_msg);

            for(e= best_edges.begin(); e!= best_edges.end();e++)
            {
                QtEdgeItem* edge=(*g)[*e].edgeItem;
                QString strDistance;
                mDebugText->log("Copying edge( " +edge->sourceVertex()->strLabel + ", " + edge->destVertex()->strLabel + ") with distance "+ strDistance.setNum((*g)[*e].distance), sub_msg);
                if (edge->enabled()==false)
                {
                   mDebugText->log("edge( " +edge->sourceVertex()->strLabel + ", " + edge->destVertex()->strLabel + ") disabled", failure_msg);
                }


                edge->copyTo(mMapWidget);
                edge->disable();

                (*g)[*e].distance=100000;

                //rigoreus:
               // mForestWidget->deleteEdge(*e);

            }
            best_edges.clear();


    }



}
