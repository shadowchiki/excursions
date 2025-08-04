pragma ComponentBehavior: Bound
import QtQuick 2.15
import QtQuick.Controls 2.15

ItemDelegate {
    id: buttonMenu
    property string title: "Default"
    property url icon: ""
    property int padding: 5
    property string background: "#00000000"
    property string textColor: "#000"

    width: image.width + text.width + 2 * padding

    Rectangle {
        color: buttonMenu.background
        anchors.fill: parent
    }

    Row {
        anchors.fill: parent
        spacing: 5

        Add {
            id: image
            anchors.verticalCenter: parent.verticalCenter
        }

        Text {
            id: text
            text: buttonMenu.title
            wrapMode: Text.Wrap
            anchors.verticalCenter: parent.verticalCenter
            color: buttonMenu.textColor
        }
    }
}
