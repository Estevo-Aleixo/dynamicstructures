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

#ifndef QtEdgeItem_H
#define QtEdgeItem_H

#include <QGraphicsItem>
#include "GraphWidget.h"

enum EdgeState{normal_edge, important_edge,selected_edge, active_edge,unimportant_edge, collision_edge, toBeDeleted_edge, interest_edge,disabled_edge};
enum EdgeTag{edge_no_tag, edge_selected_tag, edge_disabled_tag, edge_minspan_tag};


class QtVertexItem;

class QtEdgeItem : public QGraphicsItem
{
public:
    QtEdgeItem(vertex_descriptor& start, vertex_descriptor& end, GraphWidget* graphWidget);

    ~QtEdgeItem();

    QtVertexItem *sourceVertex() const;
    void setSourceVertex(QtVertexItem *QtVertexItem);

    QtVertexItem *destVertex() const;
    void setDestVertex(QtVertexItem *QtVertexItem);

    void adjust();

    enum { Type = UserType + 2 };
    int type() const { return Type; }
    
    void setState(EdgeState state){mState=state;}

    void setTag(EdgeTag tag){mTag = tag;}

    EdgeTag mTag;

    EdgeState mState;
    Graph* mG;

    QGraphicsTextItem* mLabel;
    edge_descriptor mEd;


    void copyTo(GraphWidget* g);

    void disable(){mEnabled=false;setState(disabled_edge);}
    void enable(){mEnabled=true;setState(normal_edge);}

    bool enabled(){return mEnabled;}
    void updateDistance();
protected:
    bool mEnabled;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    
private:
    QtVertexItem *mSourceVertex, *mDestVertex;

    QPointF sourcePoint;
    QPointF destPoint;
    qreal arrowSize;
};

#endif
