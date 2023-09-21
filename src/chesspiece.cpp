#include "chesspiece.h"
#include "constants.h"

ChessPiece::ChessPiece(bool teamWhite, ChessPieceKind kind, QGraphicsItem *parent)
 : QGraphicsPixmapItem(parent), m_kind(kind),m_teamWhite(teamWhite)
{
    using namespace ChessConstants;

    QString fileName = QString();
    fileName.append(prefix()).append(name());

    QPixmap pmap = QPixmap();
    pmap.load(fileName, "PNG");

    pmap = pmap.scaledToHeight(
        static_cast<int>(CHESSPIECE_HEIGHT_SCALE * CHESSSQUARE_SIZE),
        Qt::SmoothTransformation
    );
    setPixmap(pmap);
}


std::string_view ChessPiece::prefix() const {
    using namespace ChessConstants;
    return m_teamWhite ? WHITE_PREFIX : BLACK_PREFIX;
}

std::string_view ChessPiece::name() const{
    switch (m_kind){
        case ROOK:
            return ChessConstants::ROOK;
        case KNIGHT:
            return ChessConstants::KNIGHT;
        case BISHOP:
            return ChessConstants::BISHOP;
        case QUEEN:
            return ChessConstants::QUEEN;
        case KING:
            return ChessConstants::KING;
        default:
        case PAWN:
            return ChessConstants::PAWN;
    }
}

void ChessPiece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QSize size = pixmap().size();
    painter->translate(-size.width()/2, -size.height()/2);
    QGraphicsPixmapItem::paint(painter, option, widget);
}