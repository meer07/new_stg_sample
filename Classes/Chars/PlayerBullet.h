//
//  PlayerBullet.h
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/05.
//
//

#ifndef __Getsuyoubi__PlayerBullet__
#define __Getsuyoubi__PlayerBullet__

#include "Mover.h"

class PlayerBullet : public Mover
{
public:
    static PlayerBullet* create(float speed, float speedRate, float angle, std::string fileName);
    void Move();
    void Collision();
    ~PlayerBullet();
};

#endif /* defined(__Getsuyoubi__PlayerBullet__) */
