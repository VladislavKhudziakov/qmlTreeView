//
// Created by movleaxedx on 31.07.19.
//

#include "TreeItem.h"

TreeItem::TreeItem(QString data, TreeItem *parent)
  : QObject(parent), m_data(std::move(data)) {}



TreeItem::TreeItem(const TreeItem& src)
  : QObject(src.parent()), m_data(src.m_data) {}



TreeItem::TreeItem(TreeItem && src) noexcept
  : QObject(src.parent()), m_data(std::move(src.m_data)) {}



TreeItem& TreeItem::operator=(const TreeItem& src)
{
  m_data = src.m_data;
  return *this;
}



TreeItem& TreeItem::operator=(TreeItem&& src) noexcept
{
  m_data = std::move(src.m_data);
  return *this;
}



QString& TreeItem::getData()
{
  return m_data;
}
