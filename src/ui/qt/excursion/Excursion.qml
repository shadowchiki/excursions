import QtQuick 2.15
import common as Common

Item {
    id: root
    width: parent.width
    height: parent.height
    anchors.centerIn: parent

    property string mensaje: ""
    property ExcursionExecutable controller: ExcursionExecutable {}

    Common.Style {
        id: styleId
    }

    Shadow {}

    Rectangle {
        anchors.fill: parent
        border.color: styleId.grey
    }

    Text {
        id: textoSaludo
        text: root.mensaje
        font.pixelSize: 20
        horizontalAlignment: Text.Top
    }

    DateSelector {
        id: dateSelector
        controller: root.controller
        anchors.top: textoSaludo.bottom
    }

    ExcursionList {
        id: excursionList
        width: parent.width
        excursionModel: dateSelector.excursionModelFiltered
        anchors.top: dateSelector.bottom
        anchors.bottom: parent.bottom
    }
}
