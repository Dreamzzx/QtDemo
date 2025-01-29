#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    status = new QLabel(this);
    mousePos = new QLabel(this);
    mouseEvent = new QLabel(this);
    keyEvent = new QLabel(this);
    status->setText(u8"鼠标当前位置：");
    status->setFixedWidth(200);

    mousePos->setText("");
    mousePos->setFixedWidth(200);

    QStatusBar * statusBar = new QStatusBar(this);
    statusBar->addPermanentWidget(status);
    statusBar->addPermanentWidget(mousePos);
    statusBar->addPermanentWidget(mouseEvent);
    statusBar->addPermanentWidget(keyEvent);

    this->setMouseTracking(true);

    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{
    mousePos->setText("("+QString::number(e->x())+","+QString::number(e->y())+")");
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
    {
        mouseEvent->setText(u8"用户按下左键");
    }
    else if(e->button() == Qt::RightButton)
    {

        mouseEvent->setText(u8"用户按下右键");
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *e)
{
    mouseEvent->setText(u8"用户松开按键");
}

void Widget::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Left)
    {
        keyEvent->setText(u8"按下左键");
    }
    else if(e->key() == Qt::Key_K)
    {
        keyEvent->setText(u8"按下K键");
    }
}

