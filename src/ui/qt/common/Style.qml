pragma Singleton
import QtQuick 2.15

QtObject {
    id: root
    property int screenWidth: 1650
    property int screenHeight: 850

    property real scaleFactor: 1.0
    property real designAspectRatio: (root.screenWidth / root.screenHeight)

    property string theme: "green"

    property string bgColor: "#D1DBE1"
    property string mainColor: (theme === "green") ? "#00D1A9" : "#FEA601"
    property string inactiveColor: "#A8A8A8"

    property string iconPath: "/resources/"
    property string imagePath: "/resources/"
    property string meshPath: "/resources/"

    function icon(name) {
        return Qt.resolvedUrl(iconPath + name + ".svg");
    }

    function gfx(name) {
        return Qt.resolvedUrl(imagePath + name + ".png");
    }

    function resize(value) {
        return (value * root.scaleFactor);
    }

    property int fontSizeS: root.resize(14)
    property int fontSizeM: root.resize(18)
    property int fontSizeL: root.resize(24)

    property color grey: "#ECF0F2"
    property color fontContrastColor: "#FFFFFF"
    property color fontPrimaryColor: "#1E272E"
    property color fontSecondaryColor: "#AAAAAA"
}
