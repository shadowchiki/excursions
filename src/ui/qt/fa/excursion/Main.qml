import QtQuick 2.15
import QtQuick.Controls 2.15 as Controls
import common

Item {
    id: root
    width: parent.width
    height: parent.height
    anchors.centerIn: parent

    property string mensaje
    property ExcursionExecutable controller: ExcursionExecutable {}

    property var components: {
        "ExcursionList": excursionListView,
        "AddExcursion": addExcursion
    }
    property string actualComponent: "ExcursionList"

    Component {
        id: excursionListView
        ExcursionListView {
            id: excursionListViewItem
            controller: root.controller
        }
    }
    Component {
        id: addExcursion
        // controller: root.controller
        AddExcursion {}
    }

    Loader {
        id: loader
        anchors.fill: parent
        sourceComponent: root.components[root.actualComponent]
    }

    Connections {
        id: connection
        target: loader.item
        function onAddExcursionLaunched() {
            connection.enabled = false;
            root.actualComponent = "AddExcursion";
        }
    }
}
