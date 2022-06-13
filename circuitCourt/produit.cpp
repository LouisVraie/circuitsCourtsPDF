#include "produit.h"

/**
 * @brief Produit::Produit
 * Constructeur vide de la classe Produit
 */
Produit::Produit()
{
    //constructeur vide
}

/**
 * @brief Produit::Produit
 * Constructeur de la classe Produit qui permet de renseigner les propriétés privées du Produit avec les valeurs passées en paramètre
 * @param unIdProduit: int Id du produit
 * @param unLibelle: QString Libelle du produit
 * @param uneImage : QString Chemin d'accès à l'image du produit
 * @param uneColVarietes: QVector<Variete> Liste des variétés du Produit
 */
Produit::Produit(QString unIdProduit, QString unLibelle, QString uneImage, QVector<Variete> uneColVarietes)
{
    idProduit = unIdProduit;
    libelle = unLibelle;
    image = uneImage;
    lesVarietes = uneColVarietes;
}

/**
 * @brief Produit::getLibelleProduit
 * Méthode publique de la classe Produit
 * @return QString Chaîne de caractère qui retourne le libelle du Produit
 */
QString Produit::getLibelleProduit()
{
    return libelle;
}

/**
 * @brief Produit::getImageProduit
 * Méthode publique de la classe Produit
 * @return QString Chaîne de caractère qui retourne le chemin d'accès à l'image du Produit
 */
QString Produit::getImageProduit()
{
    return image;
}

/**
 * @brief Produit::getLesVarietes
 * Méthode publique de la classe Produit
 * @return QVector<Variete> Retourne la liste des Varietes du Produit
 */
QVector<Variete> Produit::getLesVarietes()
{
    return lesVarietes;
}
