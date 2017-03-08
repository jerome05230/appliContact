#include "dialognewcontact.h"
#include "ui_dialognewcontact.h"

DialogNewContact::DialogNewContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewContact)
{
    ui->setupUi(this);
}

DialogNewContact::~DialogNewContact()
{
    delete ui;
}
QString DialogNewContact::getNomContact()
{
    return ui->lineEditNomContact->text();
}
QString DialogNewContact::getPrenomContact()
{
    return ui->lineEditPrenomContact->text();
}
QString DialogNewContact::getMailContact()
{
    return ui->lineEditMailContact->text();
}
QString DialogNewContact::getNPortableContact()
{
    return ui->lineEditNPortableContact->text();
}

void DialogNewContact::on_pushButtonOk_clicked()
{
    accept();
}

void DialogNewContact::on_pushButtonCancel_clicked()
{
    reject();
}

void DialogNewContact::on_lineEditNomContact_textChanged()
{
    activatedOkButton();
}

void DialogNewContact::on_lineEditPrenomContact_textChanged()
{
    activatedOkButton();
}

void DialogNewContact::on_lineEditMailContact_textChanged()
{
   activatedOkButton();
}

void DialogNewContact::on_lineEditNPortableContact_textChanged()
{
  activatedOkButton();
}

void DialogNewContact::activatedOkButton(){
    ui->pushButtonOk->setEnabled((ui->lineEditPrenomContact->text()!="")&& (ui->lineEditNomContact->text()!="")&&(ui->lineEditMailContact->text()!="")&&(ui->lineEditNPortableContact->text().length()==10));
}
