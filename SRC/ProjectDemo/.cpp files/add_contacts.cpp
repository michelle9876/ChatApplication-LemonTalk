#include "add_contacts.h"
#include "ui_add_contacts.h"
#include "chat.h"


Add_Contacts::Add_Contacts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_Contacts)
{
    ui->setupUi(this);
}



Add_Contacts::~Add_Contacts()
{
    delete ui;
}


void Add_Contacts::on_Add_Contact_push_Button_clicked()
{
    ui->setupUi(this);
    QString Contact_Name = ui->Contact_Name_Line_add->text();
    QString Contact_Phone = ui->Phone_Number_Line_add ->text();

   // ui -> Chat::Contact_list_Widget -> setText (ui -> Contact_Name_Line_add -> text());
   // ui->lineEditTopic_2->setText(ui ->lineEditTopic->text());
    hide();
}


