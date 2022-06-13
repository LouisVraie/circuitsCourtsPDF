#include "variete.h"

/**
 * @brief Variete::Variete
 * Constructeur vide de la classe Variete
 */
Variete::Variete()
{
    //Constructeur vide
}

/**
 * @brief Variete::Variete
 * Constructeur de la classe Variete qui permet de renseigner les propriétés privées de la Variete avec les valeurs passées en paramètre
 * @param unIdVariete: int Id de la variété
 * @param unLibelle: QString Libelle de la variété
 * @param uneImage : QString Chemin pour accéder à l'image de la variété
 */
Variete::Variete(QString unIdVariete, QString unLibelle, QString uneImage)
{
    idVariete = unIdVariete;
    libelle = unLibelle;
    image = uneImage;
}

/**
 * @brief Variete::getIdVariete
 * Méthode publique de la classe Variete
 * @return QString Chaîne de caractère qui retourne l'identifiant de la Variete
 */
QString Variete::getIdVariete()
{
    return idVariete;
}

/**
 * @brief Variete::getLibelleVariete
 * Méthode publique de la classe Variete
 * @return QString Chaîne de caractère qui retourne le libelle de la Variete
 */
QString Variete::getLibelleVariete()
{
    return libelle;
}

/**
 * @brief Variete::getImageVariete
 * Méthode publique de la classe Variete
 * @return QString Chaîne de caractère qui retourne le chemin d'accès de l'image de la Variete
 */
QString Variete::getImageVariete()
{
    return image;
}
