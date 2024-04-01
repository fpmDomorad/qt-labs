#include "superclicker.h"
#include "ui_superclicker.h"


Clicker::Clicker(QWidget *parent)
    : QMainWindow(parent),totalClicks(0)
{
    setWindowTitle("Super Clicker");
    setGeometry(100, 100, 400, 200);

    spinBox = new QSpinBox(this);
    spinBox->setRange(0, 100);

    button = new QPushButton("Тык", this);
    connect(button, &QPushButton::clicked, this, &Clicker::moveProgressBar);

    progressBar = new QProgressBar(this);
    progressBar->setRange(0, 100);
    progressBar->setValue(0);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(spinBox);
    layout->addWidget(button);
    layout->addWidget(progressBar);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

Clicker::~Clicker()
{
}

void Clicker::moveProgressBar()
{
    if (progressBar->value() == 0){
        totalClicks = spinBox->value();
        progressBar->setMaximum(totalClicks);
        spinBox->setEnabled(false);
    }

    if (progressBar->value() < progressBar->maximum()) {
        progressBar->setValue(progressBar->value() + 1);
    } else {
        button->setEnabled(false);
    }
}
