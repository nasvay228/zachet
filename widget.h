#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT


public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    int ball_y;
    int ball_x;
    int schet;
    int x = 10;
    int y = 10;
    int r;
    int started;

private:
    Ui::Widget *ui;
    QTimer timer;
protected:
    void mousePressEvent(QMouseEvent * e);
    void paintEvent(QPaintEvent * e);

protected slots:
    bool checkCoords(int x, int y);
    void move(int w,int h);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


};

#endif // WIDGET_H
