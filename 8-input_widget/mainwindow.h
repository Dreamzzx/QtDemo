#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QDebug>
#include <QGridLayout>
#include <QFontComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QPushButton>
#include <QSpinBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setComboBox();
    void setFontBox();
    void setLineEdit();
    void setDateEdit();

    void setSpinbox();

private:
    Ui::MainWindow *ui;
    QGridLayout * glayout;
};
#endif // MAINWINDOW_H
