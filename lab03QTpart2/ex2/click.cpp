#include "click.h"

Click::Click(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Click");
    setGeometry(200, 200, 800, 400);
    label = new QLabel("Нажми мышкой или тыкни на пробел", this);
    label->setStyleSheet("font-size: 21px; font-family: Arial;");
    label->setGeometry(200, 100, 350, 100);
}

Click::~Click()
{
}

void Click::mousePressEvent(QMouseEvent *event)
{
    label->setText("Щелчок");
}

void Click::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space) {
       label->setText("Ой!");
    }
}
