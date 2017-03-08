#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QModelIndex>
#include "dialognewcontact.h"
#include "dialogmodif.h"
#include "contact.h"

namespace Ui {
class mainWindow;
}

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = 0);
    ~mainWindow();
    QVector<Contact> vectContact;

    void chargeContact();

    void actualiser(int idContact, QString nomContact, QString prenomContact, QString mailContact, QString nPortableContact);
    void afficherContact();
    void createContact(int idContact, QString nomContact, QString prenomContact, QString mailContact, QString nPortableContact);
    void deleteContact(int idContact);
private slots:
    void on_pushButtonNewContact_clicked();
    void on_pushButtonDelContact_clicked();
    void on_pushButtonModifier_clicked();

private:
    Ui::mainWindow *ui;
};

#endif // MAINWINDOW_H
