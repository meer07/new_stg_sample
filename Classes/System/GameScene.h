#pragma once
#include <cocos2d.h>
#include "EnemyPattern.h"

class GameScene {
public:
    GameScene();
    ~GameScene();
    void Scene01(cocos2d::Size windowSize);
    void Scene02(cocos2d::Size windowSize);
private:
    EnemyPattern *pattern;
    cocos2d::Label *scoreLabel;
    
    void Pattern01(cocos2d::Size windowSize);
    void Pattern02(cocos2d::Size windowSize);
    void Pattern03(float pointX);
    void Pattern04(float pointX);
    void Pattern05(float pointY);
    void Pattern06(float pointY);

};
