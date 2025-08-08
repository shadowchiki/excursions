import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: root

    property var excursionModel

    ListView {
        id: listView
        height: 500
        anchors.fill: parent

        model: root.excursionModel
        highlightFollowsCurrentItem: true

        delegate: ItemDelegate {
            width: parent.width
            height: 65 - listView.spacing
            background: null
            contentItem: Row {
                anchors.fill: parent
                anchors.leftMargin: 20
                spacing: 5
                Text {
                    id: text
                    text: modelData
                    wrapMode: Text.Wrap
                    anchors.verticalCenter: parent.verticalCenter
                    color: "blue"
                    font.pixelSize: 16
                }
                Row {
                  anchors.verticalCenter: parent.verticalCenter
                    Rectangle {
                        width: 25
                        height: 25
                        MouseArea {
                          anchors.fill:parent
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
