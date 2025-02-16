#include "qrcode.h"
#include "ui_qrcode.h"

Qrcode::Qrcode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Qrcode)
{
    ui->setupUi(this);
}

Qrcode::~Qrcode()
{
    delete ui;
}
