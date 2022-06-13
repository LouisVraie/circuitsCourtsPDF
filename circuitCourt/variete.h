#ifndef VARIETE_H
#define VARIETE_H

#include <QString>
/**
 * @brief La classe Variete
 */
class Variete
{
private:
    QString idVariete;
    QString libelle;
    QString image;
public:
    Variete();
    Variete(QString unIdVariete, QString unLibelle, QString uneImage);
    QString getIdVariete();
    QString getLibelleVariete();
    QString getImageVariete();
};

#endif // VARIETE_H
