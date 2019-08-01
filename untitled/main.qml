import QtQuick 2.12
import QtQuick.Controls 1.4

ApplicationWindow {
    width: 800
    height: 600

    ListView {
        anchors.fill: parent
        model: TestModel

        
        Component.onCompleted: {
            TestModel.append("1");
            TestModel.append("2");
            TestModel.append("3");
            TestModel.append("4");
        }


        delegate: Text {
            text: model.text
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    model.text = "edited"
                }
            }
        }
    }
}