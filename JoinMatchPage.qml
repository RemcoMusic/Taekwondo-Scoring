import QtQuick 2.15

JoinMatchPageForm {
    Connections {
        target: button
        function onClicked(mouse) {
            mainLoader.source = "RoleSelectionPage.qml"
            mainLoader.createState = false
        }
    }

    Connections {
        target: buttonBack
        function onClicked(mouse) {
            mainLoader.source = "StartUpPage.qml"
        }
    }
}
