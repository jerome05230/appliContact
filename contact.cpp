#include "contact.h"


Contact::Contact()
{
}
Contact::Contact(int lId, QString leNom, QString lePrenom, QString leMail, QString leNPortable)
{
    id=lId;
    nom=leNom;
    prenom=lePrenom;
    mail=leMail;
    nPortable=leNPortable;
}
int Contact::getId() const
{
    return id;
}

void Contact::setId(int value)
{
    id = value;
}
QString Contact::getNom() const
{
    return nom;
}

void Contact::setNom(const QString &value)
{
    nom = value;
}
QString Contact::getPrenom() const
{
    return prenom;
}

void Contact::setPrenom(const QString &value)
{
    prenom = value;
}
QString Contact::getMail() const
{
    return mail;
}

void Contact::setMail(const QString &value)
{
    mail = value;
}
QString Contact::getNPortable() const
{
    return nPortable;
}

void Contact::setNPortable(const QString &value)
{
    nPortable = value;
}





