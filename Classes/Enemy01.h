#pragma once
#include "Enemy.h"

class Enemy01 : public Enemy
{
public:
    static Enemy01* create(const float enemyParam[], const float shotParam[],std::string fileName);
    void Move();
    void Shot();
    void Destroy();
private:
    void MovePattern();
};