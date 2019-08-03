//
// Created by movleaxedx on 31.07.19.
//

#include "TreeItem.h"


TreeItem::TreeItem(): QObject(nullptr), m_data(), p_parent(), m_isOpened(false)
{

}



TreeItem::TreeItem(QString data, TreeItem *parent)
  : QObject(parent), m_data(std::move(data)), p_parent(parent), m_isOpened(false)
{

}



TreeItem::TreeItem(const TreeItem& src)
  : QObject(src.parent()), m_data(src.m_data), p_parent(src.p_parent), m_isOpened(false)
{

}



TreeItem& TreeItem::operator=(const TreeItem& src)
{
  m_data = src.m_data;
  m_children = src.m_children;
  p_parent = src.p_parent;
  return *this;
}



TreeItem::~TreeItem()
{
  qDeleteAll(m_children);
}



QString& TreeItem::getData()
{
  return m_data;
}



void TreeItem::setData(const QString &data)
{
  m_data = data;
  emit onDataChanged(m_data);
}



QList<QObject*> TreeItem::getChildrenAsQObject()
{
  QList<QObject*> list;

  for (auto item : m_children) {
    list.push_back(item);
  }
  return list;
}



QList<TreeItem*> TreeItem::getChildren()
{
  return m_children;
}



void TreeItem::appendChild(const QString & data)
{
  m_children.push_back(new TreeItem(data, this));
  emit onChildrenChanged(m_children);
}



void TreeItem::appendChild(TreeItem * child)
{
  m_children.append(child);
}
