import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: item1
    width: 400
    height: 400
    property alias textInputMatchName: textInputMatchName
    property alias mouseAreaMakeServer: mouseAreaMakeServer
    property alias mouseAreaBackToSetup: mouseAreaBackToSetup
    property alias mouseAreaBackToStart: mouseAreaBackToStart
    property alias column1: column1
    property alias stackView: stackView
    property alias mouseAreaContinue: mouseAreaContinue

    StackView {
        id: stackView
        width: 200
        height: 200
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        initialItem: column

        Column {
            id: column
            x: 100
            y: 0
            width: 200
            height: 400
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 10

            Text {
                id: text1
                text: qsTr("Match Name:")
                font.pixelSize: 24
                anchors.horizontalCenter: parent.horizontalCenter
                font.bold: true
            }

            Rectangle {
                id: rectangle
                width: 200
                height: 50
                color: "#ffffff"
                radius: 15
                border.width: 2
                anchors.horizontalCenter: parent.horizontalCenter

                TextInput {
                    id: textInputMatchName
                    text: qsTr("Match#1")
                    anchors.fill: parent
                    font.pixelSize: 18
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: false
                }
            }

            Text {
                id: text2
                text: qsTr("Number of Juries:")
                font.pixelSize: 24
                anchors.horizontalCenter: parent.horizontalCenter
                font.bold: true
            }

            ComboBox {
                id: comboBox
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
            }

            Rectangle {
                id: rectangle1
                width: 200
                height: 50
                color: "#ffffff"
                radius: 15
                border.width: 2
                anchors.horizontalCenter: parent.horizontalCenter

                Text {
                    id: text3
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
                }
            }

            Rectangle {
                id: rectangle8
                width: 200
                height: 50
                color: "#ffffff"
                radius: 15
                border.width: 2
                Text {
                    id: text10
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
                }
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

        Column {
            id: column1
            width: 200
            height: 400
            visible: false
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 10

            Text {
                id: text4
                text: qsTr("What should this device be?")
                font.pixelSize: 24
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.horizontalCenter: parent.horizontalCenter
                font.bold: true
            }

            Rectangle {
                id: rectangle2
                width: 200
                height: 50
                color: "#ffffff"
                radius: 15
                border.width: 2
                anchors.horizontalCenter: parent.horizontalCenter
                Text {
                    id: text5
                    text: qsTr("Host")
                    anchors.fill: parent
                    font.pixelSize: 24
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }

                MouseArea {
                    id: mouseAreaHost
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: rectangle3
                width: 200
                height: 50
                color: "#ffffff"
                radius: 15
                border.width: 2
                anchors.horizontalCenter: parent.horizontalCenter
                Text {
                    id: text6
                    text: qsTr("Jury")
                    anchors.fill: parent
                    font.pixelSize: 24
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }

                MouseArea {
                    id: mouseAreaJury
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: rectangle4
                width: 200
                height: 50
                color: "#ffffff"
                radius: 15
                border.width: 2
                anchors.horizontalCenter: parent.horizontalCenter
                Text {
                    id: text7
                    text: qsTr("Scoreboard")
                    anchors.fill: parent
                    font.pixelSize: 24
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }

                MouseArea {
                    id: mouseAreaScoreboard
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: rectangle5
                width: 200
                height: 50
                color: "#ffffff"
                radius: 15
                border.width: 2
                anchors.horizontalCenter: parent.horizontalCenter
                Text {
                    id: text8
                    text: qsTr("Headless Server")
                    anchors.fill: parent
                    font.pixelSize: 24
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }

                MouseArea {
                    id: mouseAreaServer
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: rectangle7
                width: 200
                height: 50
                color: "#00000000"
                border.color: "#00000000"
            }

            Rectangle {
                id: rectangle6
                width: 200
                height: 50
                color: "#ffffff"
                radius: 15
                border.width: 2
                anchors.horizontalCenterOffset: 0
                anchors.horizontalCenter: parent.horizontalCenter
                Text {
                    id: text9
                    text: qsTr("Make Match ->")
                    anchors.fill: parent
                    font.pixelSize: 24
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }

                MouseArea {
                    id: mouseAreaMakeServer
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: rectangle9
                width: 200
                height: 50
                color: "#ffffff"
                radius: 15
                border.width: 2
                Text {
                    id: text11
                    text: qsTr("Back")
                    anchors.fill: parent
                    font.pixelSize: 24
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }

                MouseArea {
                    id: mouseAreaBackToSetup
                    anchors.fill: parent
                }
                anchors.horizontalCenterOffset: 0
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }
}
