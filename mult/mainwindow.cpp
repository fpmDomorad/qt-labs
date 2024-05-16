#include <QtMath>
#include "mainwindow.h"

MainWindow::MainWindow() :
    scene_(new QGraphicsScene(this)),
    view_(new QGraphicsView(this)),
    fon_(":/resource/img/mult phon.jpg"),
    vini_(":/resource/img/vinni.png"){
    setFixedSize(710,530);
    SetupScene();
    SetupVini();
    animation_timer_.start(2, this);
}


void MainWindow::SetupScene() {
    scene_->addPixmap(fon_);
    vini_=vini_.scaled(200,200,Qt::KeepAspectRatio);
    view_->setScene(scene_);
    view_->resize(710, 530);
    QIcon appIcon(":/resource/img/3F3F3F3F.webp");
    setWindowIcon(appIcon);
    setWindowTitle("Winnie-the-Pooh");
}


void MainWindow::SetupVini() {
    vini_item_ = scene_->addPixmap(vini_);
    vini_item_->setPos(0, 270);
    vini_width_ = static_cast<int>(vini_item_->boundingRect().width());
}


void MainWindow::timerEvent(QTimerEvent* event) {
    if (event->timerId() == animation_timer_.timerId()) {
        y_ = -abs(jump_height_ * qSin(x_ / jump_length_));
        vini_item_->setPos(x_, 270 + y_);
        if (direction_ == DirectionTypes::kRight && x_ + vini_width_ >= 660) {
            direction_ = DirectionTypes::kLeft;
            vini_item_->setPixmap(vini_.transformed(QTransform().scale(-1, 1)));
        }
        else if (direction_ == DirectionTypes::kLeft && x_ <= 0) {
            direction_ = DirectionTypes::kRight;
            vini_item_->setPixmap(vini_);
        }

        if (direction_ == DirectionTypes::kRight) {
           x_ += 0.5;
        } else {
            x_ -= 0.5;
        }

        repaint();
    }

}
