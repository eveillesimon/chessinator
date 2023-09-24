#ifndef CHESSSCENE_H
#define CHESSSCENE_H

#include <QGraphicsScene>

// Hash function def for tuple


class ChessScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit ChessScene(QObject *parent = nullptr);

    void displayMoves(QList<QPair<int, int>> moves);

private:
    void initBoard();
};

#endif // CHESSSCENE_H
