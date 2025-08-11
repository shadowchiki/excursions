import QtQuick 2.15
import QtQuick.Controls 2.15
import common

Item {
    id: root
    width: Style.resize(parent.width)
    height: Style.resize(parent.height / 2)

    signal itemClicked(var button)

    ListModel {
        id: menuModel
        ListElement {
            text: "Excursions"
        }
        ListElement {
            text: "Partners"
        }
        ListElement {
            text: "Secures"
        }
        ListElement {
            text: "Federations"
        }
        ListElement {
            text: "Inscriptions"
        }
    }

    ListView {
        id: listView
        anchors.fill: parent
        highlight: Item {
            width: parent.width
            height: Style.resize((root.height / menuModel.count) - listView.spacing)
            Rectangle {
                anchors.fill: parent
                opacity: .6
            }
            Rectangle {
                width: 4
                height: parent.height
                color: Style.fontContrastColor
            }
        }

        interactive: false
        model: menuModel
        highlightFollowsCurrentItem: true

        delegate: ItemDelegate {
            width: parent.width
            height: Style.resize((root.height / menuModel.count) - listView.spacing)
            background: null
            contentItem: Row {
                anchors.fill: parent
                anchors.leftMargin: Style.resize(20)
                spacing: 5

                Add {
                    id: image
                    anchors.verticalCenter: parent.verticalCenter
                    color: Style.fontContrastColor
                }
                Text {
                    id: text
                    text: model.text
                    wrapMode: Text.Wrap
                    anchors.verticalCenter: parent.verticalCenter
                    color: Style.fontContrastColor
                    font.pixelSize: Style.fontSizeS
                }
            }
            onClicked: {
                listView.currentIndex = index;
                root.itemClicked(model);
            }
        }
    }

    Component.onCompleted: {
        root.itemClicked(menuModel.get(listView.currentIndex));
    }
}
