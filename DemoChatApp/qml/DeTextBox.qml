import QtQuick

Rectangle {
    border.color: "blue"
    border.width: 2
    radius: 5

    property string text: chat.text

    TextInput {
        id: chat
        anchors.centerIn: parent
        text: "Input"
        onAccepted: {
            console.log("Input received:", text);
        }
    }
}
