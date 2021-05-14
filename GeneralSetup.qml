import QtQuick 2.15

GeneralSetupForm {
    Connections {
        target: mouseAreaContinue
        function onClicked(mouse) { stackView.push(column1) }
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
        function onClicked(mouse) { mainLoader.source = "StartUp.qml" }
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

    Connections {
        target: mouseAreaBackToSetup
        function onClicked(mouse) { stackView.pop() }
    }

    Connections {
        target: mouseAreaMakeServer
        function onClicked(mouse) {
            if(textFieldMatchName.text === ""){
                console.log(textFieldMatchName.text)
            } else {
                connection.onReceivedStartSignal(textFieldMatchName.text)
                mainLoader.source = "MatchSettings.qml"
            }
        }
    }
}
