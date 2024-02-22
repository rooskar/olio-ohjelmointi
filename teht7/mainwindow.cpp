#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player1Timer = new QTimer(this);
    connect(player1Timer, &QTimer::timeout, this, &MainWindow::updateTimer);
    player2Timer = new QTimer(this);
    connect(player2Timer, &QTimer::timeout, this, &MainWindow::updateTimer);

    totalTime = 0;
    gameStarted = false;

    ui->progressBar1->setMaximum(player1Time);
    ui->progressBar1->setValue(player1Time);
    ui->progressBar2->setMaximum(player2Time);
    ui->progressBar2->setValue(player2Time);
    ui->gameStateLabel->setText("Select playtime");
    gameStarted = false;

    connect(ui->time120Button, &QPushButton::clicked, this, [this](){ updateTime(120); });
    connect(ui->time300Button, &QPushButton::clicked, this, [this](){ updateTime(300); });
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::on_startButton_clicked);
    connect(ui->switchPlayerButton1, &QPushButton::clicked, this, &MainWindow::on_switchPlayerButton_clicked);
    connect(ui->switchPlayerButton2, &QPushButton::clicked, this, &MainWindow::on_switchPlayerButton_clicked);
    connect(ui->endGameButton, &QPushButton::clicked, this, &MainWindow::on_endGameButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    if (!gameStarted && totalTime > 0) {
        gameStarted = true;
        ui->startButton->setEnabled(false); // disables start button during the game
        currentPlayer = 1; // sets player 1 as starter player

        // resets timer values
        player1Time = ui->progressBar1->maximum();
        player2Time = ui->progressBar2->maximum();
        ui->progressBar1->setValue(player1Time);
        ui->progressBar2->setValue(player2Time);

    ui->gameStateLabel->setText("Game ongoing");

        if (currentPlayer == 1) {
            player1Timer->start(1000); // starts player1's timer, 1sec
        } else {
            player2Timer->start(1000); // starts player2's timer, 1sec
        }
    }
}

void MainWindow::on_endGameButton_clicked()
{
    player1Timer->stop();
    player2Timer->stop();
    gameStarted = false;
    currentPlayer = 1;
    ui->gameStateLabel->setText("Select playtime and press start button");
    ui->startButton->setEnabled(true); // enables start button to play with a new time

}

void MainWindow::on_switchPlayerButton_clicked()
{
    if (currentPlayer == 1) {
        player1Timer->stop();
        currentPlayer = 2;
        player2Timer->start(1000); // starts player 2's timer
        //ui->gameStateLabel->setText("Player 2's turn");
    } else {
        player2Timer->stop();
        currentPlayer = 1;
        player1Timer->start(1000); // starts player 1's timer
        //ui->gameStateLabel->setText("Player 1's turn");
    }
}


void MainWindow::updateTime(int time)
{
    player1Time = time;
    player2Time = time;
    totalTime = time * 2; // total time for both players
    ui->progressBar1->setMaximum(player1Time);
    ui->progressBar1->setValue(player1Time);
    ui->progressBar2->setMaximum(player2Time);
    ui->progressBar2->setValue(player2Time);
    ui->gameStateLabel->setText("Ready to play");

    ui->switchPlayerButton1->setEnabled(true);
    ui->switchPlayerButton2->setEnabled(true); // enables switch buttons after selecting time
}

void MainWindow::updateTimer()
{
    if (currentPlayer == 1) {
        player1Time--;
        ui->progressBar1->setValue(player1Time);
        if (player1Time == 0) {
            player1Timer->stop();
            ui->gameStateLabel->setText("Player 2 won");
            gameStarted = false;
            ui->startButton->setEnabled(true); // enables start button to play again with the same time
        }
    } else {
        player2Time--;
        ui->progressBar2->setValue(player2Time);
        if (player2Time == 0) {
            player2Timer->stop();
            ui->gameStateLabel->setText("Player 1 won");
            gameStarted = false;
            ui->startButton->setEnabled(true); // enables start button to play again with the same time
        }
    }
}
