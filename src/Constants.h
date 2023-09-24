#ifndef CONSTANTS_H
#define CONSTANTS_H

#include<QColor>


namespace ChessConstants {
    inline constexpr int CHESSBOARD_SIZE{8};                // Usual chessboard is 8 by 8
    inline constexpr int CHESSSQUARE_SIZE{100};             // Value in px
    inline constexpr float CHESSPIECE_HEIGHT_SCALE{0.75f};  // Between 0 and 1
    inline constexpr float AVAILABLE_SPOT_SCALE{0.3f};      // Between 0 and 1
    inline constexpr int CHESSPIECE_HOVER_EFFECT{150};     // Darkening scale between 100 and +inf : 100 is no darkening
    inline constexpr bool FIRST_SQUARE_IS_WHITE{1};         // Whether or not top left square is white

    // Color settings
    inline constexpr QColor WHITE_SQUARE_COLOR{
        QColorConstants::Svg::lemonchiffon
    };
    inline constexpr QColor BLACK_SQUARE_COLOR{
        QColorConstants::Svg::maroon
    };
    inline constexpr QColor AVAILABLE_SPOT_COLOR{
        QColorConstants::Svg::gainsboro
    };
    inline constexpr QColor AVAILABLE_SPOT_HOVER_COLOR{
        QColorConstants::Svg::forestgreen
    };


    // Pieces' image location
    inline constexpr std::string_view IMAGE_FORMAT{"PNG"};
    inline constexpr std::string_view WHITE_PREFIX{":/w_"};
    inline constexpr std::string_view BLACK_PREFIX{":/b_"};
    inline constexpr std::string_view PAWN{"pawn"};
    inline constexpr std::string_view ROOK{"rook"};
    inline constexpr std::string_view KNIGHT{"knight"};
    inline constexpr std::string_view BISHOP{"bishop"};
    inline constexpr std::string_view QUEEN{"queen"};
    inline constexpr std::string_view KING{"king"};

}

#endif // CONSTANTS_H
