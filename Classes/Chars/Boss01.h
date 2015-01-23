#pragma once
#include "Enemy.h"

class Boss01 : public Enemy
{
public:
    static Boss01* create(std::string fileName);
    void Move();
    void Shot(cocos2d::Point nowPoint);
    void Destroy();
    
private:
    bool moveFlag;
    bool shotFlag;
    void MovePattern(cocos2d::Point nowPoint);
    void MainShot(float baseAngle);
    void RotateShot(float angle);
};