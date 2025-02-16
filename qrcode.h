#ifndef QRCODE_H
#define QRCODE_H

#include <QWidget>

namespace Ui {
class Qrcode;
}

class Qrcode : public QWidget
{
    Q_OBJECT

public:
    explicit Qrcode(QWidget *parent = nullptr);
    ~Qrcode();

private:
    Ui::Qrcode *ui;
};

#endif // QRCODE_H
