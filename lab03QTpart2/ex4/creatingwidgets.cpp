#include "creatingwidgets.h"
#include "ui_creatingwidgets.h"

#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>

CreatingWidget::CreatingWidget(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Creating widgets");
    setGeometry(100, 100, 400, 200);
    widgetComboBox = new QComboBox(this);
    widgetComboBox->addItem("Кнопка");
    widgetComboBox->addItem("Редактирование текста");

    quantitySpinBox = new QSpinBox(this);
    quantitySpinBox->setRange(0, 5);

    spawnButton = new QPushButton("Spawn!", this);
    connect(spawnButton, &QPushButton::clicked, this, &CreatingWidget::spawnWidgets);

    widgetContainer = new QWidget(this);
    mainLayout = new QVBoxLayout(widgetContainer);

    // Создаем главный макет
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(widgetComboBox);
    mainLayout->addWidget(quantitySpinBox);
    mainLayout->addWidget(spawnButton);
    mainLayout->addWidget(widgetContainer);

    // Устанавливаем главный макет для главного окна
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

CreatingWidget::~CreatingWidget()
{
}

void CreatingWidget::spawnWidgets()
{
    // Очищаем контейнер с виджетами
    QLayoutItem *child;
    while ((child = mainLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    // Создаем виджеты в количестве, указанном в QSpinBox
    int quantity = quantitySpinBox->value();
    for (int i = 0; i < quantity; ++i) {
        QWidget *widget = nullptr;
        if (widgetComboBox->currentText() == "Кнопка") {
            widget = new QPushButton(QString("Кнопка %1").arg(i + 1), this);
        } else if (widgetComboBox->currentText() == "Редактирование текста") {
            widget = new QLineEdit(QString("Редактирование текста %1").arg(i + 1), this);
        }

        if (widget) {
            mainLayout->addWidget(widget);
        }
    }
}

