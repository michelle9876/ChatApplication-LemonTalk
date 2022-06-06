#ifndef ADD_CONTACTS_H
#define ADD_CONTACTS_H

#include <QDialog>
#include <string>
#include <QtGlobal>
namespace Ui
{
class Add_Contacts;
}

class Add_Contacts : public QDialog
{
    Q_OBJECT

public:
    explicit Add_Contacts(QWidget *parent = nullptr);
    ~Add_Contacts();

private slots:
    void on_Add_Contact_push_Button_clicked();

private:
    Ui::Add_Contacts *ui;
};

extern QString Con_Name;
extern QString Con_Phone;
#endif // ADD_CONTACTS_H
