#include "TaskManager.h"

void TaskManager::Run()
{
    std::vector<Mover *>::iterator i;
    for (i = objectContainer.begin(); i != objectContainer.end(); ++i)
    {
        // そもそもリストが空のときループを抜ける
        if (objectContainer.empty()) {
            break;
        }
        
        // 生存フラグが負であるとき削除
        if ((*i)->isAlive == false)
        {
            (*i)->setVisible(false);
            (*i)->Destroy();
        }
        else
        {
            (*i)->Move();
        }
    }
}

void TaskManager::Clear(Mover *)
{
    std::vector<Mover *>::iterator i;
    for (i = objectContainer.begin(); i != objectContainer.end(); ++i)
    {
        (*i)->getScene()->removeChild(*i);
    }
    
    objectContainer.clear();
}