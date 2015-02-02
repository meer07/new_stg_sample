#pragma once
#include <cocos2d.h>
#include <vector>
#include "Mover.h"

class TaskManager {
public:
    TaskManager(){}
    static std::vector<Mover *> objectContainer;
    static Mover *player;
    void Run();
    void Clear(Mover *);
};