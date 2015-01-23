#pragma once
#include "Enemy.h"

class MidEnemy01 : public Enemy {
public:
    static MidEnemy01* create(const float enemyParam[], const float shotParam[],std::string fileName);
    void Move();
    void Shot();
    void Destroy();

private:
    void MovePattern();
    float GetAngle();
};