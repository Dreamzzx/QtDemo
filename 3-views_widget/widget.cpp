#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    glayout = new QGridLayout(this);
    setQListView();

    setQTreeView();

    seQTableView();
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setQListView()
{
    QStringList qls;
    qls.append(u8"xxx:xxx ,xxx ,xxx");
    qls.append(u8"xxx:xxx ,xxx ,xxx");
    qls.append(u8"xxx:xxx ,xxx ,xxx");

    QStringListModel *qslm = new QStringListModel(qls);
    QListView*qlv = new QListView(this);
    qlv->setModel(qslm);
    qlv->setWindowTitle(u8"清单视图控件");

    glayout->addWidget(qlv,0,0);
}

void Widget::setQTreeView()
{
    QTreeView*qtv = new QTreeView(this);
    QStandardItemModel* qsim = new QStandardItemModel(qtv);
    qsim->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("test")<<QStringLiteral("test"));
    qtv->setModel(qsim);

    QList<QStandardItem*>itemSet;
    itemSet.append(new QStandardItem("test1"));
    itemSet.append(new QStandardItem("test2"));
    qsim->appendRow(itemSet);

    QList<QStandardItem*>itemSet1;
    QStandardItem*item1 = new QStandardItem("test");
    QStandardItem*item2 = new QStandardItem("test");
    itemSet1.append(item1);
    itemSet1.append(item2);
    QList<QStandardItem*>itemSet2;
    QStandardItem*item3 = new QStandardItem("test");
    QStandardItem*item4 = new QStandardItem("test");
    itemSet2.append(item3);
    itemSet2.append(item4);
    item1->appendRow(itemSet2);
    qsim->appendRow(itemSet1);

    glayout->addWidget(qtv,0,1,0,1);
}

void Widget::seQTableView()
{
    QTableView* qtv = new QTableView(this);

    QStandardItemModel*qsim = new QStandardItemModel(qtv);
    qtv->setModel(qsim);
    //设置不可修改
    qtv->setEditTriggers(QAbstractItemView::NoEditTriggers);
    qsim->setHorizontalHeaderItem(0,new QStandardItem(u8"ID"));
    qsim->setHorizontalHeaderItem(1,new QStandardItem(u8"姓名"));
    qsim->setHorizontalHeaderItem(2,new QStandardItem(u8"性别"));
    qsim->setHorizontalHeaderItem(3,new QStandardItem(u8"手机号"));

    qsim->setItem(0,0,new QStandardItem("0"));
    qsim->setItem(0,1,new QStandardItem("zz"));
    qsim->setItem(0,2,new QStandardItem("zz"));
    qsim->setItem(0,3,new QStandardItem("zz"));

    qsim->setItem(1,0,new QStandardItem("1"));
    qsim->setItem(1,1,new QStandardItem("xx"));
    qsim->setItem(1,2,new QStandardItem("xx"));
    qsim->setItem(1,3,new QStandardItem("xx"));

    qsim->setItem(2,0,new QStandardItem("2"));
    qsim->setItem(2,1,new QStandardItem("cc"));
    qsim->setItem(2,2,new QStandardItem("cc"));
    qsim->setItem(2,3,new QStandardItem("cc"));

    glayout->addWidget(qtv,1,0);
}

