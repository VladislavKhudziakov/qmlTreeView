#include <QDebug>
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QQuickWindow>
#include <QQmlContext>

#include "TestModel.h"
#include "TreeModel.h"
#include "TreeItem.h"

int main(int argc, char** argv) {
  QGuiApplication application(argc, argv);

  qmlRegisterType<TreeItem>();
  QQmlApplicationEngine engine;

  TestModel test_model;
  engine.rootContext()->setContextProperty("TestModel", &test_model);

  TreeModel tree_model;
  engine.rootContext()->setContextProperty("TreeModel", &tree_model);

  engine.load(QUrl("../main.qml"));

  auto window = qobject_cast<QQuickWindow*>(engine.rootObjects().first());

  if(window == nullptr) {
    qDebug() << "window is not created";
    return -1;
  }

  window->show();

  return QGuiApplication::exec();
}