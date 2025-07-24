import QtQuick 2.15

Column {
    anchors.centerIn: parent

    property string mensaje: ""

    Text {
        id: textoSaludo
        text: "Excursion Management"
        font.pixelSize: 20
        horizontalAlignment: Text.Top
    }

}
