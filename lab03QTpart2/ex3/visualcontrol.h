#ifndef VISUALCONTROL_H
#define VISUALCONTROL_H

#include <QMainWindow>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>

class VisualControl : public QMainWindow
{
    Q_OBJECT

public:
    VisualControl(QWidget *parent = nullptr);
    ~VisualControl();

private slots:
    void toggleButtonVisibility(bool checked);
    void connectCheckBoxes();

private:
    QWidget *centralWidget;
    QVBoxLayout *layout;
    QList<QCheckBox*> checkboxes;
    QList<QPushButton*> buttons;
};

#endif // VISUALCONTROL_H
