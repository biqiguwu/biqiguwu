#include "userwindow.h"
#include "ui_userwindow.h"

#include <QCryptographicHash>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDebug>
#include <QString>

userWindow::userWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::userWindow)
{
    ui->setupUi(this);
    connect(ui->rebt,&QPushButton::clicked,[=](){
        //发一个信号过去
        emit this->back();
    });

   // ui->avatar->setMask(QRegion(ui->avatar->rect(),QRegion::RegionType::Ellipse));
    ui->mainfood->setText("主菜");
    ui->mainfood->setIcon(QIcon(":/main.png"));
    ui->mainfood->setIconSize(QSize(50, 50));

    ui->specialfood->setText("特色菜");
    ui->specialfood->setIcon(QIcon(":/special.png"));
    ui->specialfood->setIconSize(QSize(50, 50));

    ui->soup->setText("汤羹");
    ui->soup->setIcon(QIcon(":/soup.png"));
    ui->soup->setIconSize(QSize(50, 50));

    ui->snack->setText("小吃");
    ui->snack->setIcon(QIcon(":/food.png"));
    ui->snack->setIconSize(QSize(50, 50));

    ui->drink->setText("饮料");
    ui->drink->setIcon(QIcon(":/drink.png"));
    ui->drink->setIconSize(QSize(50, 50));

    ui->tableWidget->setCellWidget(0, 0, ui->widget_main1);
    ui->tableWidget->setCellWidget(0, 1, ui->widget_main2);


    ui->tableWidget_2->setCellWidget(0, 1, ui->widget_special2);
    ui->tableWidget_2->setCellWidget(0, 0, ui->widget_special1);

    ui->tableWidget_5->setCellWidget(0, 1, ui->widget_soup2);
    ui->tableWidget_5->setCellWidget(0, 0, ui->widget_soup1);

    ui->tableWidget_6->setCellWidget(0, 1, ui->widget_snack2);
    ui->tableWidget_6->setCellWidget(0, 0, ui->widget_snack1);

   // ui->wechat_bt->setStyleSheet("font:20px kai;border-radius:10px;");
    ui->widget_8->hide();
    ui->widget_9->hide();
    ui->widget_11->hide();

}

userWindow::~userWindow()
{
    delete ui;
}

void userWindow::receiveMessage()
{
    QSqlTableModel model;  //自动关联到默认的数据库
    model.setTable("food");//绑定数据库表格

    // 从数据库中选择数据
    model.select();

    // 获取第一行数据

    QString filename = model.record(0).value("filename").toString();
    QString foodname = model.record(0).value("foodname").toString();
    QString foodtext = model.record(0).value("foodtext").toString();
    QString foodpiece = model.record(0).value("foodpiece").toString();

    ui->new_picture->setPixmap(QPixmap(filename));
    ui->new_name->setText(foodname);
    ui->new_piece->setText(foodpiece);
    ui->new_text->setText(foodtext);
    ui->tableWidget->setCellWidget(1, 0, ui->widget_main1_2);
    qDebug()<<"用户界面同步菜单中";
}




void userWindow::on_menu_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void userWindow::on_table_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
     ui->tableWidget_3->show();
}

void userWindow::on_comknow_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void userWindow::on_message_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void userWindow::on_my_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void userWindow::on_xia_jia_clicked()
{
    xia_num++;
    ui->xia_num->setText(QString::number(xia_num));
}


void userWindow::on_xia_jian_clicked()
{
    if(xia_num == 0) return;
    xia_num--;
    ui->xia_num->setText(QString::number(xia_num));
}

void userWindow::on_rose_jian_clicked()
{
    if(rose_num == 0) return;
    rose_num--;
    ui->rose_num->setText(QString::number(rose_num));

}

void userWindow::on_rose_jia_clicked()
{
    rose_num++;
    ui->rose_num->setText(QString::number(rose_num));
}

void userWindow::on_mei_jian_clicked()
{
    if(meicai_num == 0) return;
    meicai_num--;
    ui->mei_num->setText(QString::number(meicai_num));
}

void userWindow::on_mei_jia_clicked()
{
    meicai_num++;
    ui->mei_num->setText(QString::number(meicai_num));
}

void userWindow::on_gu_jian_clicked()
{
    if(xianggu_num == 0) return;
    xianggu_num--;
    ui->gu_num->setText(QString::number(xianggu_num));
}

void userWindow::on_gu_jia_clicked()
{
    xianggu_num++;
    ui->gu_num->setText(QString::number(xianggu_num));
}

void userWindow::on_soup1_jian_clicked()
{
    if(soup1_num == 0) return;
    soup1_num--;
    ui->soup1_num->setText(QString::number(soup1_num));
}

void userWindow::on_soup1_jia_clicked()
{
    soup1_num++;
    ui->soup1_num->setText(QString::number(soup1_num));
}

void userWindow::on_soup2_jian_clicked()
{
    if(soup2_num == 0) return;
    soup2_num--;
    ui->soup_num->setText(QString::number(soup2_num));
}

void userWindow::on_soup2_jia_clicked()
{
    soup2_num++;
    ui->soup_num->setText(QString::number(soup2_num));
}

void userWindow::on_meicai_jian_10_clicked()
{
    if(snack2_num == 0) return;
    snack2_num--;
    ui->snack2_num->setText(QString::number(snack2_num));
}

void userWindow::on_snack2_jia_clicked()
{
    snack2_num++;
    ui->snack2_num->setText(QString::number(snack2_num));
}

void userWindow::on_snack1_jian_clicked()
{
    if(snack1_num == 0) return;
    snack1_num--;
    ui->snack1_num->setText(QString::number(snack1_num));
}

void userWindow::on_snack1_jia_clicked()
{
    snack1_num++;
    ui->snack1_num->setText(QString::number(snack1_num));
}

void userWindow::on_drink1_jia_clicked()
{
    drink1_num++;
    ui->drink1_num->setText(QString::number(drink1_num));
}

void userWindow::on_drink1_jian_clicked()
{
    if(drink1_num == 0) return;
    drink1_num--;
    ui->drink1_num->setText(QString::number(drink1_num));
}

void userWindow::on_mainfood_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void userWindow::on_specialfood_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(1);
}

void userWindow::on_snack_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(3);
}



void userWindow::on_soup_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(2);
}

void userWindow::on_drink_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(4);
}

void userWindow::on_xia_bt_clicked()
{
    if(xia_row == -1)
    {
        xia_row = order_row;order_row++;

        ui->tableWidget_3->setCellWidget(xia_row, 0, ui->order_ex);
        ui->order_picture->setPixmap(QPixmap(":/xia.png"));
        ui->order_num->setText(QString::number(xia_num));
        ui->order_name->setText("蒜蓉小龙虾");
        ui->order_piece->setText(QString::number(40));
        xia_sum = xia_num*40;
        ui->order_sum->setText(QString::number(xia_num*40));


        xiaoji += xia_num*40;
        heji = xiaoji;
        ui->xiaoji->setText(QString::number(xiaoji));
        ui->heji->setText(QString::number(heji));
    }
    else{
        xiaoji += xia_num*40;
        heji =xiaoji;
        xia_sum +=xia_num*40;
        ui->xiaoji->setText(QString::number(xiaoji));
        ui->heji->setText(QString::number(heji));
        ui->order_sum->setText(QString::number(xia_sum));
        ui->order_num->setText(QString::number(ui->order_num->text().toInt()+xia_num));

    }

    ui->xia_num->setText(QString::number(0));
    xia_num = 0;
   // qDebug()<<"当前行数为"<<order_row;
}

void userWindow::on_xia_bt_3_clicked()
{

    if(rose_row == -1)
    {
        rose_row = order_row;order_row++;

        ui->tableWidget_3->setCellWidget(rose_row, 0, ui->order_ex_2);
        ui->order_picture_2->setPixmap(QPixmap(":/rose.png"));
        ui->order_num_2->setText(QString::number(rose_num));
        ui->order_name_2->setText("鱼香肉丝");
        rose_sum = rose_num*30;
        ui->order_sum_2->setText(QString::number(rose_sum));
        ui->order_piece_2->setText(QString::number(30));

        xiaoji += rose_num*30;
        heji = xiaoji;
        ui->xiaoji->setText(QString::number(xiaoji));
        ui->heji->setText(QString::number(heji));
    }
    else{
        xiaoji += rose_num*30;
        heji = xiaoji;
        rose_sum += rose_num*30;
        ui->xiaoji->setText(QString::number(xiaoji));
        ui->heji->setText(QString::number(heji));
        ui->order_sum_2->setText(QString::number(rose_sum));
        ui->order_num_2->setText(QString::number(ui->order_num_2->text().toInt()+rose_num));
    }

      ui->rose_num->setText(QString::number(0));
      rose_num = 0;
     // qDebug()<<"当前行数为"<<order_row;
}

void userWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void userWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void userWindow::on_pushButton_clicked()
{
    qDebug()<<"查询中..";

    QString search_line = ui->search_line->text();
    qDebug()<<"文本框中的内容为"<<search_line.toStdString().c_str();

    int len = strlen(search_line.toStdString().c_str());
    qDebug()<<len;

    int result = strncmp(search_line.toStdString().c_str(), "蒜蓉小龙虾", len);
    if (result == 0)    { ;ui->stackedWidget_4->setCurrentIndex(0);return ;}

    result = strncmp(search_line.toStdString().c_str(), "鱼香肉丝", len);
    if (result == 0)    {ui->stackedWidget_4->setCurrentIndex(0);return ;}

    result = strncmp(search_line.toStdString().c_str(), "梅菜扣肉", len);
    if (result == 0)    {ui->stackedWidget_4->setCurrentIndex(1);return ;}

    result = strncmp(search_line.toStdString().c_str(), "香菇滑鸡", len);
    if (result == 0)    {ui->stackedWidget_4->setCurrentIndex(1);return ;}

    result = strncmp(search_line.toStdString().c_str(), "瘦肉花胶汤", len);
    if (result == 0)    {ui->stackedWidget_4->setCurrentIndex(2);return ;}

    result = strncmp(search_line.toStdString().c_str(), "冬瓜薏米汤", len);
    if (result == 0)    {ui->stackedWidget_4->setCurrentIndex(2);return ;}

    result = strncmp(search_line.toStdString().c_str(), "蒸饺", len);
    if (result == 0)    {qDebug()<<"已查到蒸..";ui->stackedWidget_4->setCurrentIndex(3);return ;}

    result = strncmp(search_line.toStdString().c_str(), "春卷", len);
    if (result == 0)    {ui->stackedWidget_4->setCurrentIndex(3);return ;}

    result = strncmp(search_line.toStdString().c_str(), "可口可乐", len);
    if (result == 0)    {ui->stackedWidget_4->setCurrentIndex(4);return ;}

    result = strncmp(search_line.toStdString().c_str(), "王老吉", len);
    if (result == 0)    {ui->stackedWidget_4->setCurrentIndex(4);return ;}


}

void userWindow::on_new_jian_clicked()
{
    if(new_num == 0) return;
    new_num--;
    ui->new_num->setText(QString::number(new_num));
}

void userWindow::on_new_jia_clicked()
{
    new_num++;
    ui->new_num->setText(QString::number(new_num));
}

void userWindow::on_new_car_clicked()
{
    QSqlTableModel model;  //自动关联到默认的数据库
    model.setTable("food");//绑定数据库表格

    // 从数据库中选择数据
    model.select();

    // 获取第一行数据
    QString filename = model.record(0).value("filename").toString();
    QString foodname = model.record(0).value("foodname").toString();
    QString foodtext = model.record(0).value("foodtext").toString();
    QString foodpiece = model.record(0).value("foodpiece").toString();
    if(new_row == -1)
    {
        new_row = order_row;order_row++;
    }
    ui->tableWidget_3->setCellWidget(new_row, 0, ui->order_ex_3);
    ui->order_picture_3->setPixmap(QPixmap(filename));
    ui->order_num_3->setText(QString::number(new_num));
    ui->order_name_3->setText(foodname);
    ui->order_sum_3->setText(QString::number(new_num*foodpiece.toInt()));
    ui->order_piece_3->setText(QString::number(40));


    xiaoji += new_num*foodpiece.toInt();
    heji = xiaoji;
    ui->xiaoji->setText(QString::number(xiaoji));
    ui->heji->setText(QString::number(heji));

    ui->new_num->setText(QString::number(0));
    emit sendmessage();


}
//提交订单给数据库
void userWindow::on_pushButton_63_clicked()
{
    ui->tableWidget_3->hide();
    order_row = 0;
    //创建一个数据库表模型
    QSqlTableModel model;  //自动关联到默认的数据库
    model.setTable("ding");//绑定数据库表格
    //准备一条插入的记录
    QSqlRecord record = model.record();//获取表格结构记录


    QColor bgColor1 = ui->cash_bt->palette().color(QPalette::Button);
    QColor bgColor2 = ui->wechat_bt->palette().color(QPalette::Button);
    QColor bgColor3 = ui->Alipay_bt->palette().color(QPalette::Button);

    QString colorString = "#00aaff";

    int pay_flag = 0;
    if(bgColor1.name() == colorString)
    {
        record.setValue("order_num",ui->dingdan_num->text());
        record.setValue("table_num",ui->zhuotai_num->text());
        record.setValue("xiaoji",ui->xiaoji->text());
        record.setValue("heji",ui->heji->text());
        record.setValue("payway","cash");
        record.setValue("food1_name",ui->order_name->text());
        record.setValue("food1_num",ui->order_num->text());
        record.setValue("food1_piece",ui->order_piece->text());

        record.setValue("food2_name",ui->order_name_2->text());
        record.setValue("food2_num",ui->order_num_2->text());
        record.setValue("food2_piece",ui->order_piece_2->text());

        record.setValue("food3_name",ui->order_name_3->text());
        record.setValue("food3_num",ui->order_num_3->text());
        record.setValue("food3_piece",ui->order_piece_3->text());
         qDebug()<<"现金支付";

        pay_flag++;
    }

    if(bgColor2.name() == colorString)
    {
        record.setValue("order_num",ui->dingdan_num->text());
        record.setValue("table_num",ui->zhuotai_num->text());
        record.setValue("xiaoji",ui->xiaoji->text());
        record.setValue("heji",ui->heji->text());
        record.setValue("payway","wechat");

        record.setValue("food1_name",ui->order_name->text());
        record.setValue("food1_num",ui->order_num->text());
        record.setValue("food1_piece",ui->order_piece->text());

        record.setValue("food2_name",ui->order_name_2->text());
        record.setValue("food2_num",ui->order_num_2->text());
        record.setValue("food2_piece",ui->order_piece_2->text());

        record.setValue("food3_name",ui->order_name_3->text());
        record.setValue("food3_num",ui->order_num_3->text());
        record.setValue("food3_piece",ui->order_piece_3->text());
        pay_flag++;
        qDebug()<<"微信支付";
    }

    if(bgColor3.name() == colorString)
    {
        record.setValue("order_num",ui->dingdan_num->text());
        record.setValue("table_num",ui->zhuotai_num->text());
        record.setValue("xiaoji",ui->xiaoji->text());
        record.setValue("heji",ui->heji->text());
        record.setValue("payway","Alipay");

        record.setValue("food1_name",ui->order_name->text());
        record.setValue("food1_num",ui->order_num->text());
        record.setValue("food1_piece",ui->order_piece->text());

        record.setValue("food2_name",ui->order_name_2->text());
        record.setValue("food2_num",ui->order_num_2->text());
        record.setValue("food2_piece",ui->order_piece_2->text());

        record.setValue("food3_name",ui->order_name_3->text());
        record.setValue("food3_num",ui->order_num_3->text());
        record.setValue("food3_piece",ui->order_piece_3->text());
        qDebug()<<"支付宝支付";
        pay_flag++;
    }

    //未选择支付方式
    if(pay_flag == 0) return;

    //插入到模型中
    if(!model.insertRecord(0, record))
    {
        qDebug()<<"插入失败";
    }
    ui->dingdan_num->setText("#114515");
    ui->zhuotai_num->setText("02");
    xiaoji = 0;
    heji = 0;
    ui->xiaoji->setText(QString::number(0));
    ui->heji->setText(QString::number(0));
    xia_row = -1;
    rose_row = -1;
    order_row = 0;
    ui->wechat_bt->setStyleSheet("font:20px kai;border-radius:10px;background-color: white;");
    ui->cash_bt->setStyleSheet("font:20px kai;border-radius:10px;background-color: white;");
    ui->Alipay_bt->setStyleSheet("font:20px kai;border-radius:10px;background-color: white;");
    emit this->sendtable();
}

void userWindow::on_cash_bt_clicked()
{

    ui->cash_bt->setStyleSheet("font:20px kai;border-radius:10px;background-color: rgb(0, 170, 255)");
    ui->wechat_bt->setStyleSheet("font:20px kai;border-radius:10px;background-color: white;");
    ui->Alipay_bt->setStyleSheet("font:20px kai;border-radius:10px;background-color: white;");
}

void userWindow::on_wechat_bt_clicked()
{
    ui->wechat_bt->setStyleSheet("font:20px kai;border-radius:10px;background-color: rgb(0, 170, 255);");
    ui->cash_bt->setStyleSheet("font:20px kai;border-radius:10px;background-color: white;");
    ui->Alipay_bt->setStyleSheet("font:20px kai;border-radius:10px;background-color: white;");
}

void userWindow::on_Alipay_bt_clicked()
{
    ui->Alipay_bt->setStyleSheet("font:20px kai;border-radius:10px;background-color: rgb(0, 170, 255)");
    ui->cash_bt->setStyleSheet("font:20px kai;border-radius:10px;background-color: white;");
    ui->wechat_bt->setStyleSheet("font:20px kai;border-radius:10px;background-color: white;");
}

void userWindow::on_rebt_clicked()
{
    ;
}

void userWindow::on_xia_jia_triggered(QAction *arg1)
{
    ;
}

void userWindow::on_change_bt_clicked()
{
    //创建一个数据库表模型
    QSqlTableModel model;  //自动关联到默认的数据库
    model.setTable("student");//绑定数据库表格
    //准备一条插入的记录
    model.select();
    QSqlRecord record = model.record();//获取表格结构记录
    QString mima = model.record(0).value("password").toString();
    qDebug()<<"原密码为"<<mima;
    //获取密码
    QString old_password = ui->old_password->text();
    QCryptographicHash hash(QCryptographicHash::Md5);
    hash.addData(old_password.toUtf8());

    QByteArray old_hash = hash.result();
    QString hash_Hex = old_hash.toHex();
    qDebug()<<"输入密码为"<<hash_Hex;

    QString new_password = ui->new_password->text();
    QCryptographicHash hash1(QCryptographicHash::Md5);
    hash1.addData(new_password.toUtf8());

    QByteArray new_hash = hash1.result();
    QString new_hash_Hex = new_hash.toHex();
    qDebug()<<"输入密码为"<<new_hash_Hex;

    if(mima == hash_Hex)
    {
        qDebug()<<"密码正确";
        model.setData(model.index(0, model.fieldIndex("password")), new_hash_Hex);
        model.submitAll(); // 提交更改到数据库
    }
    else
    {
        qDebug()<<"密码错误";
    }






}

void userWindow::on_submit_clicked()
{
    if(widget_index==0)
    {
        ui->widget_8->show();
        ui->liuyan_1->setText(ui->liuyan->toPlainText());
    }
    if(widget_index==1)
    {
        ui->widget_9->show();
        ui->liuyan_2->setText(ui->liuyan_1->text());
        ui->liuyan_1->setText(ui->liuyan->toPlainText());
    }
    qDebug() << ui->liuyan->toPlainText();  // 输出QTextEdit中的文本内容

    // 创建一个数据库表模型并绑定到默认的数据库
    QSqlTableModel model;
    model.setTable("liuyan");  // 绑定数据库表格

    // 准备一条插入的记录
    QSqlRecord record = model.record();  // 获取表格结构记录
    record.setValue("message", ui->liuyan->toPlainText());  // 设置记录的值

    // 将记录插入到模型中
    if (model.insertRecord(-1, record)) {  // 在最后一行插入记录
        if (model.submitAll()) {  // 提交所有的更改
            qDebug() << "Insertion successful";  // 插入成功
        } else {
            qDebug() << "Failed to submit changes to the database";  // 无法提交更改到数据库
        }
    } else {
        qDebug() << "Failed to insert record";  // 无法插入记录
    }
    emit sendliuyan();
    widget_index++;
}

void userWindow::on_pushButton_7_clicked()
{

}
