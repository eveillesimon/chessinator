#ifndef CHESSPIECE_H
#define CHESSPIECE_H


#include <QAbstractButton>
#include <cstdint>
#include <string>
#include <vector>
class ChessPiece : public QAbstractButton
{
    Q_OBJECT
public:
    ChessPiece(QWidget *parent);

private:
    QPixmap *m_pixmap;

    std::string_view getImagePath();
};

#endif // CHESSPIECE_H
