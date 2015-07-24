#include "fenprincipale.h"

FenPrincipale::FenPrincipale()
{
    //barre menu
    QMenu *f = menuBar()->addMenu("Fichier");
    f->addAction("Save");
    QMenu *e = menuBar()->addMenu("Edit");
    e->addAction("Admin");

    //taille de la fenêtre
    setMinimumSize(650,450);
    setMaximumSize(650,450);

    QWidget *zoneCentrale = new QWidget;
    // 1 : Création du QTabWidget
    QTabWidget *onglets = new QTabWidget(zoneCentrale);
    onglets->setGeometry(30, 20, 600, 400);

    // 2 : Création des pages, en utilisant un widget parent pour contenir chacune des pages
    QWidget *page1 = new QWidget;
    QWidget *page2 = new QWidget;
    QWidget *page3 = new QWidget;
    QLabel *page4 = new QLabel;

    // 3 : Création du contenu

        // Page 1 = Patient

        //identité
        QLineEdit *idpatient = new QLineEdit("IdPatient");
        QLineEdit *lineEdit1 = new QLineEdit("Nom du Patient");
        QLineEdit *lineEdit2 = new QLineEdit("Prénom du Patient");

        //sexe du patient
        QLabel *textsexe = new QLabel(page1);
        textsexe->setText("Sexe du patient : ");
        QGroupBox *groupbox = new QGroupBox("Sexe du patient");
        QRadioButton *Femme = new QRadioButton("Femme");
        QRadioButton *Homme = new QRadioButton("Homme");
        QRadioButton *Autre = new QRadioButton("Autre");

        Femme->setChecked(true);

        //N°INSEE
        QLineEdit *lineEdit3 = new QLineEdit("N° INSEE");

        //Age
        QSpinBox *age = new QSpinBox;
               age->setSuffix(" ans");
               age->setRange(0, 100);

         QSpinBox *poid = new QSpinBox;
               poid->setSuffix(" Kg");
               poid->setRange(0, 250);

         QSpinBox *taille = new QSpinBox;
               taille->setSuffix(" cm");
               taille->setRange(0, 250);

        QVBoxLayout *vbox1 = new QVBoxLayout;
        vbox1->addWidget(idpatient);
        vbox1->addWidget(lineEdit1);
        vbox1->addWidget(lineEdit2);
        vbox1->addWidget(age);
        vbox1->addWidget(textsexe);
        groupbox->setLayout(vbox1);
        vbox1->addWidget(Femme);
        vbox1->addWidget(Homme);
        vbox1->addWidget(Autre);
        vbox1->addWidget(lineEdit3);
        vbox1->addWidget(poid);
        vbox1->addWidget(taille);



        page1->setLayout(vbox1);

        // Page 2 = examen

        QLabel *position = new QLabel(page2);
        position->setText("Choisir la position patient :");
        QComboBox *liste1 = new QComboBox(page2);
        liste1->addItem("Debout");
        liste1->addItem("Allongé");
        liste1->move(5, 20);

        QLabel *etat = new QLabel(page2);
        etat->setText("Définir l'état du patient :");
        QComboBox *liste2 = new QComboBox(page2);
        liste2->addItem("Repos");
        liste2->addItem("Contraction");
        liste2->addItem("Extention");
        etat->move(5, 60);
        liste2->move(5, 80);

        QLabel *localisation = new QLabel(page2);
        localisation->setText("Définir la localisation de l'examen :");
        QComboBox *listeLoc = new QComboBox(page2);
        listeLoc->addItem("Bras");
        listeLoc->addItem("Molet");
        listeLoc->addItem("Ventre");
        localisation->move(5, 120);
        listeLoc->move(5, 140);


        QVBoxLayout *vbox2 = new QVBoxLayout;
        vbox2->addWidget(position);
        vbox2->addWidget(liste1);
        vbox2->addWidget(etat);
        vbox2->addWidget(liste2);
        vbox2->addWidget(localisation);
        vbox2->addWidget(listeLoc);

        //page 3 = opérateur
        //identité
        QLineEdit *lineEdit4 = new QLineEdit("Nom de l'opérateur");
        QLineEdit *lineEdit5 = new QLineEdit("Prénom de l'opérateur");

        QVBoxLayout *vbox3 = new QVBoxLayout;
        vbox3->addWidget(lineEdit4);
        vbox3->addWidget(lineEdit5);

        page3->setLayout(vbox3);


        //page 4 = Validation
        QPushButton *bouton= new QPushButton("Validation");
        QPushButton *autreBouton = new QPushButton("Charger configuration");
        autreBouton->move(100, 0);

        QVBoxLayout *vbox4 = new QVBoxLayout;
        vbox4->addWidget(bouton);
        vbox4->addWidget(autreBouton);

        page4->setLayout(vbox4);



    // 4 : ajouter les onglets au QTabWidget, en indiquant la page qu'ils contiennent
    onglets->addTab(page1, "Patient");
    onglets->addTab(page2, "Examen");
    onglets->addTab(page3, "Opérateur");
    onglets->addTab(page4, "Validation");

    setCentralWidget(zoneCentrale);

}
