#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    setPushButton();

    setToolButton();

    setRadioButton();

    setCheckBox();

    setCommandLinkBtn();

    setDialogBoxBtn();
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setPushButton()
{
    setGeometry(50,50,50,300);
    btn1 = new QPushButton("btn1",this);
    btn2 = new QPushButton("btn2",this);
    //设置btn的位置和大小
    btn1->setGeometry(20,20,100,100);
    btn2->setGeometry(20,150,100,100);
    connect(btn1,&QPushButton::clicked,this,&Widget::setColor1);
    connect(btn2,&QPushButton::clicked,this,&Widget::setColor2);
}

void Widget::setToolButton()
{
    tbar = new QToolBar("toolbar",this);
    tbar->setGeometry(0,0,1000,20);
    QStyle *sty = QApplication::style();
    QIcon icon = sty->standardIcon(QStyle::SP_TitleBarContextHelpButton);
    tbtn = new QToolButton(this);
    tbtn->setIcon(icon);
    tbtn->setIconSize(QSize(10,10));
    tbtn->setText(QString::fromLocal8Bit("tool按钮"));
    tbtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    tbtn->setGeometry(0,0,100,20);
}

void Widget::setRadioButton()
{
    rbtn1 = new QRadioButton(this);
    rbtn1->setText(QString::fromLocal8Bit("动态"));  // 这里不应有换行符

    rbtn2 = new QRadioButton(this);
    rbtn2->setText(QString::fromLocal8Bit("静态"));
    rbtn1->setGeometry(140,100,100,40);
    rbtn2->setGeometry(240,100,100,40);

    rbtn2->setChecked(true);
    timer = new QTimer(this);
    colors = {Qt::red,Qt::blue,Qt::yellow};
    colors_index = 0;
    connect(timer,&QTimer::timeout,this,&Widget::setDynamicColor);
    connect(rbtn1,&QRadioButton::clicked,this,&Widget::handleRationButton);
    connect(rbtn2,&QRadioButton::clicked,this,&Widget::handleRationButton);
}

void Widget::handleRationButton(bool checked)
{
    if(checked)
    {
        QRadioButton* ret = qobject_cast<QRadioButton*>(sender());
        if(ret== rbtn1)
        {
            //动态
            timer->start(800);
        }
        else
        {
            timer->stop();
            setStaticColor();
        }
    }
}

void Widget::setCheckBox()
{
    cbtn = new QCheckBox(QString::fromLocal8Bit("checkbox特性"),this);
    cbtn->setGeometry(200,200,140,40);

    cbtn->setTristate(true);//开启三态模式
    connect(cbtn,&QCheckBox::stateChanged,this,&Widget::setTriStatus);
}

void Widget::setCommandLinkBtn()
{
    cmdbtn = new QCommandLinkButton(QString::fromLocal8Bit("进入Edge"),this);
    cmdbtn->setGeometry(400,200,200,40);
    connect(cmdbtn,&QCommandLinkButton::clicked,this,&Widget::openUrl);
}

void Widget::setDialogBoxBtn()
{
    dbb = new QDialogButtonBox(this);
    dbb->addButton(QString::fromLocal8Bit("确认"),QDialogButtonBox::AcceptRole);
    dbb->addButton(QDialogButtonBox::Cancel)->setText(QString::fromLocal8Bit("取消"));
    dbb->setGeometry(400,300,200,40);

    connect(dbb,&QDialogButtonBox::clicked,this,&Widget::setDialogButtonSlogs);
}

void Widget::setColor1()
{
    this->setStyleSheet("QWidget { background-color: rgba(255,0,0,100%) } ");
}

void Widget::setColor2()
{
    this->setStyleSheet("QWidget { background-color: rgba(0,255,0,100%) } ");
}

void Widget::setDynamicColor()
{
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window,colors[(++colors_index)%colors.size()]);
    this->setPalette(palette);
}

void Widget::setStaticColor()
{
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window,Qt::white);
    this->setPalette(palette);
}

void Widget::setTriStatus(int status)
{
    QCheckBox* ret = qobject_cast<QCheckBox*>(sender());
    switch(status)
    {
        case Qt::Unchecked:
        ret->setText(QString::fromLocal8Bit("未选择"));
            break;
        case Qt::Checked:
            ret->setText(QString::fromLocal8Bit("已选择"));
            break;
        case Qt::PartiallyChecked:
            ret->setText(QString::fromLocal8Bit("正选择中"));
            break;
        default:
            break;
        }
}

void Widget::openUrl()
{
        QDesktopServices::openUrl(QUrl("www.baidu.com"));
}

void Widget::setDialogButtonSlogs(QAbstractButton *button)
{
        if(button == dbb->button(QDialogButtonBox::Cancel))
        {
            qDebug()<<u8"取消";
        }
        else{
            qDebug()<<u8"确认";
        }
}
