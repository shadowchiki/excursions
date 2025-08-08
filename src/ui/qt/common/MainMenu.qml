pragma ComponentBehavior: Bound
import QtQuick 2.15

Item {
    id: root
    width: buttonMenuList.width

    signal mainContentChanged(string text)

    Style {
        id: styleId
    }

    Rectangle {
        id: buttonMenuListBg
        width: styleId.resize(250)
        height: styleId.resize(parent.height - (parent.height / 4))
        color: styleId.mainColor
        ButtonMenuList {
            id: buttonMenuList
            anchors.centerIn: parent
        }
    }

    Rectangle {
        id: userInfoBg
        width: buttonMenuListBg.width
        height: parent.height - buttonMenuListBg.height
        anchors.top: buttonMenuListBg.bottom
    }

    UserInfo {
        width: userInfoBg.width
        anchors.top: userInfoBg.top
        anchors.topMargin: -styleId.resize(32.5)
        name: "Alejandro"
        direction: "Calle 1"
        job: "Software Architect"
        userImagePath: styleId.icon("Account")
    }

    Connections {
        target: buttonMenuList
        function onItemClicked(item) {
            root.mainContentChanged(item.text);
        }
    }
}
