import QtQuick 2.15
import QtQuick.Controls 2.15 as Controls
import common

Item {
    id: root
    width: parent.width
    height: parent.height
    anchors.centerIn: parent

    property string mensaje: ""
    property ExcursionExecutable controller: ExcursionExecutable {}

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
        anchors.horizontalCenter: parent.horizontalCenter
    }

    ExcursionList {
        id: excursionList
        width: parent.width
        excursionModel: dateSelector.excursionModelFiltered
        anchors.top: dateSelector.bottom
        anchors.topMargin: 20
    }

    Controls.Button {
        id: send
        width: 250
        height: 40
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: excursionList.bottom
        anchors.topMargin: 20
        contentItem: Text {
            font.bold: true
            font.pixelSize: Style.fontSizeM
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: "Add Excursion"
            color: send.hovered ? Style.mainColor : "#FFF"
            Behavior on color {
                ColorAnimation {
                    duration: 300
                }
            }
        }
        background: Rectangle {
            color: send.hovered ? "#99FFFFFF" : Style.mainColor
            radius: Style.resize(25)
            Behavior on color {
                ColorAnimation {
                    duration: 300
                }
            }
        }
    }
}
