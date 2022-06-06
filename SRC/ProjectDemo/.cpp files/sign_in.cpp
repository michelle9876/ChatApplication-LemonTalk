#include "sign_in.h"
#include "ui_sign_in.h"
#include "mainwindow.h"
#include "chat.h"
#include <QMessageBox>

MainWindow * MWindow;
Sign_In::Sign_In(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Sign_In)
{
    ui->setupUi(this);
}

Sign_In::~Sign_In()
{
    delete ui;
}

void Sign_In::on_Cancel_SPage_clicked()
{
    hide();
    MWindow = new MainWindow(this);
    MWindow -> show();

}
void Sign_In::on_Sign_In_SPage_clicked()
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
            QMessageBox::information(this,"Database connection", "Database connection SUCCESSFUL.");

                    //Get user data input
            QString username = ui->lineEdit_UserName->text();
            QString password = ui->lineEdit_Password->text();

            QSqlQuery query(QSqlDatabase::database(DB_NAME));
            QString sql_sentence ="SELECT username, password FROM ";
            sql_sentence += TB_NAME;
            sql_sentence += " WHERE username = :username AND password = :password";
            query.prepare(sql_sentence);

            query.bindValue(":username", username);
            query.bindValue(":password", password);

            query.exec();

                    if(query.next())
                    {
                            QMessageBox::information(this,"Success","You are logged in");
                            hide();
                            chat = new Chat(this);
                            chat -> show();


                    }

                    else
                    {
                            QMessageBox::information(this,"Error","Wrong password or username");

                           // hide();

                    }
               }
               else
               {
                   QMessageBox::information(this,"atabase connection", "Database connection FAILED.");
               }
        database.close();

}
