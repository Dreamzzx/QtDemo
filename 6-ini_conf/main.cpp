#include "widget.h"

#include <QApplication>

void create_ini()
{
    QSettings*sqlini = new QSettings("mysql",QSettings::IniFormat);
    sqlini->clear();
    sqlini->setValue("Database/ip","127.0.0.1");
    sqlini->setValue("Database/user","root");
    sqlini->setValue("Database/pwd","rootroot");
    sqlini->sync();

    delete sqlini;
}


void  ini_write(){
    QSettings *sqlwr =new QSettings("mysql",QSettings::IniFormat);

    sqlwr->beginGroup("redis");

    sqlwr->setValue("/ip","127.0.0.1");
    sqlwr->setValue("/port","8000");

    sqlwr->endGroup();
    sqlwr->sync(); //因为存储在缓冲区中，使用sync落盘

    delete sqlwr;

}

void read_ini()
{
    QSettings* read = new QSettings("mysql",QSettings::IniFormat);
    QString ip = read->value("Database/ip").toString();
    QString user = read->value("Database/user").toString();
    QString pwd = read->value("Database/pwd").toString();
    qDebug()<<ip<<user<<pwd;
    delete read;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    create_ini();

    read_ini();

    ini_write();
    //Widget w;
    //w.show();
    return a.exec();
}
