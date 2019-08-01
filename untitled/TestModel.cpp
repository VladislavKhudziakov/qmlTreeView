//
// Created by movleaxedx on 31.07.19.
//

#include "TestModel.h"
#include <QDebug>

TestModel::TestModel(QObject *parent) : QAbstractListModel(parent)
{
  connect(this, &QAbstractListModel::dataChanged,
      [&](const QModelIndex &topLeft,
          const QModelIndex &bottomRight,
          const QVector<int> &roles = QVector<int>()) {
          qDebug() << topLeft.row();
      });
}



QVariant TestModel::data(const QModelIndex &index, int role) const
{
  if (!index.isValid()) {
    return QVariant();
  }

  if (role == TextRole) {
    return QVariant(m_data.at(index.row()));
  }

  return QVariant();
}



int TestModel::rowCount(const QModelIndex &parent) const
{
  return m_data.count();
}



QHash<int,QByteArray> TestModel::roleNames() const
{
  auto roles = QAbstractListModel::roleNames();
  roles[TextRole] = "text";

  return roles;
}


void TestModel::append(const QVariant &value)
{
  beginInsertRows(QModelIndex(), 0, 0);
  m_data.append(value.toString());
  endInsertRows();
  auto index = createIndex(0, 0, static_cast<void *>(nullptr));
  emit dataChanged(index, index);
}
bool TestModel::setData(const QModelIndex &index, const QVariant &value,
                        int role)
{
  if (!index.isValid()) {
    return false;
  }

  if (role == TextRole) {
    m_data[index.row()] = value.toString();
  }

  emit dataChanged(index, index);
  return true;
}
