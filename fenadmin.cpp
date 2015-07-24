
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
  //layout de la page
  QFormLayout * layoutReglagesGeneraux = new QFormLayout(m_pageReglagesGeneraux);

  m_pageReglagesGeneraux->setLayout(layoutReglagesGeneraux);

  /*----site----*/
  QLineEdit * lineEdit_nomDuSite = new QLineEdit(m_pageReglagesGeneraux);
  lineEdit_nomDuSite->setPlaceholderText("Nom du site");
  layoutReglagesGeneraux->addRow("Nom du site", lineEdit_nomDuSite);

  QLineEdit * lineEdit_adresse = new QLineEdit(m_pageReglagesGeneraux);
  lineEdit_adresse->setPlaceholderText("Adresse");
  layoutReglagesGeneraux->addRow("Adresse", lineEdit_adresse);


  /*----liste des opérateurs----*/
  QWidget * listeOperateurs_widget = new QWidget(m_pageReglagesGeneraux);
  QGridLayout * listeOperateurs_layout = new QGridLayout(listeOperateurs_widget);

  QComboBox * listeOperateurs_combobox = new QComboBox(listeOperateurs_widget);
  listeOperateurs_combobox->addItem("Monsieur Stark");
  listeOperateurs_combobox->addItem("Madame Potts");

  QLineEdit * listeOperateurs_lineedit = new QLineEdit(listeOperateurs_widget);
  listeOperateurs_lineedit->setPlaceholderText("Ajouter un opérateur");

  QPushButton * listeOperateurs_pushbutton = new QPushButton("Ajouter", listeOperateurs_widget);

  listeOperateurs_layout->addWidget(listeOperateurs_combobox,0,0,1,2);
  listeOperateurs_layout->addWidget(listeOperateurs_lineedit,1,0);
  listeOperateurs_layout->addWidget(listeOperateurs_pushbutton,1,1);

  listeOperateurs_widget->setLayout(listeOperateurs_layout);
  layoutReglagesGeneraux->addRow("Opérateur :",listeOperateurs_widget);


  /*----liste des prescripteurs----*/
  QWidget * listePrescripteurs_widget = new QWidget(m_pageReglagesGeneraux);
  QGridLayout * listePrescripteurs_layout = new QGridLayout(listePrescripteurs_widget);

  QComboBox * listePrescripteurs_combobox = new QComboBox(listePrescripteurs_widget);
  listePrescripteurs_combobox->addItem("Monsieur Wayne");
  listePrescripteurs_combobox->addItem("Madame Kyle");

  QLineEdit * listePrescripteurs_lineedit = new QLineEdit(listePrescripteurs_widget);
  listePrescripteurs_lineedit->setPlaceholderText("Ajouter un prescripteur");

  QPushButton * listePrescripteurs_pushbutton = new QPushButton("Ajouter", listePrescripteurs_widget);

  listePrescripteurs_layout->addWidget(listePrescripteurs_combobox,0,0,1,2);
  listePrescripteurs_layout->addWidget(listePrescripteurs_lineedit,1,0);
  listePrescripteurs_layout->addWidget(listePrescripteurs_pushbutton,1,1);

  listePrescripteurs_widget->setLayout(listePrescripteurs_layout);
  layoutReglagesGeneraux->addRow("Prescripteur :",listePrescripteurs_widget);


  /*----liste des réalisateurs----*/
  QWidget * listeRealisateurs_widget = new QWidget(m_pageReglagesGeneraux);
  QGridLayout * listeRealisateurs_layout = new QGridLayout(listeRealisateurs_widget);

  QComboBox * listeRealisateurs_combobox = new QComboBox(listeRealisateurs_widget);
  listeRealisateurs_combobox->addItem("Monsieur Rogers");
  listeRealisateurs_combobox->addItem("Madame Carter");

  QLineEdit * listeRealisateurs_lineedit = new QLineEdit(listeRealisateurs_widget);
  listeRealisateurs_lineedit->setPlaceholderText("Ajouter un réalisateur");

  QPushButton * listeRealisateurs_pushbutton = new QPushButton("Ajouter", listeRealisateurs_widget);

  listeRealisateurs_layout->addWidget(listeRealisateurs_combobox,0,0,1,2);
  listeRealisateurs_layout->addWidget(listeRealisateurs_lineedit,1,0);
  listeRealisateurs_layout->addWidget(listeRealisateurs_pushbutton,1,1);

  listeRealisateurs_widget->setLayout(listeRealisateurs_layout);
  layoutReglagesGeneraux->addRow("Réalisateurs :",listeRealisateurs_widget);


  /*----liste des positions patients----*/
  QWidget * positionsPatients_widget = new QWidget(m_pageReglagesGeneraux);
  QGridLayout * positionsPatients_layout = new QGridLayout(positionsPatients_widget);

  QComboBox * positionsPatients_combobox = new QComboBox(positionsPatients_widget);
  positionsPatients_combobox->addItem("Debout");
  positionsPatients_combobox->addItem("Allongé");

  QLineEdit * positionsPatients_lineedit = new QLineEdit(positionsPatients_widget);
  positionsPatients_lineedit->setPlaceholderText("Ajouter une position patient");

  QPushButton * positionsPatients_pushbutton = new QPushButton("Ajouter", positionsPatients_widget);

  positionsPatients_layout->addWidget(positionsPatients_combobox,0,0,1,2);
  positionsPatients_layout->addWidget(positionsPatients_lineedit,1,0);
  positionsPatients_layout->addWidget(positionsPatients_pushbutton,1,1);

  positionsPatients_widget->setLayout(positionsPatients_layout);
  layoutReglagesGeneraux->addRow("Position patient :",positionsPatients_widget);


  /*----liste des etats----*/
  QWidget * listeEtats_widget = new QWidget(m_pageReglagesGeneraux);
  QGridLayout * listeEtats_layout = new QGridLayout(listeEtats_widget);

  QComboBox * listeEtats_combobox = new QComboBox(listeEtats_widget);
  listeEtats_combobox->addItem("Repos");
  listeEtats_combobox->addItem("Contraction");
  listeEtats_combobox->addItem("Extension");

  QLineEdit * listeEtats_lineedit = new QLineEdit(listeEtats_widget);
  listeEtats_lineedit->setPlaceholderText("Ajouter un état");

  QPushButton * listeEtats_pushbutton = new QPushButton("Ajouter",listeEtats_widget);

  listeEtats_layout->addWidget(listeEtats_combobox,0,0,1,2);
  listeEtats_layout->addWidget(listeEtats_lineedit,1,0);
  listeEtats_layout->addWidget(listeEtats_pushbutton,1,1);

  listeEtats_widget->setLayout(listeEtats_layout);
  layoutReglagesGeneraux->addRow("État :",listeEtats_widget);


  /*----localisation----*/
  QWidget * localisation_widget = new QWidget(m_pageReglagesGeneraux);
  QGridLayout * localisation_layout = new QGridLayout(localisation_widget);

  QComboBox * localisation_combobox = new QComboBox(localisation_widget);
  localisation_combobox->addItem("Bras");
  localisation_combobox->addItem("Molet");
  localisation_combobox->addItem("Ventre");

  QLineEdit * localisation_lineedit = new QLineEdit(localisation_widget);
  localisation_lineedit->setPlaceholderText("Ajouter une localisation");

  QPushButton * localisation_pushbutton = new QPushButton("Ajouter", localisation_widget);

  localisation_layout->addWidget(localisation_combobox,0,0,1,2);
  localisation_layout->addWidget(localisation_lineedit,1,0);
  localisation_layout->addWidget(localisation_pushbutton,1,1);

  localisation_widget->setLayout(localisation_layout);
  layoutReglagesGeneraux->addRow("Localisation :", localisation_widget);
}

//réglages DICOM
void FenAdmin::_setupReglagesDicom()
{
  QFormLayout * layoutReglagesDicom = new QFormLayout(m_pageReglagesDicom);
  m_pageReglagesDicom->setLayout(layoutReglagesDicom);

  QLineEdit * ip_lineEdit = new QLineEdit(m_pageReglagesDicom);
  ip_lineEdit->setPlaceholderText("Adresse IP");
  layoutReglagesDicom->addRow("Adresse IP :",ip_lineEdit);

  QLineEdit * port_lineEdit = new QLineEdit(m_pageReglagesDicom);
  port_lineEdit->setPlaceholderText("Port DICOM");
  layoutReglagesDicom->addRow("Port DICOM",port_lineEdit);

  QComboBox * syntaxe_combobox = new QComboBox(m_pageReglagesDicom);
  syntaxe_combobox->addItem("Implicit little endian");
  syntaxe_combobox->addItem("Implicit big endian");
  syntaxe_combobox->addItem("Explicit little endian");
  syntaxe_combobox->addItem("Explicit big endian");
  layoutReglagesDicom->addRow("Syntaxe de transfert :", syntaxe_combobox);
}

//logs
void FenAdmin::_setupLogs()
{
  QVBoxLayout * layoutLogs = new QVBoxLayout(m_pageLogs);
  layoutLogs->setAlignment(Qt::AlignTop);

  QLabel *texttest = new QLabel(m_pageLogs);
  texttest->setText("plop");

  layoutLogs->addWidget(texttest);

  /*QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(upLabel()));
        timer->start(1000);*/
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
