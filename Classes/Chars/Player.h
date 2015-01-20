//
//  Player.h
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/05.
//
//

#ifndef __Getsuyoubi__Player__
#define __Getsuyoubi__Player__

#include "Mover.h"

class Player : public Mover
{
public:
    float shotSpeed;
    float shotSpeedRate;
    float shotAngle;
    float shotDelay;
    
    int frame;
    bool muteki;
    
    static Player* create(cocos2d::Layer *sceneLayer_);
    void Move();
    void Shot();
    void Destroy();
};
#endif /* defined(__Getsuyoubi__Player__) */
