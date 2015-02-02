#pragma once
#include <cocos2d.h>

class GameData {
public:
    static GameData* getInstance();
    GameData(const GameData &other) = delete;
    GameData &operator=(const GameData &other) = delete;
    
    int nowStage, score, playerHp;
    float frame;
    bool stageClear01, stageClear02, stageClear03; // クリアフラグ
    void init();
private:
    GameData(){};
};

