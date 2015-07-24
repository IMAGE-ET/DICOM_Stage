
#include "fenadmin.h"

FenAdmin::FenAdmin()
{
    //barre menu
    QMenu *f = menuBar()->addMenu("Fichier");
    f->addAction("Save");
    QMenu *e = menuBar()->addMenu("Edit");
    e->addAction("Admin");

    //taille de la fenêtre
    setMinimumSize(650,550);
    setMaximumSize(650,550);

    QWidget *zoneCentrale = new QWidget;
    // 1 : Création du QTabWidget
    QTabWidget *onglets = new QTabWidget(zoneCentrale);
    onglets->setGeometry(30, 20, 600, 500);

    // 2 : Création des pages, en utilisant un widget parent pour contenir chacune des pages
    QWidget *page1 = new QWidget;
    QWidget *page2 = new QWidget;
    QWidget *page3 = new QWidget;
    QLabel *page4 = new QLabel;

    // 3 : Création du contenu

        // Page 1 = Réglages généraux

        //Site
        QLineEdit *lineEdit1 = new QLineEdit("Nom du Site");
        QLineEdit *lineEdit2 = new QLineEdit("Adresse");


        //Liste Opérateurs
        QLabel *operateur = new QLabel(page1);
        operateur->setText("Liste des Opérateurs");
        QComboBox *listeOperateurs = new QComboBox(page1);
        listeOperateurs->addItem("Monsieur X");
        listeOperateurs->addItem("Madame Y");

        QLineEdit *lineEditOp = new QLineEdit("Ajouter un Opérateur");

        //Liste Prescripteurs
        QLabel *prescripteur = new QLabel(page1);
        prescripteur->setText("Liste des Prescripteurs");
        QComboBox *listePrescripteurs = new QComboBox(page1);
        listePrescripteurs->addItem("Monsieur X");
        listePrescripteurs->addItem("Madame Y");

        QLineEdit *lineEditPr = new QLineEdit("Ajouter un Prescripteur");

        //Liste Réalisateurs
        QLabel *realisateur = new QLabel(page1);
        realisateur->setText("Liste des Réalisateurs");
        QComboBox *listeRealisateurs = new QComboBox(page1);
        listeRealisateurs->addItem("Monsieur X");
        listeRealisateurs->addItem("Madame Y");

        QLineEdit *lineEditReal = new QLineEdit("Ajouter un Réalisateur");

        //Positions patient
        QLabel *position = new QLabel(page1);
        position->setText("Liste des Positions Patient");
        QComboBox *listePosition = new QComboBox(page1);
        listePosition->addItem("Debout");
        listePosition->addItem("Allongé");

        QLineEdit *lineEditPos = new QLineEdit("Ajouter une Position Patient");

        //Etats
        QLabel *etat = new QLabel(page1);
        etat->setText("Liste des Etats");
        QComboBox *listeEtat = new QComboBox(page1);
        listeEtat ->addItem("Repos");
        listeEtat ->addItem("Contraction");
        listeEtat ->addItem("Extention");
        QLineEdit *lineEditEtat = new QLineEdit("Ajouter un Etat");

        //localisation
        QLabel *localisation = new QLabel(page2);
        localisation->setText("Définir la localisation de l'examen :");
        QComboBox *listeLoc = new QComboBox(page2);
        listeLoc->addItem("Bras");
        listeLoc->addItem("Molet");
        listeLoc->addItem("Ventre");
        QLineEdit *lineEditLoc = new QLineEdit("Ajouter une localisation");


        QVBoxLayout *vbox1 = new QVBoxLayout;
        vbox1->addWidget(lineEdit1);
        vbox1->addWidget(lineEdit2);
        vbox1->addWidget(operateur);
        vbox1->addWidget(listeOperateurs);
        vbox1->addWidget(lineEditOp);
        vbox1->addWidget(prescripteur);
        vbox1->addWidget(listePrescripteurs);
        vbox1->addWidget(lineEditPr);
        vbox1->addWidget(realisateur);
        vbox1->addWidget(listeRealisateurs);
        vbox1->addWidget(lineEditReal);
        vbox1->addWidget(position);
        vbox1->addWidget(listePosition);
        vbox1->addWidget(lineEditPos);
        vbox1->addWidget(etat);
        vbox1->addWidget(listeEtat);
        vbox1->addWidget(lineEditEtat);
        vbox1->addWidget(localisation);
        vbox1->addWidget(listeLoc);
        vbox1->addWidget(lineEditLoc);



        page1->setLayout(vbox1);

        // Page 2 = Réglages DICOM

        QLineEdit *lineEditIP = new QLineEdit("Indiquez adresse IP");
        QLineEdit *lineEditPort = new QLineEdit("Indiquer le port DICOM");
        QLabel *syntaxe = new QLabel(page2);
        syntaxe->setText("Choisir la syntaxe de transfert :");
        QComboBox *listeSyntaxe = new QComboBox(page2);
        listeSyntaxe ->addItem("Implicit little Endian");
        listeSyntaxe ->addItem("Implicit big Endian");
        listeSyntaxe ->addItem("Explicit little Endian");
        listeSyntaxe ->addItem("Explicit big Endian");


        QVBoxLayout *vbox2 = new QVBoxLayout;
        vbox2->addWidget(lineEditIP);
        vbox2->addWidget(lineEditPort);
        vbox2->addWidget(syntaxe);
        vbox2->addWidget(listeSyntaxe);

        page2->setLayout(vbox2);

        //page 3 = LOGS

        QLabel *texttest = new QLabel(page3);
        texttest->setText("plop");
        /*QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(upLabel()));
        timer->start(1000);*/

        QVBoxLayout *vbox3 = new QVBoxLayout;
        vbox3->addWidget(texttest);



        //page 4 = Sauvegarder
        QPushButton *bouton= new QPushButton("Sauvegarder");
        QPushButton *autreBouton = new QPushButton("Charger configuration");
        autreBouton->move(100, 0);

        QVBoxLayout *vbox4 = new QVBoxLayout;
        vbox4->addWidget(bouton);
        vbox4->addWidget(autreBouton);

        page4->setLayout(vbox4);



    // 4 : ajouter les onglets au QTabWidget, en indiquant la page qu'ils contiennent
    onglets->addTab(page1, "Réglages généraux");
    onglets->addTab(page2, "Réglages DICOM");
    onglets->addTab(page3, "LOGS");
    onglets->addTab(page4, "Sauvegarder");

    setCentralWidget(zoneCentrale);

}
