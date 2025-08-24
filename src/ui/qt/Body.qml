import QtQuick 2.15
import excursion 1.0 as Excursion

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
        Excursion.Main {
            mensaje: "Excursion Management"
        }
    }

    Component {
        id: federation
        Excursion.Main {
            mensaje: "Federation Management"
        }
    }

    Loader {
        id: loader
        anchors.fill: parent
        sourceComponent: root.components[root.currentBody]
    }
}
