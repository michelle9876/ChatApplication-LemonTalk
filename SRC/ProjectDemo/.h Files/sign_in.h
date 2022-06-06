#ifndef SIGN_IN_H
#define SIGN_IN_H

#include <QMainWindow>
#include <chat.h>
namespace Ui {
class Sign_In;
}

class Sign_In : public QMainWindow
{
    Q_OBJECT

public:
    explicit Sign_In(QWidget *parent = nullptr);
    ~Sign_In();

private slots:
    void on_Cancel_SPage_clicked();

    void on_Sign_In_SPage_clicked();

private:
    Ui::Sign_In *ui;
    Chat * chat;
};

#endif // SIGN_IN_H
