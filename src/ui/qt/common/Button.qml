import QtQuick.Controls 2.15 as Control
import QtQuick 2.15

Control.Button {
    id: root
    width: 250
    height: 40

    property string backgroundColor: "#fff"
    property string title: "Button"

    anchors.verticalCenter: parent.verticalCenter
    contentItem: Text {
        font.bold: true
        font.pixelSize: Style.fontSizeM
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: root.title
        color: root.hovered ? Style.mainColor : "#FFF"
        Behavior on color {
            ColorAnimation {
                duration: 300
            }
        }
    }
    background: Rectangle {
        color: root.hovered ? "#99FFFFFF" : Style.mainColor
        radius: Style.resize(25)
        Behavior on color {
            ColorAnimation {
                duration: 300
            }
        }
    }
}
