#include "gamestatemanager.h"
#include "QDebug"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonArray"
#include "QVariant"

GameStateManager::GameStateManager()
{

}


/*Makes a stream of data wich represents the gamestate */
size_t GameStateManager::serialize(QJsonObject &json)
{    
    json["version"] = gameState->version;
    json["creationDate"] = gameState->creationDate;
    json["matchName"] = gameState->matchName;
    json["currentDivision"] = gameState->currentDivision;
    json["numberOfJuries"] = gameState->numberOfJuries;
    json["numberOfRounds"] = gameState->numberOfRounds;
    json["timePerMatch"] = gameState->timePerMatch;
    json["participatingPlayers"] = serializeNestedData();
    json["currentPlayerID"] = gameState->currentPlayerID;

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

        if(key == "creationDate"){
            gameState->creationDate = value.toString();
        } else if(key == "version"){
            gameState->version = value.toString();
        } else if(key == "matchName"){
            gameState->matchName = value.toString();
        } else if(key == "currentDivision"){
            gameState->currentDivision = value.toString();
        } else if(key == "numberOfJuries"){
            gameState->numberOfJuries = value.toInt();
        } else if(key == "numberOfRounds"){
            gameState->numberOfRounds = value.toInt();
        } else if(key == "timePerMatch"){
            gameState->timePerMatch = value.toInt();
        } else if(key == "participatingPlayers"){
//            gameState->participatingPlayers = value.toArray();
            deSerializeNestedData(value.toArray());
        } else if(key == "currentPlayerID"){
            gameState->currentPlayerID = value.toInt();
        } else{
            qDebug() << "ERR. Key = " << key << ", Value = " << value.toString() << ":     COULD NOT BE DESERIALIZED";
        }
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

QJsonArray GameStateManager::serializeNestedData(){

    QJsonArray listWithPlayerData;
    for(auto &a : gameState->participatingPlayers){
        QJsonObject player;
        player.insert("uniqueID", a.uniqueID);
        player.insert("name", a.name);
        player.insert("middleName", a.middleName);
        player.insert("lastName", a.lastName);
        player.insert("age", a.age);
        player.insert("beltDegree", QVariant::fromValue(a.beltDegree).toJsonValue());
        player.insert("club", a.club);
        player.insert("totalRounds", a.totalRounds);
        player.insert("currentRound", a.currentRound);
        QJsonArray playerScores;
        for(auto &y : a.playerScores){
            QJsonObject score;
            score.insert("round", y.round);
            score.insert("firstPoomsae", y.firstPoomsae);
            score.insert("secondPoomsae", y.secondPoomsae);
            QJsonArray pArrayScore;
            QJsonArray tArrayScore;
            for(auto &z : y.presentationScore){
                QJsonObject pScore;
                pScore.insert("CurrentPoomsae", QVariant::fromValue(z.currentPoomsae).toJsonValue());
                pScore.insert("date", z.date.toString());
                pScore.insert("score", z.score);
                pScore.insert("juryName", z.juryName);
                pArrayScore.append(pScore);
            }
            for(auto &x : y.technicScore){
                QJsonObject tScore;
                tScore.insert("CurrentPoomsae", QVariant::fromValue(x.currentPoomsae).toJsonValue());
                tScore.insert("date", x.date.toString());
                tScore.insert("score", x.score);
                tScore.insert("juryName", x.juryName);
                tArrayScore.append(tScore);
            }
            score.insert("presentationScore", pArrayScore);
            score.insert("technicScore", tArrayScore);
            playerScores.append(score);
        }
        player.insert("participatingPlayers", playerScores);
        listWithPlayerData.append(player);
    }
    return listWithPlayerData;
}

void GameStateManager::deSerializeNestedData(QJsonArray jsonArray){

    foreach (const QJsonValue & player, jsonArray){
        foreach( const QString& key, player.toObject().keys()){
            if(key == "uniqueID"){
                qDebug() << "Nested data deSerialized!";
            }
        }

    }

}
