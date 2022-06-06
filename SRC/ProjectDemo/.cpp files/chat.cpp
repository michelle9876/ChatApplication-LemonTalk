#include "chat.h"
#include "ui_chat.h"
#include "settings.h"
#include "add_contacts.h"

#include <QtCore/QDateTime>
#include <QtMqtt/QMqttClient>
#include <QtMqtt/QtMqtt>
#include <QtWidgets/QMessageBox>
#include <QMqttClient>



Chat::Chat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);


    m_client = new QMqttClient(this);
    m_client->setHostname("127.0.0.1");
    m_client->setPort(1883);

    connect(m_client, &QMqttClient::stateChanged, this, &Chat::updateLogStateChange);
    connect(m_client, &QMqttClient::disconnected, this, &Chat::brokerDisconnected);

    connect(m_client, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic) {
        const QString content =QDateTime::currentDateTime().toString()
                    +topic.name()
                    + QLatin1Char('\n')
                    + message
                    + QLatin1Char('\n')
                    + QLatin1Char('\n');
        ui->plainTextEdit_msgBox->insertPlainText(content);
    });

    connect(m_client, &QMqttClient::pingResponseReceived, this, []() {
        const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(" PingResponse")
                    + QLatin1Char('\n');
    });
    m_client->connectToHost();


}

Chat::~Chat()
{
    delete ui;
}

void Chat::updateLogStateChange()
{
    const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(": State Change")
                    + QString::number(m_client->state())
                    + QLatin1Char('\n');
}

void Chat::brokerDisconnected()
{

}


void Chat::on_Settings_clicked()
{
    hide();
    settings = new Settings(this);
    settings ->show();
}

void Chat::setClientPort(int p)
{
    m_client->setPort(p);
}

void Chat::on_buttonSend_clicked()
{

    if (m_client->publish(ui->lineEditTopic ->text(), ui->lineEditMessage->text().toUtf8()) == -1)
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not Send message"));
    ui-> lineEditMessage -> clear();
    ui-> lineEditTopic_2 -> setText(ui-> lineEditTopic->text());
}

void Chat::on_Add_Contacts_clicked()
{
    addC = new Add_Contacts(this);
    addC -> show();
}

void Chat::on_Refresh_clicked()
{
    ui ->setupUi(this);
    ui ->Contact_list_Widget ->addItem("New Contact Added");

}


//void Chat::on_buttonConnect_clicked()
//{
//    if (m_client->state() == QMqttClient::Disconnected) {
//            ui->lineEditHost->setEnabled(false);
//            ui->spinBoxPort->setEnabled(false);
//            ui->buttonConnect->setText(tr("Disconnect"));
//            m_client->connectToHost();
//        } else {
//            ui->lineEditHost->setEnabled(true);
//            ui->spinBoxPort->setEnabled(true);
//            ui->buttonConnect->setText(tr("Connect"));
//            m_client->disconnectFromHost();
//        }
//}



void Chat::on_buttonSubscribe_clicked()
{
    auto subscription = m_client->subscribe(ui->lineEditTopic->text());
        if (!subscription) {
            QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
            return;
        }
    ui->lineEditTopic_2->setText(ui ->lineEditTopic->text());
}
