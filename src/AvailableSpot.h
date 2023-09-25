//
// Created by eveil on 24/09/2023.
//

#ifndef CHESSINATOR_AVAILABLESPOT_H
#define CHESSINATOR_AVAILABLESPOT_H

#include "ChessPiece.h"

#include <QGraphicsItemGroup>


class AvailableSpot : public QObject, public QGraphicsItemGroup {
    Q_OBJECT
public:
    AvailableSpot(ChessPiece *piece, QPair<int, int> coords, QGraphicsItem *parent = nullptr);

private:
    QGraphicsRectItem *m_container;
    QGraphicsEllipseItem *m_spot;
    ChessPiece *m_piece;
    QPair<int, int> m_coords;

    QPair<int, int> calculateSpotCoords(QPair<int, int> coords);

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};


#endif //CHESSINATOR_AVAILABLESPOT_H
