#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_17->setModel(tmpcategories.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_14_clicked()
    {
        QString id,nom,descr,livr;


        
        
        if( ui->lineEdit_13->text().isEmpty() || ui->lineEdit_17->text().isEmpty()|| ui->textEdit->toPlainText().isEmpty() )
        {
            QMessageBox::warning(nullptr, QObject::tr("Attention"),
                                 QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
        }
        else{
            id=ui->lineEdit_17->text();
            nom=ui->lineEdit_13->text();
            descr=ui->textEdit->toPlainText();
            
            
            
            if (ui->comboBox->currentIndex()==0)
                livr="livrable";
            else {
                livr="non livrable";
            }
            
            
            categories c(id,nom,descr,livr);
            bool test= c.ajouter();
            
            if (test)
            {
                QMessageBox::information(nullptr, QObject::tr("Ajouter un   categories"),
                                         QObject::tr("  categories ajouté.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
                ui->tableView_17->setModel(tmpcategories.afficher());
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Ajouter un  categories"),
                                      QObject::tr("Erreur !.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
            }
        }
    

}

void MainWindow::on_pushButton_13_clicked()
{
    QString id,nom,descr,livr;


    id=ui->lineEdit_17->text();
    nom=ui->lineEdit_13->text();
    descr=ui->textEdit->toPlainText();

    if (ui->comboBox->currentIndex()==0)

    livr="livrable";
    else {
       livr="non livrable";
    }



    categories c(id,nom,descr,livr);
    bool test= c.modifier(id);

    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Modifier un   categorie"),
                                 QObject::tr("  categorie Modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_17->setModel(tmpcategories.afficher());//refresh
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un categorie"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_17_clicked()
{
    QString id = ui->lineEdit_17->text();
    categories c;
    bool test=c.supprimer(id);
    ui->tableView_17->setModel(tmpcategories.afficher());//refresh
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer categories"),
                                 QObject::tr("categorie supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
}



