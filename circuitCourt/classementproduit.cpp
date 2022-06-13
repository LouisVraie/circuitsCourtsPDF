
#include "classementproduit.h"
/**
 * @brief ClassementProduit::ClassementProduit
 * Constructeur de la classe ClassementProduit qui permet de remplir les propriétés privées du produit avec les valeurs passées en paramètre
 * @param unRayon: QString Rayon du produit
 * @param unNom: QString Nom du produit
 * @param uneVariete: QString Variété du produit
 */
ClassementProduit::ClassementProduit(QString unRayon, QString unNom, QString uneVariete)
{
    rayon = unRayon;
    nom = unNom;
    variete = uneVariete;
}
/**
 * @brief ClassementProduit::ClassementProduit
 * Constructeur vide de la classe ClassementProduit
 */
ClassementProduit::ClassementProduit()
{
    //Constructeur vide
}

/**
 * @brief ClassementProduit::getClassementProduit
 * Méthode publique de la classe ClassementProduit qui renvoie la liste du classement du produit
 * @return QVector<QString> Un vecteur de chaînes de caractères qui contient les détails du classement d'un produit rayon/nom/variété
 */
QVector<QString> ClassementProduit::getClassementProduit()
{
    qDebug()<<"QVector<QString> ClassementProduit::getClassementProduit()";
    QVector<QString> classement;
    classement.push_back(rayon);
    classement.push_back(nom);
    classement.push_back(variete);
    return classement;
}
