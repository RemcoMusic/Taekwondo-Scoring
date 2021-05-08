import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 1920
    height: 1080
    visible: true
    title: qsTr("Taekwondo Scoring")

    Loader{
        id: mainLoader
        anchors.fill: parent
        source: "StartUp.qml"
    }
}
