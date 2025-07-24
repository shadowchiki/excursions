import QtQuick.Controls 2.15 as Control
import QtQuick 2.15

Control.Button {
    id: button
    width: 225
    height: 60

    property string backgroundColor: "#fff"
    property string title: "Button"

    contentItem: Text {
        text: button.title
        font.pixelSize: button.font.pixelSize
        font.family: button.font.family
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    background: Rectangle {
        color: button.backgroundColor
        border.color: button.backgroundColor
        border.width: 1
        radius: 50
    }
}
