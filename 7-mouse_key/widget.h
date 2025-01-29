#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QStatusBar>
#include <QMouseEvent>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void mouseMoveEvent(QMouseEvent*e);
    void mousePressEvent(QMouseEvent*e);
    void mouseReleaseEvent(QMouseEvent*e);

    void keyPressEvent(QKeyEvent*e);

    QLabel* status ;
    QLabel* mousePos;
    QLabel* mouseEvent;
    QLabel* keyEvent;

    Ui::Widget *ui;
};
#endif // WIDGET_H
