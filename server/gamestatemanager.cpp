#include "gamestatemanager.h"
#include "QDebug"
#include "QJsonDocument"
#include "QJsonObject"

GameStateManager::GameStateManager()
{

}


/*Makes a stream of data wich represents the gamestate */
size_t GameStateManager::serialize(QJsonObject &json)
{    
    json["version"] = gameState->version;
    json["matchName"] = gameState->matchName;
    json["creationDate"] = gameState->creationDate;

    return json.size();
}

/*fills the gamestate with from the data received from server*/
void GameStateManager::deSerialize(QJsonObject &json)
{


   if(json.value("version")!=gameState->version){
       qDebug() << "ERR. GAME CLIENT VERSIONS DO NOT MATCH";
       exit(-69);
   }

   foreach(const QString& key, json.keys()) {
       QJsonValue value = json.value(key);
       //qDebug() << "Key = " << key << ", Value = " << value.toString();

        if(key == "creationDate"){  gameState->creationDate = value.toString();} else
        if(key == "version"){       gameState->version = value.toString();} else
        if(key == "matchName"){     gameState->matchName = value.toString();} else
        qDebug() << "ERR. Key = " << key << ", Value = " << value.toString() << ":     COULD NOT BE DESERIALIZED";
   }
}

//returns a pointer to the gamestate on this device.
GameState *GameStateManager::getGamestate()
{
    return gameState;
}

void GameStateManager::setGameState(GameState *gameState)
{
    this->gameState = gameState;
}

