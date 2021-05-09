#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <QBitArray>

class GameState
{
public:
    GameState();
    size_t serialize(QBitArray &buf);
    bool deSerialize(QBitArray &buf);


};

#endif // GAMESTATE_H
