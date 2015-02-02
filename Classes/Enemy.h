#pragma once
#include "Mover.h"

class Enemy : public Mover
{
protected:
    int angleRate;
    int shotLimit;
    float shotDelay, shotDelayTmp;
    float moveDelay, moveDelayTmp;
    
    Mover* GetBullet(const std::string fileName);
    Mover* CreateBullet(const std::string fileName);
};