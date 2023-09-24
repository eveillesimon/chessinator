#include "ChessPiece.h"
#include "Constants.h"

#include <QGraphicsDropShadowEffect>

ChessPiece::ChessPiece(bool teamWhite, ChessPieceKind kind, QGraphicsItem *parent)
 : QGraphicsItemGroup(parent), m_kind(kind), m_teamWhite(teamWhite)
{
    using namespace ChessConstants;
    setAcceptHoverEvents(true);

    m_container = new QGraphicsRectItem( QRectF(
                0,
                0,
                CHESSSQUARE_SIZE,
                CHESSSQUARE_SIZE
            ),
            this);
    m_container->setVisible(true);

    QString fileName = QString();
    fileName.append(prefix()).append(name());
    m_clearImage = QPixmap();
    m_clearImage.load(fileName, IMAGE_FORMAT.data());
    m_clearImage = m_clearImage.scaledToHeight(
        static_cast<int>(CHESSPIECE_HEIGHT_SCALE * CHESSSQUARE_SIZE),
        Qt::SmoothTransformation
    );
    initDarkImage();

    m_graphicsPixmap = new QGraphicsPixmapItem(m_clearImage, m_container);
    placeGPixmap();


    addToGroup(m_container);
    addToGroup(m_graphicsPixmap);
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

void ChessPiece::placeGPixmap() const {
    using namespace ChessConstants;

    int x = CHESSSQUARE_SIZE/2 - m_graphicsPixmap->pixmap().width() / 2;
    int y = CHESSSQUARE_SIZE/2 - m_graphicsPixmap->pixmap().height() / 2;
    m_graphicsPixmap->setPos(x, y);
}

void ChessPiece::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    m_graphicsPixmap->setPixmap(m_darkImage);
    QGraphicsItem::hoverEnterEvent(event);
}


void ChessPiece::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    m_graphicsPixmap->setPixmap(m_clearImage);
    QGraphicsItem::hoverLeaveEvent(event);
}

void ChessPiece::initDarkImage() {
    using namespace ChessConstants;
    QImage image = m_clearImage.toImage();
    for (int x{0}; x < image.width(); x++) {
        for (int y{0}; y < image.height(); y++) {
            QColor color = image.pixelColor(x, y);
            image.setPixelColor(x, y, color.darker(CHESSPIECE_HOVER_EFFECT));
        }
    }
    m_darkImage = QPixmap::fromImage(image);
}


