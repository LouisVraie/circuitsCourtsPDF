#ifndef RAYON_H
#define RAYON_H

#include <QString>
#include <QVector>
#include "produit.h"

/**
 * @brief La classe Rayon
 */
class Rayon
{
private:
    QString idRayon;
    QString libelle;
    QString image;
    QVector<Produit> lesProduits;

public:
    Rayon();
    Rayon(QString unIdRayon,QString unLibelle, QString uneImage, QVector<Produit> uneColProduits);
    QString getLibelleRayon();
    QString getImageRayon();
    QVector<Produit> getLesProduits();

};

#endif // RAYON_H
