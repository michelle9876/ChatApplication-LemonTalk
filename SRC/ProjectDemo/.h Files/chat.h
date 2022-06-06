#ifndef CHAT_H
#define CHAT_H

#include <QMainWindow>
#include "settings.h"
#include "add_contacts.h"
#include <QMqttClient>

namespace Ui {
class Chat;
}

class Chat : public QMainWindow
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent = nullptr);
    ~Chat();

public slots:
    void setClientPort(int p);


private slots:
    void on_Settings_clicked();

    void on_Add_Contacts_clicked();

    void on_Refresh_clicked();

    void updateLogStateChange();

    void brokerDisconnected();

    void on_buttonSend_clicked();

    void on_buttonSubscribe_clicked();

private:
    Ui::Chat *ui;
    Settings * settings;
    Add_Contacts * addC;
    QMqttClient *m_client;

};

#endif // CHAT_H
