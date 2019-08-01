#include <QDebug>
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QQuickWindow>
#include <QQmlContext>

#include "TestModel.h"
#include "TreeItem.h"

int main(int argc, char** argv) {
  QGuiApplication application(argc, argv);

  qmlRegisterType<TreeItem>();
  QQmlApplicationEngine engine;

  TestModel model;
  engine.rootContext()->setContextProperty("TestModel", &model);

  engine.load(QUrl("../main.qml"));

  auto window = qobject_cast<QQuickWindow*>(engine.rootObjects().first());

  if(window == nullptr) {
    qDebug() << "window is not created";
    return -1;
  }

  window->show();

  return QGuiApplication::exec();
}