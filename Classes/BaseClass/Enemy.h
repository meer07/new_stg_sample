//
//  Enemy.h
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/07.
//
//

#ifndef __Getsuyoubi__Enemy__
#define __Getsuyoubi__Enemy__

#include "Mover.h"
#include "Bullet.h"
#include "TaskManager.h"

class Enemy : public Mover
{
protected:
    int angleRate;
    int shotLimit;
    float shotDelay, shotDelayTmp;
    float moveDelay, moveDelayTmp;
};

#endif /* defined(__Getsuyoubi__Enemy__) */
