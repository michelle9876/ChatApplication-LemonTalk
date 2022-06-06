#ifndef MYSQL_INTERFACE_H
#define MYSQL_INTERFACE_H
#include <QSqlDatabase>

// database details
#define SQLDB "QMYSQL"
#define HOST "127.0.0.1"
#define USER "admin"
#define PASSWORD "pmaWXTxTlwA0"
#define DB_NAME "qt5register"
#define TB_NAME "users"


class mysql_interface
{
public:
    mysql_interface();
    ~mysql_interface();
    void init_database(void);
    QSqlDatabase get_database(void);
    bool get_db_status(void);

private:
    QSqlDatabase database;
    bool db_flag=false;

};

#endif // MYSQL_INTERFACE_H
