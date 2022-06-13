#include "producteur.h"

/**
 * @brief Producteur::Producteur
 * Constructeur vide de la classe ProduitProducteur
 */
Producteur::Producteur()
{
    //constructeur vide
}

/**
 * @brief Producteur::Producteur
 * Constructeur de la classe Producteur qui permet de renseigner les propriétés privées du Producteur avec les valeurs passées en paramètre
 * @param unIdProducteur: QString Identifiant du Producteur
 * @param unNom: QString Nom du Producteur
 * @param unPrenom: QString Prénom du Producteur
 * @param uneAdresse: QString Adresse du Producteur
 * @param uneVille: QString Ville du Producteur
 * @param unCodePostal: QString Code Postal du Producteur
 * @param unMail: QString Mail du Producteur
 * @param unTel: QString Tel du Producteur
 */
Producteur::Producteur(QString unIdProducteur, QString unNom, QString unPrenom,
                       QString uneAdresse, QString uneVille, QString unCodePostal,
                       QString unMail, QString unTel)
{
    idProducteur = unIdProducteur;
    nom = unNom;
    prenom = unPrenom;
    adresse = uneAdresse;
    ville = uneVille;
    codePostal = unCodePostal;
    mail = unMail;
    tel = unTel;
}

/**
 * @brief Producteur::getInfosProducteur
 * Méthode publique de la classe Producteur
 * @return QString Chaîne de caractère qui renvoie les informations du Producteur
 */
QString Producteur::getInfosProducteur()
{
    QString resultat;
    QString sautLigne = "<br>";
    QString tab = "\t";
    resultat = prenom+" "+nom+sautLigne;
    resultat += adresse+sautLigne;
    resultat += codePostal+" "+ville+sautLigne;
    resultat += mail+sautLigne;
    resultat += tel;
    qDebug()<<resultat;
    return resultat;
}
