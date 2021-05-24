#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "QString"
#include <QList>
#include <QDateTime>
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
    BLACK9
};

enum class CurrentPoomsae{
    FIRST,
    SECOND
};

struct ScoreLogging{
    CurrentPoomsae currentPoomsae;
    QDateTime date;
    int8_t score;
    QString juryName;
};

struct PlayerRound{
    int8_t round;
    QString firstPoomsae;
    QString secondPoomsae;
    QVector<ScoreLogging> technicScore;
    QVector<ScoreLogging> presentationScore;
};

struct PlayerData{
    QString name;
    QString middleName;
    QString lastName;
    int8_t age;
    Belt beltDegree;
    QString club;
    int8_t totalRounds;
    int8_t currentRound;
    QList<PlayerRound> playerScores;
};

struct GameState{
    QString version;
    QString creationDate;
    QString matchName;
    QString currentDivision;
    int8_t numberOfJuries;
    int8_t numberOfRounds;
    int8_t timePerMatch;
    QList<PlayerData> participatingPlayers;
    QList<PlayerData> eliminatedPlayers;
    PlayerData currentPlayer;
};


#endif // GAMESTATE_H
