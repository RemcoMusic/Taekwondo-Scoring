import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: item1
    width: 400
    height: 400
    property alias button: button
    property alias roundButton1: roundButton1
    property alias roundButton: roundButton
    property alias textTechnicScore: textTechnicScore

    Column {
        id: column
        width: 200
        height: 400
        anchors.verticalCenter: parent.verticalCenter
        spacing: 15
        anchors.horizontalCenter: parent.horizontalCenter

        Text {
            id: text1
            text: qsTr("Jury Screen")
            font.pixelSize: 24
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
        }

        RoundButton {
            id: roundButton
            text: "0.3"
            autoExclusive: false
            checkable: false
            checked: false
            anchors.horizontalCenter: parent.horizontalCenter
        }

        RoundButton {
            id: roundButton1
            text: "0.1"
            font.pointSize: 7
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            id: button
            text: qsTr("Send it!")
            autoRepeat: true
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: text2
            text: qsTr("Technic")
            font.pixelSize: 24
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: textTechnicScore
            text: qsTr("4.0")
            font.pixelSize: 24
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
