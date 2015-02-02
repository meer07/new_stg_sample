#pragma once
#include "Mover.h"

class PlayerBullet : public Mover
{
public:
    static PlayerBullet* create(float speed, float speedRate, float angle, std::string fileName);
    void Move();
    void Collision();
    ~PlayerBullet();
};