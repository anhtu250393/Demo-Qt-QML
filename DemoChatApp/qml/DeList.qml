import QtQuick

Rectangle {
    Component {
        id: contactDelegateRoot
        Item {
            width: 50 // Delegate fills the width of the ListView
            height: 40 // Fixed height for each item

            Column {
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                spacing: 2

                Text {
                    text: "<b>Name:</b> " + name // 'name' role from ListModel
                    font.pointSize: 12
                }
                Text {
                    text: "<b>number:</b> " + number // 'number' role from ListModel
                    font.pointSize: 10
                    color: "gray"
                }
            }

            Rectangle { // Separator line
                anchors.bottom: parent.bottom
                width: parent.width
                height: 1
                color: "lightgray"
            }
        }
    }

    ListView {
        anchors.fill: parent
        spacing: 5 // Spacing between items

        model: listModel
        delegate: contactDelegateRoot

        highlight: Rectangle { // Visual highlight for selected item
            color: "lightblue"
            radius: 5
        }
        focus: true // Enable keyboard navigation
    }
}
