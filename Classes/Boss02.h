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
    int shotcount;
    float bulletAngle, toPlayerAngle;
    bool moveFlag;
    bool shotFlag;
    void MovePattern(cocos2d::Point nowPoint);
    void MainShot01(float shotAngles[], float shotSpeed, float pointX, int way);
    void MainShot02(int angleRate, float angle);
    void ShotPattern01();
    void ShotPattern02();
    float MakeAngle();
};