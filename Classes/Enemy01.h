//
//  Enemy01.h
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/06.
//
//

#ifndef __Getsuyoubi__Enemy01__
#define __Getsuyoubi__Enemy01__

#include <stdio.h>
#include "Mover.h"
#include "Bullet.h"
#include "TaskManager.h"

class Enemy01 : public Mover{
public:
    static Enemy01* create(const float param[], Layer *sceneLayer_);
    void Move();
    void Shot();
private:
    float shotParam[3] = {5, 1, -90};
    float shotDelay;
};

#endif /* defined(__Getsuyoubi__Enemy01__) */
