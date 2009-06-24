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


soundDone= new QSound("Sounds/discovery.wav");

}

void ScenarioHandler::runScenario()
{
 ////mDebugText << "running scenario...";

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
    if (mDebugText!=0){
        mDebugText->logToBuffer("initiating LFP finder");
    }

    lfpVertices= findLFPs();
}

void ScenarioHandler::executeMultiplePathFinder()
{
      if (mDebugText!=0){
        mDebugText->logToBuffer("initiating path finder");
      }
    //step 2:generateMultiplePaths
    generateMultiplePaths(lfpVertices);
    soundDone->play();

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

        LFPs->push_back(vItem->getVertexDescriptor());
        mDebugText->logToBuffer(QString("added to LFP list:") + vItem->strLabel);

        if (vItem->getType()!= LFP_type){
             vItem->setType(LFP_type);
             vItem->copyTo(mMapWidget);
             count++;
         }



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

    mDebugText->logToBuffer(QString("generateMultiplePaths()"),very_important_msg);


    bool notdone=true;

    int iterations=0;

    while(notdone)
    {
        std::vector<vertex_descriptor> pred(num_vertices(*g));

        iterations++;

        if (iterations == this->mScenario.multiple_path_iterations)
            notdone=false;

        mDebugText->logToBuffer(QString("iteration ") + QString::number(iterations),very_important_msg);

        //for each LFP in LFPVertices
        std::vector<vertex_descriptor>::iterator i,j,n;

        //iterate over all local fight points:
        for(i=lfpVertices->begin(); i!=lfpVertices->end();i++)
        {

            //get paths from other lfp's to current lfp
            int highest_traverse_rate=0;

            QtVertexItem* v=  (*g)[*i].vertexItem;
             mDebugText->logToBuffer(QString("current source LFP: ") + v->strLabel,important_msg);

            //perform dijkstra on the current local fight point
            dijkstra_shortest_paths(*g,(*i), predecessor_map(&pred[0]).weight_map(get(&Connection::distance,*g)));

            //traverse paths of all local fight points that have been reached
                for(j = lfpVertices->begin(); j != lfpVertices->end(); j++)
                {
                    TraverseAndStorePath(g, *i, *j, pred, best_edges);
                }


            }
              pred.clear();


            //add best edges to the mapstructure and remove them from the foreststructure
            std::vector<edge_descriptor>::iterator e;

          QString num;
            if (best_edges.size()> 0){
                mDebugText->logToBuffer("moving " + num.setNum((int)best_edges.size()) + " edges to mapgraph", important_msg);
            }else{
                mDebugText->logToBuffer("no new edges for mapstructure", failure_msg);
            }
            for(e= best_edges.begin(); e!= best_edges.end();e++)
            {
                QtEdgeItem* edge=(*g)[*e].edgeItem;
                QString strDistance;
                if (edge->enabled()==false)
                {
                   //mDebugText->logToBuffer("edge( " +edge->sourceVertex()->strLabel + ", " + edge->destVertex()->strLabel + ") already used", failure_msg);
                }else
                {
                    mDebugText->logToBuffer("Copying edge( " +edge->sourceVertex()->strLabel + ", " + edge->destVertex()->strLabel + ") with distance "+ strDistance.setNum((*g)[*e].distance), sub_msg);
                }

                if (edge->enabled()==true)
                    edge->copyTo(mMapWidget);

                edge->disable();

                (*g)[*e].distance=100000;

                //rigoreus:
               // mForestWidget->deleteEdge(*e);

            }
            best_edges.clear();

        }
       mDebugText->flush();

 }



void ScenarioHandler::TraverseAndStorePath(Graph* g, vertex_descriptor i, vertex_descriptor j, std::vector<vertex_descriptor>& pred, std::vector<edge_descriptor>& edges)
{
    QtEdgeItem* curEdgeItem;
    vertex_descriptor current;
    QtVertexItem* currentItem;
    QtVertexItem* sourceItem;
    QtVertexItem* predItem;
 //n holds current vertex in the path that is traversed
                //starting at the current local fight point
                current=j;
                currentItem= (*g)[current].vertexItem;
                sourceItem= (*g)[i].vertexItem;

                if (current!=i) //KIJK NIET NAAR ZELF
                {
                   mDebugText->logToBuffer("predecessor path for: " + currentItem->strLabel + " to source " + sourceItem->strLabel, important_msg);

                   while(current!=(i)) //TRAVERSE TOTDAT WE BIJ DE SOURCE NODE ZIJN
                   {
                        if (current == pred[current])
                        {
                             mDebugText->logToBuffer("current==pred[current]: node is not connected to source node", failure_msg);
                            break;
                        }
                        else
                        {
                            currentItem=(*g)[current].vertexItem;
                            predItem= (*g)[pred[current]].vertexItem;

                            //get edge:
                            edge_c retPair = edge(current, pred[current], *g);

                            QtEdgeItem* edgeItem= (*g)[retPair.first].edgeItem;

                            (*g)[retPair.first].traverseRate+=1;

                            //add to importantedges vector
                            edges.push_back(retPair.first);

                            curEdgeItem = (*g)[retPair.first].edgeItem;
                            curEdgeItem->setState(selected_edge);

                            mDebugText->logToBuffer("The predecessor of " +currentItem->strLabel + " is " + predItem->strLabel, sub_msg);
                            current= pred[current];
                        }
                   }
            }
}
