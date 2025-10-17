import QtQuick

Rectangle {
    color: "gray"
    border.width: 2
    radius: 5

    Text {
        id: message
        anchors.centerIn: parent
        text: "Add new contact"
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            listModel.addItem("Grape", 330);
        }
    }
}
