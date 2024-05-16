#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBasicTimer>
#include <QTimerEvent>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QSlider>

enum class DirectionTypes {
    kLeft,
    kRight,
    kUp,
};

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    MainWindow();
    void SetupScene();
    void SetupVini();

    void timerEvent(QTimerEvent* event) override;

private:
    QGraphicsScene* scene_;
    QGraphicsView* view_;
    QPixmap vini_;
    QGraphicsPixmapItem* vini_item_;
    QPixmap fon_;

    double jump_length_{60};
    double jump_height_{0};
    int vini_width_{0};
    double x_{0}, y_{0};
    DirectionTypes direction_{DirectionTypes::kRight};

    QBasicTimer animation_timer_;
};

#endif //MAINWINDOW_H
