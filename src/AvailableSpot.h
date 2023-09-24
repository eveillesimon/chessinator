//
// Created by eveil on 24/09/2023.
//

#ifndef CHESSINATOR_AVAILABLESPOT_H
#define CHESSINATOR_AVAILABLESPOT_H

#include <QGraphicsItemGroup>

class AvailableSpot : public QObject, public QGraphicsItemGroup {
    Q_OBJECT
public:
    AvailableSpot(QPair<int, int> coords, QGraphicsItem *parent = nullptr);

private:
    QGraphicsRectItem *m_container;
    QGraphicsEllipseItem *m_spot;

    QPair<int, int> calculateSpotCoords(QPair<int, int> coords);

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
};


#endif //CHESSINATOR_AVAILABLESPOT_H
