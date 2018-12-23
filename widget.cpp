#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    int width = this->width();
    int height = this->height();
    r = 50;
    painter.setPen(Qt::red);
    painter.drawRect(0,0,width-1,height-1);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::blue);
    painter.drawEllipse(QPoint(x,y),r,r);
    qDebug()<<x;
    qDebug()<<y;
}
void Widget::move(int w,int h)
{
    if (x+r+5>=w || x-r<=0){
           ball_x *= -1;
       }
       if (y+r+5>=h || y-r<=0){
           ball_y *= -1;
       }
       x += ball_x;
       y += ball_y;

}
void Widget::mousePressEvent(QMouseEvent *e)
{
    if (r*r>(ball_x - e->x())*(ball_x - e->x())+(ball_y - e->y())*(ball_y - e->y()))
    {
        ui->lcdNumber->display(schet);
        schet += 1;
    }
}
bool Widget::checkCoords(int x, int y)
    {
        if (ball_x == x and ball_y == y){
            return true;
        }
        else{
            return false;
        }

}

void Widget::on_pushButton_clicked()
{
    this->close();
}

void Widget::on_pushButton_2_clicked()
{

    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->lcdNumber->show();
    schet = 0;
    started = true;
}
