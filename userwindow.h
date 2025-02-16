#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>

namespace Ui {
class userWindow;
}

class userWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit userWindow(QWidget *parent = nullptr);
    ~userWindow();

    int xia_num = 0;
    int rose_num = 0;
    int xianggu_num = 0;
    int meicai_num = 0;
    int soup1_num = 0;
    int soup2_num = 0;
    int snack1_num = 0;
    int snack2_num = 0;
    int drink1_num = 0;
    int drink2_num = 0;

    int new_num = 0;

    int order_row = 0;
    int xia_row = -1;
    int rose_row = -1;
    int new_row = -1;

    int xiaoji = 0;
    int heji = 0;

    int xia_sum = 0;
    int rose_sum = 0;

    int widget_index = 0;

public slots:
    void receiveMessage();

signals:
    void back();//定义一个信号
    void sendmessage();
    void sendtable();
    void sendliuyan();

private slots:
    void on_menu_clicked();

    void on_table_clicked();

    void on_comknow_clicked();

    void on_message_clicked();

    void on_my_clicked();

    void on_xia_jia_clicked();

    void on_xia_jian_clicked();

    void on_rose_jian_clicked();

    void on_rose_jia_clicked();

    void on_mei_jian_clicked();

    void on_mei_jia_clicked();

    void on_gu_jian_clicked();

    void on_gu_jia_clicked();

    void on_soup1_jian_clicked();

    void on_soup1_jia_clicked();

    void on_soup2_jian_clicked();

    void on_soup2_jia_clicked();

    void on_meicai_jian_10_clicked();

    void on_snack2_jia_clicked();

    void on_snack1_jian_clicked();

    void on_snack1_jia_clicked();

    void on_drink1_jia_clicked();

    void on_drink1_jian_clicked();

    void on_mainfood_clicked();

    void on_specialfood_clicked();

    void on_snack_clicked();

    void on_soup_clicked();

    void on_drink_clicked();

    void on_xia_bt_clicked();

    void on_xia_bt_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_new_jian_clicked();

    void on_new_jia_clicked();

    void on_new_car_clicked();

    void on_pushButton_63_clicked();

    void on_cash_bt_clicked();

    void on_wechat_bt_clicked();

    void on_Alipay_bt_clicked();

    void on_rebt_clicked();

    void on_xia_jia_triggered(QAction *arg1);

    void on_change_bt_clicked();

    void on_submit_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::userWindow *ui;
};

#endif // USERWINDOW_H
