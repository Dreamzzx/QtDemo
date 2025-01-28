#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrl>
#include <QDebug>
#include <qlabel.h>
#include <QLineEdit>
#include <QMessageBox>
#include <QScrollArea>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void deepseek();

    QNetworkAccessManager* manager;
private:

    QNetworkReply *reply ;
    QLabel *showmsg;
    QLineEdit*lineEdit;
    Ui::Widget *ui;
};
#endif // WIDGET_H
