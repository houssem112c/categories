#ifndef CATEGORIES_H
#define CATEGORIES_H

#include<QString>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QPainter>
#include <QGraphicsItem>



class categories
{
private:
    QString id,nom,descr,livr;


public:
    categories();
    categories(QString id,QString nom ,QString descr ,QString livr){
        this->id = id ;
        this->nom = nom;
        this->descr=descr;
        this->livr=livr;



    }
    void setid(QString id){this->id=id;}
    QString getid(){return this->id;}
    void setnom(QString nom){this->nom=nom;}
    QString getnom(){return this->nom;}
    void setdescr(QString descr){this->descr=descr;}
    QString getdescr(){return this->descr;}
    void setlivr(QString livr){this->livr=livr;}
    QString getlivr(){return this->livr;}

    bool ajouter();
    bool modifier(QString id);
    bool supprimer(QString id);

    QSqlQueryModel * afficher();

};

#endif // MATERIEL_H
