import QtQuick
import "qml"

Window {
    width: 640
    height: 480
    visible: true
    title: "ChatBox"

    DeButton {
        id: buttonAdd
        width: parent.width
        height: 30
        anchors.top: parent.top
    }

    DeList {
        id: nameList
        anchors.left: parent.left
        anchors.top: buttonAdd.bottom
        width: parent.width / 2
        height: parent.height
        border.width: 2
        radius: 5
    }

    DeBox {
        id: chatBox
        anchors.right: parent.right
        anchors.top: buttonAdd.bottom
        width: parent.width / 2
        height: parent.height
        color: "#53A66B"
        border.width: 2
        radius: 5
    }
}
