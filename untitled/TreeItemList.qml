import QtQuick 2.12
import QtQuick.Controls 1.4

Column {
  Repeater {
    model: modelData.children
   
    delegate: Text {
      text: "2"
    }
  }
}