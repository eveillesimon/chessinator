//
// Created by eveil on 24/09/2023.
//

#ifndef CHESSINATOR_BOARDPOSITION_H
#define CHESSINATOR_BOARDPOSITION_H


#include <cstdint>

class BoardPosition {

private:
    uint_fast64_t wPawns;
    uint_fast64_t wRooks;
    uint_fast64_t wKnights;
    uint_fast64_t wBishops;
    uint_fast64_t wQueens;
    uint_fast64_t wKings;
    uint_fast64_t bPawns;
    uint_fast64_t bRooks;
    uint_fast64_t bKnights;
    uint_fast64_t bBishops;
    uint_fast64_t bQueens;
    uint_fast64_t bKings;

};


#endif //CHESSINATOR_BOARDPOSITION_H
