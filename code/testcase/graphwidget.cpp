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

GraphWidget::GraphWidget(QWidget* parent)
    : QGraphicsView(parent), timerId(0)
{
     //setCursor(Qt::IBeamCursor);

    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(0, 0, 400, 400);

    this->mGraph= new Graph();
    this->setScene(scene);
    this->setCacheMode(this->CacheBackground);
    this->setViewportUpdateMode(this->BoundingRectViewportUpdate);
    this->setRenderHint(QPainter::Antialiasing);
    this->setTransformationAnchor(this->AnchorUnderMouse);
    this->setResizeAnchor(this->AnchorViewCenter);



    //this->
    //this->setDragMode(QGraphicsView::ScrollHandDrag);
    //create nodes:
    //centerNode = new QtVertexItem(this);

    // this->setMinimumSize(400, 400);
     this->show();
}

void GraphWidget::itemMoved()
{
    if (!timerId)
        timerId = startTimer(1000 / 25);
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
delete this->mGraph;
mGraph= new Graph();

//clear scene
this->scene->clear();

}

void GraphWidget::deleteEdge(edge_descriptor e)
{
    QtEdgeItem* edgeItem= (*mGraph)[e].edgeItem;
    scene->removeItem(edgeItem);
    delete edgeItem;

    remove_edge(e,*mGraph);

}
