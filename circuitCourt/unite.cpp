#include "unite.h"

/**
 * @brief Unite::Unite
 * Constructeur vide de la classe Unite
 */
Unite::Unite()
{
    //Constructeur vide
}

/**
 * @brief Unite::Unite
 * Constructeur de la classe Unite qui permet de renseigner les propriétés privées de l'Unite avec les valeurs passées en paramètre
 * @param unIdUnite: int Id de l'unité
 * @param unLibelle: QString Libelle de l'unité
 */
Unite::Unite(QString unIdUnite, QString unLibelle)
{
    idUnite = unIdUnite;
    libelle = unLibelle;
}

/**
 * @brief Unite::getLibelleUnite
 * Méthode publique de la classe Unite
 * @return QString Chaîne de caractères qui retourne le libelle de l'Unite
 */
QString Unite::getLibelleUnite()
{
    return libelle;
}
