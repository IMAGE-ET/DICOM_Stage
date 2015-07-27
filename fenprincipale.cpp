#include "fenprincipale.h"

FenPrincipale::FenPrincipale():

m_mainWidget(new QWidget(this)),
m_mainLayout(new QGridLayout(m_mainWidget)),

//réglages Patient
m_pageReglagesPatient(new QGroupBox("Réglages patient", m_mainWidget)),

//réglages Examen
m_pageReglagesExamen(new QGroupBox("Réglages examen", m_mainWidget)),

//réglages Médecins
m_pageReglagesMedecin(new QGroupBox("Réglages médecins", m_mainWidget)),

//sauvegarder
m_pageSauvegarder(new QGroupBox("Sauvegarder", m_mainWidget))

{
    /*----proprietes de la fenetre----*/
    setWindowTitle("Interface Utilisateur");
    setMinimumSize(650,550);
    setWindowState(Qt::WindowMaximized);

    //barre menu
    QMenu *f = menuBar()->addMenu("Fichier");
    f->addAction("Save");
    QMenu *e = menuBar()->addMenu("Edit");
    e->addAction("Admin");

    /*----création du contenu----*/

    _setupReglagesPatient();
    _setupReglagesExamen();
    _setupReglagesMedecin();
    _setupSauvegarder();

    m_pageReglagesExamen->setDisabled(true);

    /*----mise en place des pages----*/
    m_mainLayout->addWidget(m_pageReglagesPatient,0,0);
    m_mainLayout->addWidget(m_pageReglagesExamen,0,1);
    m_mainLayout->addWidget(m_pageReglagesMedecin,1,0);
    m_mainLayout->addWidget(m_pageSauvegarder,1,1);

    /*----widget central----*/
    setCentralWidget(m_mainWidget);
    m_mainWidget->setLayout(m_mainLayout);
  }

/*----------PRIVATE SLOTS----------*/
//réglages Patient
void FenPrincipale::_patientNext()
{
  m_pageReglagesPatient->setDisabled(true);
  m_pageReglagesExamen->setDisabled(false);
}

//réglages Examen
void FenPrincipale::_examenPrevious()
{
  m_pageReglagesPatient->setDisabled(false);
  m_pageReglagesExamen->setDisabled(true);
}

void FenPrincipale::_examenNext()
{
  m_pageReglagesExamen->setDisabled(true);
  m_pageReglagesMedecin->setDisabled(false);
}

//réglages Médecin
void FenPrincipale::_medecinPrevious()
{
    m_pageReglagesExamen->setDisabled(false);
    m_pageReglagesMedecin->setDisabled(true);
}

//sauvegarder
void FenPrincipale::_save() const
{

}

void FenPrincipale::_load()
{

}

/*----------PRIVATE FUNCS----------*/

//réglages patient
void FenPrincipale::_setupReglagesPatient()
{
  //layout de la page
  QFormLayout * layoutReglagesPatient = new QFormLayout(m_pageReglagesPatient);

  m_pageReglagesPatient->setLayout(layoutReglagesPatient);

  /*----Identité----*/
  QLineEdit * lineEdit_idPatient = new QLineEdit(m_pageReglagesPatient);
  lineEdit_idPatient->setPlaceholderText("ID Patient");
  layoutReglagesPatient->addRow("ID Patient", lineEdit_idPatient);

  QLineEdit * lineEdit_nomPatient = new QLineEdit(m_pageReglagesPatient);
  lineEdit_nomPatient->setPlaceholderText("Nom du Patient");
  layoutReglagesPatient->addRow("Nom du Patient", lineEdit_nomPatient);

  QLineEdit * lineEdit_prenomPatient = new QLineEdit(m_pageReglagesPatient);
  lineEdit_prenomPatient->setPlaceholderText("Préom du Patient");
  layoutReglagesPatient->addRow("Préom du Patient", lineEdit_prenomPatient);

  QLineEdit * lineEdit_INSEEPatient = new QLineEdit(m_pageReglagesPatient);
  lineEdit_INSEEPatient->setPlaceholderText("Numéro INSEE");
  layoutReglagesPatient->addRow("Numéro INSEE", lineEdit_INSEEPatient);

  /*----Sexe----*/
  QGroupBox *groupbox_sexe = new QGroupBox("Sexe du patient");
  layoutReglagesPatient->addRow("Sexe du patien", groupbox_sexe );
  QRadioButton *Femme = new QRadioButton("Femme");
  QRadioButton *Homme = new QRadioButton("Homme");
  QRadioButton *Autre = new QRadioButton("Autre");

  Femme->setChecked(true);

  /*----Age----*/
  QSpinBox *spinBox_age = new QSpinBox(m_pageReglagesPatient);
         spinBox_age->setSuffix(" ans");
         spinBox_age->setRange(0, 100);
  // spinBox_age->setPlaceholderText("Age du patient");
   layoutReglagesPatient->addRow("Age du patient", spinBox_age);

   /*----Morphologie----*/
   QSpinBox *spinBox_poid = new QSpinBox(m_pageReglagesPatient);
          spinBox_poid->setSuffix(" Kg");
          spinBox_poid->setRange(0, 250);
    //spinBox_age->setPlaceholderText("Poid du patient");
    layoutReglagesPatient->addRow("Poid du patient", spinBox_poid);

    QSpinBox *spinBox_taille = new QSpinBox(m_pageReglagesPatient);
           spinBox_taille->setSuffix(" cm");
           spinBox_taille->setRange(0, 250);
    // spinBox_taille->setPlaceholderText("Taille du patient");
     layoutReglagesPatient->addRow("Taille du patient", spinBox_age);

  QPushButton * nextButton = new QPushButton("Suivant", m_pageReglagesPatient);
  layoutReglagesPatient->addWidget(nextButton);
  QObject::connect(nextButton, SIGNAL(clicked(bool)), this, SLOT(_patientNext()));

  QPushButton * chargerButton = new QPushButton("Charger patient", m_pageReglagesPatient);
  layoutReglagesPatient->addWidget(chargerButton);
}

//réglages examen
void FenPrincipale::_setupReglagesExamen()
{
  //layout de la page
  QFormLayout * layoutReglagesExamen = new QFormLayout(m_pageReglagesExamen);

  m_pageReglagesExamen->setLayout(layoutReglagesExamen);

  /*----liste des positions patients----*/
  QStringList positionsPatients_items;
  positionsPatients_items.append("Debout");
  positionsPatients_items.append("Allongé");
  layoutReglagesExamen->addRow("Position du patient :",positionsPatients_widget);


  /*----liste des etats----*/
  QStringList listeEtats_items;
  listeEtats_items.append("Repos");
  listeEtats_items.append("Contraction");
  listeEtats_items.append("Extension");
  layoutReglagesExamen->addRow("État du muscle / activité demandée:",listeEtats_widget);


  /*----localisation----*/
  QStringList localisation_items;
  localisation_items.append("Bras");
  localisation_items.append("Mollet");
  localisation_items.append("Ventre");
  layoutReglagesExamen->addRow("Localisation de l'examen:", localisation_widget);

  QPushButton * nextButton = new QPushButton("Suivant", m_pageReglagesExamen);
  layoutReglagesExamen->addWidget(nextButton);
  QObject::connect(nextButton, SIGNAL(clicked(bool)), this, SLOT(_examenNext()));

  QPushButton * previousButton = new QPushButton("Précedent", m_pageReglagesExamen);
  layoutReglagesExamen->addWidget(previousButton);
  QObject::connect(previousButton, SIGNAL(clicked(bool)), this, SLOT(_examenPrevious()));

}

//réglages médecins
void FenPrincipale::_setupReglagesMedecin()
{
  //layout de la page
  QFormLayout * layoutReglagesMedecin = new QFormLayout(m_pageReglagesMedecin);

  m_pageReglagesMedecin->setLayout(layoutReglagesMedecin);

  /*----liste des opérateurs----*/
  QStringList listeOperateurs_items;
  listeOperateurs_items.append("Monsieur Stark");
  listeOperateurs_items.append("Madame Potts");
  layoutReglagesMedecin->addRow("Opérateur :",listeOperateurs_widget);


  /*----liste des prescripteurs----*/
  QStringList listePrescripteurs_items;
  listePrescripteurs_items.append("Monsieur Wayne");
  listePrescripteurs_items.append("Madame Kyle");
  layoutReglagesMedecin->addRow("Prescripteur :",listePrescripteurs_widget);


  /*----liste des réalisateurs----*/

  QStringList listeRealisateurs_items;
  listeRealisateurs_items.append("Monsieur Rogers");
  listeRealisateurs_items.append("Madame Carter");
  layoutReglagesMedecin->addRow("Réalisateur :",listeRealisateurs_widget);


  QPushButton * previousButton = new QPushButton("Précedent", m_pageReglagesMedecin);
  layoutReglagesMedecin->addWidget(previousButton);
  QObject::connect(previousButton, SIGNAL(clicked(bool)), this, SLOT(_medecinPrevious()));
}


//sauvegarder
void FenPrincipale::_setupSauvegarder()
{
  QVBoxLayout * layoutSauvegarder = new QVBoxLayout(m_pageSauvegarder);
  layoutSauvegarder->setAlignment(Qt::AlignTop);

  QPushButton * boutonSauvegarder = new QPushButton("Sauvegarder", m_pageSauvegarder);
  layoutSauvegarder->addWidget(boutonSauvegarder);

  QPushButton * boutonCharger = new QPushButton("Charger configuration", m_pageSauvegarder);
  layoutSauvegarder->addWidget(boutonCharger);
}
