#include "settings.h"
#include "ui_settings.h"
#include "chat.h"
#include "mainwindow.h"
#include "QMessageBox"
#include "mysql_interface.h"


Chat * chat;
MainWindow * MMWindow;

Settings::Settings(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_Cancel_SPage_clicked()
{
    hide();
    chat = new Chat(this);
    chat -> show();

}

void Settings::on_Cancel_SPage_2_clicked()
{
    QMessageBox::information(this, "Log out","You have successfully logged out");
    hide();
    MMWindow = new MainWindow(this);
    MMWindow -> show();
}


void Settings::on_pushButton_Confirm_clicked()
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

            QString BFusername = ui->BFuserName_Setting->text();
            QString password = ui->password_Setting->text();
            QString username = ui->userName_Setting->text();
            QString BFpassword = ui->BFpassword_Setting->text();
            QString phoneNum = ui->phoneNumber_Setting->text();

    //now this Query will insert the captured data above in to database

            QSqlQuery query;


            query.prepare("UPDATE users SET username = :username ,password = :password, phoneNum = :phoneNum WHERE username = :BFusername and password = :BFpassword");


            query.bindValue(":BFusername", BFusername);
            query.bindValue(":username", username);
            query.bindValue(":password", password);
            query.bindValue(":BFpassword", BFpassword);
            query.bindValue(":phoneNum", phoneNum);

            if(query.exec())
            {
                QMessageBox::information(this, "Inserted", "Your Data is changed successfully! ");
                hide();
                MMWindow = new MainWindow(this);
                MMWindow -> show();

            }
            else
            {
                QMessageBox::information(this,"Error","Wrong password or username");
               // hide();

            }
    }
}

void Settings::on_Cancel_SPage_3_clicked()
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

            QString BFusername = ui->BFuserName_Setting->text();
            QString BFpassword = ui->BFpassword_Setting->text();

            //now this Query will insert the captured data above in to database

            QSqlQuery query;


            query.prepare("DELETE FROM users WHERE username = :BFusername AND password = :BFpassword");


            query.bindValue(":BFusername", BFusername);
            query.bindValue(":BFpassword", BFpassword);

            if(query.exec())
            {
                QMessageBox::information(this, "Delete", "Your account is deleted successfully. ");
                hide();
                MMWindow = new MainWindow(this);
                MMWindow -> show();
            }
            else
            {
                QMessageBox::information(this,"Error","Wrong password or username");
              //  hide();

            }
    }
}
