//
//  Bullet.h
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/05.
//
//

#ifndef __Getsuyoubi__Bullet__
#define __Getsuyoubi__Bullet__

#include <stdio.h>
#include "Mover.h"
using namespace cocos2d;

class Bullet : public Mover
{
public:
    static Bullet* create(const float param[], std::string fileName);
    void Move();
    void Collision();
};
#endif /* defined(__Getsuyoubi__Bullet__) */
