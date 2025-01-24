#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    setQGroup();

    setScrollArea();

    setWidget();

    setFrame();

    setQdockWidge();
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setQGroup()
{
    //1
    QGroupBox* gbox1 = new QGroupBox(u8"1组",this);
    QRadioButton*rb1= new QRadioButton(u8"单选项1",this);
    QRadioButton*rb2= new QRadioButton(u8"单选项1",this);

    QVBoxLayout* vlayout1 = new QVBoxLayout(this);
    vlayout1->addWidget(rb1);
    vlayout1->addWidget(rb2);
    gbox1->setLayout(vlayout1);

    //2
    QGroupBox*gbox2 = new QGroupBox(u8"2组",this);
    QCheckBox*cb1 = new QCheckBox(u8"多选1",this);
    QCheckBox*cb2 = new QCheckBox(u8"多选2",this);

    QVBoxLayout* vlayout2 = new QVBoxLayout(this);
    vlayout2->addWidget(cb1);
    vlayout2->addWidget(cb2);
    gbox2->setLayout(vlayout2);

    //3
    QGroupBox*gbox3 = new QGroupBox(u8"3组",this);
    gbox3->setCheckable(true);
    QCheckBox*cb3 = new QCheckBox(u8"多选3",this);
    QCheckBox*cb4 = new QCheckBox(u8"多选3",this);
    cb4->setTristate(true);
    QRadioButton*rb3 = new QRadioButton(u8"单选3",this);
    QVBoxLayout *vlayout3 = new QVBoxLayout(this);
    vlayout3->addWidget(cb3);
    vlayout3->addWidget(cb4);
    vlayout3->addWidget(rb3);
    gbox3->setLayout(vlayout3);

    //4
    QGroupBox*gbox4 = new QGroupBox(u8"4组",this);
    QPushButton*btn = new QPushButton(u8"菜单",this);
    QVBoxLayout* vlayout4 = new QVBoxLayout(this);
    vlayout4->addWidget(btn);
    QMenu*menu = new QMenu(this);
    menu->addAction(u8"选项1");
    menu->addAction(u8"选项2");
    menu->addAction(u8"选项3");

    QList<QAction*>actions = menu->actions();
    QAction*retaction = nullptr;
    for(auto ret:actions)
    {
        if(ret->text() == u8"选项1")
        {
            retaction = ret;
            break;
        }
    }

    QMenu*menu1 = new QMenu(this);
    menu1->addAction(u8"子选项1");
    retaction->setMenu(menu1);

    btn->setMenu(menu);
    gbox4->setLayout(vlayout4);


    glayout = new QGridLayout(this);
    glayout->addWidget(gbox1,0,0);
    glayout->addWidget(gbox2,0,1);
    glayout->addWidget(gbox3,1,0);
    glayout->addWidget(gbox4,1,1);


    setLayout(glayout);
}

void Widget::setScrollArea()
{
    QImage*img = new QImage("../2-containers/test.png");
    QLabel*lb = new QLabel(this);

    lb->setScaledContents(true);
    lb->setPixmap(QPixmap::fromImage(*img));
    lb->setFixedSize(600,800);

    QScrollArea*scroll = new QScrollArea(this);
    scroll->setWidget(lb);
    //设置居中
    scroll->setAlignment(Qt::AlignCenter);
    //设置水平和垂直滚动条
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //设置自动调节大小
    scroll->setWidgetResizable(true);

    glayout->addWidget(scroll,0,2,2,1);
}

void Widget::setWidget()
{
    QTabWidget*twg = new QTabWidget(this);
    QWidget*widget1 = new QWidget(this);
    twg->addTab(widget1,u8"窗口1");
    QLabel*lb1 = new QLabel(u8"输入信息",this);
    QLineEdit*le1 = new QLineEdit(this);
    QPushButton*btn1 = new QPushButton(u8"提交",this);

    QGridLayout* glayout1 = new QGridLayout(this);
    glayout1->addWidget(lb1,0,0);
    glayout1->addWidget(le1,0,1);
    glayout1->addWidget(btn1,0,2);

    widget1->setLayout(glayout1);

    QWidget*widget2 = new QWidget(this);
    twg->addTab(widget2,u8"窗口2");
    QLabel*lb2 = new QLabel(u8"输入信息",this);
    QLineEdit*le2 = new QLineEdit(this);
    QPushButton*btn2 = new QPushButton(u8"提交",this);

    QGridLayout* glayout2 = new QGridLayout(this);
    glayout2->addWidget(lb2,0,0);
    glayout2->addWidget(le2,0,1);
    glayout2->addWidget(btn2,0,2);

    widget2->setLayout(glayout2);

    glayout->addWidget(twg,3,0,3,3);
}

void Widget::setFrame()
{
    QFrame*frame = new QFrame(this);
    QHBoxLayout*hbox = new QHBoxLayout(frame);
    QPushButton*btn1 = new QPushButton(u8"选项1",frame);
    QPushButton*btn2 = new QPushButton(u8"选项2",frame);
    hbox->addWidget(btn1);
    hbox->addWidget(btn2);
    //设置线宽
    frame->setLineWidth(3);
    //设置边框类型
    frame->setFrameStyle(QFrame::StyledPanel);

    QFrame * frame2 = new QFrame(this);

    //设置框架的阴影。阴影可以是Plain、Raised、Sunken
    frame2->setFrameShadow(QFrame::Sunken);
    //设置线宽
    frame2->setLineWidth(2);
    //设置框架的样式。样式是形状和阴影的位或（OR）组合
    frame2->setFrameStyle(QFrame::Panel | QFrame::Raised);
    //设置大小策略，这决定了控件如何在布局中改变大小
    frame2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //设置样式表，这可以用来自定义控件的外观
    //fram2->setStyleSheet("background-color: blue;");

    glayout->addWidget(frame,0,3);
    glayout->addWidget(frame2,3,3);
}

void Widget::setQdockWidge()
{
    QDockWidget*dockwidget = new QDockWidget(this);
    QLabel*lb = new QLabel(u8"拖动窗口",dockwidget);
    //dockwidget->setFloating(true);
    dockwidget->setWidget(lb);
    glayout->addWidget(dockwidget,4,0,4,4);
}

