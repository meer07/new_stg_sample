#pragma once
#include "Enemy.h"

class EnemyMissle : public Enemy
{
public:
    static EnemyMissle* create(const float param[], std::string fileName);
    void Move();
    void Collision();
    void Destroy();

private:
    int moveDelay;
    int moveDelayTmp;
    int moveLimit;
    float angleRange;
    void MovePattern();

};
