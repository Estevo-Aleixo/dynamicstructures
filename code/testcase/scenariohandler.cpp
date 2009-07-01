#include "scenariohandler.h"
#include "LogWindow.h"

bool compareVertexDegree(QtVertexItem* v1, QtVertexItem* v2);


bool compareVertexDegree(QtVertexItem* v1, QtVertexItem* v2)
{
    return v1->degree > v2->degree;
}


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


}




 void  ScenarioHandler::findSpanningPoints()
 {
QString method;
this->mDebugText->log("span method: " + method.setNum(mScenario.spanMethod) );
    switch(mScenario.spanMethod)
    {
        case random_search:

           findRandomVertices(mScenario.spanning_points, spanVertices, mForestWidget,mMapWidget,span_type);
        break;
        case high_degree_search:
             findHighDegreeVertices(mScenario.spanning_points,spanVertices, mForestWidget,mMapWidget,span_type);
        break;
        case highest_degree_search:
             findHighestDegreeVertices(mScenario.spanning_points,spanVertices, mForestWidget,mMapWidget,span_type);
        break;
    }



 }

void ScenarioHandler::executeLFPfinder()
{
    //step 1: findLFPs
    if (mDebugText!=0){
        mDebugText->log("initiating LFP finder");
    }


     switch(mScenario.lfpMethod)
    {
        case random_search:
             findRandomVertices(mScenario.local_fight_points,lfpVertices,mMapWidget,0,LFP_type);
        break;
        case high_degree_search:
             findHighDegreeVertices(mScenario.local_fight_points, lfpVertices,mMapWidget,0, LFP_type);
        break;
        case highest_degree_search:
             findHighestDegreeVertices(mScenario.local_fight_points,lfpVertices, mMapWidget,0,LFP_type);
        break;
    }
}

void ScenarioHandler::executeMultiplePathFinder()
{

        mDebugText->log("initiating path finder");

    //step 2:generateMultiplePaths
    generateMultiplePaths(spanVertices);
    //soundDone->play();

}


void ScenarioHandler::findRandomVertices(int num_vertices,std::vector<vertex_descriptor>& vertices,GraphWidget* from, GraphWidget* to, VertexType type)
{



  int LFPcount= num_vertices;
  int count=0;

  QList<QGraphicsItem*> vertexList= from->scene->items();
  QtVertexItem* vItem;
   while((count < LFPcount)==true)
  {
    int i= rand() % vertexList.size();
    if (vItem= qgraphicsitem_cast<QtVertexItem*>(vertexList[i]))
    { 
       vertices.push_back(vItem->getVertexDescriptor());
        mDebugText->logToBuffer(QString("added to list:") + vItem->strLabel);

        if (vItem->getType()!= type){
             vItem->setType(type);
             if(to!=0)
                vItem->copyTo(to);
             count++;
         }
    }
  }

 from->show();
 from->repaint();

//return vertices;
}


 //used for LFP's and spanning points
void ScenarioHandler::findImportantSteinerGraphVertices(int num_vertices,std::vector<vertex_descriptor>& vertices, GraphWidget* from, GraphWidget* to, VertexType type)
{



}

//description:
//
//find vertices with highest degree scattered over the entire range of vertices.
//

void ScenarioHandler::findHighDegreeVertices(int num_vertices,std::vector<vertex_descriptor>& vertices, GraphWidget* from, GraphWidget* to, VertexType type)
{


    std::vector<QtVertexItem*> localNodes;
    std::vector<QtVertexItem*>::iterator nItr;

    mDebugText->log("findHighDegreeVertices(int num_vertices, GraphWidget* from, GraphWidget* to)");

  QList<QGraphicsItem*> sceneList= from->scene->items();
  QtVertexItem* vItem;

    //traverse vertices
int degree;
int count=0;
int iterations=0;
int treshold=3;

 while(count < num_vertices)
  {
     iterations++;
    localNodes.clear();
    mDebugText->log("looping");
    int i= rand() % sceneList.size();

    if (vItem= qgraphicsitem_cast<QtVertexItem*>(sceneList[i]))
    {

        if (vItem->getTag()!=disabled_tag)
        {
            mDebugText->logToBuffer("selection:" + vItem->strLabel);
            from->nodesConnectedTo(vItem,localNodes, 100);

            QString size;
            int num_neighbours=localNodes.size();
            mDebugText->logToBuffer("adjacent vertices: " + size.setNum(num_neighbours));

            if (num_neighbours >= treshold)
            {
                for (nItr=localNodes.begin(); nItr!=localNodes.end(); nItr++)
                {
                    (*nItr)->setTag(disabled_tag);
                }
                vItem->setTag(disabled_tag);
                vertices.push_back(vItem->getVertexDescriptor());
                vItem->setType(type);

                if(to!=0)
              {
                  vItem->copyTo(to);
              }
                count++;
            }

        }



        if (iterations > 2000)
            break;

    }
  }
mDebugText->flush();

}

void ScenarioHandler::findHighestDegreeVertices(int num_vertices, std::vector<vertex_descriptor>& vertices, GraphWidget* from, GraphWidget* to, VertexType type)
{
    //1. iterate over all vertices and store degree
    //2. sort on degree, Descending
    //3. iterate over sorted vertices add to vertexList when not disabled

 mDebugText->logToBuffer("findHighestDegreeVertices",very_important_msg);

int count=0;



    std::vector<QtVertexItem*> sortedList;
    std::vector<QtVertexItem*>::iterator l_itr;



    //1. iterate over all vertices and store degree
    std::vector<QtVertexItem*> localNodes;
    std::vector<QtVertexItem*>::iterator s_itr;


    Graph* g= from->getGraph();

    std::pair<vertex_iterator, vertex_iterator> iterator_range= boost::vertices(*g);
    vertex_iterator start=iterator_range.first;
    vertex_iterator end=iterator_range.second;
    vertex_iterator i;

    QtVertexItem* vItem;

    for (i=start;i!=end;++i)
    {
        localNodes.clear();
        vItem=(*g)[*i].vertexItem;
        from->nodesConnectedTo(vItem,localNodes, 100);
        vItem->degree = localNodes.size();
        vItem->surroundingNodes=localNodes;

        sortedList.push_back(vItem);
        mDebugText->logToBuffer("node: " + vItem->strLabel);
        QString size;
        mDebugText->logToBuffer("adjacent vertices: " + size.setNum(vItem->degree));
        vItem->setTag(no_tag);
    }

    //2. sort on degree, Descending
    std::sort(sortedList.begin(),sortedList.end(),compareVertexDegree);

    //3. iterate over sorted vertices add to vertexList when not disabled

     mDebugText->logToBuffer("traversing sorted list..");
     QString blaat;
    mDebugText->logToBuffer("sorted list size: "+ blaat.setNum((int)sortedList.size()));
        for (l_itr = sortedList.begin(); l_itr!=sortedList.end();l_itr++)
        {

              QString text;
            if ((*l_itr)->getTag()!=disabled_tag)
            {


                vertices.push_back((*l_itr)->getVertexDescriptor());
            (*l_itr)->setType(type);
                mDebugText->logToBuffer((*l_itr)->strLabel + " has degree " +text.setNum((*l_itr)->degree));

                if(to!=0)
                      (*l_itr)->copyTo(to);


                  count++;

                //disable surrounding nodes
                for (s_itr=vItem->surroundingNodes.begin(); s_itr!=vItem->surroundingNodes.end(); s_itr++)
                {
                    (*s_itr)->setTag(disabled_tag);
                }

                if (count==num_vertices)
                {
                    break;
                }
            }

        }

 mDebugText->flush();

}



void ScenarioHandler::generateMultiplePaths(std::vector<vertex_descriptor>& vertices)
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

        //mDebugText->log(QString("iteration ") + QString::number(iterations),very_important_msg);
        mDebugText->logToBuffer(QString("iteration ") + QString::number(iterations),very_important_msg);

        //for each LFP in LFPVertices
        std::vector<vertex_descriptor>::iterator i,j,n;

        //iterate over all local fight points:
        for(i=vertices.begin(); i!=vertices.end();i++)
        {

            //get paths from other lfp's to current lfp
            int highest_traverse_rate=0;

            QtVertexItem* v=  (*g)[*i].vertexItem;

             //mDebugText->log(QString("current source LFP: ") + v->strLabel,important_msg);
             mDebugText->logToBuffer(QString("current source LFP: ") + v->strLabel,important_msg);

            //perform dijkstra on the current local fight point
            dijkstra_shortest_paths(*g,(*i), predecessor_map(&pred[0]).weight_map(get(&Connection::distance,*g)));

            //traverse paths of all local fight points that have been reached
                for(j = vertices.begin(); j != vertices.end(); j++)
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

void  ScenarioHandler::reset()
{
    this->lfpVertices.clear();
    this->spanVertices.clear();
    this->mMapWidget->clear();

    this->mForestWidget->removeAllVertexTags();
    this->mForestWidget->removeAllEdgeTypes();
    this->mForestWidget->removeAllVertexTypes();
    this->mForestWidget->updateEdgeDistances();


}
