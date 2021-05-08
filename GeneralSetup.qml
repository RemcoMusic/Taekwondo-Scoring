import QtQuick 2.15

GeneralSetupForm {
    Connections {
        target: mouseAreaContinue
        function onClicked(mouse) { stackView.push(column1) }
    }

    Connections {
        target: mouseAreaBackToSetup
        function onClicked(mouse) { stackView.pop() }
    }

    Connections {
        target: mouseAreaBackToStart
        function onClicked(mouse) { mainLoader.source = "StartUp.qml" }
    }

    Connections {
        target: mouseAreaMakeServer
        function onClicked(mouse) { connection.onReceivedStartSignal(textInputMatchName.text,
                                                                     mainLoader.source = "MatchSettings.qml") }
    }
}
