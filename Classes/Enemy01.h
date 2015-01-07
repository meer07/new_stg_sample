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
#include "Enemy.h"
#include "Bullet.h"
#include "TaskManager.h"

class Enemy01 : public Enemy
{
public:
    static Enemy01* create(const float param[], std::string fileName);
    void MovePattern();
    void Move();
    void Shot();
};

#endif /* defined(__Getsuyoubi__Enemy01__) */
