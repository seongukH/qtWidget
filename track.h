#ifndef TRACK_H
#define TRACK_H

#include <QGraphicsItem>


class Track : public QGraphicsItem
{
public:
    Track();

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

protected:
    void advance(int step) override;

private:
    qreal angle;
    qreal speed;
    //qreal mouseEyeDirection;
    QColor color;


};

#endif // TRACK_H
