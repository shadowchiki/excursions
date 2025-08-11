import QtQuick 2.15
import QtQuick.Controls 2.15
import common

Item {
    id: root
    width: column.width
    height: column.height

    property string labelText
    property string textFromEditText

    TextMetrics {
        id: textMetrics
        text: root.labelText + "\nformat: YYYY-MM-DD"
    }

    Column {
        id: column
        spacing: 10

        Label {
            id: label
            width: textMetrics.width
            height: label.implicitHeight
            text: root.labelText + "\nformat: YYYY-MM-DD"
            font.pixelSize: Style.fontSizeM
            verticalAlignment: Text.AlignVCenter
            color: Style.mainColor
        }

        TextField {
            id: editText
            width: textMetrics.width
            height: label.implicitHeight
            wrapMode: TextEdit.Wrap
            background: Rectangle{
              border.color: Style.mainColor 
              color: Style.grey 
            }
            color: Style.mainColor
            onFocusChanged: {
                if (!editText.focus)
                    root.textFromEditText = editText.text;
            }
        }
    }
}
