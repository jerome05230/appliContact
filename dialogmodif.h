#ifndef DIALOGMODIF_H
#define DIALOGMODIF_H

#include <QDialog>

namespace Ui {
class DialogModif;
}

class DialogModif : public QDialog
{
    Q_OBJECT

public:
    explicit DialogModif(QString leNom, QString lePrenom, QString leMail, QString leNPortable,QWidget *parent = 0);
    ~DialogModif();

    QString getNouveauNomContact();
    QString getNouveauPrenomContact();
    QString getNouveauMailContact();
    QString getNouveauNPortableContact();
    void activatedOkButton();
private slots:
    void on_pushButtonOk_clicked();

    void on_pushButtonCancel_clicked();

    void on_lineEditModifNomContact_textChanged();

    void on_lineEditModifPrenomContact_textChanged();

    void on_lineEditModifMailContact_textChanged();

    void on_lineEditModifNPortableContact_textChanged();

private:
    Ui::DialogModif *ui;
};

#endif // DIALOGMODIF_H
