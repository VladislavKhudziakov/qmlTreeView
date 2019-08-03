import QtQuick 2.12


Component {
    id: itemView
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

            Loader {
                sourceComponent: currItem.isOpened ? viewList: emptyView
            }

            Component {
                id: viewList
                Column {
                    Repeater {
                        model: currItem.children
                        
                        anchors.fill: parent
                        
                        delegate: Text {
                            text: modelData.data
                        }
                    }
                }
            }


            Component {
                id: emptyView
                Rectangle {
                    width: 0
                    height: 0
                    color: "transparent"
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
}

