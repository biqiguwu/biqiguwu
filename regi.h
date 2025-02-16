#ifndef REGI_H
#define REGI_H

#include <QSqlTableModel>
#include <QWidget>

namespace Ui {
class regi;
}

class regi : public QWidget
{
    Q_OBJECT

public:
    explicit regi(QWidget *parent = nullptr);
    ~regi();

private slots:
    void on_retbt_clicked();

    void on_pushButton_clicked();

    void on_resbt_clicked();

    void on_regbt_clicked();

    void on_regbt_2_clicked();

private:
    Ui::regi *ui;
    QSqlTableModel *mdl;
};

#endif // REGI_H
