//
// Created by movleaxedx on 31.07.19.
//

#pragma once
#include <QObject>

class TreeItem : public QObject
{
  Q_OBJECT;
  Q_PROPERTY(QString data READ getData NOTIFY onDataChanged);
//  Q_PROPERTY(QList<TreeItem*> children READ getChildren WRITE setChild NOTIFY onChildrenChanged);

public:
  TreeItem() = default;
  TreeItem(QString data, TreeItem* parent);
  TreeItem(const TreeItem&);
  TreeItem(TreeItem&&) noexcept;
  TreeItem&operator=(const TreeItem&);
  TreeItem&operator=(TreeItem&&) noexcept;

  //todo remake when will contain pointers
  ~TreeItem() override = default;

  QString& getData();

  signals:
    void onDataChanged();

private:
  QString m_data;
};

Q_DECLARE_METATYPE(TreeItem);
