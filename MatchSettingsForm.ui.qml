import QtQuick 2.15

Item {
    id: item1
    width: 400
    height: 400
    property alias text1: text1

    Column {
        id: column
        width: 200
        height: 400
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        Text {
            id: text1
            text: connection.uniqueID
            font.pixelSize: 24
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
