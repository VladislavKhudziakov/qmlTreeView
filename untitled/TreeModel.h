//
// Created by movleaxedx on 31.07.19.
//

#pragma once
#include <QAbstractListModel>

class TreeItem;


class TreeModel : public QAbstractListModel
{
  Q_OBJECT;

public:
  enum Roles {
    ItemRole = Qt::UserRole + 1
  };

  explicit TreeModel(QVector<TreeItem*>  items = QVector<TreeItem*>(), QObject* parent = nullptr);
  ~TreeModel() override;

  Q_INVOKABLE [[nodiscard]] QVariant data(const QModelIndex &index, int role) const override;
  Q_INVOKABLE [[nodiscard]] int rowCount(const QModelIndex &parent) const override;
  Q_INVOKABLE [[nodiscard]] QHash<int,QByteArray> roleNames() const override;

  Q_INVOKABLE void append(const TreeItem& value);
  Q_INVOKABLE void append(const QVariant&);
  Q_INVOKABLE TreeItem* getTreeItem(int);

private:
  QVector<TreeItem*> m_items;
};
