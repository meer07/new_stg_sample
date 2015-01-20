//
//  GameData.cpp
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/14.
//
//

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