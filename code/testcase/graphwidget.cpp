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
#include "edge.h"
#include "node.h"

#include <QDebug>
#include <QGraphicsScene>
#include <QWheelEvent>

#include <math.h>

GraphWidget::GraphWidget(QWidget* parent)
    : QGraphicsView(parent), timerId(0)
{

    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-200, -200, 800, 800);
    this->setScene(scene);
    this->setCacheMode(this->CacheBackground);
    this->setViewportUpdateMode(this->BoundingRectViewportUpdate);
    this->setRenderHint(QPainter::Antialiasing);
    this->setTransformationAnchor(this->AnchorUnderMouse);
    this->setResizeAnchor(this->AnchorViewCenter);


    //create nodes:
    centerNode = new Node(this);
    /*
    nodes.push_back(centerNode);
    nodes.push_back(new Node(this));
    nodes.push_back(new Node(this));
    nodes.push_back(new Node(this));
    nodes.push_back(new Node(this));
    nodes.push_back(new Node(this));
    nodes.push_back(new Node(this));
    nodes.push_back(new Node(this));
    nodes.push_back(new Node(this));
    nodes.push_back(new Node(this));
*/
    //create edges:
 /*
    edges.push_back(new Edge(nodes[1], nodes[2]));
    edges.push_back(new Edge(nodes[2], nodes[3]));
    edges.push_back(new Edge(nodes[2], nodes[0]));
    edges.push_back(new Edge(nodes[3], nodes[6]));
    edges.push_back(new Edge(nodes[4], nodes[1]));
    edges.push_back(new Edge(nodes[0], nodes[6]));
    edges.push_back(new Edge(nodes[0], nodes[8]));
    edges.push_back(new Edge(nodes[6], nodes[9]));
    edges.push_back(new Edge(nodes[7], nodes[4]));
    edges.push_back(new Edge(nodes[8], nodes[7]));
    edges.push_back(new Edge(nodes[9], nodes[8]));
*/
/*
    foreach(Node* node, nodes)
    {
         scene->addItem(node);
    }

    foreach(Edge* edge, edges)
    {
         scene->addItem(edge);
    }

    nodes[1]->setPos(-50, -50);
    nodes[2]->setPos(0, -50);
    nodes[3]->setPos(50, -50);
    nodes[4]->setPos(-50, 0);
    centerNode->setPos(0, 0);
    nodes[6]->setPos(50, 0);
    nodes[7]->setPos(-50, 50);
    nodes[8]->setPos(0, 50);
    nodes[9]->setPos(50, 50);
*/
     this->scale(qreal(0.8), qreal(0.8));
     this->setMinimumSize(400, 400);
     this->show();
}

void GraphWidget::itemMoved()
{
    if (!timerId)
        timerId = startTimer(1000 / 25);
}



void GraphWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        centerNode->moveBy(0, -20);
        break;
    case Qt::Key_Down:
        centerNode->moveBy(0, 20);
        break;
    case Qt::Key_Left:
        centerNode->moveBy(-20, 0);
        break;
    case Qt::Key_Right:
        centerNode->moveBy(20, 0);
        break;
    case Qt::Key_Plus:
        scaleView(qreal(1.2));
        break;
    case Qt::Key_Minus:
        scaleView(1 / qreal(1.2));
        break;
    case Qt::Key_Space:
    case Qt::Key_Enter:

        foreach (QGraphicsItem *item, scene->items()) {
            if (qgraphicsitem_cast<Node *>(item))
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

    QList<Node *> nodes;
    foreach (QGraphicsItem *item, scene->items()) {
        if (Node *node = qgraphicsitem_cast<Node *>(item))
            nodes << node;
    }

    foreach (Node *node, nodes)
        node->calculateForces();

    bool itemsMoved = false;
    foreach (Node *node, nodes) {
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

Node* GraphWidget::createNode(QPointF& pos)
{
    Node*  newNode=new Node(this);
    newNode->setPos(pos);
    nodes.push_back(newNode);
    scene->addItem(newNode);


    return newNode;
}

Edge* GraphWidget::createEdge(Node* source, Node* dest)
{
    Edge* newEdge= new Edge(source,dest);
    edges.push_back(newEdge);
    scene->addItem(newEdge);


    return newEdge;
}

Node* GraphWidget::getClosestNodeTo(Node* node)
{
    double distance = 10000000;
    double newDist;
    Node* closestNode=0;

    foreach(Node* n, nodes)
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

