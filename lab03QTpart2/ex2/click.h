#ifndef CLICK_H
#define CLICK_H

#include <QMainWindow>
#include <QLabel>
#include <QKeyEvent>
#include <QMouseEvent>

class Click : public QMainWindow
{
    Q_OBJECT

public:
    Click(QWidget *parent = nullptr);
    ~Click();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    QLabel *label;
};

#endif // CLICK_H
