import QtQuick 2.15

Item {
    id: root

    property string name
    property string direction
    property string job
    property string userImagePath

    Style {
        id: styleId
    }

    Rectangle {
        anchors.fill: parent
        color: styleId.fontContrastColor
    }

    Rectangle {
        id: userImageRectangle
        width: 74
        height: 74
        anchors.horizontalCenter: parent.horizontalCenter
        radius: 50

        Image {
            id: userImage
            source: root.userImagePath
            anchors.fill: parent
        }
    }

    Column {
        id: column
        anchors.top: userImageRectangle.bottom
        anchors.left: parent.left
        anchors.topMargin: styleId.resize(35)
        anchors.leftMargin: styleId.resize(20)
        spacing: styleId.resize(15)

        Row {
            spacing: styleId.resize(5)

            Add {
                id: image
                anchors.verticalCenter: parent.verticalCenter
                color: styleId.mainColor
            }
            Text {
                id: text
                text: root.name
                wrapMode: Text.Wrap
                anchors.verticalCenter: parent.verticalCenter
                color: styleId.mainColor
                font.pixelSize: styleId.fontSizeS
            }
        }

        Row {
            spacing: styleId.resize(5)

            Add {
                id: image2
                anchors.verticalCenter: parent.verticalCenter
                color: styleId.mainColor
            }
            Text {
                id: text2
                text: root.direction
                wrapMode: Text.Wrap
                anchors.verticalCenter: parent.verticalCenter
                color: styleId.mainColor
                font.pixelSize: styleId.fontSizeS
            }
        }
        Row {
            spacing: styleId.resize(5)

            Add {
                id: image3
                anchors.verticalCenter: parent.verticalCenter
                color: styleId.mainColor
            }
            Text {
                id: text3
                text: root.job
                wrapMode: Text.Wrap
                anchors.verticalCenter: parent.verticalCenter
                color: styleId.mainColor
                font.pixelSize: styleId.fontSizeS
            }
        }
    }
}
