import QtQuick 2.15
import QtQuick.Controls 2.15
import common

Row {
    id: root
    spacing: Style.resize(15)

    property ExcursionExecutable controller

    property var excursionModelFiltered

    Component.onCompleted: {
        root.excursionModelFiltered = root.controller.findExcursions(startDate.textFromEditText, endDate.textFromEditText);
    }

    TextBlock {
        id: startDate
        labelText: "Start Date"
    }

    Button {
        id: send
        width: 250
        height: 40
        anchors.verticalCenter: parent.verticalCenter
        contentItem: Text {
            font.bold: true
            font.pixelSize: Style.fontSizeM
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: "Filter Excursions"
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
        onClicked: {
            root.excursionModelFiltered = root.controller.findExcursions(startDate.textFromEditText, endDate.textFromEditText);
        }
    }

    TextBlock {
        id: endDate
        labelText: "EndDate Date"
    }
}
