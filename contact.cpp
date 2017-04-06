#include "contact.h"
#include <qDebug>

qDebug() << "Contact::Contact()";
Contact::Contact()
{
}
qDebug() << "Contact::Contact(int lId, QString leNom, QString lePrenom, QString leMail, QString leNPortable)";
Contact::Contact(int lId, QString leNom, QString lePrenom, QString leMail, QString leNPortable)
{
    id=lId;
    nom=leNom;
    prenom=lePrenom;
    mail=leMail;
    nPortable=leNPortable;
}

qDebug() << "int Contact::getId() const";
int Contact::getId() const
{
    return id;
}

qDebug() << "void Contact::setId(int value)";
void Contact::setId(int value)
{
    id = value;
}

qDebug() << "QString Contact::getNom() const";
QString Contact::getNom() const
{
    return nom;
}

qDebug() << "void Contact::setNom(const QString &value)";
void Contact::setNom(const QString &value)
{
    nom = value;
}

qDebug() << "QString Contact::getPrenom() const";
QString Contact::getPrenom() const
{
    return prenom;
}

qDebug() << "void Contact::setPrenom(const QString &value)";
void Contact::setPrenom(const QString &value)
{
    prenom = value;
}

qDebug() << "QString Contact::getMail() const";
QString Contact::getMail() const
{
    return mail;
}

qDebug() << "void Contact::setMail(const QString &value)";
void Contact::setMail(const QString &value)
{
    mail = value;
}

qDebug() << "QString Contact::getNPortable() const";
QString Contact::getNPortable() const
{
    return nPortable;
}

qDebug() << "void Contact::setNPortable(const QString &value)";
void Contact::setNPortable(const QString &value)
{
    nPortable = value;
}





