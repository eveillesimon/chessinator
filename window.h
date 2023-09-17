#ifndef WINDOW_H
#define WINDOW_H

#include "chessscene.h"

#include <QWidget>
#include <QGraphicsView>

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

private:
    ChessScene *m_chessScene;
    QGraphicsView  *m_graphicsView;
signals:

};

#endif // WINDOW_H
