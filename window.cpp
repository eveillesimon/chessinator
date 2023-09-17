#include "window.h"

#include <QPen>
#include <QBrush>
#include <QGraphicsRectItem>

Window::Window(QWidget *parent)
    : QWidget{parent}
{
    setParent(parent);
    setFixedSize(1920, 1080);

    m_chessScene = new ChessScene(this);

    m_graphicsView = new QGraphicsView(m_chessScene, this);
}

