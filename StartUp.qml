import QtQuick 2.15

StartUpForm {

        Connections {
            target: mouseAreaMake
            function onClicked(mouse) { mainLoader.source = "GeneralSetup.qml" }
        }
}
