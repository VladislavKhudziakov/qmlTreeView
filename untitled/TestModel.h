//
// Created by movleaxedx on 31.07.19.
//

#pragma once

#include "TreeItem.h"
#include <QAbstractListModel>

class TestModel : public QAbstractListModel {
  Q_OBJECT;

public:
  explicit TestModel(QObject* parent = nullptr);
  ~TestModel() final = default;

  enum Roles {
    TextRole = Qt::UserRole + 1
  };

  Q_INVOKABLE [[nodiscard]] QVariant data(const QModelIndex &index, int role) const override;
  Q_INVOKABLE [[nodiscard]] int rowCount(const QModelIndex &parent) const override;
  Q_INVOKABLE [[nodiscard]] QHash<int,QByteArray> roleNames() const override;

  Q_INVOKABLE void append(const QVariant& value);

  Q_INVOKABLE bool setData(const QModelIndex &index, const QVariant &value, int role) override;

private:
  QStringList m_data;
};
