#include "loginwidget.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //创建数据库连接
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("my.db");
    //打开数据库
    if(!db.open())
    {
        qDebug()<<db.lastError().text();
    }

    // 创建数据库表格
    //创建商家账号列表
    QString createsql = "create table if not exists business(id integer primary key, username varchar(32) unique,password varchar(32))";
    QSqlQuery query;
    if(!query.exec(createsql)) //执行sql语句
    {
        qDebug()<<query.lastError().text();
    }

    //创建用户账号列表
    QString createsqln = "create table if not exists student(id integer primary key, username varchar(32) unique,password varchar(32))";
    QSqlQuery queryn;
    if(!queryn.exec(createsqln)) //执行sql语句
    {
        qDebug()<<queryn.lastError().text();
    }

    //创建新增菜品列表
    QString createsqls = "create table if not exists food(id integer primary key, filename varchar(48),foodname varchar(32),foodtext varchar(32),foodpiece varchar(32))";
    QSqlQuery querys;
    if(!querys.exec(createsqls)) //执行sql语句
    {
        qDebug()<<querys.lastError().text();
    }

    //订单餐桌列表
    //QString createsqlo = "create table if not exists ding(id integer primary key, order_num varchar(32),table_num varchar(32),xiaoji varchar(32),heji varchar(32),payway varchar(32)，food1_name varchar(32),food1_num varchar(32),food1_piece,food2_name varchar(32),food2_num varchar(32),food2_piece)";
    QString createsqlo = "create table if not exists ding(id integer primary key, order_num varchar(32), table_num varchar(32), xiaoji varchar(32), heji varchar(32), payway varchar(32), food1_name varchar(32), food1_num varchar(32), food1_piece varchar(32), food2_name varchar(32), food2_num varchar(32), food2_piece varchar(32),food3_name varchar(32), food3_num varchar(32), food3_piece varchar(32))";

    QSqlQuery queryo;
    if(!queryo.exec(createsqlo)) //执行sql语句
    {
        qDebug()<<queryo.lastError().text();
    }

    QString createsqlm = "create table if not exists liuyan(id integer primary key, message varchar(32))";

    QSqlQuery querym;
    if(!querym.exec(createsqlm)) //执行sql语句
    {
        qDebug()<<querym.lastError().text();
    }


    loginWidget w;
    w.show();
    return a.exec();
}
