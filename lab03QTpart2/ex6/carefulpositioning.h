#ifndef CAIREFULPOSITIONING_H
#define CAIREFULPOSITIONING_H

#include <QMainWindow>
#include <QSlider>
#include <QPushButton>
#include <QVBoxLayout>

class CarefulPos : public QMainWindow
{
    Q_OBJECT

public:
    CarefulPos(QWidget *parent = nullptr);
    ~CarefulPos();

private slots:
    void sliderMoved(int value);//перемещение слайдера

private:
    QSlider *verticalSlider;
    QSlider *horizontalSlider;
    QPushButton *button;
};

#endif // CAIREFULPOSITIONING_H
