#ifndef PRODUCTEUR_H
#define PRODUCTEUR_H

#include "produitproducteur.h"
/**
 * @brief La classe Producteur
 */
class Producteur
{
private:
    QString idProducteur;
    QString nom,prenom;
    QString adresse,ville,codePostal;
    QString mail,tel;
    //QVector<ProduitProducteur> colProduitProducteur;
public:
    Producteur();
    Producteur(QString unIdProducteur,QString unNom,QString unPrenom,
               QString uneAdresse,QString uneVille,QString unCodePostal,
               QString unMail,QString unTel);
    QString getInfosProducteur();
};

#endif // PRODUCTEUR_H
