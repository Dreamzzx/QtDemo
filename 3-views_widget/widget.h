#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStringList>
#include <QGridLayout>
#include <QStringListModel>
#include <QListView>
#include <QTreeView>
#include <QStandardItemModel>
#include <QTableView>
#include <QListWidget>
#include <QTreeWidget>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //清单视图
    void setQListView();
    //树视图
    void setQTreeView();
    //表单视图
    void setQTableView();

    //清单控件
    void setQListWidget();
    //树控件
    void setQTreeWidget();
    //表单控件
    void setQTableWidget();
private:
    QGridLayout*glayout;
    Ui::Widget *ui;
};
#endif // WIDGET_H
