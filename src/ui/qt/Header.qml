import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Effects
import common

Item {
    id: root

    property string actualMenu

    RectangularShadow {
        anchors.fill: background
        offset.y: -5
        blur: 30
        spread: 5
        color: Qt.darker(background.color, 1.6)
    }

    Rectangle {
        id: background
        anchors.fill: parent
        color: Style.grey
    }

    Text {
        id: actualMenuTxt
        text: qsTr(root.actualMenu)
        font {
            pixelSize: Style.fontSizeL
        }
        anchors {
            left: parent.left
            verticalCenter: parent.verticalCenter
            leftMargin: Style.resize(50)
        }
    }

    Rectangle {
        color: "transparent"
        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
            left: actualMenuTxt.right
        }
        Row {
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            padding: Style.resize(30)
            spacing: Style.resize(15)

            Text {
                text: qsTr("Settings")
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        dropDownMenuLoader.active = !dropDownMenuLoader.active;
                    }
                }
            }

            Text {
                text: qsTr("ShutDown")
            }
        }
    }

    Loader {
        id: dropDownMenuLoader
        width: Style.resize(228)
        height: Style.resize(127)
        anchors.top: parent.top
        anchors.topMargin: ((height / 2) + Style.resize(10))
        anchors.right: parent.right
        anchors.rightMargin: Style.resize(45)
        active: false
        opacity: active ? 1.0 : 0.0
        visible: (opacity > 0.0)
        Behavior on opacity {
            NumberAnimation {
                duration: 200
            }
        }
        sourceComponent: Frame {
            anchors.fill: parent
            z: 10000
            background: Image {
                width: Style.resize(sourceSize.width)
                height: Style.resize(sourceSize.height)
                source: Style.gfx("dropdown")
            }

            contentItem: Column {
                anchors.top: parent.top
                anchors.topMargin: Style.resize(20)
                anchors.left: parent.left
                anchors.leftMargin: Style.resize(30)
                spacing: Style.resize(8)
                Label {
                    text: qsTr("Select theme")
                }
                Repeater {
                    model: ["Green", "Orange"]
                    delegate: RadioButton {
                        width: Style.resize(100)
                        height: Style.resize(26)
                        text: qsTr("%1").arg(modelData)
                        checked: (Style.theme === text.toLowerCase())
                        onClicked: {
                            if (modelData === "Green")
                            // Style.setGreenTheme();
                            {} else
                            // Style.setOrangeTheme();
                            {}
                            dropDownMenuLoader.active = false;
                        }
                    }
                }
            }
        }
    }
}
