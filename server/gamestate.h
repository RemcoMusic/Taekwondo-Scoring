#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "QString"
#include "stdint.h"

#define MAX_MATCHNAME_LENGTH 20
#define MAX_DATE_STR_LENGTH 20

struct GameState{
    uint32_t version;
    char matchName[MAX_MATCHNAME_LENGTH];
    char creationDate[MAX_DATE_STR_LENGTH];
};

#endif // GAMESTATE_H
