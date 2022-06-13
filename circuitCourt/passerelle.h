/**
  @author Louis Vraie
  @date 08/11/2021
  @version 1.0 beta 1
  @copyright GNU Public License
 */
#ifndef PASSERELLE_H
#define PASSERELLE_H
#include "jeuenregistrement.h"
#include "rayon.h"
#include "produit.h"
#include "variete.h"
#include "produitproducteur.h"
#include "producteur.h"
#include <QVector>

/**
 * @brief La classe Passerelle
 * Elle est dépendante des classes BateauVoyageur et Equipement
 */
class Passerelle
{
private:

public:
    Passerelle();
    static QVector<Rayon> chargerLesRayons(QString unIdProducteur,QString unIdVariete);
    static QVector<Produit> chargerLesProduits(QString unIdProducteur,QString unIdVariete);
    static QVector<Variete> chargerLesVarietes(QString unIdVariete);
    static QVector<ProduitProducteur> chargerLesProduitsProducteurs(QString unIdProducteur);
    static QVector<Producteur> chargerLeProducteur(QString unIdProducteur);
};

#endif // PASSERELLE_H
