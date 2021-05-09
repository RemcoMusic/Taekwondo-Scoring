#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "QString"
#include "stdint.h"

enum class GameStatePartition{
    ALL,
    POINTS,
    NOTHING
};

struct GameState{
    QString version;
    QString matchName;
    QString creationDate;

};

#endif // GAMESTATE_H
