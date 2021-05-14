import QtQuick 2.15

Item {
    id: item1
    width: 400
    height: 400
    property alias mouseAreaJoinButton: mouseAreaJoinButton
    property alias textJoinButton: textJoinButton
    property alias rectangleJoinButton: rectangleJoinButton
    property alias mouseAreaMakeButton: mouseAreaMakeButton
    property alias textMakeButton: textMakeButton
    property alias rectangleMakeButton: rectangleMakeButton

    Text {
        id: textTitleApp
        text: qsTr("Ultimate Taekwondo Scoring")
        anchors.bottom: rectangleBackGround.top
        font.pixelSize: 25
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
        anchors.bottomMargin: 50
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Rectangle {
        id: rectangleBackGround
        x: 100
        y: 120
        width: 300
        height: 500
        color: "#7a7d84"
        radius: 15
        border.color: "#212121"
        border.width: 3
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Column {
        id: column
        x: 100
        y: 0
        width: 200
        height: 400
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10

        Rectangle {
            id: rectangleJoinButton
            width: 200
            height: 50
            color: "#34acba"
            radius: 15
            border.color: "#065464"
            border.width: 2

            Text {
                id: textJoinButton
                color: "#212121"
                text: qsTr("Join Match")
                anchors.fill: parent
                font.pixelSize: 24
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                styleColor: "#861313"
                font.bold: true
            }

            MouseArea {
                id: mouseAreaJoinButton
                anchors.fill: parent
                hoverEnabled: true
            }
        }

        Rectangle {
            id: rectangleMakeButton
            width: 200
            height: 50
            color: "#34acba"
            radius: 15
            border.color: "#065464"
            border.width: 2
            Text {
                id: textMakeButton
                color: "#212121"
                text: qsTr("Make Match")
                anchors.fill: parent
                font.pixelSize: 24
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold: true
            }
            MouseArea {
                id: mouseAreaMakeButton
                anchors.fill: parent
                hoverEnabled: true
                onClicked: mainLoader.source = "GeneralSetup.qml"
            }
        }
    }
}
