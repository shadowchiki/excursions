import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: root

    property var excursionModel

    ListView {
        id: listView
        width: parent.width / 2
        height: parent.height
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10

        model: root.excursionModel

        delegate: ItemDelegate {
            width: parent.width
            height: 65 - listView.spacing
            background: Rectangle {
              Shadow{
                z: -1
              }
              border {
                color: "black"
                width: 2
              }
              radius: 15
              color: "white"
            }
            contentItem: Item {
                anchors.fill: parent
                anchors.leftMargin: 20
                anchors.rightMargin: 20
                Text {
                    id: text
                    text: modelData
                    wrapMode: Text.Wrap
                    anchors.verticalCenter: parent.verticalCenter
                    color: "blue"
                    font.pixelSize: 16
                }
                Row {
                  spacing: 6
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    Rectangle {
                        width: 25
                        height: 25
                        color: "Red"
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                console.log("Editing ", modelData);
                            }
                        }
                    }
                    Rectangle {
                        width: 25
                        height: 25
                        color: "Green"
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                console.log("Editing ", modelData);
                            }
                        }
                    }
                    Rectangle {
                        width: 25
                        height: 25
                        color: "blue"
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                console.log("Editing ", modelData);
                            }
                        }
                    }
                }
            }
            onClicked: {}
        }
    }
}
