//
// Created by movleaxedx on 31.07.19.
//

#include <QObject>
#pragma once

class Test : public QObject
{
  Q_OBJECT;

public:
  explicit Test(QObject* parent = nullptr);
};
