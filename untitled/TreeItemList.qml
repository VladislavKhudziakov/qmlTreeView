import QtQuick 2.12
import QtQuick.Controls 1.4

Column {
  id: root
  property var model: null
  Repeater {
    model: 3
    delegate: Text {
      text: index
    }
  }

  
  Component.onCompleted: {
    console.log(root.model);
    
  }
  
}