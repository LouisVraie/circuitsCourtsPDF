
#include "produitproducteur.h"

QString ProduitProducteur::lastRayon="";
QString ProduitProducteur::lastProduit="";
/**
 * @brief ProduitProducteur::ProduitProducteur
 * Constructeur vide de la classe ProduitProducteur
 */
ProduitProducteur::ProduitProducteur()
{
    //constructeur vide
}

/**
 * @brief ProduitProducteur::ProduitProducteur
 * Constructeur de la classe ProduitProducteur qui permet de renseigner les propriétés privées du ProduitProducteur avec les valeurs passées en paramètre
 * @param unIdProduitProducteur: int Identifiant du ProduitProducteur
 * @param uneQuantite: double Quantité du ProduitProducteur
 * @param unPrixUnitaire: float Prix unitaire du ProduitProducteur
 * @param uneSemaine: QString Intervalle comportant la date de début et la date de fin de la semaine du ProduitProducteur
 * @param uneUnite: QString Unite du ProduitProducteur
 * @param uneColRayon: QVector<Rayon> Liste des informations sur le Rayon du ProduitProducteur
 */
ProduitProducteur::ProduitProducteur(QString unIdProduitProducteur, double uneQuantite, float unPrixUnitaire,
                                     QString uneSemaine, QString uneUnite, QVector<Rayon> uneColRayon)
{
    idProduitProducteur = unIdProduitProducteur;
    quantite = uneQuantite;
    prixUnitaire = unPrixUnitaire;
    semaine = uneSemaine;
    unite = uneUnite;
    lesRayons = uneColRayon;
}

/**
 * @brief ProduitProducteur::getImageProduitProducteur
 * Méthode publique de la classe ProduitProducteur
 * @return QString Chaîne de caractère qui retourne le chemin d'accès à l'image du ProduitProducteur
 */
QString ProduitProducteur::getImageProduitProducteur(QString unIdProducteur)
{
    QString idVariete = lesRayons[0].getLesProduits()[0].getLesVarietes()[0].getIdVariete();
    QString reqImage = "SELECT cheminImageProducteur FROM ImageProducteur "
                       "WHERE numeroProducteur = "+unIdProducteur+" "
                       "AND numeroVariete = "+idVariete+" "
                       "ORDER BY numeroSemaine DESC LIMIT 0,1";
    qDebug()<<reqImage;
    JeuEnregistrement resultImage(reqImage);
    //si le producteur a une image de la variété
    if(!resultImage.fin()){
        qDebug()<<"Image Producteur";
        return resultImage.getValeur("cheminImageProducteur").toString();

    //sinon si l'image de la variété n'est pas vide
    }else if(!lesRayons[0].getLesProduits()[0].getLesVarietes()[0].getImageVariete().isEmpty()){
        qDebug()<<"Image Variété";
        return lesRayons[0].getLesProduits()[0].getLesVarietes()[0].getImageVariete();

    //sinon si l'image du produit n'est pas vide
    }else if(!lesRayons[0].getLesProduits()[0].getImageProduit().isEmpty()) {
        qDebug()<<"Image Produit";
        return lesRayons[0].getLesProduits()[0].getImageProduit();

    //sinon si l'image du rayon n'est pas vide
    }else if(!lesRayons[0].getImageRayon().isEmpty()) {
        qDebug()<<"Image Rayon";
        return lesRayons[0].getImageRayon();

    //sinon si aucune image
    }else {
        qDebug()<<"Image Non Disponible";
        return "Image Non Disponible";
    }
}

/**
 * @brief ProduitProducteur::getInfoProduitProducteur
 * Méthode publique de la classe ProduitProducteur
 * @return QString Chaîne de caractère qui retourne le texte détaillant les informations de chaque ProduitProducteur
 */
QString ProduitProducteur::getInfoProduitProducteur()
{
    QString resultat;
    QString sautLigne = "<br>";
    QString tab = "\t";

    //si le dernier rayon est différent
    if(lastRayon != lesRayons[0].getLibelleRayon()){
        //on définit le dernier rayon
        lastRayon = lesRayons[0].getLibelleRayon();
        //on ajoute le libelle du rayon
        resultat += lastRayon+sautLigne;
    }
    //on récupère les produits du rayons
    QVector<Produit> sesProduits = lesRayons[0].getLesProduits();

    //si le dernier produit est différent
    if(lastProduit != sesProduits[0].getLibelleProduit()){
        //on définit le dernier produit
        lastProduit = sesProduits[0].getLibelleProduit();
        //on ajoute le libelle du produit
        resultat += tab+lastProduit+sautLigne;
    }
    //on récupère les variétés du produit
    QVector<Variete> sesVarietes = sesProduits[0].getLesVarietes();

    //on ajoute le libelle du produit
    resultat += tab+tab+sesVarietes[0].getLibelleVariete()+" :"+sautLigne;
    resultat += tab+tab+" - Quantité disponible : "+QString::number(quantite)+" "+unite+sautLigne;
    resultat += tab+tab+" - Prix Unitaire : "+QString::number(prixUnitaire)+"€";

    return resultat;
}

/**
 * @brief ProduitProducteur::getSemaineProduitProducteur
 * Méthode publique de la classe ProduitProducteur
 * @return QString Chaîne de caractères qui retourne la semaine du ProduitProducteur
 */
QString ProduitProducteur::getSemaineProduitProducteur()
{
    return semaine;
}

