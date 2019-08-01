//
// Created by movleaxedx on 31.07.19.
//

#include "TreeModel.h"
#include "TreeItem.h"


#include <utility>
#include <QDebug>

TreeModel::TreeModel(QVector <TreeItem*>  items, QObject *parent) : QAbstractListModel(parent), m_items(std::move(items))
{

}



TreeModel::~TreeModel()
{
  qDeleteAll(m_items);
}



QVariant TreeModel::data(const QModelIndex &index, int role) const
{
  if (index.isValid()) {
    if (role == ItemRole) {
      QVariant variant;
      variant.setValue(*m_items.at(index.row()));
      return variant;
    }
  }

  return QVariant();
}



int TreeModel::rowCount(const QModelIndex &parent) const
{
  return m_items.count();
}



QHash<int,QByteArray> TreeModel::roleNames() const
{
  auto roles = QAbstractListModel::roleNames();
  roles[ItemRole] = "item";

  return roles;
}



void TreeModel::append(const TreeItem &value)
{
  beginInsertColumns(QModelIndex(), 0, 0);
  m_items.push_back(new TreeItem(value));
  endInsertRows();

  auto index = createIndex(0, 0);
  emit dataChanged(index, index);
}




void TreeModel::append(const QVariant &value)
{
  beginInsertColumns(QModelIndex(), 0, 0);
  m_items.push_back(new TreeItem(value.toString()));
  endInsertRows();

  auto index = createIndex(0, 0);
  emit dataChanged(index, index);
}



TreeItem *TreeModel::getTreeItem(int idx) {
  if (idx < 0 || idx >= m_items.count()) {
    return nullptr;
  }

  return m_items.at(idx);
}
