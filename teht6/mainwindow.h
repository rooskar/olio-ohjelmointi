#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void numberClickHandler(); // slot for handling number 0-9 buttons
    void clear(); // slot for handling clear button
    void enter(); // slot for handling enter button
    void operationClicked(); // slot for handling operation buttons (+, -, / and *)

private:
    Ui::MainWindow *ui;
    QString number1;
    QString number2;
    QString result;
    int operand;
    int state; // this is a state variable. 1 is for entering number 1 and 2 for entering number 2
};

#endif // MAINWINDOW_H
