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

    ChessPiece *piece = new ChessPiece(true, ChessPieceKind::PAWN);

    addItem(piece);
    piece->setPos(CHESSSQUARE_SIZE/2, CHESSSQUARE_SIZE/2);


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
