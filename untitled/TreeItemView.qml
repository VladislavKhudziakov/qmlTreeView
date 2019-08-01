import QtQuick 2.12

Row {
    property var currItem: TreeModel.getTreeItem(index)

    Text {
        width: 20
        height: 20
        text: currItem.isOpened ? "+" : "-"

        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            onClicked: {
                currItem.isOpened = !currItem.isOpened;
            }
        }
    }

    Text {
        text: currItem.data

        Column {
            Repeater {
                model: currItem.children
                
                anchors.fill: parent
                
                delegate: Text {
                    text: modelData.data
                }
            }
        }

        Component.onCompleted: {
            currItem.appendChild("1-1");
            currItem.appendChild("2-2");
            currItem.appendChild("3-3");
            currItem.appendChild("4-4");
        }
    }
}