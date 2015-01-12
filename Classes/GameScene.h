//
//  GameScene.h
//  Getsuyoubi
//
//  Created by 海下直哉 on 2015/01/08.
//
//

#ifndef __Getsuyoubi__GameScene__
#define __Getsuyoubi__GameScene__

#include <stdio.h>
#include "EnemyPattern.h"

class GameScene {
public:
    GameScene();
    ~GameScene();
    void Scene01(cocos2d::Size windowSize);

private:
    float frame;
    EnemyPattern *pattern;
};

#endif /* defined(__Getsuyoubi__GameScene__) */
