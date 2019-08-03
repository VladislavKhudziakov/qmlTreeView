import QtQuick 2.12


Component {
    id: itemView
    
    Row {

        Text {
            width: 20
            height: 20
            text: modelData.isOpened ? "+" : "-"

            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked: {
                    modelData.isOpened = !modelData.isOpened;
                }
            }
        }

        Column {
            Text {
                text: modelData.data ? modelData.data : "empty"
            }

            Loader {
                source: modelData.isOpened ? "TreeItemList.qml" : "Empty.qml"
            }
        }

        
    }
}

