import QtQuick 2.15

MatchSettingsForm {

    //This connection is used to be automaticaly updated by the backend when the signal is being emitted
    Connections{
        target: connection
        function onUniqueIDChanged() { text1.text = connection.uniqueID }
    }
}
