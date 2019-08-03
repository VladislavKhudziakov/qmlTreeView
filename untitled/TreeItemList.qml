import QtQuick 2.12
import QtQuick.Controls 1.4

Column {
  id: root
  
  Repeater {
    model: modelData.children
    delegate: TreeItemView { }
  }  
}