#ifndef FORMAL_PRO_H
#define FORMAL_PRO_H

#include <QWidget>
#include "qcustomplot.h"
#include <QTimer>

//port
#include <QSerialPort>
//debug
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class formal_pro; }
QT_END_NAMESPACE

class formal_pro : public QWidget
{
    Q_OBJECT

public:
    formal_pro(QWidget *parent = nullptr);
    ~formal_pro();
    //设置qcustomplot画图属性，实时
    void setupRealtimeDataDemo(QCustomPlot *customPlot);
    int n;


//定义槽函数
private slots:
    //button

    void btn_open_port(bool);
    void btn_close_port(bool);
    void btn_send_data(bool);

    //received data
    void receive_data();


private:
    Ui::formal_pro *ui;
    /*-----------------------------function------------------------------------*/
    void system_int();
    /*---------------------------variable-------------------------------------------*/
    QSerialPort global_port;  //直接定义

    //定时器，周期调用realtimeDataSlot()槽，实现动态数据添加到曲线
    QTimer dataTimer;
};
#endif // FORMAL_PRO_H
