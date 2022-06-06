#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMainWindow>


namespace Ui {
class Settings;
}

class Settings : public QMainWindow
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

private slots:
    void on_Cancel_SPage_clicked();

    void on_Cancel_SPage_2_clicked();

    void on_pushButton_Confirm_clicked();

    void on_Cancel_SPage_3_clicked();

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
