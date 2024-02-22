#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startButton_clicked();
    void on_switchPlayerButton_clicked();
    void on_endGameButton_clicked();
    void updateTime(int time);
    void updateTimer();

private:
    Ui::MainWindow *ui;
    QTimer *player1Timer;
    QTimer *player2Timer;
    int currentPlayer;
    int player1Time;
    int player2Time;
    int totalTime;
    bool gameStarted;
};

#endif // MAINWINDOW_H

