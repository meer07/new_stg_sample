#pragma once
#include "Enemy.h"

class Enemy03 : public Enemy {
public:
    bool flag;
    static Enemy03* create(const float enemyParam[], const float shotParam[],std::string fileName);
    void Move();
    void Shot();
    void Destroy();
private:
    void MovePattern();
};