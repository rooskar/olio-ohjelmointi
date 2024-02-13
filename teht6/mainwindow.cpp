#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->countButton, &QPushButton::clicked, this, &MainWindow::onCountClicked);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::onResetClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCountClicked()
{
    int currentNumber = ui->numberBox->text().toInt();
    ui->numberBox->setText(QString::number(currentNumber + 1));
}

void MainWindow::onResetClicked()
{
    ui->numberBox->setText("0");
}

