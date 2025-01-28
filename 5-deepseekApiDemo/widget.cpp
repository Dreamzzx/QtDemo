#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    QScrollArea *scroll = new QScrollArea(this);
    scroll->setWidgetResizable(true);
    scroll->setGeometry(100,100,500,500);
    manager = new QNetworkAccessManager(this);
    lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(0,0,400,40);


    QPushButton*btn = new QPushButton("submit",this);
    btn->setGeometry(420,0,60,40);
    showmsg = new QLabel(this);
    showmsg->setWordWrap(true);
    showmsg->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    showmsg->setGeometry(50,50,400,400);
    showmsg->setStyleSheet("QLabel{ background-color:white;}");
    scroll->setWidget(showmsg);

    connect(btn,&QPushButton::clicked,this,&Widget::deepseek);
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::deepseek()
{

    if(lineEdit->text() == "")
    {
        QMessageBox::warning(this,u8"提示",u8"请输入信息");
        return;
    }
    //showmsg->clear();
    QUrl url("https://api.deepseek.com/chat/completions");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", "Bearer <API key>"); // 替换为你的 API Key

    // 构建请求体
    QJsonObject jsonBody;
    jsonBody["model"] = "deepseek-chat";
    jsonBody["stream"] = false;

    QJsonArray messages;
    QJsonObject systemMessage;
    systemMessage["role"] = "system";
    systemMessage["content"] = "You are a helpful assistant.";
    messages.append(systemMessage);

    QJsonObject userMessage;
    userMessage["role"] = "user";
    userMessage["content"] = lineEdit->text();
    messages.append(userMessage);

    jsonBody["messages"] = messages;

    QJsonDocument doc(jsonBody);
    QByteArray data = doc.toJson();

    // 发送 POST 请求
    reply = manager->post(request, data);

    // 连接信号槽，处理响应
    connect(reply, &QNetworkReply::finished, [&]() {
        if (reply->error() == QNetworkReply::NoError) {
            // 读取响应数据
            qDebug()<<"2";
            QByteArray responseData = reply->readAll();
            QJsonDocument responseDoc = QJsonDocument::fromJson(responseData);
            QJsonObject responseObj = responseDoc.object();

            // 打印响应内容
            if(responseObj.contains("choices"))
            {
                QJsonArray choices = responseObj["choices"].toArray();
                if(!choices.isEmpty())
                {
                    QJsonObject firstChoice = choices[0].toObject();
                    qDebug()<<firstChoice;
                    QJsonObject message = firstChoice["message"].toObject();
                    qDebug()<<message;
                    QString text = message["content"].toString();
                    qDebug()<<text;
                    showmsg->setText(text);
                }
            }
            //showmsg->setText(responseObj);
            qDebug() << "Response:" << responseObj;
        } else {
            // 打印错误信息
            qDebug() << "Error:" << reply->errorString();
        }
        // 释放资源
        reply->deleteLater();
    });
}

