#include "rayon.h"

/**
 * @brief Rayon::Rayon
 * Constructeur vide de la classe Rayon
 */
Rayon::Rayon()
{
    //constructeur vide
}

/**
 * @brief Rayon::Rayon
 * Constructeur de la classe Rayon qui permet de renseigner les propriétés privées du Rayon avec les valeurs passées en paramètre
 * @param unIdRayon: int Id du rayon
 * @param unLibelle: QString Libelle du rayon
 * @param uneImage : QString Chemin pour accéder à l'image du rayon
 * @param uneColProduits: QVector<Produit> Liste des produits du rayon
 */
Rayon::Rayon(QString unIdRayon,QString unLibelle, QString uneImage, QVector<Produit> uneColProduits)
{
    idRayon = unIdRayon;
    libelle = unLibelle;
    image = uneImage;
    lesProduits = uneColProduits;
}

/**
 * @brief Rayon::getLibelleRayon
 * Méthode publique de la classe Rayon
 * @return QString Chaîne de caractère qui renvoie le libelle du Rayon
 */
QString Rayon::getLibelleRayon()
{
    return libelle;
}

/**
 * @brief Rayon::getImageRayon
 * Méthode publique de la classe Rayon
 * @return QString Chaîne de caractère qui retourne le chemin d'accès de l'image du Rayon
 */
QString Rayon::getImageRayon()
{
    return image;
}

/**
 * @brief Rayon::getLesProduits
 * Méthode publique de la classe Rayon
 * @return QVector<Produit> Retourne la Listes des Produits du Rayon
 */
QVector<Produit> Rayon::getLesProduits()
{
    return lesProduits;
}
