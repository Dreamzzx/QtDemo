#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    glayout = new QGridLayout(this);
    setQListView();

    setQTreeView();

    setQTableView();

    setQListWidget();

    setQTreeWidget();

    setQTableWidget();
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

void Widget::setQTableView()
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

void Widget::setQListWidget()
{
    QListWidget* qlw = new QListWidget(this);
    QListWidgetItem* qlwi = new QListWidgetItem("test",qlw);
    qlwi->setTextAlignment(Qt::AlignVCenter|Qt::AlignCenter);

    qlw->addItem(qlwi);
    qlw->addItem("test\n \
                  test\n \
                 ");
    glayout->addWidget(qlw,1,1);
}

void Widget::setQTreeWidget()
{
    QTreeWidget* qtw = new QTreeWidget(this);
    QTreeWidgetItem*qtwi1 = new QTreeWidgetItem(qtw);
    qtwi1->setText(0,"test1");
    QTreeWidgetItem*qtwi2 = new QTreeWidgetItem(qtw);
    qtwi2->setText(0,"test2");

    QTreeWidgetItem*qtwi11 = new QTreeWidgetItem(qtwi1);
    qtwi11->setText(0,"test");

    qtw->setHeaderHidden(true);
    glayout->addWidget(qtw,2,0);
}

void Widget::setQTableWidget()
{
    QTableWidget*qtw = new QTableWidget(this);
    qtw->setColumnCount(3);
    qtw->setRowCount(3);
    qtw->setEditTriggers(false);

    qtw->setHorizontalHeaderItem(0,new QTableWidgetItem("ID"));
    qtw->setHorizontalHeaderItem(1,new QTableWidgetItem("test1"));
    qtw->setHorizontalHeaderItem(2,new QTableWidgetItem("test2"));

    qtw->setItem(0,0,new QTableWidgetItem("0"));
    qtw->setItem(0,1,new QTableWidgetItem("zz"));
    qtw->setItem(0,2,new QTableWidgetItem("zz"));

    qtw->setItem(1,0,new QTableWidgetItem("1"));
    qtw->setItem(1,1,new QTableWidgetItem("xx"));
    qtw->setItem(1,2,new QTableWidgetItem("xx"));

    qtw->setItem(2,0,new QTableWidgetItem("2"));
    qtw->setItem(2,1,new QTableWidgetItem("cc"));
    qtw->setItem(2,2,new QTableWidgetItem("cc"));
    //qtwi.setText("");
    //qtw->setItem(0,0,qtwi);
    glayout->addWidget(qtw,2,1);
}
