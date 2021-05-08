import QtQuick 2.15

Item {
    id: item1
    width: 400
    height: 400
    property alias mouseAreaMake: mouseAreaMake

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
            id: rectangle
            width: 200
            height: 50
            color: "#debaba"
            radius: 15
            border.width: 2

            Text {
                id: text1
                text: qsTr("Join Match")
                anchors.fill: parent
                font.pixelSize: 24
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold: true
            }

            MouseArea {
                id: mouseAreaJoin
                anchors.fill: parent
            }
        }

        Rectangle {
            id: rectangle1
            width: 200
            height: 50
            color: "#debaba"
            radius: 15
            border.width: 2
            Text {
                id: text2
                text: qsTr("Make Match")
                anchors.fill: parent
                font.pixelSize: 24
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold: true
            }
            MouseArea {
                id: mouseAreaMake
                anchors.fill: parent
                onClicked: mainLoader.source = "GeneralSetup.qml"
            }
        }
    }
}
