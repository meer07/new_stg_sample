//
//  EnemyMissle.h
//  Getsuyoubi
//
//  Created by 海下直哉 on 2015/01/12.
//
//

#include <stdio.h>
#include "Mover.h"

class EnemyMissle : public Mover
{
public:
    static EnemyMissle* create(const float param[], std::string fileName);
    
    void MovePattern();
    void Move();
    void Collision();

private:
    int moveDelay;
    float angleRange;
};
