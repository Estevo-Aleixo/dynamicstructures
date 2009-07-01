/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Qt Software Information (qt-info@nokia.com)
**
** This file is part of the example classes of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain
** additional rights. These rights are described in the Nokia Qt LGPL
** Exception version 1.0, included in the file LGPL_EXCEPTION.txt in this
** package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#include "graphwidget.h"
//#include "QtVertexItem.h"
//#include "QtEdgeItem.h"

#include <QDebug>
#include <QGraphicsScene>
#include <QWheelEvent>

#include <math.h>

GraphWidget::GraphWidget(QWidget* parent,QWidget *toolbarParent)
    : QGraphicsView(parent), timerId(0),mToolbarParent(toolbarParent)
{
     //setCursor(Qt::IBeamCursor);

    //scene = new QGraphicsScene(this);
    scene = new CustomGraphicsScene(this);

    scene->setSceneRect(-50,-50, 500, 500);

    this->mGraph= new Graph();
    this->setScene(scene);
    this->setCacheMode(this->CacheBackground);
    this->setViewportUpdateMode(this->BoundingRectViewportUpdate);
    this->setRenderHint(QPainter::Antialiasing);
    this->setTransformationAnchor(this->AnchorUnderMouse);
    this->setResizeAnchor(this->AnchorViewCenter);
    this->scale(0.8,0.8);
    this->show();


  initActions();
  initToolbar();

}

GraphWidget::~GraphWidget()
{
    delete mDrawTools;
}

void GraphWidget::itemMoved()
{
    if (!timerId)
        timerId = startTimer(1000 / 10);
}

//void GraphWidget::mousePressEvent(QMouseEvent* event)
//{
  //  QString name="new node";
   // QPointF point =event->pos();

  //  addNode(point,name);


//}

//void GraphWidget::mouseMoveEvent(QMouseEvent* event)
//{

//this->addNode(event->pos(),"newNode");
//QCursor cursor= this->cursor();
//cursor.
//}



void GraphWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Plus:
        scaleView(qreal(1.2));
        break;
    case Qt::Key_Minus:
        scaleView(1 / qreal(1.2));
        break;
    case Qt::Key_Escape:
        this->showNormal();
    case Qt::Key_Space:
    case Qt::Key_Enter:

        foreach (QGraphicsItem *item, scene->items()) {
            if (qgraphicsitem_cast<QtVertexItem *>(item))
                item->setPos(-150 + qrand() % 300, -150 + qrand() % 300);
        }
        break;
    default:
        QGraphicsView::keyPressEvent(event);
    }
}

void GraphWidget::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);

    QList<QtVertexItem *> nodes;
    foreach (QGraphicsItem *item, scene->items()) {
        if (QtVertexItem *node = qgraphicsitem_cast<QtVertexItem *>(item))
            nodes << node;
    }

    foreach (QtVertexItem *node, nodes)
        node->calculateForces();

    bool itemsMoved = false;
    foreach (QtVertexItem *node, nodes) {
        if (node->advance())
            itemsMoved = true;
    }

    if (!itemsMoved) {
        killTimer(timerId);
        timerId = 0;
    }
}

void GraphWidget::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2, -event->delta() / 240.0));
}

void GraphWidget::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);
/*
    // Shadow
    QRectF sceneRect = this->sceneRect();
    QRectF rightShadow(sceneRect.right(), sceneRect.top() + 5, 5, sceneRect.height());
    QRectF bottomShadow(sceneRect.left() + 5, sceneRect.bottom(), sceneRect.width(), 5);
    if (rightShadow.intersects(rect) || rightShadow.contains(rect))
	painter->fillRect(rightShadow, Qt::darkGray);
    if (bottomShadow.intersects(rect) || bottomShadow.contains(rect))
	painter->fillRect(bottomShadow, Qt::darkGray);

    // Fill
    QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1, Qt::lightGray);
    painter->fillRect(rect.intersect(sceneRect), gradient);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(sceneRect);

    // Text
    QRectF textRect(sceneRect.left() + 4, sceneRect.top() + 4,
                    sceneRect.width() - 4, sceneRect.height() - 4);
*/

/*
    QFont font = painter->font();
    font.setBold(true);
    font.setPointSize(14);
    painter->setFont(font);
    painter->setPen(Qt::lightGray);
    painter->drawText(textRect.translated(2, 2), message);
    painter->setPen(Qt::black);
    painter->drawText(textRect, message);
*/
}

void GraphWidget::scaleView(qreal scaleFactor)
{
    qreal factor = this->matrix().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

     this->scale(scaleFactor, scaleFactor);
}

QtVertexItem* GraphWidget::addNode(QPointF& pos)
{
    int num= scene->items().length();
    QtVertexItem*  newNode=new QtVertexItem(this, pos,QString("node") + QString::number(num));
    scene->addItem(newNode);

    return newNode;
}

QtEdgeItem*  GraphWidget::addEdge(QtVertexItem*  uItem, QtVertexItem*  vItem, int directed)
{
    vertex_descriptor u=uItem->getVertexDescriptor();
    vertex_descriptor v=vItem->getVertexDescriptor();
    return addEdge(u,v,directed);
}

QtEdgeItem* GraphWidget::addEdge(vertex_descriptor& u, vertex_descriptor& v, int directed)
{
        QtEdgeItem* newEdge= new QtEdgeItem(u,v,this);
        scene->addItem(newEdge);

    return newEdge;
}

QtVertexItem* GraphWidget::getClosestNodeTo(QtVertexItem* node)
{
    double distance = 10000000;
    double newDist;
    QtVertexItem* closestNode=0;

    foreach(QtVertexItem* n, nodes)
    {
            if (n!=node)
            {
                newDist = (node->x()- n->x())*(node->x()- n->x()) + (node->y()- n->y())*(node->y()- n->y());
                 if (newDist < distance)
                 {
                    distance = newDist;
                    closestNode= n;
                 }

            }
     }

    return closestNode;
}

void GraphWidget::disableEdge(edge_descriptor e)
{


}

void GraphWidget::clear()
{
//clear graph: !WARNING INVALIDATES POINTER TO GRAPH STRUCTURE!




//clear scene

this->scene->clear();
/*
     std::pair< edge_iterator,  edge_iterator> edge_range= edges(*mGraph);
      edge_iterator i;

    QtEdgeItem* eItem;

    for (i=edge_range.first;i!=edge_range.second;++i)
    {
        eItem=(*mGraph)[*i].edgeItem;
        delete eItem;
    }

    std::pair<vertex_iterator, vertex_iterator> vertex_range= vertices(*mGraph);
    vertex_iterator j;

    QtVertexItem* vItem;

    for (j=vertex_range.first;j!=vertex_range.second;++j)
    {
        vItem=(*mGraph)[*j].vertexItem;
       delete vItem;
    }
*/
delete this->mGraph;
mGraph= new Graph();



}

void GraphWidget::deleteEdge(edge_descriptor e)
{
    QtEdgeItem* edgeItem= (*mGraph)[e].edgeItem;
    scene->removeItem(edgeItem);
    delete edgeItem;

    remove_edge(e,*mGraph);

}

void  GraphWidget::removeVertex(vertex_descriptor v)
{
   QtVertexItem* vItem= (*mGraph)[v].vertexItem;
   scene->removeItem(vItem);
   delete vItem;
   vItem=0;

   remove_vertex(v,*mGraph);

//TODO handle connected edges.

}

void GraphWidget::saveToFile(QString filename)
{
  std::ofstream f;

  vertex_iterator vitr;
  edge_iterator eitr;
  QtVertexItem* vItem;
  QtVertexItem* vItem2;
  vertex_descriptor v1,v2;
  vertex_range v_range = vertices(*mGraph);
  std::pair<edge_iterator, edge_iterator>  e_range= edges(*mGraph);

  f.open (filename.toStdString().c_str());
  QString line;
  int i=0;
  for(vitr= v_range.first;vitr !=v_range.second;vitr++)
  {
      vItem= (*mGraph)[*vitr].vertexItem;
      vItem->mSaveIndex = i;
      line = "addNode(" + line.setNum(vItem->x())+ ", "+ line.setNum(vItem->y())+")\n";
      f  << line.toStdString();
      i++;
  }

  f << "--here will be the edges.\n";
  for(eitr= e_range.first; eitr != e_range.second; eitr++)
  {
      v1=   source(*eitr,*mGraph);
      v2=   target(*eitr,*mGraph);
      vItem=(*mGraph)[v1].vertexItem;
      vItem2=(*mGraph)[v2].vertexItem;
      line = "addEdge(" + line.setNum(vItem->mSaveIndex)+ ", "+ line.setNum(vItem2->mSaveIndex)+")\n";
      f << line.toStdString();
  }

  f.close();


}

void GraphWidget::loadFromFile(QString filename)
{



}

  void GraphWidget::initActions()
  {
    //add vertex
    nodeDrawModeAct = new QAction(QIcon("icons/addnode.png"), tr("&New Node..."), this);
    nodeDrawModeAct->setStatusTip(tr("Place Nodes"));
    connect( nodeDrawModeAct, SIGNAL(triggered()), this, SLOT(nodeTool()));
    nodeDrawModeAct->setCheckable(true);

    //add edge
     edgeDrawModeAct = new QAction(QIcon("icons/addedge.png"), tr("&New Edge..."), this);
     edgeDrawModeAct->setStatusTip(tr("Place Nodes"));
     connect(edgeDrawModeAct, SIGNAL(triggered()), this, SLOT(edgeTool()));
     edgeDrawModeAct->setCheckable(true);

     //delete item
     deleteItemAct = new QAction(QIcon("icons/delete.png"), tr("&Delete Item..."), this);
     deleteItemAct->setStatusTip(tr("Delete Item"));
     connect(deleteItemAct, SIGNAL(triggered()), this, SLOT(deleteTool()));
     deleteItemAct->setCheckable(true);

     //select item
     selectItemAct = new QAction(QIcon("icons/accept.png"), tr("&Select item..."), this);
     selectItemAct->setStatusTip(tr("Select"));
     connect(selectItemAct, SIGNAL(triggered()), this, SLOT(selectTool()));
     selectItemAct->setCheckable(true);

     clearWidgetAct= new QAction(QIcon("icons/clear.png"), tr("&Clear..."), this);
     clearWidgetAct->setStatusTip(tr("Clear Canvas"));
     connect(clearWidgetAct, SIGNAL(triggered()), this, SLOT(clearWidget()));



     //copy action
     copyGraphWidgetAct = new QAction(QIcon("icons/copy.png"), tr("&Copy Problem Structure ..."), this);
     copyGraphWidgetAct->setStatusTip(tr("Copy"));
     connect(copyGraphWidgetAct, SIGNAL(triggered()), this, SLOT(copyGraph()));
  }

  /*
 void  GraphWidget::drawNodes()
 {
    mLogWindow->log("eureka!");
 }

 void  GraphWidget::drawEdges()
 {


 }
 void GraphWidget::deleteItem()
 {


 }

 void GraphWidget::selectItem()
 {

 }
*/

 void GraphWidget::nodeTool()
 {
     setToolMode(node_tool, nodeDrawModeAct->isChecked());
 }
 void GraphWidget::edgeTool()
 {
     setToolMode(edge_tool, edgeDrawModeAct->isChecked());

 }
 void GraphWidget::selectTool()
 {
     setToolMode(select_tool, selectItemAct->isChecked());

 }
 void GraphWidget::deleteTool()
 {
     setToolMode(delete_tool, deleteItemAct->isChecked());
 }


 void GraphWidget::initToolbar()
   {
    mDrawTools = new QToolBar("Edit",mToolbarParent);
    mDrawTools ->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    //add vertex
    mDrawTools->addAction(nodeDrawModeAct);
    //add edge
     mDrawTools->addAction(edgeDrawModeAct);
     mDrawTools->addAction(deleteItemAct);
     mDrawTools->addAction(selectItemAct);
       mDrawTools->addAction(clearWidgetAct);
 }


 void GraphWidget::setToolMode(GraphToolMode mode, bool enableTool)
 {


     this->scene->resetToolMemory();

if (enableTool==false)
{
 mToolMode = no_tool;
 mLog->log("no tool ");
 this->setCursor(Qt::ArrowCursor);
}
else
{
    uncheckAllGraphWidgetActions();
    mToolMode = mode;

    switch(mode)
    {
    case edge_tool:
         mLog->log("edge tool selected");
         edgeDrawModeAct->setChecked(true);
        this->setCursor(Qt::CrossCursor);
        break;
    case node_tool:
        mLog->log("node tool selected");
        nodeDrawModeAct->setChecked(true);
        this->setCursor(Qt::CrossCursor);
        break;
    case delete_tool:
         mLog->log("delete tool selected");
        deleteItemAct->setChecked(true);
        this->setCursor(Qt::ArrowCursor);
        break;
     case select_tool:
        mLog->log("select tool selected");
        selectItemAct->setChecked(true);
        this->setCursor(Qt::ArrowCursor);
        break;
    }
}

}

 void GraphWidget::clearGraph()
 {
    delete mGraph;
    mGraph= new Graph();
    scene->clear();
 }

 void GraphWidget::nodesInArea(std::vector<vertex_descriptor>& nodes, QPointF& pos, int range)
{
    vertex_descriptor u;

    std::pair<vertex_iterator, vertex_iterator> iterator_range= vertices(*mGraph);
    vertex_iterator start=iterator_range.first;
    vertex_iterator end=iterator_range.second;
    vertex_iterator i;

    QtVertexItem* item2;

    for (i=start;i!=end;++i)
    {
        item2=(*mGraph)[*i].vertexItem;
        QPointF pos2= QPointF(item2->x(),item2->y());

        if (((pos.x() - pos2.x())*(pos.x() - pos2.x())+(pos.y() - pos2.y())*(pos.y() - pos2.y()))< range * range )
        {
            nodes.push_back(*i);
        }
    }

}

void GraphWidget::nodesConnectedTo(QtVertexItem* vItem, std::vector<QtVertexItem*>& nodes, int range, VertexTag tagWith)
{
    QtVertexItem* uItem;

     mLog->logToBuffer("nodesConnectedTo(): " + vItem->strLabel);

    graph_traits<Graph>::adjacency_iterator itr;
    std::pair< graph_traits<Graph>::adjacency_iterator ,  graph_traits<Graph>::adjacency_iterator > adjacent_range=  adjacent_vertices(vItem->getVertexDescriptor(), *mGraph);

    int distance;
    for (itr=adjacent_range.first;itr!=adjacent_range.second;itr++)
    {
     //get edge:
        uItem= (*mGraph)[*itr].vertexItem;
        distance=-1;
        if  (distance < range)
        {
            nodes.push_back(uItem);
            uItem->setTag(tagWith);
            mLog->logToBuffer("Node " + vItem->strLabel + " adjacent to " + uItem->strLabel);
        }

    }

}


void GraphWidget::tagNeighbours(vertex_descriptor v, VertexTag tag, int range)
{}

 void GraphWidget::removeAllActionsFromToolBar()
 {
     //mDrawTools->removeAction(nodeDrawModeAct);
     //mDrawTools->removeAction(edgeDrawModeAct);
     //mDrawTools->removeAction(deleteItemAct);
     //mDrawTools->removeAction(selectItemAct);
     mDrawTools->clear();
 }

 void GraphWidget::addCopyFromWidgetAction(GraphWidget* gWidget)
 {
    mOtherGraphWidget= gWidget;
    mDrawTools->addAction(copyGraphWidgetAct);
 }


 void GraphWidget::copyGraph()
 {
        mOtherGraphWidget->copyAllTo(this);
 }

 void GraphWidget::copyAllTo(GraphWidget* gWidget)
 {

  QtEdgeItem* eItem;
  std::pair<edge_iterator, edge_iterator> e_range= edges(*mGraph);
  edge_iterator itr;

for (itr = e_range.first; itr!=e_range.second;itr++)
  {
    eItem = (*mGraph)[*itr].edgeItem;
    eItem->copyTo(gWidget);
  }

//traverse through edges:


 }

void GraphWidget::clearWidget()
{
    this->clear();
}


std::vector<edge_descriptor>& GraphWidget::getMinimumSpanningTree()
{

QtEdgeItem* eItem;
mSpanning_tree.clear();

kruskal_minimum_spanning_tree(*mGraph, std::back_inserter(mSpanning_tree),weight_map(get(&Connection::distance,*mGraph)));


  for (std::vector <edge_descriptor>::iterator ei = mSpanning_tree.begin();
       ei != mSpanning_tree.end(); ++ei)
        {
            eItem= (*mGraph)[*ei].edgeItem;
            eItem->setTag(edge_minspan_tag);
        }
 return this->mSpanning_tree;
 }

 void  GraphWidget::hideMinimumSpanningTree()
 {

     QtEdgeItem* eItem;
  for (std::vector <edge_descriptor>::iterator ei = mSpanning_tree.begin();
       ei != mSpanning_tree.end(); ++ei)
        {
            eItem= (*mGraph)[*ei].edgeItem;
            eItem->setTag(edge_no_tag);
        }

 }



void GraphWidget::removeAllEdgeTags()
{

     std::pair< edge_iterator,  edge_iterator> iterator_range= edges(*mGraph);
     edge_iterator start=iterator_range.first;
     edge_iterator end=iterator_range.second;
     edge_iterator i;

    QtEdgeItem* eItem;

    for (i=start;i!=end;++i)
    {
        eItem=(*mGraph)[*i].edgeItem;
        eItem->setTag(edge_no_tag);
    }



}

void GraphWidget::removeAllVertexTags()
{

    vertex_descriptor u;

    std::pair<vertex_iterator, vertex_iterator> iterator_range= vertices(*mGraph);
    vertex_iterator start=iterator_range.first;
    vertex_iterator end=iterator_range.second;
    vertex_iterator i;

    QtVertexItem* vItem;

    for (i=start;i!=end;++i)
    {
        vItem=(*mGraph)[*i].vertexItem;
        vItem->setTag(no_tag);
    }


}

void GraphWidget::removeAllEdgeTypes()
{

        std::pair< edge_iterator,  edge_iterator> iterator_range= edges(*mGraph);
     edge_iterator start=iterator_range.first;
     edge_iterator end=iterator_range.second;
      edge_iterator i;

    QtEdgeItem* eItem;

    for (i=start;i!=end;++i)
    {
        eItem=(*mGraph)[*i].edgeItem;
        eItem->setState(normal_edge);
        eItem->enable();
    }
}

void GraphWidget::removeAllVertexTypes()
{
    vertex_descriptor u;

    std::pair<vertex_iterator, vertex_iterator> iterator_range= vertices(*mGraph);
    vertex_iterator start=iterator_range.first;
    vertex_iterator end=iterator_range.second;
    vertex_iterator i;

    QtVertexItem* vItem;

    for (i=start;i!=end;++i)
    {
        vItem=(*mGraph)[*i].vertexItem;
        vItem->setType(normal_type);
        vItem->unsetClone();
    }


}

void GraphWidget::updateEdgeDistances()
{
     std::pair< edge_iterator,  edge_iterator> iterator_range= edges(*mGraph);
     edge_iterator start=iterator_range.first;
     edge_iterator end=iterator_range.second;
      edge_iterator i;

    QtEdgeItem* eItem;

    for (i=start;i!=end;++i)
    {
        eItem=(*mGraph)[*i].edgeItem;
        eItem->updateDistance();
    }


}



