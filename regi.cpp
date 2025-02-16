#include "regi.h"
#include "ui_regi.h"
#include <QCryptographicHash>
#include <QMovie>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDebug>

regi::regi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::regi)
{
    ui->setupUi(this);
    //去掉边框
    setWindowFlag(Qt::WindowType::FramelessWindowHint);
    //背景透明
    setAttribute(Qt::WA_TranslucentBackground);

    QMovie *movie = new QMovie(this);//用来播放gif
    movie->setFileName(":/rebg.gif");

    ui->backgrond->setMovie(movie);
    movie->start();//播放
}

regi::~regi()
{
    delete ui;
}

void regi::on_retbt_clicked()
{
    this->hide();
}

void regi::on_pushButton_clicked()
{
    this->hide();
}

void regi::on_resbt_clicked()
{
    this->hide();
}

void regi::on_regbt_clicked()
{

    //创建一个数据库表模型
    QSqlTableModel model;  //自动关联到默认的数据库
    model.setTable("business");//绑定数据库表格

    //获取商家验证码
    QString captcha = ui->Captcha->text();
    if(captcha != "114514")
    {
        qDebug()<<"验证码错误失败";
        return;
    }

    qDebug()<<"验证码正确";
    //获取密码
    QString pwd = ui->password->text();
    QCryptographicHash hash(QCryptographicHash::Md5);
    hash.addData(pwd.toUtf8());
    QByteArray pwded = hash.result();
    QString pwdstr = pwded.toHex();


    //准备一条插入的记录
    QSqlRecord record = model.record();//获取表格结构记录
    record.setValue("username",ui->username->text());
    record.setValue("password",pwdstr);

    //插入到模型中
    if(!model.insertRecord(0, record))
    {
        qDebug()<<"插入失败";
    }
    qDebug()<<"已注册商家账号";
    qDebug()<<"账号："<<ui->username->text();
    qDebug()<<"密码："<<pwdstr;
}

void regi::on_regbt_2_clicked()
{

    //创建一个数据库表模型
    QSqlTableModel model;  //自动关联到默认的数据库
    model.setTable("student");//绑定数据库表格

    //获取密码
    QString pwd = ui->password->text();
    QCryptographicHash hash(QCryptographicHash::Md5); //加密方式
    hash.addData(pwd.toUtf8());  //将密码字符串转换为UTF-8编码的字节数组，并添加到哈希对象中。
    QByteArray pwded = hash.result(); // 计算哈希值并将结果存储在pwded中。
    QString pwdstr = pwded.toHex(); //转换十六进制


    //准备一条插入的记录
    QSqlRecord record = model.record();//获取表格结构记录
    record.setValue("username",ui->username->text());
    record.setValue("password",pwdstr);

    //插入到模型中
    if(!model.insertRecord(0, record))
    {
        qDebug()<<"插入失败";
    }
    else{
        qDebug()<<"已注册用户账号";
        qDebug()<<"账号："<<ui->username->text();
        qDebug()<<"密码："<<pwdstr;
    }
}
