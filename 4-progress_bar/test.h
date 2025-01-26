#pragma once

#include <QtWidgets/QWidget>
#include "ui_test.h"
#include <QTimer>

class Test : public QWidget
{
    Q_OBJECT

public:
    Test(QWidget *parent = nullptr);
    ~Test();
private slots:
    void on_btn_start_clicked();
    void on_btn_stop_clicked();
private:
    QTimer* timer = nullptr;
private:
    Ui::TestClass ui;
};
