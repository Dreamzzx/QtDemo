#include "mainwindow.h"

#include <QApplication>
#include "log.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Log::instance()->open("./test.log");
    //Log::instance()->log(Log::DEBUG,__FILE__,__LINE__,"test");
    debug("dd");
    Log::instance()->close();
    return 0;
    // MainWindow w;
    //w.show();
    //return a.exec();
}
