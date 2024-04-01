#ifndef BUTTON_H
#define BUTTON_H

#include <QMainWindow>
#include <QPushButton>
#include <QEvent>
#include <QRandomGenerator>

class Button : public QMainWindow
{
    Q_OBJECT

public:
    Button(QWidget *parent = nullptr);
    ~Button();

protected:
    void buttonHovered();
    void buttonClicked();
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    QPushButton *button;
};

#endif // BUTTON_H
