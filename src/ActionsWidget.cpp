#include "ActionsWidget.h"

#include <QVBoxLayout>

ActionWidget::ActionWidget(QWidget *parent)
    : QWidget(parent)
{
    initButtons();

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_move);
    layout->addWidget(m_update);
    layout->setAlignment(Qt::AlignTop);

    setLayout(layout);

    setContentsMargins(QMargins(5, 10, 5, 10));
}

void ActionWidget::initButtons() {
    m_move = new QPushButton("Move");
    m_update = new QPushButton("Update");
}
