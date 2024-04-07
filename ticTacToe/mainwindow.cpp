#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QGridLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentPlayer = 1;
    clickedButtonsCount = 0;
    player1Wins = 0;
    player2Wins = 0;
    QIcon appIcon(":/rec/img/icons8-tic-tak-toe---cross-and-circle-matrix-game-with-work-strategy-concept-100.png");
    setWindowIcon(appIcon);
    setWindowTitle("TicTacToe");
    ui->labelPlayer1Wins->setReadOnly(true);
    ui->labelPlayer2Wins->setReadOnly(true);
    ui->labelPlayer1Wins->setText(QString::number(player1Wins));
    ui->labelPlayer2Wins->setText(QString::number(player2Wins));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_player1X_clicked(){
    ui->player2O->setChecked(true);
    ui->player2X->setDisabled(true);
    ui->player2O->setDisabled(false);
}

void MainWindow::on_player2X_clicked(){
    ui->Player1O->setChecked(true);
    ui->player1X->setDisabled(true);
    ui->Player1O->setDisabled(false);
}

void MainWindow::on_Player1O_clicked(){
    ui->player2X->setChecked(true);
    ui->player2O->setDisabled(true);
    ui->player2X->setDisabled(false);
}

void MainWindow::on_player2O_clicked(){
    ui->player1X->setChecked(true);
    ui->Player1O->setDisabled(true);
    ui->player1X->setDisabled(false);
}

Symbol MainWindow::getButtonSymbol(QPushButton *button) {
    QIcon icon = button->icon();
    if (icon.isNull()) {
        return Empty;
    } else {
        QPixmap pixmap = icon.pixmap(button->iconSize());
        QPixmap circlePixmap(":/rec/img/icons8-о-100.png");
        QPixmap crossPixmap(":/rec/img/icons8-x-100.png");
        if (pixmap.toImage() == circlePixmap.toImage()) {
            return Circle;
        } else if (pixmap.toImage() == crossPixmap.toImage()) {
            return Cross;
        } else {
            return Empty;
        }
    }
}

bool MainWindow::checkWin(int player) {
    Symbol playerSymbol = (player == 1 && ui->player1X->isChecked()) ? Cross : (player == 1 && ui->Player1O->isChecked()) ? Circle : (player == 2 && ui->player2X->isChecked()) ? Cross : Circle;


    // Получаем символы на кнопках
    Symbol button1Symbol = getButtonSymbol(ui->pushButton);
    Symbol button2Symbol = getButtonSymbol(ui->pushButton_2);
    Symbol button3Symbol = getButtonSymbol(ui->pushButton_3);
    Symbol button4Symbol = getButtonSymbol(ui->pushButton_4);
    Symbol button5Symbol = getButtonSymbol(ui->pushButton_5);
    Symbol button6Symbol = getButtonSymbol(ui->pushButton_6);
    Symbol button7Symbol = getButtonSymbol(ui->pushButton_7);
    Symbol button8Symbol = getButtonSymbol(ui->pushButton_8);
    Symbol button9Symbol = getButtonSymbol(ui->pushButton_9);

    // Проверяем выигрышные комбинации
    if ((button1Symbol == playerSymbol && button2Symbol == playerSymbol && button7Symbol == playerSymbol) ||
        (button3Symbol == playerSymbol && button4Symbol == playerSymbol && button8Symbol == playerSymbol) ||
        (button5Symbol == playerSymbol && button6Symbol == playerSymbol && button9Symbol == playerSymbol) ||
        (button1Symbol == playerSymbol && button3Symbol == playerSymbol && button5Symbol == playerSymbol) ||
        (button2Symbol == playerSymbol && button4Symbol == playerSymbol && button6Symbol == playerSymbol) ||
        (button7Symbol == playerSymbol && button8Symbol == playerSymbol && button9Symbol == playerSymbol) ||
        (button1Symbol == playerSymbol && button4Symbol == playerSymbol && button9Symbol == playerSymbol) ||
        (button7Symbol == playerSymbol && button4Symbol == playerSymbol && button5Symbol == playerSymbol)) {
        return true;
    }
    return false;
}

void MainWindow::on_pushButton_clicked()
{
    if((ui->player1X->isChecked())||(ui->player2X->isChecked())||(ui->player2O->isChecked())||(ui->Player1O->isChecked())){
    QPushButton *button = ui->pushButton;
    setButtonIcon(button);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if((ui->player1X->isChecked())||(ui->player2X->isChecked())||(ui->player2O->isChecked())||(ui->Player1O->isChecked())){
    QPushButton *button = ui->pushButton_2;
    setButtonIcon(button);

    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if((ui->player1X->isChecked())||(ui->player2X->isChecked())||(ui->player2O->isChecked())||(ui->Player1O->isChecked())){
    QPushButton *button = ui->pushButton_3;
    setButtonIcon(button);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if((ui->player1X->isChecked())||(ui->player2X->isChecked())||(ui->player2O->isChecked())||(ui->Player1O->isChecked())){
    QPushButton *button = ui->pushButton_4;
    setButtonIcon(button);
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if((ui->player1X->isChecked())||(ui->player2X->isChecked())||(ui->player2O->isChecked())||(ui->Player1O->isChecked())){
    QPushButton *button = ui->pushButton_5;
    setButtonIcon(button);
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    if((ui->player1X->isChecked())||(ui->player2X->isChecked())||(ui->player2O->isChecked())||(ui->Player1O->isChecked())){
    QPushButton *button = ui->pushButton_6;
    setButtonIcon(button);
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    if((ui->player1X->isChecked())||(ui->player2X->isChecked())||(ui->player2O->isChecked())||(ui->Player1O->isChecked())){
    QPushButton *button = ui->pushButton_7;
    setButtonIcon(button);
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    if((ui->player1X->isChecked())||(ui->player2X->isChecked())||(ui->player2O->isChecked())||(ui->Player1O->isChecked())){
    QPushButton *button = ui->pushButton_8;
        setButtonIcon(button);
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    if((ui->player1X->isChecked())||(ui->player2X->isChecked())||(ui->player2O->isChecked())||(ui->Player1O->isChecked())){
    QPushButton *button = ui->pushButton_9;
    setButtonIcon(button);
    }
}
void MainWindow::showGameOverDialog() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "TicTacToe", "Хотите ли вы сыграть ещё раз?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {

        resetGame();

    } else {

        close();
    }
}

void MainWindow::resetGame() {
    // Reset all buttons
    QList<QPushButton *> buttons = findChildren<QPushButton *>();
    for (QPushButton *button : buttons) {
        button->setIcon(QIcon());
        button->setDisabled(false);
        QObject::connect(button, &QPushButton::clicked, [=]() { setButtonIcon(button); });
    }

    currentPlayer = 1;
    clickedButtonsCount = 0;
    //this->player1Wins;
    //this->player2Wins;

    // Reset radio buttons to initial state
    ui->player1X->setChecked(false);
    ui->player2X->setChecked(false);
    ui->Player1O->setChecked(false);
    ui->player2O->setChecked(false);

    // Enable radio buttons
    ui->player1X->setEnabled(true);
    ui->player2X->setEnabled(true);
    ui->Player1O->setEnabled(true);
    ui->player2O->setEnabled(true);
}




void MainWindow::setButtonIcon(QPushButton *clickedButton) {
    if (clickedButton->icon().isNull()) {
        if (currentPlayer == 1) {
            if (ui->player1X->isChecked()) {
                clickedButton->setIcon(QIcon(":/rec/img/icons8-x-100.png"));
            } else {
                clickedButton->setIcon(QIcon(":/rec/img/icons8-о-100.png"));
            }
        } else {
            if (ui->player2X->isChecked()) {
                clickedButton->setIcon(QIcon(":/rec/img/icons8-x-100.png"));
            } else {
                clickedButton->setIcon(QIcon(":/rec/img/icons8-о-100.png"));
            }
        }
        clickedButton->setIconSize(QSize(100, 100));
        clickedButton->disconnect();

        clickedButtonsCount++;

        if (checkWin(currentPlayer)) {
            QMessageBox::information(this, "TicTacToe", QString("Игрок %1 победил!").arg(currentPlayer));
            if (currentPlayer == 1) {
                player1Wins++;
            } else {
                player2Wins++;
            }

            ui->labelPlayer1Wins->setText(QString::number(player1Wins));
            ui->labelPlayer2Wins->setText(QString::number(player2Wins));
            showGameOverDialog();
            return;
        }
        if (clickedButtonsCount == 9) {
            QMessageBox::information(this, "TicTacToe", "Ничья!");
              showGameOverDialog();
            return;
        }
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
}


