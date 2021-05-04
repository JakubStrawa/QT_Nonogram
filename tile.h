#ifndef TILE_H
#define TILE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QObject>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QGraphicsEffect>
#include <QGraphicsSceneMouseEvent>



class Tile : public QGraphicsItem
{

public:
    Tile();

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool getIfLeftButtonPressed();
    bool getIfRightButtonPressed();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    bool leftButtonPressed;
    bool rightButtonPressed;
    qreal width;
    qreal height;
};

#endif // TILE_H
