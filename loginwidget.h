#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QLabel>
#include "mainwindow.h" //商家界面对应的头文件
#include "regi.h"       //注册界面头文件
#include "userwindow.h" //用户界面头文件
#include "qrcode.h"     //二维码界面
QT_BEGIN_NAMESPACE
namespace Ui { class loginWidget; }
QT_END_NAMESPACE

class loginWidget : public QWidget
{
    Q_OBJECT

public:
    loginWidget(QWidget *parent = nullptr);
    ~loginWidget();
    MainWindow *mainwindow = NULL;  //用来保存商家界面的实例化对象的地址
    regi *regis =NULL;              //登录界面实例化地址
    userWindow *user =NULL;         // 用户界面实例化地址
    Qrcode *code = NULL;
private slots:
    void on_btMin_clicked();

    void on_btClose_clicked();

    void on_loginbt_clicked();

    void on_pushButton_clicked();

    void on_registbt_clicked();

    void on_Qrcodebt_clicked();

    void on_loginbt_2_clicked();

private:
    Ui::loginWidget *ui;
};
#endif // LOGINWIDGET_H
