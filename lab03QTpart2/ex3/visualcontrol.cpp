#include "visualcontrol.h"
#include "ui_visualcontrol.h"


VisualControl::VisualControl(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Visual Control");
    setGeometry(100, 100, 400, 200);
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    layout = new QVBoxLayout(centralWidget);

    for (int i = 0; i < 5; ++i) {
        checkboxes.append(new QCheckBox(QString("Чекбокс %1").arg(i + 1), this));
        layout->addWidget(checkboxes.last());

        buttons.append(new QPushButton(QString("Кнопка %1").arg(i + 1), this));
        layout->addWidget(buttons.last());

        connect(checkboxes.last(), &QCheckBox::toggled, this, &VisualControl::toggleButtonVisibility);
        buttons.last()->setVisible(true); // Устанавливаем кнопки видимыми изначально
    }

    connectCheckBoxes();
}

void VisualControl::connectCheckBoxes()
{
}

VisualControl::~VisualControl()
{
}

void VisualControl::toggleButtonVisibility(bool checked)
{
    QCheckBox *senderCheckbox = qobject_cast<QCheckBox*>(sender());
    if (!senderCheckbox)
        return;

    int index = checkboxes.indexOf(senderCheckbox);
    if (index == -1)
        return;

    buttons[index]->setVisible(!checked);
}
