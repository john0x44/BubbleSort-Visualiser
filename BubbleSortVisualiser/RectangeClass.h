#ifndef RECTANGECLASS_H
#define RECTANGECLASS_H
/*
    Name: RectangleClass
    Copyright: 2023
    Author: John
    Date: 22/06/23 16:31
    Description: Implementing Rectangle object class
*/
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

// Class rectangle
class Rect {
    QGraphicsRectItem* rect;
public:
    int getX() { return rect->pos().x(); }
    int getY() { return rect->pos().y(); }
    int getYH() { return rect->rect().height(); }
    int getXH() { return rect->rect().width(); }
    void setPos(int x, int y) {
        rect->setPos(x, y);
    }
    Rect(QGraphicsRectItem* item) : rect(item) {}

    // Overload the assignment operator
    Rect& operator=(const Rect& other) {
        if (this != &other) {
            rect = other.rect;
        }
        return *this;
    }
};

#endif
