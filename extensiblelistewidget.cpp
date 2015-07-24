#include "extensiblelistewidget.h"

ExtensibleListeWidget::ExtensibleListeWidget(QString const& placeholder, QStringList items, QWidget *parent) :
  QWidget(parent),
  m_items(items),

  m_combobox(new QComboBox(this)),
  m_lineedit(new QLineEdit(this)),
  m_button(new QPushButton("Ajouter", this))
{
  m_lineedit->setPlaceholderText(placeholder);
  _loadCombobox();

  QObject::connect(m_button, SIGNAL(clicked(bool)), this, SLOT(_addItemInLineEdit()));

  QGridLayout * layout = new QGridLayout(this);
  layout->addWidget(m_combobox,0,0,1,2);
  layout->addWidget(m_lineedit,1,0);
  layout->addWidget(m_button,1,1);
}

QString ExtensibleListeWidget::getItem() const
{
  return m_combobox->currentText();
}

void ExtensibleListeWidget::_addItemInLineEdit()
{
  m_items.append(m_lineedit->text());
  m_lineedit->clear();
  _loadCombobox();
  m_combobox->setCurrentIndex(m_items.length() - 1);
}

void ExtensibleListeWidget::_loadCombobox()
{
  m_combobox->clear();
  m_combobox->addItems(m_items);
}
