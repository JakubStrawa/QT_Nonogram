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
    // painting tile with correct color based on button pressed
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
        // tile is enabled and left mouse button is pressed
        if (event->button() == Qt::LeftButton)
        {
            // if tile is blue, change it to white
            if(leftButtonPressed == true) leftButtonPressed = false;
            // if tile is not blue, change it to blue
            else
            {
                leftButtonPressed = true;
                rightButtonPressed = false;
            }
        }
        // tile is enabled and right mouse button is pressed
        else if (event->button() == Qt::RightButton)
        {
            // if tile is red, change it to white
            if(rightButtonPressed == true) rightButtonPressed = false;
            // if tile is not red, change it to red
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
