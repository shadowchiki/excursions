import QtQuick 2.15
import excursion 1.0

Item {
    id: root

    property string currentBody: "Excursions"
    property var components: {
        "Excursions": excursion,
        "Federations": federation
    }

    onCurrentBodyChanged: {
        loader.sourceComponent = components[currentBody];
    }

    Component {
        id: excursion
        Excursion {
            mensaje: "Excursion Management"
        }
    }

    Component {
        id: federation
        Excursion {
            mensaje: "Federation Management"
        }
    }

    Loader {
        id: loader
        anchors.fill: parent
        sourceComponent: root.components[root.currentBody]
    }
}
