#ifndef CREATE_ACCOUNT_H
#define CREATE_ACCOUNT_H

#include <QMainWindow>
#include "chat.h"

namespace Ui {
class Create_Account;
}

class Create_Account : public QMainWindow
{
    Q_OBJECT

public:
    explicit Create_Account(QWidget *parent = nullptr);
    ~Create_Account();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_Create_Account_clicked();

private:
    Ui::Create_Account *ui;
    Chat * chat;
};

#endif // CREATE_ACCOUNT_H
