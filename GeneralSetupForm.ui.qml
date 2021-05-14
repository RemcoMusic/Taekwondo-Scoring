import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: item1
    width: 400
    height: 400
    property alias item1: item1
    property alias textBackToSetup: textBackToSetup
    property alias rectangleBackToSetup: rectangleBackToSetup
    property alias textMakeServer: textMakeServer
    property alias rectangleMakeServer: rectangleMakeServer
    property alias mouseAreaServer: mouseAreaServer
    property alias textServer: textServer
    property alias rectangleServer: rectangleServer
    property alias mouseAreaScoreboard: mouseAreaScoreboard
    property alias textScoreboard: textScoreboard
    property alias rectangleScoreboard: rectangleScoreboard
    property alias mouseAreaJury: mouseAreaJury
    property alias textJury: textJury
    property alias rectangleJury: rectangleJury
    property alias mouseAreaHost: mouseAreaHost
    property alias textHost: textHost
    property alias rectangleHost: rectangleHost
    property alias columnDeviceType: columnDeviceType
    property alias textBackToStart: textBackToStart
    property alias rectangleBackToStart: rectangleBackToStart
    property alias textContinueButton: textContinueButton
    property alias rectangleContinueButton: rectangleContinueButton
    property alias comboBoxJuries: comboBoxJuries
    property alias cbItems: cbItems
    property alias textFieldMatchName: textFieldMatchName
    property alias mouseAreaMakeServer: mouseAreaMakeServer
    property alias mouseAreaBackToSetup: mouseAreaBackToSetup
    property alias mouseAreaBackToStart: mouseAreaBackToStart
    property alias stackView: stackView
    property alias mouseAreaContinue: mouseAreaContinue

    StackView {
        id: stackView
        width: 200
        height: 200
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        initialItem: columnBasicSettings

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

        Column {
            id: columnDeviceType
            width: 200
            height: 400
            visible: false
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 10

            Text {
                id: textInfoDeviceType
                text: qsTr("What should this device be?")
                font.pixelSize: 24
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.horizontalCenter: parent.horizontalCenter
                font.bold: true
            }

            Rectangle {
                id: rectangleHost
                width: 200
                height: 50
                color: "#34acba"
                radius: 15
                border.color: "#065464"
                border.width: 2
                anchors.horizontalCenter: parent.horizontalCenter
                Text {
                    id: textHost
                    color: "#212121"
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
                id: rectangleJury
                width: 200
                height: 50
                color: "#34acba"
                radius: 15
                border.color: "#065464"
                border.width: 2
                anchors.horizontalCenter: parent.horizontalCenter
                Text {
                    id: textJury
                    color: "#212121"
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
                id: rectangleScoreboard
                width: 200
                height: 50
                color: "#34acba"
                radius: 15
                border.color: "#065464"
                border.width: 2
                anchors.horizontalCenter: parent.horizontalCenter
                Text {
                    id: textScoreboard
                    color: "#212121"
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
                id: rectangleServer
                width: 200
                height: 50
                color: "#34acba"
                radius: 15
                border.color: "#065464"
                border.width: 2
                anchors.horizontalCenter: parent.horizontalCenter
                Text {
                    id: textServer
                    color: "#212121"
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
                id: rectangleMakeServer
                width: 200
                height: 50
                color: "#34acba"
                radius: 15
                border.color: "#065464"
                border.width: 2
                anchors.horizontalCenterOffset: 0
                anchors.horizontalCenter: parent.horizontalCenter
                Text {
                    id: textMakeServer
                    color: "#212121"
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
                id: rectangleBackToSetup
                width: 200
                height: 50
                color: "#34acba"
                radius: 15
                border.color: "#065464"
                border.width: 2
                Text {
                    id: textBackToSetup
                    color: "#212121"
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
    states: [
        State {
            name: "hostSelected"
            PropertyChanges {
                target: rectangleHost
                color: "#85c3cf"
                width: 210
                height: 60
                restoreEntryValues: true
            }
            PropertyChanges {
                target: textHost
                font.pixelSize: 26
                restoreEntryValues: true
            }
        },
        State {
            name: "jurySelected"
            PropertyChanges {
                target: rectangleJury
                color: "#85c3cf"
                width: 210
                height: 60
                restoreEntryValues: true
            }
            PropertyChanges {
                target: textJury
                font.pixelSize: 26
                restoreEntryValues: true
            }
        },
        State {
            name: "scoreboardSelected"
            PropertyChanges {
                target: rectangleScoreboard
                color: "#85c3cf"
                width: 210
                height: 60
                restoreEntryValues: true
            }
            PropertyChanges {
                target: textScoreboard
                font.pixelSize: 26
                restoreEntryValues: true
            }
        },
        State {
            name: "serverSelected"
            PropertyChanges {
                target: rectangleServer
                color: "#85c3cf"
                width: 210
                height: 60
                restoreEntryValues: true
            }
            PropertyChanges {
                target: textServer
                font.pixelSize: 26
                restoreEntryValues: true
            }
        }
    ]
}
