//
// Created by movleaxedx on 31.07.19.
//

#pragma once


#include <QObject>
#include <QVector>


class TreeItem;

class TreeModel : public QObject
{
  Q_OBJECT;
  Q_PROPERTY(QList<QObject*> tree READ getTreeAsQObject NOTIFY treeChanged)

public:

  explicit TreeModel(QList<TreeItem*> items = QList<TreeItem*>(), QObject* parent = nullptr);
  ~TreeModel() final;

  QList<TreeItem*>& getTree();
  QList<QObject*> getTreeAsQObject() const;

  Q_INVOKABLE void append(const QString& value);

  signals:
    void treeChanged();

private:
  QList<TreeItem*> m_tree;
};
