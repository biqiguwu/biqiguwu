#include "loginwidget.h"
#include "ui_loginwidget.h"

#include <QCryptographicHash>
#include <QMovie>
#include <QDebug>
loginWidget::loginWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::loginWidget)

{
    ui->setupUi(this);

    this->mainwindow = new MainWindow; //实例化商家界面
    this->regis = new class regi;      //注册界面
    this->user = new userWindow;       //用户界面
    this->code = new Qrcode;       //用户界面

    connect(mainwindow, &MainWindow::sendMessage, user, &userWindow::receiveMessage);
    connect(user, &userWindow::sendmessage, mainwindow, &MainWindow::receivemessage);
    connect(user, &userWindow::sendtable, mainwindow, &MainWindow::receivetable);
    connect(user, &userWindow::sendliuyan, mainwindow, &MainWindow::receiveliuyan);
    //去掉边框
    setWindowFlag(Qt::WindowType::FramelessWindowHint);
    //背景透明
    setAttribute(Qt::WA_TranslucentBackground);

    //给labtop设置动画
    QMovie *movie = new QMovie(this);//用来播放gif
    movie->setFileName(":/login.gif");

    ui->labtop->setMovie(movie);
    movie->start();//播放

    //用户名提示
    ui->nameBox->setEditable(true);   //QComboBox部件本身没有lineEdit部件，要通过该句设置或打开editable
    ui->nameBox->lineEdit()->setPlaceholderText("账号");

    //设置头像为圆形
    ui->avatar->setMask(QRegion(ui->avatar->rect(),QRegion::RegionType::Ellipse));

    //接收到信息后的操作
    connect(this->mainwindow,&MainWindow::back,[=](){
        //此处用槽函数也行
        this->mainwindow->hide();
        this->show();
    });

    connect(this->user,&userWindow::back,[=](){
        this->user->hide();
        this->show();
    });

    ui->password->setEchoMode(QLineEdit::Password);

    QIcon icon(":/password_hide.png"); // 加载图片文件，路径为 ":/images/image.png"
    ui->pushButton->setIcon(icon); // 将按钮上显示的图标设置为加载的图片文件
}

loginWidget::~loginWidget()
{
    delete ui;
}


void loginWidget::on_btMin_clicked()
{
    this->showMinimized();
}

void loginWidget::on_btClose_clicked()
{
    this->close();
}

void loginWidget::on_loginbt_clicked()
{

    //创建一个数据库表模型
    QSqlTableModel model;  //自动关联到默认的数据库
    model.setTable("business");//绑定数据库表格

    //获取密码
    QString pwd = ui->password->text();
    QCryptographicHash hash(QCryptographicHash::Md5);
    hash.addData(pwd.toUtf8());
    QByteArray pwded = hash.result();
    QString pwdstr = pwded.toHex();

    //查询条件
    model.setFilter(QString("username='%1' and password='%2'").arg(ui->nameBox->lineEdit()->text()).arg(pwdstr));
    //查询
    model.select();
    //检查结果
    if(model.rowCount() > 0)
    {
        qDebug()<<"登录成功";
        //关闭当前窗口
        this->hide();

        //显示窗口
        this->mainwindow->show();
    }else
    {
        qDebug()<<"登录失败";
    }


}

//眼睛
void loginWidget::on_pushButton_clicked()
{
    if (ui->password->echoMode() == QLineEdit::Normal)
    {
        ui->password->setEchoMode(QLineEdit::Password); // 将输入内容隐藏
        QIcon icon(":/password_hide.png");
        ui->pushButton->setIcon(icon); // 将按钮上显示的图标设置为加载的图片文件
    }
    else
    {
        ui->password->setEchoMode(QLineEdit::Normal); // 将输入内容显示
        QIcon icon(":/password_show.png");
        ui->pushButton->setIcon(icon);
    };
}

void loginWidget::on_registbt_clicked()
{
    //this->hide();
    this->regis->show();
}

void loginWidget::on_Qrcodebt_clicked()
{
  this->code->show();
}

void loginWidget::on_loginbt_2_clicked()
{
    //创建一个数据库表模型
    QSqlTableModel model;  //自动关联到默认的数据库
    model.setTable("student");//绑定数据库表格

    //获取密码
    QString pwd = ui->password->text();
    QCryptographicHash hash(QCryptographicHash::Md5);
    hash.addData(pwd.toUtf8());
    QByteArray pwded = hash.result();
    QString pwdstr = pwded.toHex();


    //查询条件
    model.setFilter(QString("username='%1' and password='%2'").arg(ui->nameBox->lineEdit()->text()).arg(pwdstr));
    //查询
    model.select();
    //检查结果
    if(model.rowCount() > 0)
    {
        qDebug()<<"登录成功";
        //关闭当前窗口
        this->hide();

        //显示窗口
        this->user->show();
    }
    else
    {
        qDebug()<<"登录失败";
        ui->password->clear();
        ui->password->setPlaceholderText("密码错误");
        return;
    }
    bool isChecked = ui->auto_word->isChecked();
    if(!isChecked)  ui->password->clear();
    ui->password->setPlaceholderText("密码");

}
