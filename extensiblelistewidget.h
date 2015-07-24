#ifndef EXTENSIBLELISTEWIDGET_H
#define EXTENSIBLELISTEWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QStringList>

#include <initializer_list>

class ExtensibleListeWidget : public QWidget
{
  Q_OBJECT
public:
  explicit ExtensibleListeWidget(QString const& placeholder, QStringList items, QWidget *parent = 0);

signals:
  void itemSelected(QString item);

private slots:
  void _addItemInLineEdit();

private:
  void _loadCombobox();

  QStringList m_items;

  QComboBox * m_combobox;
  QLineEdit * m_lineedit;
  QPushButton * m_button;
};

#endif // EXTENSIBLELISTEWIDGET_H
