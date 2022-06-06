#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Sign_In_clicked()
{
    hide();
    sign_in = new Sign_In(this);
    sign_in ->show();
}

void MainWindow::on_Create_Account_clicked()
{
    hide();
    Create_Acc = new Create_Account(this);
    Create_Acc -> show();
}
