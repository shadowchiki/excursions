import QtQuick.Controls 2.15
import QtQuick 2.15
import common

ApplicationWindow {
    id: root
    visible: true
    width: Style.screenWidth
    height: Style.screenHeight
    title: "Excursions"

    background: Rectangle {
        anchors.fill: parent
        color: "#D3D3D3"
    }

    Header {
        id: mainHeader
        width: parent.width - mainMenu.width
        height: 65
        anchors {
            right: parent.right
            top: parent.top
        }
    }

    MainMenu {
        id: mainMenu
        height: parent.height
        anchors {
            top: parent.top
            left: parent.left
        }
    }

    Body {
        id: body
        anchors {
            top: mainHeader.bottom
            right: parent.right
            bottom: parent.bottom
            left: mainMenu.right
            margins: 16
        }
    }

    Connections {
        target: mainMenu
        function onMainContentChanged(text) {
            mainHeader.actualMenu = text;
            body.currentBody = text;
        }
    }
}
