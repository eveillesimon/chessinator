#ifndef CHESSPIECE_H
#define CHESSPIECE_H


#include <cstdint>
#include <string>
#include <vector>
class ChessPiece
{
public:
    ChessPiece(std::string pathToWhiteImage, std::string pathToBlackImage);

    std::string pathToWhiteImage();
    std::string pathToBlackImage();
    int x();
    int y();

    virtual std::vector<std::pair<int, int>> allowedMoves() = 0;

private:
    std::string m_pathToWhiteImage;
    std::string m_pathToBlackImage;
    int m_x;
    int m_y;
    // TODO: should decide what the chessboard data structure will look like, and should add a pointer to it in private args
};

#endif // CHESSPIECE_H
