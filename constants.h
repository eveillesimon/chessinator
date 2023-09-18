#ifndef CONSTANTS_H
#define CONSTANTS_H

#include<QColor>


namespace ChessConstants {
    inline constexpr int CHESSBOARD_SIZE{8};            // Usual chessboard is 8 by 8
    inline constexpr int CHESSSQUARE_SIZE{72};          // Value in px
    inline constexpr bool FIRST_SQUARE_IS_WHITE{1};     // whether or not top left square is white
    inline constexpr QColor WHITE_SQUARE_COLOR{
        QColorConstants::Svg::lemonchiffon
    };
    inline constexpr QColor BLACK_SQUARE_COLOR{
        QColorConstants::Svg::maroon
    };
}

#endif // CONSTANTS_H
