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
    score = 0;
    playerHp = 3;
}