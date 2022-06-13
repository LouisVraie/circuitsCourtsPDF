#ifndef UNITE_H
#define UNITE_H

#include <QString>
/**
 * @brief La classe Unite
 */
class Unite
{
private:
    QString idUnite;
    QString libelle;
public:
    Unite();
    Unite(QString unIdUnite,QString unLibelle);
    QString getLibelleUnite();
};

#endif // UNITE_H
