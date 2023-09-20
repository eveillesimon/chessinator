#ifndef PAWN_H
#define PAWN_H

#include "chesspiece.h"

class Pawn : public ChessPiece
{
    Q_OBJECT
public:
    Pawn(bool isWhite, QWidget *parent);

private:
    static constexpr std::string_view W = "";
};

#endif // PAWN_H
