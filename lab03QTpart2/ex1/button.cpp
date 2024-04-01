#include "button.h"
#include "ui_button.h"


Button::Button(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Поймай меня, если сможешь");
    setGeometry(100, 100, 400, 200);
    button = new QPushButton("Тык", this);
    button->setGeometry(150, 100, 100, 30);
    connect(button, &QPushButton::clicked, this, &Button::buttonClicked);
    button->installEventFilter(this);
}

Button::~Button()
{
}

void Button::buttonHovered()
{
    int newX = QRandomGenerator::global()->bounded(0, width() - button->width());
    int newY = QRandomGenerator::global()->bounded(0, height() - button->height());
    button->move(newX, newY);
}

void Button::buttonClicked()
{
    QColor color = QColor::fromRgb(QRandomGenerator::global()->bounded(256),
                                   QRandomGenerator::global()->bounded(256),
                                   QRandomGenerator::global()->bounded(256));
    QString style = QString("background-color: %1").arg(color.name());
    button->setStyleSheet(style);
}

bool Button::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == button && event->type() == QEvent::Enter) {
        buttonHovered();
    }
    return QMainWindow::eventFilter(obj, event);
}
