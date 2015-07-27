#ifndef FENPRINCIPALE
#define FENPRINCIPALE

#include <QApplication>
#include <QFormLayout>
#include <QCheckBox>
#include <QRadioButton>
#include <QGroupBox>
#include <QComboBox>
#include <QLabel>
#include <QProgressBar>
#include <QTabWidget>
#include <QSpinBox>
#include <QtWidgets>
#include<QMenuBar>
#include<QMainWindow>
#include<QStatusBar>

class FenPrincipale : public QMainWindow
{
    Q_OBJECT

  public:
    FenPrincipale();

  signals:

  public slots:
    void addLogLine(QString const& line);

  private slots:
    //Patient
    void _patientNext();

    //Examen
    void _examenPrevious();
    void _examenNext();

    //Medecin
    void _medecinPrevious();
    void _medecinNext();

    //sauvegarder
    void _save() const;
    void _load();

  private:
    QWidget * m_mainWidget;
    QGridLayout * m_mainLayout;

    //réglages patient
    void _setupReglagesPatient();
    QWidget * m_pageReglagesPatient;

    //réglages examen
    void _setupReglagesExamen();
    QWidget * m_pageReglagesExamen;

    //réglages médecins
    void _setupReglagesMedecin();
    QWidget * m_pageReglagesMedecin;

    //sauvegarder
    void _setupSauvegarder();
    QWidget * m_pageSauvegarder;
};

#endif
