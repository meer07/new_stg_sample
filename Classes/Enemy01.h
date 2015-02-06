#pragma once
#include "Enemy.h"

class Enemy01 : public Enemy
{
public:
    static Enemy01* create(const float enemyParam[], std::string fileName);
    void Move();
    void Shot();
    void Destroy();
private:
    void MovePattern();
};