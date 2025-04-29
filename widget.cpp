#include "widget.h"
#include "./ui_widget.h"
#include <QMessageBox>

const int COFFEE_PRICE=100;
const int TEA_PRICE=150;
const int MILK_PRICE=200;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    checkAvailable();
    money=0;
}

Widget::~Widget()
{
    delete ui;
}
void Widget::checkAvailable(){
    ui->buyCoffee->setEnabled(money-COFFEE_PRICE>=0);
    ui->buyTea->setEnabled(money-TEA_PRICE>=0);
    ui->BuyMilk->setEnabled(money-MILK_PRICE>=0);
    ui->Reset->setEnabled(money>0);
}
void Widget::changeMoney(int diff){
    if(money+diff>=0){
        money+=diff;
        ui->lcdNumber->display(money);
        checkAvailable();
    }
    else{
        QMessageBox::warning(this, "경고", "잔액이 부족합니다!");
    }

}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_buyCoffee_clicked()
{
    changeMoney(-COFFEE_PRICE);

}


void Widget::on_buyTea_clicked()
{
    changeMoney(-TEA_PRICE);
}


void Widget::on_BuyMilk_clicked()
{
    changeMoney(-MILK_PRICE);
}


void Widget::on_Reset_clicked()
{
    int m = money;

    int n500 = m / 500;
    m %= 500;

    int n100 = m / 100;
    m %= 100;

    int n50 = m / 50;
    m %= 50;

    int n10 = m / 10;

    QString msg;
    msg = "500원: " + QString::number(n500) + "개\n" +
          "100원: " + QString::number(n100) + "개\n" +
          "50원: " + QString::number(n50) + "개\n" +
          "10원: " + QString::number(n10) + "개";
    QMessageBox::information(this, "잔돈 반환", msg);

    changeMoney(-money);
}

