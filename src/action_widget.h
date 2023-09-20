#ifndef ACTIONWIDGET_H
#define ACTIONWIDGET_H

#include <QWidget>
#include <QPushButton>

class ActionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ActionWidget(QWidget *parent = nullptr);

private:
    QPushButton *m_move{};
    QPushButton *m_update{};

    void initButtons();

signals:

};

#endif // ACTIONWIDGET_H
