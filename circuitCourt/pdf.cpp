#include "pdf.h"

/**
 * @brief PDF::PDF
 * Constructeur vide de la classe PDF qui permet de renseigner le paramètre de la classe QTextBrowser
 * @param parent: QWidget
 */
PDF::PDF(QWidget *parent):QTextBrowser(parent)
{

}

/**
 * @brief PDF::setName
 * Méthode publique qui permet de définir le nom du PDF
 * @param nomDocument: QString Nom du document PDF
 */
void PDF::setName(QString nomDocument)
{
    nomDoc = nomDocument;
}

/**
 * @brief PDF::ecrireTexte
 * Méthode publique qui permet d'ajouter le texte passé en paramètre au document PDF
 * @param leTexte: QString
 */
void PDF::ecrireTexte(QString leTexte)
{
    //écrit le texte
    setHtml(toHtml()+"<p>"+leTexte+"</p>");
}

/**
 * @brief PDF::chargerImage
 * Méthode publique qui permet d'ajouter le code HTML qui permet d'afficher une image avec le chemin d'accès passé en paramètres
 * @param chemin: QString Chemin d'accès pour accéder à l'image
 */
void PDF::chargerImage(QString chemin)
{
    QString imgStyle =
            "width: 50px;"
            "height: auto;"
            "border: 1px solid black;";
    //écrit l'image
    setHtml(toHtml()+"<center><img width=\"200\" style=\""+imgStyle+"\" src=\""+chemin+"\" alt=\"/home/lvraie/sio2/AP/circuitsCourts/"+chemin+"\"/></center>");
}

/**
 * @brief PDF::fermer
 * Méthode publique qui permet de fermer le pdf en l'enregistrant et l'affichant
 */
void PDF::fermer()
{
    //ferme le pdf en l'enregistrant
    QPdfWriter *printer = new QPdfWriter(nomDoc);
    printer->newPage();
    printer->setTitle("Circuits Courts : Catalogue des produits de la semaine");
    printer->setPageSize(QPagedPaintDevice::A4);

    print(printer);
    delete printer;
}
