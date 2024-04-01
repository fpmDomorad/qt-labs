#include "carefulpositioning.h"


CarefulPos::CarefulPos(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Careful positioning");
    setGeometry(100, 100, 400, 200);

    verticalSlider = new QSlider(Qt::Vertical, this);
    verticalSlider->setRange(0, 100);//установка диаразона по вертикали
    connect(verticalSlider, &QSlider::valueChanged, this, &CarefulPos::sliderMoved);//подключение вертикального слайдера

    horizontalSlider = new QSlider(Qt::Horizontal, this);
    horizontalSlider->setRange(0, 100);//установка диаразона по горизонтали
    connect(horizontalSlider, &QSlider::valueChanged, this, &CarefulPos::sliderMoved);//подключение горизонтального слайдера

    button = new QPushButton("Тык", this);
    button->move((width() - button->width()) / 2, (height() - button->height()) / 2);//расположение кнопки по центру окна

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(verticalSlider);
    layout->addWidget(horizontalSlider);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

CarefulPos::~CarefulPos()
{
}

void CarefulPos::sliderMoved(int value)
{
    QPoint pos = button->pos();

    pos.setX(horizontalSlider->value());//перемещение позициии по X (по горизонтали)
    pos.setY(this->height() - button->height() - verticalSlider->value());//переммещение позиции по Y (по вертикали)

    button->move(pos);//перемещение кнопки вместе с слайдером(и по горизонтали, и по вертикали)
}

