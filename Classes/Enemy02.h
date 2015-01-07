//
//  Enemy02.h
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/07.
//
//

#ifndef __Getsuyoubi__Enemy02__
#define __Getsuyoubi__Enemy02__

#include <stdio.h>
#include "Enemy.h"
#include "Bullet.h"
#include "TaskManager.h"

class Enemy02 : public Enemy
{
public:
    static Enemy02* create(const float param[], std::string fileName);
    void MovePattern();
    void Move();
    void Shot();
private:
    int angleRate;
};

#endif /* defined(__Getsuyoubi__Enemy02__) */
