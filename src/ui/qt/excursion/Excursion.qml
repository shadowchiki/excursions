import QtQuick 2.15
import QtQuick.Controls 2.15

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

    Rectangle {
        id: startDateBg
        anchors.top: textoSaludo.bottom
        anchors.left: parent.left
        width: parent.width / 3
        height: 40
        Flickable {
            id: startDateFlick
            anchors.fill: parent
            flickableDirection: Flickable.VerticalFlick

            ScrollBar.vertical: ScrollBar {
                id: hbar
                active: true
            }
            TextEdit {
                id: startDateTxtEdit
                anchors.fill: parent
                wrapMode: TextEdit.Wrap
            }
        }
    }

    Button {
        id: send
        text: "Filter Excursions"
        width: 60
        height: 40
        anchors.top: textoSaludo.bottom
        anchors.left: startDateBg.right
        anchors.right: endDateBg.left
        onClicked: {
            excursionList.excursionModel = root.controller.findExcursions(startDateTxtEdit.text, endDateTxtEdit.text);
        }
    }

    Rectangle {
        id: endDateBg
        anchors.top: textoSaludo.bottom
        anchors.right: parent.right
        width: parent.width / 3
        height: 40

        Flickable {
            id: endDateFlick
            anchors.fill: parent
            flickableDirection: Flickable.VerticalFlick

            ScrollBar.vertical: ScrollBar {
                id: endDatehbar
                active: true
            }
            TextEdit {
                id: endDateTxtEdit
                anchors.fill: parent
                wrapMode: TextEdit.Wrap
            }
        }
    }

    ExcursionList {
        id: excursionList
        width: parent.width
        excursionModel: root.controller.findExcursions("", "2025-01-16")
        anchors.top: startDateBg.bottom
        anchors.bottom: parent.bottom
    }
}
