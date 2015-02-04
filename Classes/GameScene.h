//
//  GameScene.h
//  SimpleSTG
//
//  Created by 海下 直哉 on 2015/02/03.
//
//
#pragma onece
#include <cocos2d.h>
#include "Mover.h"

class  GameScene{
public:
    virtual void Init(cocos2d::Layer &layer) = 0;
    virtual void RunScene() = 0;
    
protected:
    Mover* GetEnemy(const int enemyNum, const std::string enemyName);
    Mover* CreateEnemy(const int enemyNum);
};