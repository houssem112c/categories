#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("project2A");
db.setUserName("houssem");//inserer nom de l'utilisateur
db.setPassword("houssem15");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
