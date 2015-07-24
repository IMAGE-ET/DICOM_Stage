#ifndef FENADMIN
#define FENADMIN

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
#include<QTime>
#include<QTimer>

#include <QGridLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QVBoxLayout>

class FenAdmin : public QMainWindow
{
public:
  FenAdmin();

private:
  QWidget * m_mainWidget;
  QGridLayout * m_mainLayout;

  //réglages généraux
  void _setupReglagesGeneraux();
  QWidget * m_pageReglagesGeneraux;

  //réglages DICOM
  void _setupReglagesDicom();
  QWidget * m_pageReglagesDicom;

  //logs
  void _setupLogs();
  QWidget * m_pageLogs;

  //sauvegarder
  void _setupSauvegarder();
  QWidget * m_pageSauvegarder;
};

#endif

