#pragma once
#include "Enemy.h"

class Meteorite : public Enemy{
public:
    static Meteorite* create(const float enemyParam[], std::string fileName);
    void Move();
    void Destroy();
};

