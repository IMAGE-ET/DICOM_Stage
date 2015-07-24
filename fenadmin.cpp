
#include "fenadmin.h"

FenAdmin::FenAdmin():

  m_mainWidget(new QWidget(this)),
  m_mainLayout(new QGridLayout(m_mainWidget)),

  //réglages généraux
  m_pageReglagesGeneraux(new QGroupBox("Réglages généraux", m_mainWidget)),

  //réglages DICOM
  m_pageReglagesDicom(new QGroupBox("Réglages DICOM", m_mainWidget)),

  //logs
  m_pageLogs(new QGroupBox("Logs", m_mainWidget)),
  m_textEditLogs(new QTextEdit(m_pageLogs)),

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

  m_pageReglagesDicom->setDisabled(true);

  /*----mise en place des pages----*/
  m_mainLayout->addWidget(m_pageReglagesGeneraux,0,0);
  m_mainLayout->addWidget(m_pageReglagesDicom,0,1);
  m_mainLayout->addWidget(m_pageLogs,1,0);
  m_mainLayout->addWidget(m_pageSauvegarder,1,1);

  /*----widget central----*/
  setCentralWidget(m_mainWidget);
  m_mainWidget->setLayout(m_mainLayout);
}

/*----------PUBLIC SLOTS----------*/

void FenAdmin::addLogLine(QString const& line)
{
  m_textEditLogs->append(line);
}

/*----------PRIVATE SLOTS----------*/
//réglages généraux
void FenAdmin::_generalNext()
{
  m_pageReglagesGeneraux->setDisabled(true);
  m_pageReglagesDicom->setDisabled(false);
}

//réglages DICOM
void FenAdmin::_dicomPrevious()
{
  m_pageReglagesGeneraux->setDisabled(false);
  m_pageReglagesDicom->setDisabled(true);
}

void FenAdmin::_dicomNext()
{

}

//logs
void FenAdmin::_saveLogs() const
{
  //TODO
}

//sauvegarder
void FenAdmin::_save() const
{

}

void FenAdmin::_load()
{

}

/*----------PRIVATE FUNCS----------*/

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
  QStringList listeOperateurs_items;
  listeOperateurs_items.append("Monsieur Stark");
  listeOperateurs_items.append("Madame Potts");

  ExtensibleListeWidget * listeOperateurs_widget = new ExtensibleListeWidget("Ajouter un état", listeOperateurs_items, m_pageReglagesGeneraux);
  layoutReglagesGeneraux->addRow("État :",listeOperateurs_widget);


  /*----liste des prescripteurs----*/
  QStringList listePrescripteurs_items;
  listePrescripteurs_items.append("Monsieur Wayne");
  listePrescripteurs_items.append("Madame Kyle");

  ExtensibleListeWidget * listePrescripteurs_widget = new ExtensibleListeWidget("Ajouter un état", listePrescripteurs_items, m_pageReglagesGeneraux);
  layoutReglagesGeneraux->addRow("État :",listePrescripteurs_widget);


  /*----liste des réalisateurs----*/
  QStringList listeRealisateurs_items;
  listeRealisateurs_items.append("Monsieur Rogers");
  listeRealisateurs_items.append("Madame Carter");

  ExtensibleListeWidget * listeRealisateurs_widget = new ExtensibleListeWidget("Ajouter un état", listeRealisateurs_items, m_pageReglagesGeneraux);
  layoutReglagesGeneraux->addRow("État :",listeRealisateurs_widget);


  /*----liste des positions patients----*/
  QStringList positionsPatients_items;
  positionsPatients_items.append("Debout");
  positionsPatients_items.append("Allongé");
  ExtensibleListeWidget * positionsPatients_widget = new ExtensibleListeWidget("Ajouter une position patient", positionsPatients_items, m_pageReglagesGeneraux);
  layoutReglagesGeneraux->addRow("Position patient :",positionsPatients_widget);


  /*----liste des etats----*/
  QStringList listeEtats_items;
  listeEtats_items.append("Repos");
  listeEtats_items.append("Contraction");
  listeEtats_items.append("Extension");

  ExtensibleListeWidget * listeEtats_widget = new ExtensibleListeWidget("Ajouter un état", listeEtats_items, m_pageReglagesGeneraux);
  layoutReglagesGeneraux->addRow("État :",listeEtats_widget);


  /*----localisation----*/
  QStringList localisation_items;
  localisation_items.append("Bras");
  localisation_items.append("Mollet");
  localisation_items.append("Ventre");

  ExtensibleListeWidget * localisation_widget = new ExtensibleListeWidget("Ajouter une localisation", localisation_items, m_pageReglagesGeneraux);
  layoutReglagesGeneraux->addRow("Localisation :", localisation_widget);

  QPushButton * nextButton = new QPushButton("Suivant", m_pageReglagesGeneraux);
  layoutReglagesGeneraux->addWidget(nextButton);
  QObject::connect(nextButton, SIGNAL(clicked(bool)), this, SLOT(_generalNext()));
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
  layoutReglagesDicom->addRow("Port DICOM :",port_lineEdit);

  QComboBox * syntaxe_combobox = new QComboBox(m_pageReglagesDicom);
  syntaxe_combobox->addItem("Implicit little endian");
  syntaxe_combobox->addItem("Implicit big endian");
  syntaxe_combobox->addItem("Explicit little endian");
  syntaxe_combobox->addItem("Explicit big endian");
  layoutReglagesDicom->addRow("Syntaxe de transfert :", syntaxe_combobox);

  QPushButton * previousButton = new QPushButton("Précedent", m_pageReglagesDicom);
  layoutReglagesDicom->addWidget(previousButton);
  QObject::connect(previousButton, SIGNAL(clicked(bool)), this, SLOT(_dicomPrevious()));
}

//logs
void FenAdmin::_setupLogs()
{
  QVBoxLayout * layoutLogs = new QVBoxLayout(m_pageLogs);
  layoutLogs->setAlignment(Qt::AlignTop);

  m_textEditLogs->setReadOnly(true);
  m_textEditLogs->setText("plop");

  layoutLogs->addWidget(m_textEditLogs);

  QHBoxLayout * layoutButtonsLog = new QHBoxLayout;
  QPushButton * buttonSelectAll = new QPushButton("Tout sélectionner", m_pageLogs);
  QPushButton * buttonSaveAs = new QPushButton("Sauvegarder les logs", m_pageLogs);

  QObject::connect(buttonSelectAll, SIGNAL(clicked(bool)), m_textEditLogs, SLOT(selectAll()));
  QObject::connect(buttonSaveAs, SIGNAL(clicked(bool)), this, SLOT(_saveLogs()));

  layoutButtonsLog->addWidget(buttonSelectAll);
  layoutButtonsLog->addWidget(buttonSaveAs);

  layoutLogs->addLayout(layoutButtonsLog);

  /*QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(upLabel()));
        timer->start(1000);*/
}

//sauvegarder
void FenAdmin::_setupSauvegarder()
{
  QVBoxLayout * layoutSauvegarder = new QVBoxLayout(m_pageSauvegarder);
  layoutSauvegarder->setAlignment(Qt::AlignTop);

  QPushButton * boutonSauvegarder = new QPushButton("Sauvegarder", m_pageSauvegarder);
  layoutSauvegarder->addWidget(boutonSauvegarder);

  QPushButton * boutonCharger = new QPushButton("Charger configuration", m_pageSauvegarder);
  layoutSauvegarder->addWidget(boutonCharger);
}
