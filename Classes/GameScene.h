//
//  GameScene.h
//  Getsuyoubi
//
//  Created by 海下直哉 on 2015/01/08.
//
//

#ifndef __Getsuyoubi__GameScene__
#define __Getsuyoubi__GameScene__

#include "EnemyPattern.h"
#include "UIManager.h"

class GameScene {
public:
    GameScene();
    ~GameScene();
    void Scene01(cocos2d::Size windowSize);

private:
    float frame;
    EnemyPattern *pattern;
    UIManager *ui;
    cocos2d::Label *scoreLabel;
    
    void Pattern01(cocos2d::Size windowSize);
    void Pattern02(cocos2d::Size windowSize);
    void Pattern03(float pointX);
};

#endif /* defined(__Getsuyoubi__GameScene__) */
