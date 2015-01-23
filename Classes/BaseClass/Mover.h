#pragma once // 二重展開防止
#include <cocos2d.h>

class Mover : public cocos2d::Sprite
{
public:
    int score;
    int hitpoint;
    float speed;
    float speedRate;
    float angle;
    bool isAlive;
    
    // 仮想メソッド
    virtual void Move(){};
    virtual void Collision(){};
    virtual void Destroy();
    
protected:
    virtual void MovePattern(){};
    void MoveBase();
};
