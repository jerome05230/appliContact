#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QDebug>

mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow)

{
    ui->setupUi(this);
    chargeContact();
    afficherContact();
}

mainWindow::~mainWindow()
{
    delete ui;
}
//permet de récupérer tous les contacts de la base de donnée
void mainWindow::chargeContact(){
    QSqlQuery reqLireContact("select * from contact order by nom,prenom asc;");
    while (reqLireContact.next())
    {
        int id=reqLireContact.value(0).toInt();
        QString nom=reqLireContact.value(1).toString();
        QString prenom=reqLireContact.value(2).toString();
        QString mail=reqLireContact.value(3).toString();
        QString nPortable=reqLireContact.value(4).toString();
        Contact newContact(id,nom,prenom,mail,nPortable);
        vectContact.push_back(newContact);
    }
}

//requète permettant de créer un contact
void mainWindow::createContact(int idContact, QString nomContact, QString prenomContact, QString mailContact, QString nPortableContact){
    QSqlQuery reqPushContact;
        QString texteRequete="insert into contact values ('";
        texteRequete+=QString::number(idContact);
        texteRequete+="','";
        texteRequete+=nomContact;
        texteRequete+="','";
        texteRequete+=prenomContact;
        texteRequete+="','";
        texteRequete+=mailContact;
        texteRequete+="','";
        texteRequete+=nPortableContact;
        texteRequete+="')";
        qDebug() << texteRequete << endl;
        reqPushContact.exec(texteRequete);
}

//crée un nouveau contact
void mainWindow::on_pushButtonNewContact_clicked()
{
    DialogNewContact FormContact;

    if (FormContact.exec() ==QDialog::Accepted)
    {
        int idContact;
        if (!vectContact.size()==0)
        {
            idContact=vectContact[vectContact.size()-1].getId()+1;
        }
        else
        {
            idContact=0;
        }
        QString nomContact=FormContact.getNomContact();
        QString prenomContact=FormContact.getPrenomContact();
        QString mailContact=FormContact.getMailContact();
        QString nPortableContact=FormContact.getNPortableContact();
        if ((nomContact.size()>1) &&(prenomContact.size()>1) && (nomContact.size()>1) && (mailContact.size()>1) && (nPortableContact.size()==10))
        {
                Contact nouveauContact(idContact,nomContact,prenomContact,mailContact,nPortableContact);
                vectContact.push_back(nouveauContact);
                actualiser(idContact, nomContact, prenomContact, mailContact, nPortableContact);
                createContact(idContact, nomContact, prenomContact, mailContact, nPortableContact);
        }
        else
        {
            ui->statusBar->showMessage(tr("one or more field is not correctly written"), 5000);
        }
    }
}
//affiche le nouveau contact créer sans tout réafficher
void mainWindow::actualiser(int idContact ,QString nomContact, QString prenomContact, QString mailContact, QString nPortableContact)
{
    ui->tableWidgetContact->setRowCount(ui->tableWidgetContact->rowCount()+1);
    int ligne=ui->tableWidgetContact->rowCount();

    QTableWidgetItem *itemIdContact=new QTableWidgetItem(QString::number(idContact));
    ui->tableWidgetContact->setItem(ligne-1,0,itemIdContact);

    QTableWidgetItem *itemNomContact=new QTableWidgetItem(nomContact);
    ui->tableWidgetContact->setItem(ligne-1,1,itemNomContact);

    QTableWidgetItem *itemPrenomContact=new QTableWidgetItem(prenomContact);
    ui->tableWidgetContact->setItem(ligne-1,2,itemPrenomContact);

    QTableWidgetItem *itemMailContact=new QTableWidgetItem(mailContact);
    ui->tableWidgetContact->setItem(ligne-1,3,itemMailContact);

    QTableWidgetItem *itemNPortableContact=new QTableWidgetItem(nPortableContact);
    ui->tableWidgetContact->setItem(ligne-1,4,itemNPortableContact);
}
//affiches tous les contacts
void mainWindow::afficherContact()
{
        int nbContact=vectContact.size();
        ui->tableWidgetContact->setRowCount(nbContact);
        for (int noMat=0;noMat<vectContact.size();noMat++)
        {
            QString idContact=QString::number(vectContact[noMat].getId());
            QTableWidgetItem *itemIdContact=new QTableWidgetItem(idContact);
            ui->tableWidgetContact->setItem(noMat,0,itemIdContact);

            QString nomContact=vectContact[noMat].getNom();
            QTableWidgetItem *itemNomContact=new QTableWidgetItem(nomContact);
            ui->tableWidgetContact->setItem(noMat,1,itemNomContact);

            QString prenomContact=vectContact[noMat].getPrenom();
            QTableWidgetItem *itemPrenomContact=new QTableWidgetItem(prenomContact);
            ui->tableWidgetContact->setItem(noMat,2,itemPrenomContact);

            QString mailContact=vectContact[noMat].getMail();
            QTableWidgetItem *itemMailContact=new QTableWidgetItem(mailContact);
            ui->tableWidgetContact->setItem(noMat,3,itemMailContact);

            QString nPortableContact=vectContact[noMat].getNPortable();
            QTableWidgetItem *itemNPortableContact=new QTableWidgetItem(nPortableContact);
            ui->tableWidgetContact->setItem(noMat,4,itemNPortableContact);
        }
}

void mainWindow::on_pushButtonDelContact_clicked()
{
    deleteContact(ui->tableWidgetContact->currentRow());
}
//permet de supprimer un contact de la base , du vecteur et du tableau
void mainWindow::deleteContact(int idContact)
{
    QSqlQuery reqPushContact;
    QString texteRequete= "delete from contact where id=";
    texteRequete+=QString::number(vectContact[ui->tableWidgetContact->currentRow()].getId());
    qDebug() << texteRequete << endl;
    reqPushContact.exec(texteRequete);
    vectContact.remove(idContact);
    ui->tableWidgetContact->removeRow(ui->tableWidgetContact->currentRow());
}
/*bool mainWindow::testNumTelephone(QString numATester){
    bool valide=false;
    for (int i =0;i<numATester.size();i++)
    {
        if (numATester[i].isDigit())// to check if it is number!!
        {
            valide=true;
        }
        else if (numATester[i].isLetter())// to check if it is alphabet !!
        {
          ui->statusBar->showMessage(tr("you have letters in the phone number it's impossible"), 5000);
          valide=false;
        }
        else
        {
          ui->statusBar->showMessage(tr("you hif (FormContact.exec() ==QDialog::Accepted)
    {ave other caracters in the phone number it's impossible"), 5000);
          valide=false;
        }
    }
    return valide;
}*/

void mainWindow::on_pushButtonModifier_clicked()
{
    QString id=QString::number(ui->tableWidgetContact->currentRow());
    int indice=ui->tableWidgetContact->currentRow();
       qDebug() << id << endl;
    DialogModif FormModif(  vectContact[indice].getNom(),
                            vectContact[indice].getPrenom(),
                            vectContact[indice].getMail(),
                            vectContact[indice].getNPortable());
    if (FormModif.exec() ==QDialog::Accepted)
    {
        QString leNouveauNom=FormModif.getNouveauNomContact();
        QString leNouveauPrenom=FormModif.getNouveauPrenomContact();
        QString leNouveauMail=FormModif.getNouveauMailContact();
        QString leNouveauNPortable=FormModif.getNouveauNPortableContact();
        QString texteRequete="";
        QSqlQuery reqPushContact;

        if (vectContact[ui->tableWidgetContact->currentRow()].getNom()!= leNouveauNom)
        {
            vectContact[ui->tableWidgetContact->currentRow()].setNom(leNouveauNom);
            QString texteRequete="UPDATE contact SET nom='";
            texteRequete+=leNouveauNom;
            texteRequete+="' WHERE id=";
            texteRequete+=id;
            texteRequete+=";";

        }
        if (vectContact[ui->tableWidgetContact->currentRow()].getPrenom()!= leNouveauPrenom)
        {
            vectContact[ui->tableWidgetContact->currentRow()].setPrenom(leNouveauPrenom);
            texteRequete="UPDATE contact SET prenom='";
            texteRequete+=leNouveauPrenom;
            texteRequete+="' WHERE id=";
            texteRequete+=id;
            texteRequete+=";";
        }
        if (vectContact[ui->tableWidgetContact->currentRow()].getMail()!= leNouveauMail)
        {
            vectContact[ui->tableWidgetContact->currentRow()].setMail(leNouveauMail);
            texteRequete="UPDATE contact SET mail='";
            texteRequete+=leNouveauMail;
            texteRequete+="' WHERE id=";
            texteRequete+=id;
            texteRequete+=";";
        }
        if (vectContact[ui->tableWidgetContact->currentRow()].getNPortable()!= leNouveauNPortable)
        {
            vectContact[ui->tableWidgetContact->currentRow()].setNPortable(leNouveauNPortable);
            texteRequete="UPDATE contact SET nPortable='";
            texteRequete+=leNouveauNPortable;
            texteRequete+="' WHERE id=";
            texteRequete+=id;
            texteRequete+=";";
        }
        qDebug() << texteRequete << endl;
        actualiser(id.toInt(), leNouveauNom, leNouveauPrenom, leNouveauMail, leNouveauNPortable);
        reqPushContact.exec(texteRequete);
    }
    else
    {
        ui->statusBar->showMessage(tr("one or more field is not correctly written"), 5000);
    }
}
