#include "create_account.h"
#include "mysql_interface.h"
#include "ui_create_account.h"
#include "mainwindow.h"
#include "chat.h"
#include "QMessageBox"

MainWindow * Mwindow;
Create_Account::Create_Account(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Create_Account)
{
    ui->setupUi(this);
}

Create_Account::~Create_Account()
{
    delete ui;
}

void Create_Account::on_pushButton_2_clicked()
{
    hide();
    Mwindow = new MainWindow(this);
    Mwindow -> show();
}

void Create_Account::on_pushButton_Create_Account_clicked()
{
    // Connecting to my MYSQL database
        auto db=mysql_interface();
        QSqlDatabase database=db.get_database();
        if(!db.get_db_status())
        {
            db.init_database();
        }

        if(db.get_db_status())
        {

// Retreive Data From Input Fields

    QString username = ui->lineEdit_userName->text();
    QString password = ui->lineEdit_password->text();
    QString repassword = ui->lineEdit_repassword->text();
    QString dateOfBirth = ui->lineEdit_dateOfBirth->text();
    QString phoneNum = ui->lineEdit_phoneNumber->text();

    //now this Query will insert the captured data above in to database
            if (password != repassword){
                QMessageBox::information(this,"Details Missmatched", "Please enter correct password!");
                hide();
                Mwindow = new MainWindow(this);
                Mwindow -> show();
            }
            else if (username == "" || password == "" || repassword == "" || dateOfBirth == "" || phoneNum == "" )
            {
                QMessageBox::information(this,"Details Not Entered", "Please enter all details!");
                hide();
                Mwindow = new MainWindow(this);
                Mwindow -> show();
            }

            else
                {


                QSqlQuery query;

                query.prepare("INSERT INTO users (username, password, repassword, dateOfBirth, phoneNum)"
                            "VALUES (:username, :password, :repassword, :dateOfBirth, :phoneNum)");


                query.bindValue(":username", username);
                query.bindValue(":password", password);
                query.bindValue(":repassword",repassword);
                query.bindValue(":dateOfBirth", dateOfBirth);
                query.bindValue(":phoneNum", phoneNum);

                if(query.exec())
                {

                    QMessageBox::information(this, "Inserted", "Data is Inserted Succesfully");

                    hide();
                    Mwindow = new MainWindow(this);
                    Mwindow -> show();

                }
                else
                {
                    QMessageBox::information(this, "NOT Inserted", "Data is NOT Inserted Succesfully");
                    hide();
                }
              }
        }

        else
        {
            QMessageBox::information(this,"Not Connected","Database is not connected");
        }

        hide();


        database.close();


    }

