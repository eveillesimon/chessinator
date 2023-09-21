#include "chessscene.h"
#include "constants.h"
#include "chesspiece.h"

#include <QPainterPath>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPushButton>
#include <QDir>

ChessScene::ChessScene(QObject *parent)
    : QGraphicsScene{parent}
{

    using namespace ChessConstants;
    initBoard();

    auto *piece = new ChessPiece(true, ChessPieceKind::PAWN);
    auto *piece2 = new ChessPiece(false, ChessPieceKind::QUEEN);

    addItem(piece2);
    addItem(piece);
    piece->setPos( CHESSSQUARE_SIZE*5/2, CHESSSQUARE_SIZE*7/2);
    piece2->setPos( CHESSSQUARE_SIZE*13/2, CHESSSQUARE_SIZE*9/2);


}

void ChessScene::initBoard() {
    using namespace ChessConstants;
    setSceneRect(QRectF(
        0,
        0,
        CHESSBOARD_SIZE * CHESSSQUARE_SIZE,
        CHESSBOARD_SIZE * CHESSSQUARE_SIZE
        ));

    QPointF nextPosition = QPointF(0, 0);
    QSizeF squareSize = QSize(CHESSSQUARE_SIZE, CHESSSQUARE_SIZE);

    QBrush whiteBrush = QBrush(WHITE_SQUARE_COLOR);
    QBrush blackBrush = QBrush(BLACK_SQUARE_COLOR);

    bool firstIsWhite{FIRST_SQUARE_IS_WHITE};
    bool nextIsWhite{};

    QPointF uX = QPointF(CHESSSQUARE_SIZE , 0);
    QPointF uY = uX.transposed();

    for(int i{0}; i < CHESSBOARD_SIZE; i++) {

        QGraphicsRectItem *gFirstRect = new QGraphicsRectItem(QRectF(nextPosition, squareSize));
        gFirstRect->setBrush(firstIsWhite ? whiteBrush : blackBrush);
        nextIsWhite = !firstIsWhite;
        addItem(gFirstRect);
        QPointF nextPositionInLine = QPointF(nextPosition + uX);

        for(int j{0}; j < CHESSBOARD_SIZE - 1; j++) {
            QGraphicsRectItem *gNextRect = new QGraphicsRectItem(QRectF(nextPositionInLine, squareSize));
            gNextRect->setBrush(nextIsWhite ? whiteBrush : blackBrush);
            addItem(gNextRect);

            nextIsWhite = !nextIsWhite;
            nextPositionInLine += uX;
        }


        firstIsWhite = !firstIsWhite;
        nextPosition += uY;
    }
}
