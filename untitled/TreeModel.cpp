//
// Created by movleaxedx on 31.07.19.
//

#include "TreeModel.h"
#include "TreeItem.h"


#include <utility>
#include <QDebug>


const int number = 100;

TreeItem *createTreeItem(){
  auto res = new TreeItem(QString::number(qrand() % number));
  while(qrand() % 2)
    res->appendChild(createTreeItem());
  return res;
}

TreeModel::TreeModel(QList<TreeItem*>  items, QObject *parent)
  : QObject(parent), m_tree(std::move(items))
{
  m_tree.append(createTreeItem());
  m_tree.append(createTreeItem());
  m_tree.append(createTreeItem());
  m_tree.append(createTreeItem());
  m_tree.append(new TreeItem(QString::number(2)));
  m_tree.append(new TreeItem(QString::number(3)));

  connect(this, &TreeModel::treeChanged, [&]() {
    qDebug() << "changed";
  });
}



TreeModel::~TreeModel()
{
  qDeleteAll(m_tree);
}



QList<TreeItem*>& TreeModel::getTree()
{
  return m_tree;
}



QList<QObject*> TreeModel::getTreeAsQObject() const
{
  QList<QObject*> objects;
  std::copy(m_tree.begin(), m_tree.end(), std::back_inserter(objects));
  return objects;
}



void TreeModel::append(const QString &value)
{
  m_tree.append(new TreeItem(value));
  emit treeChanged();
}
