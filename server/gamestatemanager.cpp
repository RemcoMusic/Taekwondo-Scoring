#include "gamestatemanager.h"
#include "QDebug"

GameStateManager::GameStateManager()
{

}


/*Makes a stream of data wich represents the gamestate */
size_t GameStateManager::serialize(QByteArray &buf)
{
    buf.clear();
    buf.append((const char*)&gameState,sizeof (GameState));
    return buf.size();
}

/*fills the gamestate with from the data received from server*/
void GameStateManager::deSerialize(QByteArray &buf)
{
    memcpy(&gameState,buf.data(),sizeof (GameState));
}

/*playing around with the class, without UI*/
void GameStateManager::quickTesting()
{
    strcpy(gameState.matchName,"LOL");
    strcpy(gameState.creationDate,"Yesterday");
    gameState.version = 1;




    qDebug() << "Original Data: ";
    qDebug() << gameState.matchName;
    qDebug() << gameState.creationDate;
    qDebug() << gameState.version <<"\n";

    //serialize the gameState
    QByteArray b;
    serialize(b);

    //copy the data (network emulation)
    QByteArray c;
    c = b;

    // clear the old data
    b.clear();

    //set the gameState from the "network" data
    deSerialize(c);

    //test results
    qDebug() << "Copied Gamestate: ";
    qDebug() << gameState.matchName;
    qDebug() << gameState.creationDate;
    qDebug() << gameState.version << "\n";

    //check if old (cleared) data is really cleared

    //set the gameState from the "network" data
    deSerialize(b);
    qDebug() << "Old Gamestate: ";
    qDebug() << gameState.matchName;
    qDebug() << gameState.creationDate;
    qDebug() << gameState.version << "\n";


}
