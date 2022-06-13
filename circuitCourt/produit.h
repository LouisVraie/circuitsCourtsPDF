#ifndef PRODUIT_H
#define PRODUIT_H

#include <QString>
#include <QVector>
#include "variete.h"
/**
 * @brief La classe Produit
 */
class Produit
{
private:
    QString idProduit;
    QString libelle;
    QString image;
    QVector<Variete> lesVarietes;
public:
    Produit();
    Produit(QString unIdProduit, QString unLibelle, QString uneImage, QVector<Variete> uneColVarietes);
    QString getLibelleProduit();
    QString getImageProduit();
    QVector<Variete> getLesVarietes();
};

#endif // PRODUIT_H
