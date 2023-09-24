#ifndef WINDOW_H
#define WINDOW_H

#include "ChessScene.h"
#include "ActionsWidget.h"

#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>

class Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

private:
    ChessScene *m_chessScene;
    QGraphicsView *m_graphicsView;
    ActionWidget *m_action;
    QDockWidget *m_dock;

    void initView();
    void initDock();
signals:

};

#endif // WINDOW_H
