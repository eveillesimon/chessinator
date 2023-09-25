#ifndef CHESSSCENE_H
#define CHESSSCENE_H

#include "ChessPiece.h"
#include "AvailableSpot.h"

#include <QGraphicsScene>

class ChessScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit ChessScene(QObject *parent = nullptr);

    void showAvailableSpots(ChessPiece *piece, QList<QPair<int, int>> moves);
    void clearAvailableSpots();

private:
    QList<AvailableSpot> m_availableSpots;

    void initBoard();
    void initPieces();
};

#endif // CHESSSCENE_H
