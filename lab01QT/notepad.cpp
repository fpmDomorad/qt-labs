#include "notepad.h"
#include "ui_notepad.h"

MainWindow::MainWindow(QApplication *parent) :
    QMainWindow(),ui(new Ui::MainWindow) {
    ui->setupUi(this);
    //После этой строчки - наши действия!
    openAction = new QAction(tr("&Open"), this);
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));
    saveAction = new QAction(tr("&Save as"), this);
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));
    exitAction = new QAction(tr("&Exit"), this);
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
    fileMenu = this->menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);
    textEdit = new QTextEdit();
    setCentralWidget(textEdit);
    setWindowTitle(tr("Notepad"));
}

MainWindow::~MainWindow() {
    delete ui;
}

//Ниже - наши методы класса
void MainWindow::open() {
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open file"), "",tr("Text file (*.txt);;File C++ (*.cpp *.h)"));
    if (fileName != "") {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("error"), tr("Can not open the file"));
            return;
        }
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    }
}

void MainWindow::save() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save file"), "",tr("Text file (*.txt);;File C++ (*.cpp *.h)"));
    if (fileName != "") {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox msgBox; msgBox.setText("I can't write a file"); msgBox.exec();
            //или как выше, коротко QMessageBox::critical...
        }
        else {
            QTextStream stream(&file);
            stream << textEdit->toPlainText();
            stream.flush();
            file.close();
        }
    }
}
