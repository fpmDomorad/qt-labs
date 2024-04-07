#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSignalMapper>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
enum Symbol {
    Empty,
    Cross,
    Circle
};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_player1X_clicked();

    void on_player2X_clicked();

    void on_Player1O_clicked();

    void on_player2O_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_7_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    bool checkWin(int player);

    Symbol getButtonSymbol(QPushButton *button);


private:
    Ui::MainWindow *ui;
    int currentPlayer;
    int clickedButtonsCount;
    int player1Wins;
    int player2Wins;
    void setButtonIcon(QPushButton *button);
    void showGameOverDialog();
    void resetGame();
    QHash<QPushButton*, QSignalMapper*> buttonSignalMapper;

};
#endif // MAINWINDOW_H
