import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Effects

Item {
    id: root

    property string actualMenu

    Style {
        id: styleId
    }

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
        color: styleId.grey
    }

    Text {
        id: actualMenuTxt
        text: qsTr(root.actualMenu)
        font {
            pixelSize: styleId.fontSizeL
        }
        anchors {
            left: parent.left
            verticalCenter: parent.verticalCenter
            leftMargin: styleId.resize(50)
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
            padding: styleId.resize(30)
            spacing: styleId.resize(15)

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
        width: styleId.resize(228)
        height: styleId.resize(127)
        anchors.top: parent.top
        anchors.topMargin: ((height / 2) + styleId.resize(10))
        anchors.right: parent.right
        anchors.rightMargin: styleId.resize(45)
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
                width: styleId.resize(sourceSize.width)
                height: styleId.resize(sourceSize.height)
                source: styleId.gfx("dropdown")
            }

            contentItem: Column {
                anchors.top: parent.top
                anchors.topMargin: styleId.resize(20)
                anchors.left: parent.left
                anchors.leftMargin: styleId.resize(30)
                spacing: styleId.resize(8)
                Label {
                    text: qsTr("Select theme")
                }
                Repeater {
                    model: ["Green", "Orange"]
                    delegate: RadioButton {
                        width: styleId.resize(100)
                        height: styleId.resize(26)
                        text: qsTr("%1").arg(modelData)
                        checked: (styleId.theme === text.toLowerCase())
                        onClicked: {
                            if (modelData === "Green")
                            // styleId.setGreenTheme();
                            {} else
                            // styleId.setOrangeTheme();
                            {}
                            dropDownMenuLoader.active = false;
                        }
                    }
                }
            }
        }
    }
}
