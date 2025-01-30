#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    glayout = new QGridLayout(this);
    setComboBox();
    setFontBox();
    setLineEdit();
    setSpinbox();
    this->setLayout(glayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setComboBox()
{
    QComboBox* qCbox = new QComboBox(this);
    qCbox->addItem("test1");
    qCbox->addItem("test2");
    qCbox->addItem("test3");
    qCbox->addItem("test4");
    qCbox->setCurrentIndex(0);
    qCbox->setEnabled(true);

    connect(qCbox,QOverload<int>::of(&QComboBox::currentIndexChanged),[](int index){
        qDebug()<<"changed"<<index;
    });
    glayout->addWidget(qCbox,0,0);
}

void MainWindow::setFontBox()
{
    QFontComboBox*qfcbox = new QFontComboBox(this);
    qfcbox->setGeometry(50,50,100,20);
    QLabel*label = new QLabel("hello world",this);
    label->setGeometry(100,100,200,50);
    connect(qfcbox,&QFontComboBox::currentFontChanged,this,[label](const QFont &f){
        label->setFont(f);
    });
    glayout->addWidget(qfcbox,1,1);
}

void MainWindow::setLineEdit(){

    QLineEdit* line = new QLineEdit(u8"账号",this);
    line->setGeometry(300,300,100,30);
    QPushButton* pb = new QPushButton(this);
    pb->setGeometry(400,300,40,40);
    QLabel* lb = new QLabel(this);
    lb->setGeometry(400,400,60,60);
    pb->setText(u8"确认");
    lb->setText(u8"请输入");
    //点击事件clicked   单复选 click
    QObject::connect(pb,&QPushButton::clicked,this,[line,lb](){
        lb->setText(line->text());
    });


}

void MainWindow::setSpinbox() {
    QSpinBox* spinbox = new QSpinBox(this);
    spinbox->setGeometry(200, 10, 90, 50);
    //this->setStyleSheet("QMainWindow{background-color:""rgba(250,220,120,100%)}"); // 设置初始透明度为50%
    //数值范围为 0 到 100
    spinbox->setRange(0, 100);
    //步长为 5
    spinbox->setSingleStep(15);
    //初始值为 50
    spinbox->setValue(50);
    //添加前缀和后缀
    spinbox->setPrefix(u8"透明度：");
    spinbox->setSuffix("%");

    connect(spinbox, QOverload<int>::of(&QSpinBox::valueChanged), this, [this](int value) {
        this->setStyleSheet(QString("QMainWindow{background-color:rgba(250,220,120,%1%);}").arg(value));
    });
}
void MainWindow::setDateEdit(){
    QDateEdit * date = new QDateEdit(this);
    QTimeEdit* timeEdit = new QTimeEdit(this);
    QDateTimeEdit* dateTimeEdit = new QDateTimeEdit(QDateTime::currentDateTime(),this);


    dateTimeEdit->setDisplayFormat("yyyy-MM-dd hh:mm:ss");

    date->setGeometry(200, 150, 190, 20);
    timeEdit->setGeometry(200, 170, 190, 20);
    dateTimeEdit->setGeometry(200, 190, 190, 20);
}

