#include "tile.h"

Tile::Tile()
{
    leftButtonPressed = false;
    rightButtonPressed = false;
    isTileEnabled = true;
    width = 30;
    height = 30;
}

QRectF Tile::boundingRect() const
{
    return QRectF(0,0,width,height);
}

void Tile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::white);
    if(rightButtonPressed == true)
    {
        brush.setColor(Qt::red);
    }
    else if(leftButtonPressed == true)
    {
        brush.setColor(Qt::blue);
    }
    else
    {
        brush.setColor(Qt::white);
    }
    painter->fillRect(rec, brush);
    painter->drawRect(rec);
}

bool Tile::getIfLeftButtonPressed()
{
    return leftButtonPressed;
}

bool Tile::getIfRightButtonPressed()
{
    return rightButtonPressed;
}

void Tile::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (isTileEnabled)
    {
        if (event->button() == Qt::LeftButton)
        {
            if(leftButtonPressed == true) leftButtonPressed = false;
            else
            {
                leftButtonPressed = true;
                rightButtonPressed = false;
            }
        }
        else if (event->button() == Qt::RightButton)
        {
            if(rightButtonPressed == true) rightButtonPressed = false;
            else
            {
                rightButtonPressed = true;
                leftButtonPressed = false;
            }
        }

        update();
        QGraphicsItem::mousePressEvent(event);
    }

}

void Tile::setIsTileEnabled(bool value)
{
    isTileEnabled = value;
}
