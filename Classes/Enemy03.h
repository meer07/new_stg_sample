//
//  Enemy03.h
//  Getsuyoubi
//
//  Created by 海下直哉 on 2015/01/08.
//
//

#ifndef __Getsuyoubi__Enemy03__
#define __Getsuyoubi__Enemy03__

#include "TaskManager.h"
#include "Enemy.h"

class Enemy03 : public Enemy {
public:
    bool flag;
    static Enemy03* create(const float enemyParam[], const float shotParam[],std::string fileName);
    void MovePattern();
    void Move();
    void Shot();
};

#endif /* defined(__Getsuyoubi__Enemy03__) */
