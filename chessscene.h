#ifndef CHESSSCENE_H
#define CHESSSCENE_H

#include <QGraphicsScene>

class ChessScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit ChessScene(QObject *parent = nullptr);
};

#endif // CHESSSCENE_H
