import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: item1
    width: 400
    height: 400
    property alias buttonBack: buttonBack
    property alias button: button

    Column {
        id: column
        width: 200
        height: 400
        anchors.verticalCenter: parent.verticalCenter
        spacing: 15
        anchors.horizontalCenter: parent.horizontalCenter

        TextField {
            id: textField
            placeholderText: qsTr("Input: IP Adress")
        }

        Button {
            id: button
            text: qsTr("Continue")
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            id: buttonBack
            text: qsTr("Back")
            checkable: false
            checked: false
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
