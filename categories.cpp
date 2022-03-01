#include "categories.h"

categories::categories()
{

    
}
bool categories::ajouter()
{
    QSqlQuery query;
    
    
    query.prepare("INSERT INTO CATEGORIE (ID, NOM, DESCR,LIVR) " "VALUES (:id, :nom, :descr, :livr )");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":descr", descr);
    query.bindValue(":livr", livr);
    
    return query.exec();
}
QSqlQueryModel * categories::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    
    model->setQuery("SELECT *FROM CATEGORIE ");
    
    
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESCR"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("LIVR"));
    
    model->setQuery("SELECT ID, NOM, DESCR,LIVR FROM CATEGORIE");
    return model;
    
}
bool categories::supprimer(QString id)
{
    QSqlQuery query;
    query.prepare("Delete from CATEGORIE where ID = :id ");
    query.bindValue(":id",id);
    return query.exec();
}
bool categories::modifier(QString id)
{
    
    QSqlQuery query;
    
    
    

 query.prepare("UPDATE CATEGORIE SET  NOM = :nom , DESCR = :descr , LIVR= :livr  WHERE ID = :id ");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":descr", descr);
    query.bindValue(":livr", livr);

    return query.exec();
    
    
    
    
}


