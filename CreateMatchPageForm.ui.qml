import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: item1
    width: 400
    height: 400
    property alias item1: item1
    property alias textBackToStart: textBackToStart
    property alias rectangleBackToStart: rectangleBackToStart
    property alias textContinueButton: textContinueButton
    property alias rectangleContinueButton: rectangleContinueButton
    property alias comboBoxJuries: comboBoxJuries
    property alias cbItems: cbItems
    property alias textFieldMatchName: textFieldMatchName
    property alias mouseAreaBackToStart: mouseAreaBackToStart
    property alias mouseAreaContinue: mouseAreaContinue

    Column {
        id: columnBasicSettings
        x: 100
        y: 0
        width: 200
        height: 400
        visible: true
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10

        Text {
            id: textInfoInputField
            text: qsTr("Match Name:")
            font.pixelSize: 24
            anchors.horizontalCenter: parent.horizontalCenter
            font.bold: true
        }

        TextField {
            id: textFieldMatchName
            width: 200
            height: 50
            horizontalAlignment: Text.AlignHCenter
            font.bold: true
            font.pointSize: 18
            placeholderText: qsTr("#Match1")
            background: Rectangle {
                id: rectangleInputMatchName
                color: "#34acba"
                radius: 15
                border.color: "#065464"
                border.width: 2
            }
        }

        Text {
            id: textInfoJuries
            text: qsTr("Number of Juries:")
            font.pixelSize: 24
            anchors.horizontalCenter: parent.horizontalCenter
            font.bold: true
        }

        ComboBox {
            id: comboBoxJuries
            width: 200
            height: 50
            font.bold: true
            font.weight: Font.Normal
            font.pointSize: 14
            editable: false
            anchors.horizontalCenter: parent.horizontalCenter
            displayText: "Select number"
            flat: false
            model: ListModel {
                id: cbItems
                ListElement {
                    text: "3"
                }
                ListElement {
                    text: "5"
                }
                ListElement {
                    text: "7"
                }
            }
            background: Rectangle {
                id: rectangleDropDown
                color: "#34acba"
                radius: 15
                border.color: "#065464"
                border.width: 2
            }
        }

        Rectangle {
            id: rectangleContinueButton
            width: 200
            height: 50
            color: "#34acba"
            radius: 15
            border.color: "#065464"
            border.width: 2
            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                id: textContinueButton
                color: "#212121"
                text: qsTr("Continue")
                anchors.fill: parent
                font.pixelSize: 24
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold: true
            }

            MouseArea {
                id: mouseAreaContinue
                anchors.fill: parent
                hoverEnabled: true
            }
        }

        Rectangle {
            id: rectangleBackToStart
            width: 200
            height: 50
            color: "#34acba"
            radius: 15
            border.color: "#065464"
            border.width: 2
            Text {
                id: textBackToStart
                color: "#212121"
                text: qsTr("Back")
                anchors.fill: parent
                font.pixelSize: 24
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold: true
            }

            MouseArea {
                id: mouseAreaBackToStart
                anchors.fill: parent
                hoverEnabled: true
            }
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
