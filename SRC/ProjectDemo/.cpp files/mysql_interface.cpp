#include "mysql_interface.h"

mysql_interface::mysql_interface()
{
          mysql_interface::init_database();
    }


    void mysql_interface::init_database(void)
    {

        mysql_interface::database = QSqlDatabase::addDatabase(SQLDB);
        mysql_interface::database.setHostName(HOST);
        mysql_interface::database.setUserName(USER);
        mysql_interface::database.setPassword(PASSWORD);
        mysql_interface::database.setDatabaseName(DB_NAME);
        mysql_interface::database.open();
        mysql_interface::db_flag=true;

    }

    QSqlDatabase mysql_interface::get_database(void)
    {
        if(!mysql_interface::db_flag)
        {
            mysql_interface::init_database();
        }
        return mysql_interface::database;
    }

    mysql_interface::~mysql_interface()
    {
        if(!mysql_interface::db_flag)
        {
            mysql_interface::database.close();
        }
    }

    bool mysql_interface::get_db_status(void)
    {
        return mysql_interface::db_flag;
    }
