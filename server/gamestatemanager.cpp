#include "gamestatemanager.h"
#include "QDebug"
#include "QJsonDocument"
#include "QJsonObject"

GameStateManager::GameStateManager()
{

}


/*Makes a stream of data wich represents the gamestate */
size_t GameStateManager::serialize(QJsonDocument &json, GameStatePartition partition)
{
    //a bit tedious.. but it works...
    QJsonObject j;
    j["version"] = gameState.version;
    j["matchName"] = gameState.matchName;
    j["creationDate"] = gameState.creationDate;


    switch (partition) {
    case(GameStatePartition::NOTHING):
        json.setObject(j);
        return j.size();
    break;
    case(GameStatePartition::ALL):
        //sync every variable

    case(GameStatePartition::POINTS): // will also be called when ALL needs to be serialized
        //sync only the points/score. in case only the score needs to be serialized
    break;
    }

    json.setObject(j);
    return j.size();
}

/*fills the gamestate with from the data received from server*/
void GameStateManager::deSerialize(QJsonDocument &json)
{
   QJsonObject j = json.object();

   if(j.value("version")!=gameState.version){
       qDebug() << "ERR. GAME CLIENT VERSIONS DO NOT MATCH";
       exit(-69);
   }

   foreach(const QString& key, j.keys()) {
       QJsonValue value = j.value(key);
       //qDebug() << "Key = " << key << ", Value = " << value.toString();

        if(key == "creationDate"){  gameState.creationDate = value.toString();} else
        if(key == "version"){       gameState.version = value.toString();} else
        if(key == "matchName"){     gameState.matchName = value.toString();} else
        qDebug() << "ERR. Key = " << key << ", Value = " << value.toString() << ":     COULD NOT BE DESERIALIZED";
   }
}

//returns a pointer to the gamestate on this device.
GameState *GameStateManager::getGamestate()
{
    return &gameState;
}









/*playing around with the class, without UI*/
void GameStateManager::quickTesting()
{
    //set temp gamestate data
    gameState.version = QString::number(1);
    gameState.matchName = "Match#1";
    gameState.creationDate = QDateTime::currentDateTime().toString();





    qDebug() << "Original Data: ";
    qDebug() << gameState.matchName;
    qDebug() << gameState.creationDate;
    qDebug() << gameState.version <<"\n";

    //serialize the gameState
    QJsonDocument doc;
    serialize(doc, GameStatePartition::ALL);

    qDebug() << "formatted JSON \n --------------";
    qDebug() << doc.toJson(QJsonDocument::Indented);
    qDebug() << "--------------<\n";

    //copy data
    QJsonDocument copy = doc;

    //deserialize data
    deSerialize(copy);


    qDebug() << "Data after deserialisation: ";
    qDebug() << gameState.matchName;
    qDebug() << gameState.creationDate;
    qDebug() << gameState.version <<"\n";


//    //copy the data (network emulation)
//    QByteArray c;
//    c = b;

//    // clear the old data
//    b.clear();

//    //set the gameState from the "network" data
//    deSerialize(c);

//    //test results
//    qDebug() << "Copied Gamestate: ";
//    qDebug() << gameState.matchName;
//    qDebug() << gameState.creationDate;
//    qDebug() << gameState.version << "\n";

//    //check if old (cleared) data is really cleared

//    //set the gameState from the "network" data
//    deSerialize(b);
//    qDebug() << "Old Gamestate: ";
//    qDebug() << gameState.matchName;
//    qDebug() << gameState.creationDate;
//    qDebug() << gameState.version << "\n";


}
