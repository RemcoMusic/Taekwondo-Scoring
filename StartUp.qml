import QtQuick 2.15

StartUpForm {

        Connections {
            target: mouseAreaMakeButton
            function onClicked(mouse) { mainLoader.source = "GeneralSetup.qml" }
            function onEntered(mouse) {
                rectangleMakeButton.color = "#85c3cf"
                textMakeButton.font.pixelSize += 2
            }
            function onExited(mouse) {
                rectangleMakeButton.color = "#34acba"
                textMakeButton.font.pixelSize -= 2
            }
        }

        Connections {
            target: mouseAreaJoinButton
//            function onClicked(mouse) { mainLoader.source = "GeneralSetup.qml" }
            function onEntered(mouse) {
                rectangleJoinButton.color = "#85c3cf"
                textJoinButton.font.pixelSize += 2
            }
            function onExited(mouse) {
                rectangleJoinButton.color = "#34acba"
                textJoinButton.font.pixelSize -= 2
            }
        }
}
