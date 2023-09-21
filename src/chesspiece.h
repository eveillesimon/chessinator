#ifndef CHESSPIECE_H
#define CHESSPIECE_H

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


class ChessPiece : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit ChessPiece(bool teamWhite, ChessPieceKind kind, QGraphicsItem *parent = nullptr);

private:
    ChessPieceKind m_kind;
    bool m_teamWhite;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    [[nodiscard]] std::string_view prefix() const;
    [[nodiscard]] std::string_view name() const ;

};

#endif // CHESSPIECE_H
