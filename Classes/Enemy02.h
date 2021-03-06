﻿#pragma once
#include "Enemy.h"

class Enemy02 : public Enemy
{
public:
    static Enemy02* create(const float enemyParam[], std::string fileName);
    void Move();
    void Shot();
    void Destroy();
private:
    void MovePattern();
};