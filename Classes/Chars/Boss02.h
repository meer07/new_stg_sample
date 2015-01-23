#pragma once
#include "Enemy.h"

class Boss02 : public Enemy
{
public:
    static Boss02* create(std::string fileName);
    
    void Move();
    void Shot();
    void Destroy();
    
private:
    float bulletAngle;
    bool moveFlag;
    bool shotFlag;
    void MovePattern(cocos2d::Point nowPoint);
    void MainShot(float shotAngle[], float shotSpeed, int way, std::string fileName);
    void ShotPattern(float angle, float shotSpeed, std::string fileName);
    float MakeAngle();
};