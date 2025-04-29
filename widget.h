#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pb10_clicked();

    void on_pb100_clicked();

    void on_pb50_clicked();

    void on_pb500_clicked();

    void on_buyCoffee_clicked();

    void on_buyTea_clicked();

    void on_BuyMilk_clicked();

    void on_Reset_clicked();

private:
    Ui::Widget *ui;
    void changeMoney(int money);
    void checkAvailable();
    int money;
};
#endif // WIDGET_H
