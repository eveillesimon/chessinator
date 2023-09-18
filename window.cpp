#include "window.h"

#include <QPen>
#include <QBrush>
#include <QGraphicsRectItem>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDockWidget>

Window::Window(QWidget *parent)
    : QMainWindow{parent}
{

    setParent(parent);
    setFixedSize(1920, 1080);

    m_chessScene = new ChessScene(this);

    m_graphicsView = new QGraphicsView(m_chessScene, this);
    setCentralWidget(m_graphicsView);


    m_dock = new QDockWidget("Actions");
    m_action = new ActionWidget(m_dock);
    m_dock->setWidget(m_action);
    m_dock->show();
    addDockWidget(Qt::LeftDockWidgetArea ,m_dock);
}

