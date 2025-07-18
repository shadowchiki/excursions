import QtQuck 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 300
    height: 200
    title: "Ejemplo QML"

    property string mensaje: "Hola, QML"

    Column {
        anchors.centerIn: parent
        spacing: 10

        Text {
            id: textoSaludo
            text: mensaje
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
        }

        Button {
            text: "Cambiar mensaje"
            onClicked: mensaje = "¡Mensaje actualizado!"
        }
    }
}
