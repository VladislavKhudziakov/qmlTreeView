import QtQuick 2.12
import QtQuick.Controls 1.4

ApplicationWindow {
    width: 800
    height: 600
    color: "skyblue"

    ListView {
        anchors.fill: parent
        model: TreeModel

        Component.onCompleted: {
            TreeModel.append("first");
            TreeModel.append("second");
            TreeModel.append("third");
            TreeModel.append("fourth");
        }

        delegate: TreeItemView { }
    }
}