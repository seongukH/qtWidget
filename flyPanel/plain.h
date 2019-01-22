#ifndef PLAIN_H
#define PLAIN_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QRandomGenerator>
#include <QStyleOption>
#include <qmath.h>
#include <QKeyEvent>

class Plain : public QGraphicsItem
{
public:
    Plain();

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

protected:
    void advance(int step) override;

private:
    qreal angle;
    qreal speed;
};

#endif // PLAIN_H
