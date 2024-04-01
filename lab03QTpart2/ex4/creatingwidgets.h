#ifndef CREATINGWIDGETS_H
#define CREATINGWIDGETS_H

#include <QMainWindow>
#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class CreatingWidget : public QMainWindow
{
    Q_OBJECT

public:
    CreatingWidget(QWidget *parent = nullptr);
    ~CreatingWidget();

private slots:
    void spawnWidgets();

private:
    QComboBox *widgetComboBox;
    QSpinBox *quantitySpinBox;
    QPushButton *spawnButton;
    QWidget *widgetContainer;
    QVBoxLayout *mainLayout;
};

#endif // CREATINGWIDGETS_H
