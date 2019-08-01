//
// Created by movleaxedx on 31.07.19.
//

#include "TreeModel.h"
#include "TreeItem.h"

#include <utility>

TreeModel::TreeModel(QVector <TreeItem*>  items, QObject *parent) : QAbstractListModel(parent), m_items(std::move(items))
{

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
