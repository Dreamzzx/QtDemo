#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QToolButton>
#include <QToolBar>
#include <QStyle>
#include <QRadioButton>
#include <QTimer>
#include <QVector>
#include <QCheckBox>
#include <QCommandLinkButton>
#include <QDesktopServices>
#include <QUrl>
#include <QDialogButtonBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void setPushButton();

    void setToolButton();

    void setRadioButton();

    void handleRationButton(bool checked);

    void setCheckBox();

    void setCommandLinkBtn();

    void setDialogBoxBtn();
private:
    void setColor1();
    void setColor2();

    void setDynamicColor();
    void setStaticColor();

    void setTriStatus(int status);

    void openUrl();

    void handleDialogBox();

    void setDialogButtonSlogs(QAbstractButton *button);

    Ui::Widget *ui;
    QPushButton* btn1;
    QPushButton* btn2;

    QToolBar* tbar;
    QToolButton* tbtn;

    QRadioButton* rbtn1;
    QRadioButton* rbtn2;

    QTimer* timer;
    QVector<QColor> colors;
    int colors_index;

    QCheckBox * cbtn;

    QCommandLinkButton* cmdbtn;

    QDialogButtonBox* dbb;
};
#endif // WIDGET_H
