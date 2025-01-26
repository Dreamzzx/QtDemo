#include "test.h"

Test::Test(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    QString qss = R"(QProgressBar{
                        border-radius: 10px;   
                        border:none;
                        text-align:center;  
                        background-color:#FFFFFF;
                        }
                     QProgressBar::chunk{
                        border-radius:10px;
                        background-color:#00FF00;
                                })";
    ui.progressBar->setStyleSheet(qss);
    timer = new QTimer(this);

    ui.progressBar->setValue(0);
    ui.progressBar->setRange(0, 100);  
    connect(timer, &QTimer::timeout, [=] {
        static int step = 0;
        ui.progressBar->setValue(++step);
        });
}

Test::~Test()
{}

void Test::on_btn_start_clicked()
{
    timer->start(50);
}

void Test::on_btn_stop_clicked()
{
    timer->stop();
}
