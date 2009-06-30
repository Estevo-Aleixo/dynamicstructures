#ifndef CUSTOMGRAPHICSSCENE_H
#define CUSTOMGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class GraphWidget;
class QtVertexItem;

class CustomGraphicsScene : public QGraphicsScene
{
public:
    CustomGraphicsScene(QObject* parent);

GraphWidget* mParentWidget;


//draw edge tool:
QtVertexItem* node1;
QtVertexItem* node2;


void resetToolMemory()
{
node1=0;
node2=0;
}

void addVertexForEdge(QtVertexItem* v);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CUSTOMGRAPHICSSCENE_H
