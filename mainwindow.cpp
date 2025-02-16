#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMovie>
#include <QPushButton>
#include <QDebug>
#include <QFileDialog>
#include <QSqlTableModel>
#include <QCryptographicHash>
#include <QSqlRecord>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->rebt,&QPushButton::clicked,[=](){
        //发一个信号过去
        emit this->back();
    });

    //ui->menu->setFocus();
    //设置头像为圆形
    ui->avatar->setMask(QRegion(ui->avatar->rect(),QRegion::RegionType::Ellipse));
    ui->label_wode->setMask(QRegion(ui->label_wode->rect(),QRegion::RegionType::Ellipse));
    ui->avatar_4->setMask(QRegion(ui->avatar->rect(),QRegion::RegionType::Ellipse));


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

    ui->tableWidget->setCellWidget(1, 0, ui->widget_tianjia);

    ui->tableWidget_2->setCellWidget(0, 1, ui->widget_special2);
    ui->tableWidget_2->setCellWidget(0, 0, ui->widget_special1);

    ui->tableWidget_5->setCellWidget(0, 1, ui->widget_soup2);
    ui->tableWidget_5->setCellWidget(0, 0, ui->widget_soup1);

    ui->tableWidget_6->setCellWidget(0, 1, ui->widget_snack2);
    ui->tableWidget_6->setCellWidget(0, 0, ui->widget_snack1);

   // ui->tableWidget_drink->setCellWidget(0, 0, ui->tableWidget_drink);
    ui->order_hide->hide();
    //ui->widget_6->hide();
    ui->widget_7->hide();
    ui->widget_9->hide();
}

void MainWindow::receivetable()
{

    QSqlTableModel model;  //自动关联到默认的数据库
    model.setTable("ding");//绑定数据库表格

    // 从数据库中选择数据
    model.select();

    QString table_num1 = model.record(0).value("table_num").toString();
    QString order_num1 = model.record(0).value("order_num").toString();
    QString table_num2 = model.record(1).value("table_num").toString();
    QString order_num2 = model.record(0).value("order_num").toString();
    qDebug()<<"订单桌号为"<<table_num1<<"订单编号为"<<order_num2;
    qDebug()<<table_num2;
    if(table_num1 == "01"){
            ui->color_01->setStyleSheet("font:20px kai;border-radius:20px;background-color: rgb(255, 0, 0);");
            flag1 = 1;
    }
    if(table_num2 == "02"){
                ui->color_02->setStyleSheet("font:20px kai;border-radius:20px;background-color: rgb(255, 0, 0);");
                flag2 = 1;
        }
}
void MainWindow::receiveliuyan()
{
    ui->widget_6->show();
    QSqlTableModel model;  //自动关联到默认的数据库
    model.setTable("liuyan");//绑定数据库表格

    // 从数据库中选择数据
    model.select();

    QString message = model.record(0).value("message").toString();

    ui->liuyan->setText(message);
    QString message1 = model.record(1).value("message").toString();
    qDebug()<<"第二行的数据为"<<message1;
    if(!message1.isEmpty())
    {
        ui->widget_7->show();
        ui->liuyan_2->setText(ui->liuyan->text());
        ui->liuyan->setText(message1);
    }

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receivemessage(){
    ui->order_hide->show();

}
void MainWindow::on_searchbt_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); //查询
}

void MainWindow::on_menu_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
    qDebug()<<"menu_click";
}

void MainWindow::on_table_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);//桌台
     qDebug()<<"table_click";
}


void MainWindow::on_order_clicked()
{
     ui->stackedWidget->setCurrentIndex(2); //订单
}

void MainWindow::on_comknow_clicked()
{
     ui->stackedWidget->setCurrentIndex(3); //常识
}

void MainWindow::on_message_clicked()
{
     ui->stackedWidget->setCurrentIndex(4); //留言
}

void MainWindow::on_my_clicked()
{
     ui->stackedWidget->setCurrentIndex(5); //我的
}

void MainWindow::on_mainfood_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_specialfood_clicked()
{
     ui->stackedWidget_4->setCurrentIndex(1);
}

void MainWindow::on_soup_clicked()
{
     ui->stackedWidget_4->setCurrentIndex(2);
}

void MainWindow::on_snack_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(3);
}

void MainWindow::on_drink_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(4);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_personbt_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_xia_jia_clicked()
{
    xia_num++;
    ui->xia_num->setText(QString::number(xia_num));
}

void MainWindow::on_xia_jian_clicked()
{
    if(xia_num == 0) return;
    xia_num--;
    ui->xia_num->setText(QString::number(xia_num));
}

void MainWindow::on_rose_jia_clicked()
{
    rose_num++;
    ui->rose_num->setText(QString::number(rose_num));
}

void MainWindow::on_rose_jian_clicked()
{
    if(rose_num == 0 ) return;
    rose_num--;
    ui->rose_num->setText(QString::number(rose_num));
}



void MainWindow::on_mei_jian_clicked()
{
    meicai_num++;
    ui->mei_num->setText(QString::number(meicai_num));
}

void MainWindow::on_mei_jian_triggered(QAction *arg1)
{
    if(meicai_num == 0) return;
    meicai_num--;
    ui->mei_num->setText(QString::number(meicai_num));
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tableWidget->setCellWidget(1, 1, ui->widget_tianjia_2);
    ui->stackedWidget->setCurrentIndex(7);

}

void MainWindow::on_filebt_clicked()
{
    //获取文件路径
    QString filename = QFileDialog::getOpenFileName(this);
    ui->fileEdit->setText(filename);
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->new_picture->setPixmap(QPixmap(ui->fileEdit->text()));
    ui->new_name->setText(ui->edit_name->text());
    ui->new_piece->setText(ui->edit_piece->text());
    ui->new_text->setText(ui->edit_text->text());
    ui->stackedWidget->setCurrentIndex(0);
    ui->tableWidget->setCellWidget(1, 0, ui->widget_main1_2);

    //创建一个数据库表模型
    QSqlTableModel model;  //自动关联到默认的数据库
    model.setTable("food");//绑定数据库表格

    //准备一条插入的记录
    QSqlRecord record = model.record();//获取表格结构记录
    record.setValue("filename",ui->fileEdit->text());
    record.setValue("foodname",ui->edit_name->text());
    record.setValue("foodtext",ui->edit_text->text());
    record.setValue("foodpiece",ui->edit_piece->text());


    //插入到模型中
    if(!model.insertRecord(0, record))
    {
        qDebug()<<"插入失败";
    }
    emit this->sendMessage();


}

void MainWindow::on_new_jian_clicked()
{
    if(new_num == 0) return;
    new_num--;
    ui->new_num->setText(QString::number(new_num));
}

void MainWindow::on_new_jia_clicked()
{
    new_num++;
    ui->new_num->setText(QString::number(new_num));
}

void MainWindow::on_xia_bt_2_clicked()
{

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}
//1号桌台
void MainWindow::on_pushButton_22_clicked()
{
    QSqlTableModel model;  //自动关联到默认的数据库
    model.setTable("ding");//绑定数据库表格

    // 从数据库中选择数据
    model.select();

    // 检查按钮1状态
    QPushButton* button = ui->pushButton_22;
    bool isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "1号按钮聚焦状态";
      if(flag1 == 1){ui->stackedWidget_5->setCurrentIndex(1);}
      else{ui->stackedWidget_5->setCurrentIndex(0);}
      ui->chair11->setStyleSheet("background-color: blue;");
      ui->chair12->setStyleSheet("background-color: blue;");
      ui->chair13->setStyleSheet("background-color: blue;");
      ui->chair14->setStyleSheet("background-color: blue;");

      // 获取第一行数据
      QString order_num = model.record(0).value("order_num").toString();
      QString table_num = model.record(0).value("table_num").toString();
      QString xiaoji = model.record(0).value("xiaoji").toString();
      QString heji = model.record(0).value("heji").toString();
      QString payway = model.record(0).value("payway").toString();

      QString food1_name = model.record(0).value("food1_name").toString();
      QString food1_num = model.record(0).value("food1_num").toString();
      QString food1_piece = model.record(0).value("food1_piece").toString();
     // int food1_sum = food1_num.toInt()*food1_piece.toInt();

      QString food2_name = model.record(0).value("food2_name").toString();
      QString food2_num = model.record(0).value("food2_num").toString();
      QString food2_piece = model.record(0).value("food2_piece").toString();
    //  int food2_sum = food2_num.toInt()*food2_piece.toInt();

      ui->s1_food1_name->setText(food1_name);
      ui->s1_food1_num->setText(food1_num);
      ui->s1_food2_name->setText(food2_name);
      ui->s1_food2_num->setText(food2_num);

    }
    else
    {
      qDebug() << "1号按钮非聚焦状态";
      ui->chair11->setStyleSheet("background-color: white;");
      ui->chair12->setStyleSheet("background-color: white;");
      ui->chair13->setStyleSheet("background-color: white;");
      ui->chair14->setStyleSheet("background-color: white;");

    }

    // 检查按钮状态2
    button = ui->table2_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "2号按钮聚焦状态";
      ui->chair21->setStyleSheet("background-color: blue;");
      ui->chair22->setStyleSheet("background-color: blue;");
      ui->chair23->setStyleSheet("background-color: blue;");
      ui->chair24->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "2号按钮非聚焦状态";
      ui->chair21->setStyleSheet("background-color: white;");
      ui->chair22->setStyleSheet("background-color: white;");
      ui->chair23->setStyleSheet("background-color: white;");
      ui->chair24->setStyleSheet("background-color: white;");

    }

    // 检查按钮状态3
    button = ui->table3_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "3号按钮聚焦状态";
      ui->chair31->setStyleSheet("background-color: blue;");
      ui->chair32->setStyleSheet("background-color: blue;");
      ui->chair33->setStyleSheet("background-color: blue;");
      ui->chair34->setStyleSheet("background-color: blue;");
      ui->chair35->setStyleSheet("background-color: blue;");
      ui->chair36->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "3号按钮非聚焦状态";
      ui->chair31->setStyleSheet("background-color: white;");
      ui->chair32->setStyleSheet("background-color: white;");
      ui->chair33->setStyleSheet("background-color: white;");
      ui->chair34->setStyleSheet("background-color: white;");
      ui->chair35->setStyleSheet("background-color: white;");
      ui->chair36->setStyleSheet("background-color: white;");
    }

    //检查按钮状态4
    button = ui->table4_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "4号按钮聚焦状态";
      ui->chair41->setStyleSheet("background-color: blue;");
      ui->chair42->setStyleSheet("background-color: blue;");

    }
    else
    {
      qDebug() << "4号按钮非聚焦状态";
      ui->chair41->setStyleSheet("background-color: white;");
      ui->chair42->setStyleSheet("background-color: white;");
    }

    // 检查按钮状态5
    button = ui->table5_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "5号按钮聚焦状态";
      ui->chair51->setStyleSheet("background-color: blue;");
      ui->chair52->setStyleSheet("background-color: blue;");
      ui->chair53->setStyleSheet("background-color: blue;");
      ui->chair54->setStyleSheet("background-color: blue;");
      ui->chair55->setStyleSheet("background-color: blue;");
      ui->chair56->setStyleSheet("background-color: blue;");
      ui->chair57->setStyleSheet("background-color: blue;");
      ui->chair58->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "5号按钮非聚焦状态";
      ui->chair51->setStyleSheet("background-color: white;");
      ui->chair52->setStyleSheet("background-color: white;");
      ui->chair53->setStyleSheet("background-color: white;");
      ui->chair54->setStyleSheet("background-color: white;");
      ui->chair55->setStyleSheet("background-color: white;");
      ui->chair56->setStyleSheet("background-color: white;");
      ui->chair57->setStyleSheet("background-color: white;");
      ui->chair58->setStyleSheet("background-color: white;");
    }

    // 检查按钮状态6
    button = ui->table6_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "6号按钮聚焦状态";
      ui->chair61->setStyleSheet("background-color: blue;");
      ui->chair62->setStyleSheet("background-color: blue;");
      ui->chair63->setStyleSheet("background-color: blue;");
      ui->chair64->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "6号按钮非聚焦状态";
      ui->chair61->setStyleSheet("background-color: white;");
      ui->chair62->setStyleSheet("background-color: white;");
      ui->chair63->setStyleSheet("background-color: white;");
      ui->chair64->setStyleSheet("background-color: white;");

    }


}

void MainWindow::on_table1_bt_clicked()
{
    ;//弃用
}

//2号桌台
void MainWindow::on_table2_bt_clicked()
{
    QSqlTableModel model;  //自动关联到默认的数据库
    model.setTable("ding");//绑定数据库表格

    // 从数据库中选择数据
    model.select();
    // 检查按钮1状态
    QPushButton* button = ui->pushButton_22;
    bool isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "1号按钮聚焦状态";
      ui->chair11->setStyleSheet("background-color: blue;");
      ui->chair12->setStyleSheet("background-color: blue;");
      ui->chair13->setStyleSheet("background-color: blue;");
      ui->chair14->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "1号按钮非聚焦状态";
      ui->chair11->setStyleSheet("background-color: white;");
      ui->chair12->setStyleSheet("background-color: white;");
      ui->chair13->setStyleSheet("background-color: white;");
      ui->chair14->setStyleSheet("background-color: white;");

    }

    // 检查按钮状态2
    button = ui->table2_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "2号按钮聚焦状态";
      if(flag2 == 1){ui->stackedWidget_5->setCurrentIndex(2);}
      else{ui->stackedWidget_5->setCurrentIndex(0);}
      ui->chair21->setStyleSheet("background-color: blue;");
      ui->chair22->setStyleSheet("background-color: blue;");
      ui->chair23->setStyleSheet("background-color: blue;");
      ui->chair24->setStyleSheet("background-color: blue;");


      // 获取第一行数据
      QString order_num = model.record(1).value("order_num").toString();
      QString table_num = model.record(1).value("table_num").toString();
      QString xiaoji = model.record(1).value("xiaoji").toString();
      QString heji = model.record(1).value("heji").toString();
      QString payway = model.record(1).value("payway").toString();

      QString food1_name = model.record(1).value("food1_name").toString();
      QString food1_num = model.record(1).value("food1_num").toString();
      QString food1_piece = model.record(1).value("food1_piece").toString();
     // int food1_sum = food1_num.toInt()*food1_piece.toInt();

      QString food2_name = model.record(1).value("food2_name").toString();
      QString food2_num = model.record(1).value("food2_num").toString();
      QString food2_piece = model.record(1).value("food2_piece").toString();
    //  int food2_sum = food2_num.toInt()*food2_piece.toInt();
      QString food3_name = model.record(1).value("food3_name").toString();
      QString food3_num = model.record(1).value("food3_num").toString();

      ui->s2_food1_name->setText(food1_name);
      ui->s2_food1_num->setText(food1_num);
      ui->s2_food2_name->setText(food2_name);
      ui->s2_food2_num->setText(food2_num);
      ui->s2_food3_name->setText(food3_name);
      ui->s2_food3_num->setText(food3_num);



    }
    else
    {
      qDebug() << "2号按钮非聚焦状态";
      ui->chair21->setStyleSheet("background-color: white;");
      ui->chair22->setStyleSheet("background-color: white;");
      ui->chair23->setStyleSheet("background-color: white;");
      ui->chair24->setStyleSheet("background-color: white;");

    }

    // 检查按钮状态3
    button = ui->table3_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "3号按钮聚焦状态";
      ui->chair31->setStyleSheet("background-color: blue;");
      ui->chair32->setStyleSheet("background-color: blue;");
      ui->chair33->setStyleSheet("background-color: blue;");
      ui->chair34->setStyleSheet("background-color: blue;");
      ui->chair35->setStyleSheet("background-color: blue;");
      ui->chair36->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "3号按钮非聚焦状态";
      ui->chair31->setStyleSheet("background-color: white;");
      ui->chair32->setStyleSheet("background-color: white;");
      ui->chair33->setStyleSheet("background-color: white;");
      ui->chair34->setStyleSheet("background-color: white;");
      ui->chair35->setStyleSheet("background-color: white;");
      ui->chair36->setStyleSheet("background-color: white;");
    }

    //检查按钮状态4
    button = ui->table4_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "4号按钮聚焦状态";
      ui->chair41->setStyleSheet("background-color: blue;");
      ui->chair42->setStyleSheet("background-color: blue;");

    }
    else
    {
      qDebug() << "4号按钮非聚焦状态";
      ui->chair41->setStyleSheet("background-color: white;");
      ui->chair42->setStyleSheet("background-color: white;");
    }

    // 检查按钮状态5
    button = ui->table5_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "5号按钮聚焦状态";
      ui->chair51->setStyleSheet("background-color: blue;");
      ui->chair52->setStyleSheet("background-color: blue;");
      ui->chair53->setStyleSheet("background-color: blue;");
      ui->chair54->setStyleSheet("background-color: blue;");
      ui->chair55->setStyleSheet("background-color: blue;");
      ui->chair56->setStyleSheet("background-color: blue;");
      ui->chair57->setStyleSheet("background-color: blue;");
      ui->chair58->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "5号按钮非聚焦状态";
      ui->chair51->setStyleSheet("background-color: white;");
      ui->chair52->setStyleSheet("background-color: white;");
      ui->chair53->setStyleSheet("background-color: white;");
      ui->chair54->setStyleSheet("background-color: white;");
      ui->chair55->setStyleSheet("background-color: white;");
      ui->chair56->setStyleSheet("background-color: white;");
      ui->chair57->setStyleSheet("background-color: white;");
      ui->chair58->setStyleSheet("background-color: white;");
    }

    // 检查按钮状态6
    button = ui->table6_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "6号按钮聚焦状态";
      ui->chair61->setStyleSheet("background-color: blue;");
      ui->chair62->setStyleSheet("background-color: blue;");
      ui->chair63->setStyleSheet("background-color: blue;");
      ui->chair64->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "6号按钮非聚焦状态";
      ui->chair61->setStyleSheet("background-color: white;");
      ui->chair62->setStyleSheet("background-color: white;");
      ui->chair63->setStyleSheet("background-color: white;");
      ui->chair64->setStyleSheet("background-color: white;");

    }

}

void MainWindow::on_table4_bt_clicked()
{
    // 检查按钮1状态
    QPushButton* button = ui->pushButton_22;
    bool isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "1号按钮聚焦状态";
      ui->chair11->setStyleSheet("background-color: blue;");
      ui->chair12->setStyleSheet("background-color: blue;");
      ui->chair13->setStyleSheet("background-color: blue;");
      ui->chair14->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "1号按钮非聚焦状态";
      ui->chair11->setStyleSheet("background-color: white;");
      ui->chair12->setStyleSheet("background-color: white;");
      ui->chair13->setStyleSheet("background-color: white;");
      ui->chair14->setStyleSheet("background-color: white;");

    }

    // 检查按钮状态2
    button = ui->table2_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "2号按钮聚焦状态";
      ui->chair21->setStyleSheet("background-color: blue;");
      ui->chair22->setStyleSheet("background-color: blue;");
      ui->chair23->setStyleSheet("background-color: blue;");
      ui->chair24->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "2号按钮非聚焦状态";
      ui->chair21->setStyleSheet("background-color: white;");
      ui->chair22->setStyleSheet("background-color: white;");
      ui->chair23->setStyleSheet("background-color: white;");
      ui->chair24->setStyleSheet("background-color: white;");

    }

    // 检查按钮状态3
    button = ui->table3_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "3号按钮聚焦状态";
      ui->chair31->setStyleSheet("background-color: blue;");
      ui->chair32->setStyleSheet("background-color: blue;");
      ui->chair33->setStyleSheet("background-color: blue;");
      ui->chair34->setStyleSheet("background-color: blue;");
      ui->chair35->setStyleSheet("background-color: blue;");
      ui->chair36->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "3号按钮非聚焦状态";
      ui->chair31->setStyleSheet("background-color: white;");
      ui->chair32->setStyleSheet("background-color: white;");
      ui->chair33->setStyleSheet("background-color: white;");
      ui->chair34->setStyleSheet("background-color: white;");
      ui->chair35->setStyleSheet("background-color: white;");
      ui->chair36->setStyleSheet("background-color: white;");
    }

    //检查按钮状态4
    button = ui->table4_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "4号按钮聚焦状态";
      ui->chair41->setStyleSheet("background-color: blue;");
      ui->chair42->setStyleSheet("background-color: blue;");

    }
    else
    {
      qDebug() << "4号按钮非聚焦状态";
      ui->chair41->setStyleSheet("background-color: white;");
      ui->chair42->setStyleSheet("background-color: white;");
    }

    // 检查按钮状态5
    button = ui->table5_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "5号按钮聚焦状态";
      ui->chair51->setStyleSheet("background-color: blue;");
      ui->chair52->setStyleSheet("background-color: blue;");
      ui->chair53->setStyleSheet("background-color: blue;");
      ui->chair54->setStyleSheet("background-color: blue;");
      ui->chair55->setStyleSheet("background-color: blue;");
      ui->chair56->setStyleSheet("background-color: blue;");
      ui->chair57->setStyleSheet("background-color: blue;");
      ui->chair58->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "5号按钮非聚焦状态";
      ui->chair51->setStyleSheet("background-color: white;");
      ui->chair52->setStyleSheet("background-color: white;");
      ui->chair53->setStyleSheet("background-color: white;");
      ui->chair54->setStyleSheet("background-color: white;");
      ui->chair55->setStyleSheet("background-color: white;");
      ui->chair56->setStyleSheet("background-color: white;");
      ui->chair57->setStyleSheet("background-color: white;");
      ui->chair58->setStyleSheet("background-color: white;");
    }

    // 检查按钮状态6
    button = ui->table6_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "6号按钮聚焦状态";
      ui->chair61->setStyleSheet("background-color: blue;");
      ui->chair62->setStyleSheet("background-color: blue;");
      ui->chair63->setStyleSheet("background-color: blue;");
      ui->chair64->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "6号按钮非聚焦状态";
      ui->chair61->setStyleSheet("background-color: white;");
      ui->chair62->setStyleSheet("background-color: white;");
      ui->chair63->setStyleSheet("background-color: white;");
      ui->chair64->setStyleSheet("background-color: white;");

    }

}

void MainWindow::on_table5_bt_clicked()
{
    // 检查按钮1状态
    QPushButton* button = ui->pushButton_22;
    bool isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "1号按钮聚焦状态";
      ui->chair11->setStyleSheet("background-color: blue;");
      ui->chair12->setStyleSheet("background-color: blue;");
      ui->chair13->setStyleSheet("background-color: blue;");
      ui->chair14->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "1号按钮非聚焦状态";
      ui->chair11->setStyleSheet("background-color: white;");
      ui->chair12->setStyleSheet("background-color: white;");
      ui->chair13->setStyleSheet("background-color: white;");
      ui->chair14->setStyleSheet("background-color: white;");

    }

    // 检查按钮状态2
    button = ui->table2_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "2号按钮聚焦状态";
      ui->chair21->setStyleSheet("background-color: blue;");
      ui->chair22->setStyleSheet("background-color: blue;");
      ui->chair23->setStyleSheet("background-color: blue;");
      ui->chair24->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "2号按钮非聚焦状态";
      ui->chair21->setStyleSheet("background-color: white;");
      ui->chair22->setStyleSheet("background-color: white;");
      ui->chair23->setStyleSheet("background-color: white;");
      ui->chair24->setStyleSheet("background-color: white;");

    }

    // 检查按钮状态3
    button = ui->table3_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "3号按钮聚焦状态";
      ui->chair31->setStyleSheet("background-color: blue;");
      ui->chair32->setStyleSheet("background-color: blue;");
      ui->chair33->setStyleSheet("background-color: blue;");
      ui->chair34->setStyleSheet("background-color: blue;");
      ui->chair35->setStyleSheet("background-color: blue;");
      ui->chair36->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "3号按钮非聚焦状态";
      ui->chair31->setStyleSheet("background-color: white;");
      ui->chair32->setStyleSheet("background-color: white;");
      ui->chair33->setStyleSheet("background-color: white;");
      ui->chair34->setStyleSheet("background-color: white;");
      ui->chair35->setStyleSheet("background-color: white;");
      ui->chair36->setStyleSheet("background-color: white;");
    }

    //检查按钮状态4
    button = ui->table4_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "4号按钮聚焦状态";
      ui->chair41->setStyleSheet("background-color: blue;");
      ui->chair42->setStyleSheet("background-color: blue;");

    }
    else
    {
      qDebug() << "4号按钮非聚焦状态";
      ui->chair41->setStyleSheet("background-color: white;");
      ui->chair42->setStyleSheet("background-color: white;");
    }

    // 检查按钮状态5
    button = ui->table5_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "5号按钮聚焦状态";
      ui->chair51->setStyleSheet("background-color: blue;");
      ui->chair52->setStyleSheet("background-color: blue;");
      ui->chair53->setStyleSheet("background-color: blue;");
      ui->chair54->setStyleSheet("background-color: blue;");
      ui->chair55->setStyleSheet("background-color: blue;");
      ui->chair56->setStyleSheet("background-color: blue;");
      ui->chair57->setStyleSheet("background-color: blue;");
      ui->chair58->setStyleSheet("background-color: blue;");
      ui->stackedWidget_5->setCurrentIndex(0);
    }
    else
    {
      qDebug() << "5号按钮非聚焦状态";
      ui->chair51->setStyleSheet("background-color: white;");
      ui->chair52->setStyleSheet("background-color: white;");
      ui->chair53->setStyleSheet("background-color: white;");
      ui->chair54->setStyleSheet("background-color: white;");
      ui->chair55->setStyleSheet("background-color: white;");
      ui->chair56->setStyleSheet("background-color: white;");
      ui->chair57->setStyleSheet("background-color: white;");
      ui->chair58->setStyleSheet("background-color: white;");
    }

    // 检查按钮状态6
    button = ui->table6_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "6号按钮聚焦状态";
      ui->chair61->setStyleSheet("background-color: blue;");
      ui->chair62->setStyleSheet("background-color: blue;");
      ui->chair63->setStyleSheet("background-color: blue;");
      ui->chair64->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "6号按钮非聚焦状态";
      ui->chair61->setStyleSheet("background-color: white;");
      ui->chair62->setStyleSheet("background-color: white;");
      ui->chair63->setStyleSheet("background-color: white;");
      ui->chair64->setStyleSheet("background-color: white;");

    }

}

void MainWindow::on_table6_bt_clicked()
{
    // 检查按钮1状态
    QPushButton* button = ui->pushButton_22;
    bool isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "1号按钮聚焦状态";
      ui->chair11->setStyleSheet("background-color: blue;");
      ui->chair12->setStyleSheet("background-color: blue;");
      ui->chair13->setStyleSheet("background-color: blue;");
      ui->chair14->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "1号按钮非聚焦状态";
      ui->chair11->setStyleSheet("background-color: white;");
      ui->chair12->setStyleSheet("background-color: white;");
      ui->chair13->setStyleSheet("background-color: white;");
      ui->chair14->setStyleSheet("background-color: white;");

    }

    // 检查按钮状态2
    button = ui->table2_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "2号按钮聚焦状态";
      ui->chair21->setStyleSheet("background-color: blue;");
      ui->chair22->setStyleSheet("background-color: blue;");
      ui->chair23->setStyleSheet("background-color: blue;");
      ui->chair24->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "2号按钮非聚焦状态";
      ui->chair21->setStyleSheet("background-color: white;");
      ui->chair22->setStyleSheet("background-color: white;");
      ui->chair23->setStyleSheet("background-color: white;");
      ui->chair24->setStyleSheet("background-color: white;");

    }

    // 检查按钮状态3
    button = ui->table3_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "3号按钮聚焦状态";
      ui->chair31->setStyleSheet("background-color: blue;");
      ui->chair32->setStyleSheet("background-color: blue;");
      ui->chair33->setStyleSheet("background-color: blue;");
      ui->chair34->setStyleSheet("background-color: blue;");
      ui->chair35->setStyleSheet("background-color: blue;");
      ui->chair36->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "3号按钮非聚焦状态";
      ui->chair31->setStyleSheet("background-color: white;");
      ui->chair32->setStyleSheet("background-color: white;");
      ui->chair33->setStyleSheet("background-color: white;");
      ui->chair34->setStyleSheet("background-color: white;");
      ui->chair35->setStyleSheet("background-color: white;");
      ui->chair36->setStyleSheet("background-color: white;");
    }

    //检查按钮状态4
    button = ui->table4_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "4号按钮聚焦状态";
      ui->chair41->setStyleSheet("background-color: blue;");
      ui->chair42->setStyleSheet("background-color: blue;");

    }
    else
    {
      qDebug() << "4号按钮非聚焦状态";
      ui->chair41->setStyleSheet("background-color: white;");
      ui->chair42->setStyleSheet("background-color: white;");
    }

    // 检查按钮状态5
    button = ui->table5_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "5号按钮聚焦状态";
      ui->chair51->setStyleSheet("background-color: blue;");
      ui->chair52->setStyleSheet("background-color: blue;");
      ui->chair53->setStyleSheet("background-color: blue;");
      ui->chair54->setStyleSheet("background-color: blue;");
      ui->chair55->setStyleSheet("background-color: blue;");
      ui->chair56->setStyleSheet("background-color: blue;");
      ui->chair57->setStyleSheet("background-color: blue;");
      ui->chair58->setStyleSheet("background-color: blue;");
      ui->stackedWidget_5->setCurrentIndex(0);
    }
    else
    {
      qDebug() << "5号按钮非聚焦状态";
      ui->chair51->setStyleSheet("background-color: white;");
      ui->chair52->setStyleSheet("background-color: white;");
      ui->chair53->setStyleSheet("background-color: white;");
      ui->chair54->setStyleSheet("background-color: white;");
      ui->chair55->setStyleSheet("background-color: white;");
      ui->chair56->setStyleSheet("background-color: white;");
      ui->chair57->setStyleSheet("background-color: white;");
      ui->chair58->setStyleSheet("background-color: white;");
    }

    // 检查按钮状态6
    button = ui->table6_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "6号按钮聚焦状态";
      ui->chair61->setStyleSheet("background-color: blue;");
      ui->chair62->setStyleSheet("background-color: blue;");
      ui->chair63->setStyleSheet("background-color: blue;");
      ui->chair64->setStyleSheet("background-color: blue;");
      ui->stackedWidget_5->setCurrentIndex(0);
    }
    else
    {
      qDebug() << "6号按钮非聚焦状态";
      ui->chair61->setStyleSheet("background-color: white;");
      ui->chair62->setStyleSheet("background-color: white;");
      ui->chair63->setStyleSheet("background-color: white;");
      ui->chair64->setStyleSheet("background-color: white;");

    }

}

void MainWindow::on_table3_bt_clicked()
{
    // 检查按钮1状态
    QPushButton* button = ui->pushButton_22;
    bool isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "1号按钮聚焦状态";
      ui->chair11->setStyleSheet("background-color: blue;");
      ui->chair12->setStyleSheet("background-color: blue;");
      ui->chair13->setStyleSheet("background-color: blue;");
      ui->chair14->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "1号按钮非聚焦状态";
      ui->chair11->setStyleSheet("background-color: white;");
      ui->chair12->setStyleSheet("background-color: white;");
      ui->chair13->setStyleSheet("background-color: white;");
      ui->chair14->setStyleSheet("background-color: white;");

    }

    // 检查按钮状态2
    button = ui->table2_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "2号按钮聚焦状态";
      ui->chair21->setStyleSheet("background-color: blue;");
      ui->chair22->setStyleSheet("background-color: blue;");
      ui->chair23->setStyleSheet("background-color: blue;");
      ui->chair24->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "2号按钮非聚焦状态";
      ui->chair21->setStyleSheet("background-color: white;");
      ui->chair22->setStyleSheet("background-color: white;");
      ui->chair23->setStyleSheet("background-color: white;");
      ui->chair24->setStyleSheet("background-color: white;");

    }

    // 检查按钮状态3
    button = ui->table3_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "3号按钮聚焦状态";
      ui->chair31->setStyleSheet("background-color: blue;");
      ui->chair32->setStyleSheet("background-color: blue;");
      ui->chair33->setStyleSheet("background-color: blue;");
      ui->chair34->setStyleSheet("background-color: blue;");
      ui->chair35->setStyleSheet("background-color: blue;");
      ui->chair36->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "3号按钮非聚焦状态";
      ui->chair31->setStyleSheet("background-color: white;");
      ui->chair32->setStyleSheet("background-color: white;");
      ui->chair33->setStyleSheet("background-color: white;");
      ui->chair34->setStyleSheet("background-color: white;");
      ui->chair35->setStyleSheet("background-color: white;");
      ui->chair36->setStyleSheet("background-color: white;");
    }

    //检查按钮状态4
    button = ui->table4_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "4号按钮聚焦状态";
      ui->chair41->setStyleSheet("background-color: blue;");
      ui->chair42->setStyleSheet("background-color: blue;");

    }
    else
    {
      qDebug() << "4号按钮非聚焦状态";
      ui->chair41->setStyleSheet("background-color: white;");
      ui->chair42->setStyleSheet("background-color: white;");
    }

    // 检查按钮状态5
    button = ui->table5_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "5号按钮聚焦状态";
      ui->chair51->setStyleSheet("background-color: blue;");
      ui->chair52->setStyleSheet("background-color: blue;");
      ui->chair53->setStyleSheet("background-color: blue;");
      ui->chair54->setStyleSheet("background-color: blue;");
      ui->chair55->setStyleSheet("background-color: blue;");
      ui->chair56->setStyleSheet("background-color: blue;");
      ui->chair57->setStyleSheet("background-color: blue;");
      ui->chair58->setStyleSheet("background-color: blue;");
      ui->stackedWidget_5->setCurrentIndex(0);
    }
    else
    {
      qDebug() << "5号按钮非聚焦状态";
      ui->chair51->setStyleSheet("background-color: white;");
      ui->chair52->setStyleSheet("background-color: white;");
      ui->chair53->setStyleSheet("background-color: white;");
      ui->chair54->setStyleSheet("background-color: white;");
      ui->chair55->setStyleSheet("background-color: white;");
      ui->chair56->setStyleSheet("background-color: white;");
      ui->chair57->setStyleSheet("background-color: white;");
      ui->chair58->setStyleSheet("background-color: white;");
    }

    // 检查按钮状态6
    button = ui->table6_bt;
    isPressed = button->hasFocus();

    if(isPressed)
    {
      qDebug() << "6号按钮聚焦状态";
      ui->chair61->setStyleSheet("background-color: blue;");
      ui->chair62->setStyleSheet("background-color: blue;");
      ui->chair63->setStyleSheet("background-color: blue;");
      ui->chair64->setStyleSheet("background-color: blue;");
    }
    else
    {
      qDebug() << "6号按钮非聚焦状态";
      ui->chair61->setStyleSheet("background-color: white;");
      ui->chair62->setStyleSheet("background-color: white;");
      ui->chair63->setStyleSheet("background-color: white;");
      ui->chair64->setStyleSheet("background-color: white;");

    }

}

void MainWindow::on_pushButton_24_clicked()
{
    QSqlTableModel model;  //自动关联到默认的数据库
    model.setTable("ding");//绑定数据库表格

    // 从数据库中选择数据
    model.select();

    // 获取第一行数据
    QString order_num = model.record(0).value("order_num").toString();
    QString table_num = model.record(0).value("table_num").toString();
    QString xiaoji = model.record(0).value("xiaoji").toString();
    QString heji = model.record(0).value("heji").toString();
    QString payway = model.record(0).value("payway").toString();

    QString food1_name = model.record(0).value("food1_name").toString();
    QString food1_num = model.record(0).value("food1_num").toString();
    QString food1_piece = model.record(0).value("food1_piece").toString();
    int food1_sum = food1_num.toInt()*food1_piece.toInt();

    QString food2_name = model.record(0).value("food2_name").toString();
    QString food2_num = model.record(0).value("food2_num").toString();
    QString food2_piece = model.record(0).value("food2_piece").toString();
    int food2_sum = food2_num.toInt()*food2_piece.toInt();

    QString food3_name = model.record(0).value("food3_name").toString();
    QString food3_num = model.record(0).value("food3_num").toString();
    QString food3_piece = model.record(0).value("food3_piece").toString();
    int food3_sum = food3_num.toInt()*food3_piece.toInt();

    qDebug()<<"名字"<<food3_name;
    ui->tableWidget_3->setCellWidget(0, 0, ui->order1);
    if(food2_name =="name")
    {
        qDebug()<<"第二个菜品不存在";
    }
    else{ui->tableWidget_3->setCellWidget(1, 0, ui->order2);qDebug()<<"第二个菜品存在";}
    if(food3_name !="name")
    {
        ui->tableWidget_3->setCellWidget(2, 0, ui->order3);
        qDebug()<<"第三个菜品存在";
    }
    ui->order1_name->setText(food1_name);
    ui->order1_num->setText(food1_num);
    ui->order1_piece->setText(food1_piece);
    ui->order1_sum->setText(QString::number(food1_sum));

    ui->order2_name->setText(food2_name);
    ui->order2_num->setText(food2_num);
    ui->order2_piece->setText(food2_piece);
    ui->order2_sum->setText(QString::number(food2_sum));

    ui->order3_name->setText(food3_name);
    ui->order3_num->setText(food3_num);
    ui->order3_piece->setText(food3_piece);
    ui->order3_sum->setText(QString::number(food3_sum));

    ui->xiaoji->setText(xiaoji);
    ui->heji->setText(heji);

    ui->ding_num->setText(order_num);
    ui->zhuo_num->setText(table_num);

    if(payway == "cash") {ui->cash->setStyleSheet("font:20px kai;border-radius:10px;background-color: rgb(0, 170, 255);");}
    if(payway == "wechat") {ui->wechat->setStyleSheet("font:20px kai;border-radius:10px;background-color: rgb(0, 170, 255);");}
    if(payway == "Alipay") {ui->Alipay->setStyleSheet("font:20px kai;border-radius:10px;background-color: rgb(0, 170, 255);");}

    ui->pay->setStyleSheet("font:20px kai;border-radius:10px;background-color: rgb(0, 170, 255);");

}

void MainWindow::on_pushButton_25_clicked()
{
    QSqlTableModel model;  //自动关联到默认的数据库
    model.setTable("ding");//绑定数据库表格

    // 从数据库中选择数据
    model.select();

    // 获取第一行数据
    QString order_num = model.record(1).value("order_num").toString();
    QString table_num = model.record(1).value("table_num").toString();
    QString xiaoji = model.record(1).value("xiaoji").toString();
    QString heji = model.record(1).value("heji").toString();
    QString payway = model.record(1).value("payway").toString();

    QString food1_name = model.record(1).value("food1_name").toString();
    QString food1_num = model.record(1).value("food1_num").toString();
    QString food1_piece = model.record(1).value("food1_piece").toString();
    int food1_sum = food1_num.toInt()*food1_piece.toInt();

    QString food2_name = model.record(1).value("food2_name").toString();
    QString food2_num = model.record(1).value("food2_num").toString();
    QString food2_piece = model.record(1).value("food2_piece").toString();
    int food2_sum = food2_num.toInt()*food2_piece.toInt();

    QString food3_name = model.record(1).value("food3_name").toString();
    QString food3_num = model.record(1).value("food3_num").toString();
    QString food3_piece = model.record(1).value("food3_piece").toString();
    int food3_sum = food3_num.toInt()*food3_piece.toInt();

    ui->tableWidget_3->setCellWidget(0, 0, ui->order1);
    if(food2_name =="name")
    {
        qDebug()<<"第二个菜品不存在";
    }
    else{ui->tableWidget_3->setCellWidget(1, 0, ui->order2);qDebug()<<"第二个菜品存在";}
    if(food3_name !="name")
    {
        ui->tableWidget_3->setCellWidget(2, 0, ui->order3);
        qDebug()<<"第三个菜品存在";
    }

    ui->order1_name->setText(food1_name);
    ui->order1_num->setText(food1_num);
    ui->order1_piece->setText(food1_piece);
    ui->order1_sum->setText(QString::number(food1_sum));

    ui->order2_name->setText(food2_name);
    ui->order2_num->setText(food2_num);
    ui->order2_piece->setText(food2_piece);
    ui->order2_sum->setText(QString::number(food2_sum));

    ui->order3_name->setText(food3_name);
    ui->order3_num->setText(food3_num);
    ui->order3_piece->setText(food3_piece);
    ui->order3_sum->setText(QString::number(food3_sum));

    ui->xiaoji->setText(xiaoji);
    ui->heji->setText(heji);

    ui->ding_num->setText(order_num);
    ui->zhuo_num->setText(table_num);

    if(payway == "cash")
    {
        ui->cash->setStyleSheet("font:20px kai;border-radius:10px;background-color: rgb(0, 170, 255);");
        ui->wechat->setStyleSheet("font:20px kai;border-radius:10px;background-color: rgb(255, 255, 255);");
        ui->Alipay->setStyleSheet("font:20px kai;border-radius:10px;background-color: rgb(255, 255, 255);");
    }
    if(payway == "wechat")
    {
        ui->wechat->setStyleSheet("font:20px kai;border-radius:10px;background-color: rgb(0, 170, 255);");
        ui->Alipay->setStyleSheet("font:20px kai;border-radius:10px;background-color: rgb(255, 255, 255);");
        ui->cash->setStyleSheet("font:20px kai;border-radius:10px;background-color: rgb(255, 255, 255);");
    }
    if(payway == "Alipay")
    {
        ui->wechat->setStyleSheet("font:20px kai;border-radius:10px;background-color: rgb(255, 255, 255);");
        ui->Alipay->setStyleSheet("font:20px kai;border-radius:10px;background-color: rgb(0, 170, 255);");
        ui->cash->setStyleSheet("font:20px kai;border-radius:10px;background-color: rgb(255, 255, 255);");
    }

    ui->pay->setStyleSheet("font:20px kai;border-radius:10px;background-color: rgb(0, 170, 255);");

}

void MainWindow::on_rebt_clicked()
{
      ;
}

void MainWindow::on_pay_clicked()
{
    ;
}
