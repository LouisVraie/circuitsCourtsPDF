#ifndef CLASSEMENTPRODUIT_H
#define CLASSEMENTPRODUIT_H

#include <QString>
#include <QVector>
#include <QDebug>
/**
 * @brief La classe ClassementProduit
 */
class ClassementProduit
{
private:
    QString rayon;
    QString nom;
    QString variete;
public:
    ClassementProduit(QString unRayon,QString unNom,QString uneVariete);
    ClassementProduit();
    QVector<QString> getClassementProduit();
};

#endif // CLASSEMENTPRODUIT_H
