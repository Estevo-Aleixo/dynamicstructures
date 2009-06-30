#include "customgraphicsscene.h"

#include "graphwidget.h"

CustomGraphicsScene::CustomGraphicsScene(QObject* parent)
 :QGraphicsScene(parent)
{

mParentWidget= (GraphWidget*)this->parent();
resetToolMemory();
}
 void CustomGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
 {

       QPointF pos=event->scenePos();
    switch(mParentWidget->getToolMode())
    {

        case no_tool:
        case select_tool:
        case edge_tool:
         QGraphicsScene::mousePressEvent(event);
        break;
        case node_tool:
            mParentWidget->addNode(pos);
        break;
        case delete_tool:
            //mParentWidget->addNode(pos);
        break;
        default:
             QGraphicsScene::mousePressEvent(event);
        break;
    }

}

void CustomGraphicsScene::addVertexForEdge(QtVertexItem* v)
{
    if (node1==0)
    {
        node1=v;
        //node1->setState(selected_state);
    }else
    {
        //node1->setType(node1->getType());
        node2=v;
        mParentWidget->addEdge( node1,node2,0);
        node1=0;
        node2=0;

    }



}
