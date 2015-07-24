#ifndef FENADMIN
#define FENADMIN

#include <QMainWindow>
#include <QMenuBar>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QGroupBox>

#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

class FenAdmin : public QMainWindow
{
  Q_OBJECT

public:
  FenAdmin();

signals:

public slots:
  void addLogLine(QString const& line);

private slots:
  //réglages généraux
  void _generalNext();

  //réglages DICOM
  void _dicomNext();

  //logs
  void _saveLogs() const;

  //sauvegarder
  void _save() const;
  void _load();

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
  QTextEdit * m_textEditLogs;

  //sauvegarder
  void _setupSauvegarder();
  QWidget * m_pageSauvegarder;
};

#endif

