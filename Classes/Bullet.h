#pragma once
#include "Mover.h"

class Bullet : public Mover
{
public:
    static Bullet* create(const float param[], std::string fileName);
    void Move();
    void Collision();
};
