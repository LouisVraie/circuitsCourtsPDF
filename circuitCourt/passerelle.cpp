#include "passerelle.h"
#include <QDebug>
/**
 * @brief Passerelle::Passerelle
 * Constructeur vide de la classe Passerelle
 */
Passerelle::Passerelle()
{
    //constructeur vide
}

/**
 * @brief Passerelle::chargerLesRayons
 * Méthode statique publique de la classe Passerelle
 * @param unIdProducteur: QString Identifiant d'un Producteur
 * @param unIdVariete: QString Identifiant d'une Variete
 * @return QVector<Rayon> Listes qui retourne les informations du Rayon
 */
QVector<Rayon> Passerelle::chargerLesRayons(QString unIdProducteur,QString unIdVariete)
{
    qDebug()<<"QVector<Rayon> Passerelle::chargerLesRayons(int unIdProducteur)";
    QVector<Rayon> resultat;
    QString requete = "SELECT DISTINCT r.numeroRayon,r.libelleRayon,r.imageRayon FROM Rayon r "
            "INNER JOIN Produit pdt ON pdt.numeroRayon = r.numeroRayon "
            "INNER JOIN Variete var ON var.numeroProduit = pdt.numeroProduit "
            "INNER JOIN ProduitProducteur pp ON pp.numeroVariete = var.numeroVariete "
            "INNER JOIN Producteur prod ON prod.numeroProducteur = pp.numeroProducteur "
            "INNER JOIN Semaine sem ON sem.numeroSemaine = pp.numeroSemaine "
            "WHERE sem.numeroSemaine = (SELECT MAX(numeroSemaine) FROM Semaine) "
            "AND prod.numeroProducteur = "+unIdProducteur+" "
            "AND var.numeroVariete = "+unIdVariete;
    qDebug()<<requete;
    JeuEnregistrement monJeu = JeuEnregistrement(requete);

    //on rempli et retourne notre vecteur
    QString sonId= monJeu.getValeur("numeroRayon").toString();
    QString sonLibelle = monJeu.getValeur("libelleRayon").toString();
    QString sonImage = monJeu.getValeur("imageRayon").toString();
    qDebug()<<sonId<<" "<<sonLibelle;
    //j'obtiens ses produits
    QVector<Produit> sesProduits;
    sesProduits = chargerLesProduits(unIdProducteur,unIdVariete);
    Rayon unRayon = Rayon(sonId,sonLibelle,sonImage,sesProduits);
    resultat.push_back(unRayon);

    return resultat;
}

/**
 * @brief Passerelle::chargerLesProduits
 * Méthode statique publique de la classe Passerelle
 * @param unIdProducteur: QString Identifiant d'un Producteur
 * @param unIdVariete: QString Identifiant d'une Variete
 * @return QVector<Produit> Listes qui retourne les informations du Produit
 */
QVector<Produit> Passerelle::chargerLesProduits(QString unIdProducteur,QString unIdVariete)
{
    qDebug()<<"QVector<Produit> Passerelle::chargerLesProduits(int unIdProducteur)";
    QVector<Produit> resultat;
    QString requete = "SELECT DISTINCT pdt.numeroProduit,pdt.libelleProduit,pdt.imageProduit FROM Produit pdt "
            "INNER JOIN Variete var ON var.numeroProduit = pdt.numeroProduit "
            "INNER JOIN ProduitProducteur pp ON pp.numeroVariete = var.numeroVariete "
            "INNER JOIN Producteur prod ON prod.numeroProducteur = pp.numeroProducteur "
            "INNER JOIN Semaine sem ON sem.numeroSemaine = pp.numeroSemaine "
            "INNER JOIN Rayon r ON pdt.numeroRayon = r.numeroRayon "
            "WHERE sem.numeroSemaine = (SELECT MAX(numeroSemaine) FROM Semaine) "
            "AND prod.numeroProducteur = "+unIdProducteur+" "
            "AND var.numeroVariete = "+unIdVariete;
    qDebug()<<requete;
    JeuEnregistrement monJeu = JeuEnregistrement(requete);

    //on rempli et retourne notre vecteur
    QString sonId= monJeu.getValeur("numeroProduit").toString();
    QString sonLibelle = monJeu.getValeur("libelleProduit").toString();
    QString sonImage = monJeu.getValeur("imageProduit").toString();
    qDebug()<<sonId<<" "<<sonLibelle;
    //j'obtiens ses variétés
    QVector<Variete> sesVarietes;
    sesVarietes = chargerLesVarietes(unIdVariete);
    Produit unProduit = Produit(sonId,sonLibelle,sonImage,sesVarietes);
    resultat.push_back(unProduit);

    return resultat;
}

/**
 * @brief Passerelle::chargerLesVarietes
 * Méthode statique publique de la classe Passerelle
 * @param unIdVariete: QString Identifiant d'une Variete
 * @return QVector<Variete> Listes qui retourne les informations de la Variete
 */
QVector<Variete> Passerelle::chargerLesVarietes(QString unIdVariete)
{
    qDebug()<<"QVector<Variete> Passerelle::chargerLesVarietes(int unIdProducteur)";
    QVector<Variete> resultat;
    QString requete = "SELECT DISTINCT var.numeroVariete,var.libelleVariete,var.imageVariete FROM Variete var "
            "WHERE var.numeroVariete = "+unIdVariete;
    qDebug()<<requete;
    JeuEnregistrement monJeu = JeuEnregistrement(requete);

    //on rempli et retourne notre vecteur
    QString sonId= monJeu.getValeur("numeroVariete").toString();
    QString sonLibelle = monJeu.getValeur("libelleVariete").toString();
    QString sonImage = monJeu.getValeur("imageVariete").toString();
    qDebug()<<sonId<<" "<<sonLibelle;
    resultat.push_back(Variete(sonId,sonLibelle,sonImage));

    return resultat;
}

/**
 * @brief Passerelle::chargerLesProduitsProducteurs
 * Méthode statique publique de la classe Passerelle
 * @param unIdProducteur: QString Identifiant d'un Producteur
 * @return QVector<ProduitProducteur> Listes qui retourne les informations du ProduitProducteur
 */
QVector<ProduitProducteur> Passerelle::chargerLesProduitsProducteurs(QString unIdProducteur)
{
    qDebug()<<"QVector<ProduitProducteur> Passerelle::chargerLesProduitsProducteurs(int unIdProducteur)";
    QVector<ProduitProducteur> resultat;
    QString requete = "SELECT DISTINCT pp.numeroProduitProducteur, pp.quantiteProduitProducteur, pp.prixUnitaireProduitProducteur, pp.numeroVariete, "
                      "CONCAT(' du ',s.dateDebSemaine,' au ',s.dateFinSemaine) AS semaine, u.libelleUnite FROM ProduitProducteur pp "
                      "INNER JOIN Semaine s ON s.numeroSemaine = pp.numeroSemaine "
                      "INNER JOIN Producteur p ON p.numeroProducteur = pp.numeroProducteur "
                      "INNER JOIN Unite u ON u.numeroUnite = pp.numeroUnite "
                      "WHERE s.numeroSemaine = (SELECT MAX(numeroSemaine) FROM Semaine) "
                      "AND pp.numeroProducteur = "+unIdProducteur;
    qDebug()<<requete;
    JeuEnregistrement monJeu = JeuEnregistrement(requete);
    //on rempli et retourne notre vecteur
    while(!monJeu.fin()){
        QString sonId = monJeu.getValeur("numeroProduitProducteur").toString();
        double saQuantite = monJeu.getValeur("quantiteProduitProducteur").toDouble();
        float sonPu = monJeu.getValeur("prixUnitaireProduitProducteur").toFloat();
        QString sonIdVariete = monJeu.getValeur("numeroVariete").toString();
        QString saSemaine = monJeu.getValeur("semaine").toString();
        QString sonUnite = monJeu.getValeur("libelleUnite").toString();
        //j'obtiens ses Rayons
        QVector<Rayon> sesRayons;
        sesRayons = chargerLesRayons(unIdProducteur,sonIdVariete);
        ProduitProducteur unProduitProducteur = ProduitProducteur(sonId,saQuantite,sonPu,saSemaine,sonUnite,sesRayons);
        resultat.push_back(unProduitProducteur);
        //on passe à l'enregistrement suivant
        monJeu.suivant();
    }
    return resultat;
}

/**
 * @brief Passerelle::chargerLeProducteur
 * Méthode statique publique de la classe Passerelle
 * @param unIdProducteur: QString Identifiant d'un Producteur
 * @return QVector<Producteur> Listes qui retourne les informations du Producteur
 */
QVector<Producteur> Passerelle::chargerLeProducteur(QString unIdProducteur)
{
    qDebug()<<"QVector<Producteur> Passerelle::chargerLeProducteur(QString unIdProducteur)";
    QVector<Producteur> resultat;
    QString requete = "SELECT numeroProducteur,nomProducteur,prenomProducteur,adresseProducteur,"
                      "villeProducteur,codePostalProducteur,mailProducteur,telProducteur FROM Producteur "
                      "WHERE numeroProducteur = "+unIdProducteur;
    qDebug()<<requete;
    JeuEnregistrement monJeu = JeuEnregistrement(requete);

    //on rempli et retourne notre vecteur
    QString sonId= monJeu.getValeur("numeroProducteur").toString();
    QString sonNom = monJeu.getValeur("nomProducteur").toString();
    QString sonPrenom = monJeu.getValeur("prenomProducteur").toString();
    QString sonAdresse = monJeu.getValeur("adresseProducteur").toString();
    QString saVille = monJeu.getValeur("villeProducteur").toString();
    QString sonCodePostal = monJeu.getValeur("codePostalProducteur").toString();
    QString sonMail = monJeu.getValeur("mailProducteur").toString();
    QString sonTel = monJeu.getValeur("telProducteur").toString();

    resultat.push_back(Producteur(sonId,sonNom,sonPrenom,sonAdresse,saVille,sonCodePostal,sonMail,sonTel));

    return resultat;
}


