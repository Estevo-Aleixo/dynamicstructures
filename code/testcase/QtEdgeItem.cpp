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

#include <QPainter>

#include "QtEdgeItem.h"
#include "QtVertexItem.h"

#include <math.h>

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;



QtEdgeItem::QtEdgeItem(vertex_descriptor& start, vertex_descriptor& end, GraphWidget *graphWidget)
         : arrowSize(10)
{
   mG= graphWidget->getGraph();


    mState=normal_edge;
    edge_c retValue;
    retValue =  boost::add_edge(start,end,*mG);

    mEd= retValue.first;
    (*mG)[mEd].edgeItem=this;
    (*mG)[mEd].distance=0.0;
    setAcceptedMouseButtons(0);
    source = (*mG)[start].vertexItem;
    dest = (*mG)[end].vertexItem;;
    source->addEdge(this);
    dest->addEdge(this);
    adjust();

    QString s="distance";
    mLabel = new QGraphicsTextItem(s,this,graphWidget->scene);
}



QtEdgeItem::~QtEdgeItem()
{
}

QtVertexItem *QtEdgeItem::sourceVertex() const
{
    return source;
}

void QtEdgeItem::setSourceVertex(QtVertexItem *QtVertexItem)
{
    source = QtVertexItem;
    adjust();
}

QtVertexItem *QtEdgeItem::destVertex() const
{
    return dest;
}

void QtEdgeItem::setDestVertex(QtVertexItem *QtVertexItem)
{
    dest = QtVertexItem;
    adjust();
}

void QtEdgeItem::adjust()
{
    if (!source || !dest)
        return;

    QLineF line(mapFromItem(source, 0, 0), mapFromItem(dest, 0, 0));
    qreal length = line.length();
    QPointF QtEdgeItemOffset((line.dx() * 10) / length, (line.dy() * 10) / length);

    prepareGeometryChange();
    sourcePoint = line.p1() + QtEdgeItemOffset;
    destPoint = line.p2() - QtEdgeItemOffset;

    (*mG)[mEd].distance=line.length();
}

QRectF QtEdgeItem::boundingRect() const
{
    if (!source || !dest)
        return QRectF();

    qreal penWidth = 1;
    qreal extra = (penWidth + arrowSize) / 2.0;

    return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(),
                                      destPoint.y() - sourcePoint.y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}

void QtEdgeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (!source || !dest)
        return;

    // Draw the line itself
    QLineF line(sourcePoint, destPoint);
    // Draw the arrows if there's enough room
    double angle = ::acos(line.dx() / line.length());
    if (line.dy() >= 0)
        angle = TwoPi - angle;

    QPointF sourceArrowP1 = sourcePoint + QPointF(sin(angle + Pi / 3) * arrowSize,
                                                  cos(angle + Pi / 3) * arrowSize);
    QPointF sourceArrowP2 = sourcePoint + QPointF(sin(angle + Pi - Pi / 3) * arrowSize,
                                                  cos(angle + Pi - Pi / 3) * arrowSize);
    QPointF destArrowP1 = destPoint + QPointF(sin(angle - Pi / 3) * arrowSize,
                                              cos(angle - Pi / 3) * arrowSize);
    QPointF destArrowP2 = destPoint + QPointF(sin(angle - Pi + Pi / 3) * arrowSize,
                                              cos(angle - Pi + Pi / 3) * arrowSize);



    switch(mState)
    {
        case normal_edge:
        painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        break;
        case important_edge:
        painter->setPen(QPen(Qt::red, 2, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin));
        break;
        case interest_edge:
        painter->setPen(QPen(Qt::green, 1, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin));
        break;

    }

    painter->drawLine(line);

    painter->setBrush(Qt::black);
    painter->drawPolygon(QPolygonF() << line.p1() << sourceArrowP1 << sourceArrowP2);
    painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);

    //draw distance
    QString s;
    QPointF labelPos;
    labelPos= sourcePoint + QPointF(cos(angle)*(line.length()/2),sin(angle)*(line.length()/2));
    s.sprintf("%.2f",(*mG)[mEd].distance);

    mLabel->setPos(labelPos);
    mLabel->setPlainText(s);

}
