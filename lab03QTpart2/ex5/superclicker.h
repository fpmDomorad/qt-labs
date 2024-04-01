#ifndef SUPERCLICKER_H
#define SUPERCLICKER_H

#include <QMainWindow>
#include <QPushButton>
#include <QSpinBox>
#include <QProgressBar>
#include <QBoxLayout>

class Clicker : public QMainWindow
{
    Q_OBJECT

public:
    Clicker(QWidget *parent = nullptr);
    ~Clicker();

private slots:
    void moveProgressBar();

private:
    QSpinBox *spinBox;
    QPushButton *button;
    QProgressBar *progressBar;
    int totalClicks;
};

#endif // SUPERCLICKER_H
