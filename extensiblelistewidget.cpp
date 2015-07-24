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
}

void ExtensibleListeWidget::_addItemInLineEdit()
{
  m_items.append(m_lineedit->text());
  m_lineedit->clear();
}

void ExtensibleListeWidget::_loadCombobox()
{
  m_combobox->clear();
  for(auto it = m_items.cbegin(); it != m_items.cend(); ++it)
    m_combobox->addItems(m_items);
}
