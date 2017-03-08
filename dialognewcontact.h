#ifndef DIALOGNEWCONTACT_H
#define DIALOGNEWCONTACT_H

#include <QDialog>

namespace Ui {
class DialogNewContact;
}

class DialogNewContact : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewContact(QWidget *parent = 0);
    ~DialogNewContact();

    QString getNomContact();
    QString getPrenomContact();
    QString getMailContact();
    QString getNPortableContact();
    void activatedOkButton();
private slots:
    void on_pushButtonOk_clicked();
    void on_pushButtonCancel_clicked();
    void on_lineEditNomContact_textChanged();
    void on_lineEditPrenomContact_textChanged();
    void on_lineEditMailContact_textChanged();
    void on_lineEditNPortableContact_textChanged();
private:
    Ui::DialogNewContact *ui;
};

#endif // DIALOGNEWCONTACT_H
