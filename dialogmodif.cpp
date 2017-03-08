#include "dialogmodif.h"
#include "ui_dialogmodif.h"

DialogModif::DialogModif(QString leNom, QString lePrenom, QString leMail, QString leNPortable, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogModif)
{
    ui->setupUi(this);
    ui->lineEditModifNomContact->setText(leNom);
    ui->lineEditModifPrenomContact->setText(lePrenom);
    ui->lineEditModifMailContact->setText(leMail);
    ui->lineEditModifNPortableContact->setText(leNPortable);
}
DialogModif::~DialogModif()
{
    delete ui;
}
QString DialogModif::getNouveauNomContact()
{
    return ui->lineEditModifNomContact->text();
}
QString DialogModif::getNouveauPrenomContact()
{
    return ui->lineEditModifPrenomContact->text();
}
QString DialogModif::getNouveauMailContact()
{
    return ui->lineEditModifMailContact->text();
}
QString DialogModif::getNouveauNPortableContact()
{
    return ui->lineEditModifNPortableContact->text();
}


void DialogModif::on_pushButtonCancel_clicked()
{
    reject();
}
void DialogModif::on_lineEditModifNomContact_textChanged()
{
    activatedOkButton();
}

void DialogModif::on_lineEditModifPrenomContact_textChanged()
{
    activatedOkButton();
}

void DialogModif::on_lineEditModifMailContact_textChanged()
{
    activatedOkButton();
}

void DialogModif::on_lineEditModifNPortableContact_textChanged()
{
    activatedOkButton();
}
void DialogModif::activatedOkButton(){
    ui->pushButtonOk->setEnabled((ui->lineEditModifPrenomContact->text()!="")&& (ui->lineEditModifNomContact->text()!="")&&(ui->lineEditModifMailContact->text()!="")&&(ui->lineEditModifNPortableContact->text().length()==10));
}

void DialogModif::on_pushButtonOk_clicked()
{
    accept();
}

