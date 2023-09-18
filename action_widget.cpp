#include "action_widget.h"

#include <QVBoxLayout>

ActionWidget::ActionWidget(QWidget *parent)
    : QWidget{parent}
{
    setParent(parent);

    initButtons();

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_move);
    layout->addWidget(m_update);

    setLayout(layout);

    setContentsMargins(QMargins(5, 10, 5, 10));
}

void ActionWidget::initButtons() {
    m_move = new QPushButton("Move");
    m_update = new QPushButton("Update");
}
