import QtQuick.Effects
import QtQuick 2.15
import common

RectangularShadow {
    id: root
    anchors.fill: parent

    property Rectangle background: Rectangle {
        anchors.fill: parent
        color: Style.grey
    }

    offset.y: -5
    blur: 30
    spread: 5
    color: Qt.darker(background.color, 1.6)
}
