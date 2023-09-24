#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "ChessScene.h"

#include <cstdint>
#include <string>
#include <vector>
#include <QGraphicsItem>
#include <QPainter>


enum ChessPieceKind{
    PAWN = 1,
    ROOK = 2,
    KNIGHT = 3,
    BISHOP = 4,
    QUEEN = 5,
    KING = 6
};


class ChessPiece : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    explicit ChessPiece(bool teamWhite, ChessPieceKind kind, QGraphicsItem *parent = nullptr);

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

private:
    QGraphicsPixmapItem *m_graphicsPixmap;
    QPixmap m_clearImage;
    QPixmap m_darkImage;
    QGraphicsRectItem *m_container;
    ChessPieceKind m_kind;
    bool m_teamWhite;

    void initDarkImage();
    void placeGPixmap() const;
    [[nodiscard]] std::string_view prefix() const;
    [[nodiscard]] std::string_view name() const ;

};

#endif // CHESSPIECE_H
