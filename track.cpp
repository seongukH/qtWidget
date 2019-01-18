#include "track.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QRandomGenerator>
#include <QStyleOption>
#include <qmath.h>

const qreal Pi = M_PI;
const qreal TwoPi = 2 * M_PI;

static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}

Track::Track(): angle(0), speed(0),
    color(QRandomGenerator::global()->bounded(256),
          QRandomGenerator::global()->bounded(256),
          QRandomGenerator::global()->bounded(256))
{
    setRotation(QRandomGenerator::global()->bounded(360 * 16));
}

QRectF Track::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}

QPainterPath Track::shape() const
{
    QPainterPath path;
    path.addRect(-10, -20, 20, 20);
    return path;
}

void Track::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QBrush brushRed(Qt::red);

    painter->setBrush(brushRed);
    painter->drawEllipse(-10, -20, 20, 20);
}

void Track::advance(int step)
{
    setPos(mapToParent(0,0));
}





