#include "chesspiece.h"

ChessPiece::ChessPiece(std::string pathToWhiteImage, std::string pathToBlackImage)
    : m_pathToWhiteImage(pathToWhiteImage), m_pathToBlackImage(pathToBlackImage)
{

}

int ChessPiece::x() {
    return m_x;
}
int ChessPiece::y() {
    return m_y;
}
std::string ChessPiece::pathToWhiteImage() {
    return m_pathToWhiteImage;
}
std::string ChessPiece::pathToBlackImage() {
    return m_pathToBlackImage;
}

