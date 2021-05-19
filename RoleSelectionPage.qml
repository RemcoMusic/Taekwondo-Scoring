import QtQuick 2.4

RoleSelectionPageForm {
    Connections {
        target: mouseAreaHost
        function onClicked(mouse) {
            item1.state = "hostSelected"
        }
    }

    Connections {
        target: mouseAreaJury
        function onClicked(mouse) {
            item1.state = "jurySelected"
        }
    }

    Connections {
        target: mouseAreaScoreboard
        function onClicked(mouse) {
            item1.state = "scoreboardSelected"
        }
    }

    Connections {
        target: mouseAreaServer
        function onClicked(mouse) {
            item1.state = "serverSelected"
        }
    }

    Connections {
        target: mouseAreaMakeServer
        function onClicked(mouse) {
            if(item1.state == "hostSelected"){
                mainLoader.source = "HostPage.qml"
            } else if(item1.state == "jurySelected"){
               mainLoader.source = "JuryPage.qml"
            }
        }
    }

    Connections {
        target: mouseAreaBackToSetup
        function onClicked(mouse) {
            if(mainLoader.createState){
                mainLoader.source = "CreateMatchPage.qml"
            } else {
                mainLoader.source = "JoinMatchPage.qml"
            }
        }
    }
}
