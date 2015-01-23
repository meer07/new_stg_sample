#include "GameData.h"

GameData& GameData::getInstance()
{
    static GameData instance;
    return instance;
}

GameData::GameData()
{
    frame = 0;
    score = 0;
    playerHp = 3;
    nowStage = 1;
    stageClear01 = false;
    stageClear02 = false;
    stageClear03 = false;
}