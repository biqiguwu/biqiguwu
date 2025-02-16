#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedLayout>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int xia_num = 0;
    int rose_num = 0;
    int xianggu_num = 0;
    int meicai_num = 0;
    int new_num = 0;

    int order_row = 0;

    int order_sql = 0;

    int flag1 = 0;
    int flag2 = 0;
public slots:
    void receivemessage();
    void receivetable();
    void receiveliuyan();
signals:
    void back();//定义一个信号
    void sendMessage();

private slots:
    void on_menu_clicked();

    void on_table_clicked();

    void on_searchbt_clicked();

    void on_order_clicked();

    void on_comknow_clicked();

    void on_message_clicked();

    void on_my_clicked();

    void on_mainfood_clicked();

    void on_specialfood_clicked();

    void on_soup_clicked();

    void on_snack_clicked();

    void on_drink_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_personbt_clicked();

    void on_xia_jia_clicked();

    void on_xia_jian_clicked();

    void on_rose_jia_clicked();

    void on_rose_jian_clicked();

    void on_mei_jian_clicked();

    void on_mei_jian_triggered(QAction *arg1);

    void on_pushButton_2_clicked();

    void on_filebt_clicked();

    void on_pushButton_10_clicked();

    void on_new_jian_clicked();

    void on_new_jia_clicked();

    void on_xia_bt_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_22_clicked();

    void on_table1_bt_clicked();

    void on_table2_bt_clicked();

    void on_table4_bt_clicked();

    void on_table5_bt_clicked();

    void on_table6_bt_clicked();

    void on_table3_bt_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_rebt_clicked();

    void on_pay_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
