import QtQuick 2.15

CreateMatchPageForm {
    Connections {
        target: mouseAreaContinue
        function onClicked(mouse) {
            mainLoader.source = "RoleSelectionPage.qml"
            mainLoader.createState = true
        }
        function onEntered(mouse) {
            rectangleContinueButton.color = "#85c3cf"
            textContinueButton.font.pixelSize += 2
        }
        function onExited(mouse) {
            rectangleContinueButton.color = "#34acba"
            textContinueButton.font.pixelSize -= 2
        }
    }

    Connections {
        target: mouseAreaBackToStart
        function onClicked(mouse) { mainLoader.source = "StartUpPage.qml" }
        function onEntered(mouse) {
            rectangleBackToStart.color = "#85c3cf"
            textBackToStart.font.pixelSize += 2
        }
        function onExited(mouse) {
            rectangleBackToStart.color = "#34acba"
            textBackToStart.font.pixelSize -= 2
        }
    }

    Connections {
        target: comboBoxJuries
        function onActivated() {
            comboBoxJuries.displayText = comboBoxJuries.currentText
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
