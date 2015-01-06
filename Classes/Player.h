//
//  Player.h
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/05.
//
//

#ifndef __Getsuyoubi__Player__
#define __Getsuyoubi__Player__

#include <stdio.h>
#include "Mover.h"
#include "PlayerBullet.h"
#include "TaskManager.h"

using namespace cocos2d;

class Player : public Mover{
public:
    float shotSpeed;
    float shotSpeedRate;
    float shotAngle;
    float shotDelay;
    
    static Player* create(Layer *sceneLayer_);
    void Move();
    void Shot();
};
#endif /* defined(__Getsuyoubi__Player__) */
