import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15
import QtQuick 2.15
import excursion 1.0
import common 1.0 as Common

ApplicationWindow {
    id: main_window
    visible: true
    width: 900
    height: 700
    title: "Excursions"

    function testing() {
    }

    TabBar {
        id: tabBar
        currentIndex: stack.currentIndex
        TabButton {
            text: "Tab 1"
        }
        TabButton {
            text: "Tab 2"
        }
    }

    StackLayout {
        id: stack
        Layout.fillWidth: true
        Layout.fillHeight: true
        currentIndex: tabBar.currentIndex
        anchors.fill: parent

        ExcursionExecutable {
            id: excursion
            title: "Tittle From QML"

            Row {
                Label {
                    text: excursion.title
                    font.pixelSize: 20
                    horizontalAlignment: Text.Center
                }

                Common.Button {
                    title: "Testing live change"
                    onClicked: {
                        excursion.title = "Changind tittle from a button";
                        main_window.testing();
                    }
                }
                Common.Button {
                    title: "Button2 with other text"
                    onClicked: {
                        console.log("Texting loggin in console");
                    }
                }
            }
        }

        Label {
            text: "Configuración"
            font.pixelSize: 20
            horizontalAlignment: Text.Center
        }
    }
}
