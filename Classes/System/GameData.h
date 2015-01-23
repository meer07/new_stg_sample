#pragma once
#include <cocos2d.h>

class GameData {
public:
    static GameData& getInstance();
    int nowStage, score, playerHp;
    float frame;
    bool stageClear01, stageClear02, stageClear03;
    
    GameData();
    GameData(const GameData &other){}
    GameData &operator = (const GameData &other){}
    
    void ShowScore(cocos2d::Size windowSize);
};

