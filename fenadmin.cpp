
#include "fenadmin.h"

FenAdmin::FenAdmin():

  m_mainWidget(new QWidget(this)),
  m_mainLayout(new QGridLayout(m_mainWidget)),

  //réglages généraux
  m_pageReglagesGeneraux(new QGroupBox("Réglages généraux", m_mainWidget)),

  //réglages DICOM
  m_pageReglagesDicom(new QGroupBox("Réglages DICOM", m_mainWidget)),

  //logs
  m_pageLogs(new QGroupBox("LOGS", m_mainWidget)),

  //sauvegarder
  m_pageSauvegarder(new QGroupBox("Sauvegarder", m_mainWidget))
{
  /*----proprietes de la fenetre----*/
  setWindowTitle("Interface Administrateur");
  setMinimumSize(650,550);
  setWindowState(Qt::WindowMaximized);

  //barre menu
  QMenu *f = menuBar()->addMenu("Fichier");
  f->addAction("Save");
  QMenu *e = menuBar()->addMenu("Edit");
  e->addAction("Admin");

  /*----création du contenu----*/

  _setupReglagesGeneraux();
  _setupReglagesDicom();
  _setupLogs();
  _setupSauvegarder();

  /*----mise en place des pages----*/
  m_mainLayout->addWidget(m_pageReglagesGeneraux,0,0);
  m_mainLayout->addWidget(m_pageReglagesDicom,0,1);
  m_mainLayout->addWidget(m_pageLogs,1,0);
  m_mainLayout->addWidget(m_pageSauvegarder,1,1);

  /*----widget central----*/
  setCentralWidget(m_mainWidget);
  m_mainWidget->setLayout(m_mainLayout);
}

//réglages généraux
void FenAdmin::_setupReglagesGeneraux()
{
  //Site
  QLineEdit *lineEdit1 = new QLineEdit("Nom du Site", m_pageReglagesGeneraux);
  QLineEdit *lineEdit2 = new QLineEdit("Adresse", m_pageReglagesGeneraux);


  //Liste Opérateurs
  QLabel *operateur = new QLabel(m_pageReglagesGeneraux);
  operateur->setText("Liste des Opérateurs");
  QComboBox *listeOperateurs = new QComboBox(m_pageReglagesGeneraux);
  listeOperateurs->addItem("Monsieur X");
  listeOperateurs->addItem("Madame Y");

  QLineEdit *lineEditOp = new QLineEdit("Ajouter un Opérateur", m_pageReglagesGeneraux);

  //Liste Prescripteurs
  QLabel *prescripteur = new QLabel(m_pageReglagesGeneraux);
  prescripteur->setText("Liste des Prescripteurs");
  QComboBox *listePrescripteurs = new QComboBox(m_pageReglagesGeneraux);
  listePrescripteurs->addItem("Monsieur X");
  listePrescripteurs->addItem("Madame Y");

  QLineEdit *lineEditPr = new QLineEdit("Ajouter un Prescripteur", m_pageReglagesGeneraux);

  //Liste Réalisateurs
  QLabel *realisateur = new QLabel(m_pageReglagesGeneraux);
  realisateur->setText("Liste des Réalisateurs");
  QComboBox *listeRealisateurs = new QComboBox(m_pageReglagesGeneraux);
  listeRealisateurs->addItem("Monsieur X");
  listeRealisateurs->addItem("Madame Y");

  QLineEdit *lineEditReal = new QLineEdit("Ajouter un Réalisateur");

  //Positions patient
  QLabel *position = new QLabel(m_pageReglagesGeneraux);
  position->setText("Liste des Positions Patient");
  QComboBox *listePosition = new QComboBox(m_pageReglagesGeneraux);
  listePosition->addItem("Debout");
  listePosition->addItem("Allongé");

  QLineEdit *lineEditPos = new QLineEdit("Ajouter une Position Patient");

  //Etats
  QLabel *etat = new QLabel(m_pageReglagesGeneraux);
  etat->setText("Liste des Etats");
  QComboBox *listeEtat = new QComboBox(m_pageReglagesGeneraux);
  listeEtat ->addItem("Repos");
  listeEtat ->addItem("Contraction");
  listeEtat ->addItem("Extention");
  QLineEdit *lineEditEtat = new QLineEdit("Ajouter un Etat", m_pageReglagesGeneraux);

  //localisation
  QLabel *localisation = new QLabel(m_pageReglagesGeneraux);
  localisation->setText("Définir la localisation de l'examen :");
  QComboBox *listeLoc = new QComboBox(m_pageReglagesGeneraux);
  listeLoc->addItem("Bras");
  listeLoc->addItem("Molet");
  listeLoc->addItem("Ventre");
  QLineEdit *lineEditLoc = new QLineEdit("Ajouter une localisation");


  QVBoxLayout *vbox1 = new QVBoxLayout(m_pageReglagesGeneraux);
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



  m_pageReglagesGeneraux->setLayout(vbox1);
}

//réglages DICOM
void FenAdmin::_setupReglagesDicom()
{
  QLineEdit *lineEditIP = new QLineEdit("Indiquez adresse IP", m_pageReglagesDicom);
  QLineEdit *lineEditPort = new QLineEdit("Indiquer le port DICOM", m_pageReglagesDicom);
  QLabel *syntaxe = new QLabel(m_pageReglagesDicom);
  syntaxe->setText("Choisir la syntaxe de transfert :");
  QComboBox *listeSyntaxe = new QComboBox(m_pageReglagesDicom);
  listeSyntaxe ->addItem("Implicit little Endian");
  listeSyntaxe ->addItem("Implicit big Endian");
  listeSyntaxe ->addItem("Explicit little Endian");
  listeSyntaxe ->addItem("Explicit big Endian");


  QVBoxLayout *vbox2 = new QVBoxLayout(m_pageReglagesDicom);
  vbox2->addWidget(lineEditIP);
  vbox2->addWidget(lineEditPort);
  vbox2->addWidget(syntaxe);
  vbox2->addWidget(listeSyntaxe);

  m_pageReglagesDicom->setLayout(vbox2);
}

//logs
void FenAdmin::_setupLogs()
{
  QLabel *texttest = new QLabel(m_pageLogs);
  texttest->setText("plop");
  /*QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(upLabel()));
        timer->start(1000);*/

  QVBoxLayout *vbox3 = new QVBoxLayout(m_pageLogs);
  vbox3->addWidget(texttest);
}

//sauvegarder
void FenAdmin::_setupSauvegarder()
{
  QPushButton *bouton= new QPushButton("Sauvegarder", m_pageSauvegarder);
  QPushButton *autreBouton = new QPushButton("Charger configuration", m_pageSauvegarder);
  autreBouton->move(100, 0);

  QVBoxLayout *vbox4 = new QVBoxLayout(m_pageSauvegarder);
  vbox4->addWidget(bouton);
  vbox4->addWidget(autreBouton);

  m_pageSauvegarder->setLayout(vbox4);
}
