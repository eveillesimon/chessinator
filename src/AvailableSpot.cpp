//
// Created by eveil on 24/09/2023.
//

#include "Constants.h"
#include "AvailableSpot.h"


#include <QBrush>

AvailableSpot::AvailableSpot(QPair<int, int> coords ,QGraphicsItem *parent) : QGraphicsItemGroup(parent)
{
    using namespace ChessConstants;
    setAcceptHoverEvents(true);
    m_container = new QGraphicsRectItem( QRectF(
                coords.first * CHESSSQUARE_SIZE,
                coords.second * CHESSSQUARE_SIZE,
                CHESSSQUARE_SIZE,
                CHESSSQUARE_SIZE
            ),
            this);
    auto spotCoords = calculateSpotCoords(coords);
    m_spot = new QGraphicsEllipseItem(
            spotCoords.first,
            spotCoords.second,
            CHESSSQUARE_SIZE * AVAILABLE_SPOT_SCALE,
            CHESSSQUARE_SIZE * AVAILABLE_SPOT_SCALE,
            m_container);

    m_spot->setBrush(QBrush(QColorConstants::Svg::lightslategray));

    addToGroup(m_container);
    addToGroup(m_spot);
}

QPair<int, int> AvailableSpot::calculateSpotCoords(QPair<int, int> coords) {
    using namespace ChessConstants;
    int padding = CHESSSQUARE_SIZE * (1 - AVAILABLE_SPOT_SCALE)/2;
    return QPair<int, int>(
            coords.first * CHESSSQUARE_SIZE + padding,
            coords.second * CHESSSQUARE_SIZE + padding
            );
}

void AvailableSpot::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    m_spot->setBrush(QBrush(QColorConstants::Svg::darkgreen));
    QGraphicsItem::hoverEnterEvent(event);
}


void AvailableSpot::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    m_spot->setBrush(QBrush(QColorConstants::Svg::lightslategray));
    QGraphicsItem::hoverLeaveEvent(event);
}


