import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: item1
    width: 400
    height: 400

    Text {
        id: text1
        x: 157
        y: 132
        text: qsTr("Host Screen")
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 24
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
