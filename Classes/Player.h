#pragma once
#include "Mover.h"

class Player : public Mover
{
public:
    float shotSpeed;
    float shotSpeedRate;
    float shotAngle;
    float shotDelay;
    
    int frame;
    
    static Player* create(cocos2d::Layer *sceneLayer_);
    void Move();
    void Shot();
    void Destroy();
    
private:
    Mover* GetBullet();
    Mover* CreateBullet();
};

