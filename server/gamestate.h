#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "QString"
#include <QList>
#include "stdint.h"

#define HOST_PORT   80  //port the server will run on

enum class Belt{
    WHITE,
    WHITEYELLOW,
    YELLOW,
    YELLOWGREEN,
    GREEN,
    GREENBLUE,
    BLUE,
    BLUERED,
    RED,
    REDBLACK,
    BLACK,
    BLACK2,
    BLACK3,
    BLACK4,
    BLACK5,
    BLACK6,
    BLACK7,
    BLACK8,
    BLACK9,
};

struct PlayerData{
    QString name;
    QString middleName;
    QString lastName;
    int8_t age;
    Belt beltDegree;
    QString club;
    //A variable for tracking scores
    //A variable for how many rounds
    //A variable for which Poomsae for which round
};

struct GameState{
    QString version;
    QString creationDate;
    QString matchName;
    QString currentDivision; //eq 17 over 1 and 2 kup Male
    int8_t numberOfJuries;
    int8_t numberOfRounds; //Depends on number of players
    int8_t timePerMatch;
    QList<PlayerData> participatingPlayers;
    QList<PlayerData> eliminatedPlayers;
    PlayerData currentPlayer;
};


#endif // GAMESTATE_H
