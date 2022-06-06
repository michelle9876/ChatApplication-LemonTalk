#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sign_in.h"
#include "create_account.h"
#include <QtSql>
#include <QMessageBox>
#include "mysql_interface.h"

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
    void on_Sign_In_clicked();

    void on_Create_Account_clicked();

private:
    Ui::MainWindow *ui;
    Sign_In * sign_in;
    Create_Account * Create_Acc;
};
#endif // MAINWINDOW_H
