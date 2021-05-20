import QtQuick 2.4

JuryPageForm {
    Connections {
        target: roundButton
        function onClicked(mouse) {
            var tempScore = textTechnicScore.text
            tempScore = (tempScore - 0.3).toFixed(1)
            textTechnicScore.text = tempScore
        }
    }

    Connections {
        target: roundButton1
        function onClicked(mouse) {
            var tempScore = textTechnicScore.text
            tempScore = (tempScore - 0.1).toFixed(1)
            textTechnicScore.text = tempScore
        }
    }
}
