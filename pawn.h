#ifndef PAWN_H
#define PAWN_H

#include "chesspiece.h"

class Pawn : public ChessPiece
{
    Q_OBJECT
public:
    Pawn(QWidget *parent);
};

#endif // PAWN_H
