//
//  Enemy04.h
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/19.
//
//

#ifndef __Getsuyoubi__Enemy04__
#define __Getsuyoubi__Enemy04__

#include "Enemy.h"

class Enemy04 : public Enemy
{
public:
    static Enemy04* create(const float enemyParam[], const float shotParam[],std::string fileName);
    void Move();
    void MovePattern(float rotateAngle);
    void Shot(float rotateAngle);
    void Destroy();
    
private:
    float rotate();
};

#endif /* defined(__Getsuyoubi__Enemy04__) */
