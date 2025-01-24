#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QPushButton>
#include <QCheckBox>
#include <QMenu>
#include <QList>
#include <QScrollArea>
#include <QLabel>
#include <QDebug>
#include <QDir>
#include <QTableWidget>
#include <QLineEdit>
#include <QFrame>
#include <QDockWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    //分组容器
    void setQGroup();
    //滑动条容器
    void setScrollArea();
    //表单容器
    void setWidget();
    //边框容器 主要对边框进行操作，比如UI程序的重影等
    void setFrame();
    //固定可拖拽窗口
    void setQdockWidge();

private:

    QGridLayout* glayout;

    Ui::Widget *ui;
};
#endif // WIDGET_H
