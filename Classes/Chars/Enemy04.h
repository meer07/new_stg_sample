#pragma once
#include "Enemy.h"

class Enemy04 : public Enemy
{
public:
    static Enemy04* create(const float enemyParam[], const float shotParam[],std::string fileName);
    void Move();
    void Shot(float rotateAngle);
    void Destroy();
    
private:
    void MovePattern(float rotateAngle);
    float rotate();
};