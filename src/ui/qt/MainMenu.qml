pragma ComponentBehavior: Bound
import QtQuick 2.15
import common

Item {
    id: root
    width: buttonMenuList.width

    signal mainContentChanged(string text)

    Rectangle {
        id: buttonMenuListBg
        width: Style.resize(250)
        height: Style.resize(parent.height - (parent.height / 4))
        color: Style.mainColor
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
        anchors.topMargin: -Style.resize(32.5)
        name: "Alejandro"
        direction: "Calle 1"
        job: "Software Architect"
        userImagePath: Style.icon("Account")
    }

    Connections {
        target: buttonMenuList
        function onItemClicked(item) {
            root.mainContentChanged(item.text);
        }
    }
}
