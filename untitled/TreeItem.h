//
// Created by movleaxedx on 31.07.19.
//

#pragma once
#include <QObject>

class TreeItem : public QObject
{
  Q_OBJECT;
  Q_PROPERTY(QString data READ getData WRITE setData NOTIFY onDataChanged);
  Q_PROPERTY(bool isOpened MEMBER m_isOpened NOTIFY onOpenStatusChange);
  Q_PROPERTY(QList<QObject*> children READ getChildrenAsQObject NOTIFY onChildrenChanged);

public:
  TreeItem() = default;
  explicit TreeItem(QString data, TreeItem* parent = nullptr);
  TreeItem(const TreeItem&);
  TreeItem&operator=(const TreeItem&);
  ~TreeItem() override;

  QString& getData();
  void setData(const QString& data);

  QList<QObject*> getChildrenAsQObject();
  Q_INVOKABLE QList<TreeItem*> getChildren();
  Q_INVOKABLE void appendChild(const QString&);

  signals:
    void onChildrenChanged(const QList<TreeItem*>&);
    void onDataChanged(const QString&);
    void onOpenStatusChange(bool);

private:
  QString m_data;
  QList<TreeItem*> m_children;
  TreeItem* p_parent;
  bool m_isOpened;
};

Q_DECLARE_METATYPE(TreeItem);
