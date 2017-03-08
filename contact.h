#ifndef CONTACT_H
#define CONTACT_H
#include<QString>
class Contact
{
public:
    Contact();
    Contact(int lId, QString leNom, QString lePrenom, QString leMail, QString leNPortable);

    int getId() const;
    void setId(int value);

    QString getNom() const;
    void setNom(const QString &value);

    QString getPrenom() const;
    void setPrenom(const QString &value);

    QString getMail() const;
    void setMail(const QString &value);

    QString getNPortable() const;
    void setNPortable(const QString &value);

private:
    int id;
    QString nom;
    QString prenom;
    QString mail;
    QString nPortable;
};


#endif // CONTACT_H
