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

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>

#include "QtEdgeItem.h"
#include "QtVertexItem.h"
#include "graphwidget.h"

QtVertexItem::QtVertexItem(GraphWidget *graphWidget, Graph* g, QPointF& pos, QString& name)
    : graph(graphWidget)
{
    mV = boost::add_vertex(*g);
    (*g)[mV].vertexItem= this;

    itemLabel = new QGraphicsTextItem(name,this,graphWidget->scene);
    this->setPos(pos);

    setFlag(ItemIsMovable);
    setCacheMode(DeviceCoordinateCache);
    setZValue(1);
    mState=normal;
}

void QtVertexItem::addEdge(QtEdgeItem *edge)
{
    edgeList << edge;
    edge->adjust();
}

QList<QtEdgeItem *> QtVertexItem::edges() const
{
    return edgeList;
}

void QtVertexItem::calculateForces()
{
    //if (!scene() || scene()->mouseGrabberItem() == this) {
  //      newPos = pos();
  //      return;
 //   }
    /*
    // Sum up all forces pushing this item away
    qreal xvel = 0;
    qreal yvel = 0;
    foreach (QGraphicsItem *item, scene()->items()) {
        QtVertexItem *QtVertexItem = qgraphicsitem_cast<QtVertexItem *>(item);
        if (!QtVertexItem)
            continue;

        QLineF line(mapFromItem(QtVertexItem, 0, 0), QPointF(0, 0));
        qreal dx = line.dx();
        qreal dy = line.dy();
        double l = 2.0 * (dx * dx + dy * dy);
        if (l > 0) {
            xvel += (dx * 150.0) / l;
            yvel += (dy * 150.0) / l;
        }
    }

    // Now subtract all forces pulling items together
    double weight = (QtEdgeItemList.size() + 1) * 10;
    foreach (QtEdgeItem *QtEdgeItem, QtEdgeItemList) {
        QPointF pos;
        if (QtEdgeItem->sourceQtVertexItem() == this)
            pos = mapFromItem(QtEdgeItem->destQtVertexItem(), 0, 0);
        else
            pos = mapFromItem(QtEdgeItem->sourceQtVertexItem(), 0, 0);
        xvel += pos.x() / weight;
        yvel += pos.y() / weight;
    }
    
    if (qAbs(xvel) < 0.1 && qAbs(yvel) < 0.1)
        xvel = yvel = 0;

    QRectF sceneRect = scene()->sceneRect();
    newPos = pos() + QPointF(xvel, yvel);
    newPos.setX(qMin(qMax(newPos.x(), sceneRect.left() + 10), sceneRect.right() - 10));
    newPos.setY(qMin(qMax(newPos.y(), sceneRect.top() + 10), sceneRect.bottom() - 10));
*/
}

bool QtVertexItem::advance()
{
    if (newPos == pos())
        return false;

   // setPos(newPos);
    return true;
}

QRectF QtVertexItem::boundingRect() const
{
    qreal adjust = 2;
    return QRectF(-10 - adjust, -10 - adjust,
                  23 + adjust, 23 + adjust);
}

QPainterPath QtVertexItem::shape() const
{
    QPainterPath path;
    path.addEllipse(-10, -10, 20, 20);
    return path;
}

void QtVertexItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{

     QRadialGradient gradient(-3, -3, 10);
    switch(mState){

     case normal:
        painter->setPen(Qt::NoPen);
        painter->setBrush(Qt::darkGray);
        painter->drawEllipse(-7, -7, 20, 20);


        if (option->state & QStyle::State_Sunken) {
            gradient.setCenter(3, 3);
            gradient.setFocalPoint(3, 3);
            gradient.setColorAt(1, QColor(Qt::yellow).light(120));
            gradient.setColorAt(0, QColor(Qt::darkYellow).light(120));
        } else {
            gradient.setColorAt(0, Qt::yellow);
            gradient.setColorAt(1, Qt::darkYellow);
        }
        painter->setBrush(gradient);
        painter->setPen(QPen(Qt::black, 0));
        painter->drawEllipse(-10, -10, 20, 20);
     break;
        case important:
            painter->setPen(Qt::NoPen);
            painter->setBrush(Qt::darkGray);
            painter->drawRoundRect(-7, -7, 20, 20,4,4);
            if (option->state & QStyle::State_Sunken) {
                gradient.setCenter(3, 3);
                gradient.setFocalPoint(3, 3);
                gradient.setColorAt(1, QColor(Qt::red).light(120));
                gradient.setColorAt(0, QColor(Qt::darkRed).light(120));
            } else {
                gradient.setColorAt(0, Qt::red);
                gradient.setColorAt(1, Qt::darkRed);
            }
            painter->setBrush(gradient);
            painter->setPen(QPen(Qt::black, 0));
            painter->drawRoundRect(-10, -10, 20, 20,4,4);
        break;


    }
}

QVariant QtVertexItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        foreach (QtEdgeItem *edge, edgeList)
            edge->adjust();
        graph->itemMoved();
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}

void QtVertexItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

void QtVertexItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

void QtVertexItem::setState(VertexState state)
{
mState= state;

}
