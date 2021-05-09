#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include <QBitArray>

class GameStateManager
{
public:
    GameStateManager();
    size_t serialize(QBitArray &buf);
    bool deSerialize(QBitArray &buf);


};

#endif // GAMESTATEMANAGER_H
