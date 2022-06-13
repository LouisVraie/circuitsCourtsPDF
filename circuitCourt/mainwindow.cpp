#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief MainWindow::MainWindow
 * Constructeur de la classe MainWindow qui permet de renseigner l'identifiant du Producteur avec les valeurs passées en paramètre
 * @param parent
 */
MainWindow::MainWindow(char* numeroProd,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    idProducteur = QString(numeroProd);
    //on crée la brochure PDF
    brochurePDF();
}

/**
 * @brief MainWindow::~MainWindow
 * Destructeur de la classe MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::brochurePDF
 * Méthode privée qui permet de créer une brochure PDF des ProduitProducteur dans l'application
 */
void MainWindow::brochurePDF()
{
    ui->monPDF->setName("ProduitProducteur.pdf");
    QVector<ProduitProducteur> collectionPP;
    collectionPP = Passerelle::chargerLesProduitsProducteurs(idProducteur);

    //si la taille de la collectionPP est au minimum à 1
    if(collectionPP.size()>=1){
        QString semaine;
        semaine += "Date : ";
        semaine += collectionPP[0].getSemaineProduitProducteur();
        ui->monPDF->ecrireTexte(semaine);

        //infos producteur
        QVector<Producteur> leProducteur;
        leProducteur = Passerelle::chargerLeProducteur(idProducteur);
        QString producteur = leProducteur[0].getInfosProducteur();
        ui->monPDF->ecrireTexte(producteur);
    }

    //pour chaque pdtP de collectionPP
    for(int no=0;no<collectionPP.size();no++){
        ProduitProducteur pdtP = collectionPP.at(no);
        qDebug()<<"ProduitProducteur : "<<no+1;

        QString texte = pdtP.getInfoProduitProducteur();
        ui->monPDF->ecrireTexte(texte);
        QString image = pdtP.getImageProduitProducteur(idProducteur);
        qDebug()<<image;
        ui->monPDF->chargerImage(image);
    }
    ui->monPDF->fermer();
}
