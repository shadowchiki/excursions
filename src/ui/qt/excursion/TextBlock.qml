import QtQuick 2.15
import QtQuick.Controls 2.15
import common as Common

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

    Common.Style {
        id: styleId
    }

    Column {
        id: column
        spacing: 10

        Label {
            id: label
            width: textMetrics.width
            height: label.implicitHeight
            text: root.labelText + "\nformat: YYYY-MM-DD"
            font.pixelSize: styleId.fontSizeM
            verticalAlignment: Text.AlignVCenter
            color: styleId.mainColor
        }

        TextField {
            id: editText
            width: textMetrics.width
            height: label.implicitHeight
            wrapMode: TextEdit.Wrap
            background: Rectangle{
              border.color: styleId.mainColor 
              color: styleId.grey 
            }
            color: styleId.mainColor
            onFocusChanged: {
                if (!editText.focus)
                    root.textFromEditText = editText.text;
            }
        }
    }
}
