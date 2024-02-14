#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // initialize state and operand
    state = 1;
    operand = 0;

    // connecting number buttons to numberClickHandler
    connect(ui->N0, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N1, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N2, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N3, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N4, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N5, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N6, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N7, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N8, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N9, &QPushButton::clicked, this, &MainWindow::numberClickHandler);

    // clear and enter buttons
    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clear);
    connect(ui->enter, &QPushButton::clicked, this, &MainWindow::enter);

    // operation buttons
    connect(ui->add, &QPushButton::clicked, this, &MainWindow::operationClicked);
    connect(ui->sub, &QPushButton::clicked, this, &MainWindow::operationClicked);
    connect(ui->mul, &QPushButton::clicked, this, &MainWindow::operationClicked);
    connect(ui->div, &QPushButton::clicked, this, &MainWindow::operationClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickHandler() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString buttonText = button->text();

    // debugging text
    qDebug() << "number" << buttonText << "clicked";

    if (state == 1) {
        number1 += buttonText;
        ui->num1->setText(number1);
    } else if (state == 2) {
        number2 += buttonText;
        ui->num2->setText(number2);
    }
}

void MainWindow::clear() {
    number1.clear();
    number2.clear();
    result.clear();

    state = 1;

    ui->result->clear();
    ui->num1->clear();
    ui->num2->clear();
}

void MainWindow::enter() {
    float num1 = number1.toFloat();
    float num2 = number2.toFloat();

    switch (operand) {
    case 0: // addition
        result = QString::number(num1 + num2);
        break;
    case 1: // subtraction
        result = QString::number(num1 - num2);
        break;
    case 2: // multiplication
        result = QString::number(num1 * num2);
        break;
    case 3: // division
        if (num2 != 0)
            result = QString::number(num1 / num2);
        else
            result = "error! division by zero";
        break;
    default:
        result = "error! invalid operation";
    }

    ui->result->setText(result);
}

void MainWindow::operationClicked() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString buttonText = button->text();

    // sets operand
    if (buttonText == "+")
        operand = 0;
    else if (buttonText == "-")
        operand = 1;
    else if (buttonText == "*")
        operand = 2;
    else if (buttonText == "/")
        operand = 3;

    state = 2; // switches to enter number 2
}

