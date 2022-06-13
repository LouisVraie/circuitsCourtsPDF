#ifndef PRODUITPRODUCTEUR_H
#define PRODUITPRODUCTEUR_H

#include "rayon.h"
#include "produit.h"
#include "variete.h"
#include "unite.h"
#include "jeuenregistrement.h"
#include <QVector>
#include <QDebug>

class ProduitProducteur
{
private:
    QString idProduitProducteur;
    double quantite;
    float prixUnitaire;
    QString semaine;
    QString unite;
    QVector<Rayon> lesRayons;
    static QString lastRayon;
    static QString lastProduit;

public:
    ProduitProducteur();
    ProduitProducteur(QString unIdProduitProducteur, double uneQuantite, float unPrixUnitaire,QString uneSemaine, QString uneUnite, QVector<Rayon> uneColRayon);
    QString getImageProduitProducteur(QString unIdProducteur);
    QString getInfoProduitProducteur();
    QString getSemaineProduitProducteur();
};


#endif // PRODUITPRODUCTEUR_H
