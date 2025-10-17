import QtQuick

Rectangle {
    id: box

    Rectangle {
        id: pingButton
        anchors.top: parent.top
        color: "gray"
        border.width: 2
        radius: 5

        width: parent.width / 2
        height: 30

        Text {
            anchors.centerIn: parent
            text: applicationData.message
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                applicationData.callSendMessage(numberID.text)
            }
        }
    }

    DeTextBox {
        id: numberID
        anchors.left: pingButton.right
        width: parent.width / 2
        height: 30
    }

    DeTextBox {
        anchors.top: pingButton.bottom
        width: parent.width
        height: 30
    }
}
